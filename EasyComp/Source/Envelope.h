#pragma once
#include <JuceHeader.h>
#include "PluginParameters.h"

class PeakEnvelope
{
public:

	PeakEnvelope() {};
	~PeakEnvelope() {};
	
	void prepareToPlay(double sR) 
	{
		sampleRate = sR;
		max = 0.0f;
	};

	void releaseResources() {};

	void processBlock(AudioBuffer<float>& buffer, int numSamples)
	{
		float* sideData = buffer.getWritePointer(0);

		for (int smp = 0; smp < numSamples; ++smp) 
		{
			sideData[smp] = jmax(max * alpha, fabs(sideData[smp]));
			max = sideData[smp];
		}
	};

private:

	const float alpha = 0.9f;
	float max = 0.0f;
	double sampleRate = 0.0;
	
};


class RunningRMS
{
public:

	RunningRMS() {};
	~RunningRMS() {};

	void prepareToPlay(double sR)
	{
		sampleRate = sR;
		history.setSize(1, (int)(MAX_RMS_TIME * sampleRate));
		initHistory();
	};

	void releaseResources()
	{
		history.setSize(0, 0);
	};

	void processBlock(AudioBuffer<float>& buffer, const int numSamples)
	{
		float* data = buffer.getWritePointer(0);
		float* historyData = history.getWritePointer(0);

		FloatVectorOperations::multiply(data, data, numSamples);
		FloatVectorOperations::multiply(data, 1.0f / windowSize, numSamples);

		for (int sample = 0; sample < numSamples; ++sample)
		{
			sum += data[sample] - historyData[historyIndex];
			historyData[historyIndex] = data[sample];
			data[sample] = sqrt(sum);
			++historyIndex %= windowSize;
		}
	};

	void setRmsTime(float newTime)
	{
		rmsTime = newTime;
		initHistory();
	};


private:

	void initHistory()
	{
		windowSize = jlimit(1,
			(int)(MAX_RMS_TIME * sampleRate),
			(int)(rmsTime * sampleRate));

		history.clear();
		historyIndex = 0;
		sum = 0.0f;
	};

	AudioBuffer<float> history;
	int historyIndex = 0;
	float sum = 0.0f;

	double sampleRate = 1.0;
	float rmsTime = DEFAULT_RMS_TIME;
	int windowSize = 0;

};
