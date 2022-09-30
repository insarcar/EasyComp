#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
EasyCompAudioProcessor::EasyCompAudioProcessor() :
    AudioProcessor(BusesProperties()
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
        .withInput("Sidechain", juce::AudioChannelSet::mono(), false)
    ),
    parameters(*this, nullptr, Identifier("EasyCompParameters"), createParameterLayout())

{

    parameters.addParameterListener(NAME_INPUT, &compressor);
    parameters.addParameterListener(NAME_MAKEUP, &compressor);
    parameters.addParameterListener(NAME_RATIO, &compressor);
    parameters.addParameterListener(NAME_THRESHOLD, &compressor);
    parameters.addParameterListener(NAME_ATTACK, &compressor);
    parameters.addParameterListener(NAME_RELEASE, &compressor);
    parameters.addParameterListener(NAME_KNEE, &compressor);
    //parameters.addParameterListener(NAME_RMS_TIME, &compressor);

    
}

EasyCompAudioProcessor::~EasyCompAudioProcessor()
{
}

//==============================================================================
const juce::String EasyCompAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool EasyCompAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool EasyCompAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool EasyCompAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double EasyCompAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int EasyCompAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int EasyCompAudioProcessor::getCurrentProgram()
{
    return 0;
}

void EasyCompAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String EasyCompAudioProcessor::getProgramName (int index)
{
    return {};
}

void EasyCompAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void EasyCompAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ps.sampleRate = sampleRate;
    ps.maximumBlockSize = samplesPerBlock;
    auxSignal.setSize(1, samplesPerBlock);
    compressor.prepareToPlay(ps);
}

void EasyCompAudioProcessor::releaseResources()
{
    auxSignal.setSize(0, 0);
    compressor.releaseResources();
}


bool EasyCompAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    //sidechain
    if (layouts.inputBuses[1] != juce::AudioChannelSet::mono()
        && layouts.inputBuses[1] != juce::AudioChannelSet::stereo()
        && layouts.inputBuses[1] != juce::AudioChannelSet::disabled())
        return false;

    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;

    return true;

}


void EasyCompAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    //buffer clears
    const auto totalNumInputChannels = getTotalNumInputChannels();
    const auto totalNumOutputChannels = getTotalNumOutputChannels();
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());
    
    auxSignal.clear();

    //extract buffers from buses
    auto numSamples = buffer.getNumSamples();

    auto mainBuffer = getBusBuffer(buffer, true, 0);
    auto sideBuffer = getBusBuffer(buffer, true, 1);

    //select side chain signal
    {
        const AudioBuffer<float>* sideChainSource = sideBuffer.getNumChannels() ? &sideBuffer : &mainBuffer;
        const int numCh = sideChainSource->getNumChannels();

        for (int ch = numCh; --ch >= 0;)
            auxSignal.addFrom(0, 0, *sideChainSource, ch, 0, numSamples, 1.0f / numCh);
    }
    

    //compressor
    compressor.processBlock(mainBuffer, auxSignal);
    
    //update metering envelopes
    compEnvelope = jmax(compEnvelope.get(), compressor.getMaxGainReduction(auxSignal));
    envelope = jmax(envelope.get(), mainBuffer.getMagnitude(0, numSamples));
    
}

//==============================================================================
bool EasyCompAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* EasyCompAudioProcessor::createEditor()
{
    return new PluginEditor (*this, parameters);
    //return nullptr;
}

//==============================================================================
void EasyCompAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void EasyCompAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr) //se ho caricato dei dati
    {

        if (xmlState->hasTagName(parameters.state.getType())) //se il tipo nel valuetreestate corrisponde allora posso caricare lo stato nel tree
        {

            parameters.replaceState(ValueTree::fromXml(*xmlState));

        }

    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new EasyCompAudioProcessor();
}
