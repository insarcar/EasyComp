#pragma once
#include <JuceHeader.h>
#include "Envelope.h"
#include "Ballistics.h"

class EzComp: public AudioProcessorValueTreeState::Listener 
{
public:
	EzComp() 
	{	
		//smoothed values init
		inputGainMain.setCurrentAndTargetValue(Decibels::decibelsToGain(DEFAULT_INPUT));
		inputGainSide.setCurrentAndTargetValue(Decibels::decibelsToGain(DEFAULT_INPUT));
		ratio.setCurrentAndTargetValue(DEFAULT_RATIO);
		makeup.setCurrentAndTargetValue(Decibels::decibelsToGain(DEFAULT_MAKEUP));
		threshold.setCurrentAndTargetValue(DEFAULT_THRESHOLD);
		knee.setCurrentAndTargetValue(DEFAULT_KNEE);
	};
	~EzComp() {};

	void prepareToPlay(dsp::ProcessSpec& processSpec)
	{	

		//ballistics filter's prepareToPlay
		ballistics.prepareToPlay(processSpec.sampleRate);

		//envelope's prepareToPlay
		detector.prepareToPlay(processSpec.sampleRate);
		
		//smoothed values reset
		inputGainMain.reset(processSpec.sampleRate, SMOOTHING_RAMP);
		inputGainSide.reset(processSpec.sampleRate, SMOOTHING_RAMP);
		ratio.reset(processSpec.sampleRate, SMOOTHING_RAMP);
		makeup.reset(processSpec.sampleRate, SMOOTHING_RAMP);
		threshold.reset(processSpec.sampleRate, SMOOTHING_RAMP);
		knee.reset(processSpec.sampleRate, SMOOTHING_RAMP);
	};

	void releaseResources()
	{
		detector.releaseResources();
		ballistics.releaseResources();
		
	};

	void processBlock(AudioBuffer<float>& main, AudioBuffer<float>& side)
	{
		auto numSamples = main.getNumSamples();

		//input gain
		inputGainMain.applyGain(main, numSamples);
		inputGainSide.applyGain(side, numSamples);
		
		//peak or rRms detector
		detector.processBlock(side, numSamples);

		//gain computer
		gainComputer(side, numSamples);

		//gain staging
		applyGain(main, side, numSamples);

	};

	float getMaxGainReduction(AudioBuffer<float>& side)
	{
		const auto* ctrlData = side.getReadPointer(0);
		const auto maxGainReduction = 1.0f - pow(FloatVectorOperations::findMinimum(ctrlData, side.getNumSamples()), 0.5f);
		return maxGainReduction;
	};


private:
	//applies gain to main buffer
	void applyGain(AudioBuffer<float>& main, AudioBuffer<float>& side, int numSamples)
	{
		float** mainData = main.getArrayOfWritePointers();
		const float* sideData = side.getReadPointer(0);

		
		for (int ch = main.getNumChannels(); --ch >= 0; )
		{
			FloatVectorOperations::multiply(mainData[ch], sideData, numSamples);
		}
		makeup.applyGain(main, numSamples);
	};

	//gain computer
	void gainComputer(AudioBuffer<float>& scBuffer, int numSamples)
	{
		float* sideData = scBuffer.getWritePointer(0);
		
		FloatVectorOperations::abs(sideData, sideData, numSamples);

		for (int smp = 0; smp < numSamples; ++smp)
		{
			sideData[smp] = gainCompute(sideData[smp]);
		}
		
		//attack-release
		ballistics.processBlock(sideData, numSamples);

		//snap to zero
		FloatVectorOperations::max(sideData, sideData, 0.0f, numSamples);
	};

	//compute gain reduction
	float gainCompute(float smp)
	{
		const float level = jmax(smp, 1e-6f);
		const float levelInDecibels = Decibels::gainToDecibels(level);

		const float kneeHalf = knee.getNextValue() / 2.0f;
		const float slope = 1.0f / ratio.getNextValue() - 1.0f;
		const float overshoot = levelInDecibels - threshold.getNextValue();

		//over knee curve range
		if (overshoot > kneeHalf)
			return Decibels::decibelsToGain(overshoot * slope); 

		//inside knee curve range
		if (overshoot > -kneeHalf && overshoot < kneeHalf)
			return Decibels::decibelsToGain(0.5f * slope * ((overshoot + kneeHalf) * (overshoot + kneeHalf)) / knee.getNextValue());

		//under knee curve range
		return 1.0f;
	}

	//listener pattern
	void parameterChanged(const String& paramID, float newValue)override
	{	
		if (paramID == NAME_INPUT)
		{
			inputGainMain.setTargetValue(Decibels::decibelsToGain(newValue));
			inputGainSide.setTargetValue(Decibels::decibelsToGain(newValue));
		}
		if (paramID == NAME_MAKEUP)
			makeup.setTargetValue(Decibels::decibelsToGain(newValue));
		if (paramID == NAME_RATIO)
			ratio.setTargetValue(newValue);
		if (paramID == NAME_THRESHOLD)
			threshold.setTargetValue(newValue);
		if (paramID == NAME_ATTACK)
			ballistics.setAttack(newValue);
		if (paramID == NAME_RELEASE)
			ballistics.setRelease(newValue);
		if (paramID == NAME_KNEE)
			knee.setTargetValue(newValue);
		//if (paramID == NAME_RMS_TIME)
			//detector.setRmsTime(newValue);
	};
	
	Ballistics ballistics;

	PeakEnvelope detector;

	//possible rRMS implementation
	//RunningRMS detector;

	SmoothedValue<float, ValueSmoothingTypes::Linear> inputGainMain, inputGainSide, makeup, ratio, threshold, knee;


};