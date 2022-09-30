#pragma once

#include <JuceHeader.h>
#include "PluginParameters.h"
#include "EzComp.h"

//==============================================================================
/**
*/
class EasyCompAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    EasyCompAudioProcessor();
    ~EasyCompAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

  
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
 

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    Atomic<float> envelope;
    Atomic<float> compEnvelope;

private:

    AudioProcessorValueTreeState parameters;
    EzComp compressor;
    AudioBuffer<float> auxSignal;
    dsp::ProcessSpec ps{ -1,0,0 };
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EasyCompAudioProcessor)
};
