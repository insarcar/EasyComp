#pragma once
#include <JuceHeader.h>
//===========INPUT GAIN DB====================
#define NAME_INPUT "input"
#define MIN_INPUT -48.0f
#define MAX_INPUT 6.0f
#define DEFAULT_INPUT 0.0f
//===========MAKEUP GAIN DB====================
#define NAME_MAKEUP "makeup"
#define MIN_MAKEUP -48.0
#define MAX_MAKEUP 6.0f
#define DEFAULT_MAKEUP 0.0f
//===========THRESHOLD LEVEL DB====================
#define NAME_THRESHOLD "threshold"
#define MIN_THRESHOLD -48.0f
#define MAX_THRESHOLD 6.0f
#define DEFAULT_THRESHOLD 0.0f
//===========COMPRESSION RATIO====================
#define NAME_RATIO "ratio"
#define MIN_RATIO 1.0f
#define MAX_RATIO 20.0f
#define DEFAULT_RATIO 1.0f
//===========ATTACK TIME MS====================
#define NAME_ATTACK "attack"
#define MIN_ATTACK 1.0f
#define MAX_ATTACK 1000.0f
#define DEFAULT_ATTACK 1.0f
//===========RELEASE TIME MS====================
#define NAME_RELEASE "release"
#define MIN_RELEASE 1.0f
#define MAX_RELEASE 1000.0f
#define DEFAULT_RELEASE 1.0f
//==============RMS S=========================
#define DEFAULT_RMS_TIME 0.05f
#define MAX_RMS_TIME 1.0f
#define NAME_RMS_TIME "rmsTime"
//==============KNEE DB========================
#define DEFAULT_KNEE 0.0f
#define MAX_KNEE 12.0f
#define MIN_KNEE 0.0f
#define NAME_KNEE "knee"
//==============METER=======================
#define TIMER 50.0f //ms
#define DB_MAX 12.0f
#define DB_FLOOR -48.0f
#define DECAY_TARGET 0.267f
#define DEFAULT_RELEASE 0.5f


#define SMOOTHING_RAMP 0.3f


static AudioProcessorValueTreeState::ParameterLayout  createParameterLayout()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> params;

	params.push_back(std::make_unique<AudioParameterFloat>(NAME_INPUT, "Input Level", NormalisableRange<float>(MIN_INPUT, MAX_INPUT, 0.01f, 1.2f), DEFAULT_INPUT));
	params.push_back(std::make_unique<AudioParameterFloat>(NAME_MAKEUP, "Makeup Gain", NormalisableRange<float>(MIN_MAKEUP, MAX_MAKEUP, 0.01f, 1.2f), DEFAULT_MAKEUP));
	params.push_back(std::make_unique<AudioParameterFloat>(NAME_THRESHOLD, "Threshold", NormalisableRange<float>(MIN_THRESHOLD, MAX_THRESHOLD, 0.01f, 1.2f), DEFAULT_THRESHOLD));
	params.push_back(std::make_unique<AudioParameterFloat>(NAME_RATIO, "Ratio", NormalisableRange<float>(MIN_RATIO, MAX_RATIO, 0.1f, 0.5f), DEFAULT_RATIO));
	params.push_back(std::make_unique<AudioParameterFloat>(NAME_ATTACK, "Attack", NormalisableRange<float>(MIN_ATTACK, MAX_ATTACK, 0.1f, 0.7f), DEFAULT_ATTACK));
	params.push_back(std::make_unique<AudioParameterFloat>(NAME_RELEASE, "Release", NormalisableRange<float>(MIN_RELEASE, MAX_RELEASE, 0.1f, 0.7f), DEFAULT_RELEASE));
	params.push_back(std::make_unique<AudioParameterFloat>(NAME_KNEE, "Knee", MIN_KNEE, MAX_KNEE, DEFAULT_KNEE));
	
	//params.push_back(std::make_unique<AudioParameterFloat>(NAME_RMS_TIME, "RMS Time", 0.0f, MAX_RMS_TIME, DEFAULT_RMS_TIME));

	return { params.begin(), params.end() };
};