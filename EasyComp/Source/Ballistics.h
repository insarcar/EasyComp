#pragma once
#include <JuceHeader.h>

class Ballistics
{
public:
	Ballistics() 
	{
		attack.setCurrentAndTargetValue(expf(-1.0f / (DEFAULT_ATTACK * 0.001f * sampleRate)));
		release.setCurrentAndTargetValue(expf(-1.0f / (DEFAULT_RELEASE * 0.001f * sampleRate)));
	};
	~Ballistics() {};

	void prepareToPlay(double sR) 
	{
		sampleRate = sR;
		attack.reset(sR, SMOOTHING_RAMP);
		release.reset(sR, SMOOTHING_RAMP);
	};
	void releaseResources() {};

    void setAttack(const float atk)
    {
		const float temp = atk * 0.001f * sampleRate;
		attack.setTargetValue(expf(-1.0f / temp));
    }

    void setRelease(const float rel)
    {
		const float temp = rel * 0.001f * sampleRate;
		release.setTargetValue(expf(-1.0f / temp));
    }

	void processBlock(float* sideData, int nS) 
	{
		numSamples = nS;
		applyBallistics(sideData);
	}

private:

	void applyBallistics(float* sideData) 
	{
		for (int smp = 0; smp < numSamples; ++smp)
			sideData[smp] = processPeakBranched(sideData[smp]);
	};
	float processPeakBranched(float sample)
	{	
		const float atk = attack.getNextValue() * state + (1.0f - attack.getNextValue()) * sample;
		const float rel = release.getNextValue() * state + (1.0f - release.getNextValue()) * sample;

		state = (sample < state) ? atk : rel;
		return state;
	};

	int numSamples = 0;
	double sampleRate = 0.0;
	SmoothedValue<float,ValueSmoothingTypes::Linear> attack, release;
	float state = 0.0f;
};