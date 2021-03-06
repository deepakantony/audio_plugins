/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
HighFrequencyToneControlAudioProcessor::HighFrequencyToneControlAudioProcessor()
:
alpha(0.0f),
volume(0.0f),
zn_1()
{
}

HighFrequencyToneControlAudioProcessor::~HighFrequencyToneControlAudioProcessor()
{
}

//==============================================================================
const String HighFrequencyToneControlAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int HighFrequencyToneControlAudioProcessor::getNumParameters()
{
    return totalParams;
}

float HighFrequencyToneControlAudioProcessor::getParameter (int index)
{
    switch (index) {
        case alphaParam:
            return alpha;
        case volumeParam:
            return volume;
            
        default:
            break;
    }
    return 0.0f;
}

void HighFrequencyToneControlAudioProcessor::setParameter (int index, float newValue)
{
    switch (index) {
        case alphaParam:
            alpha = newValue;
            break;
            
        case volumeParam:
            volume = newValue;
            break;
            
        default:
            break;
    }
}

const String HighFrequencyToneControlAudioProcessor::getParameterName (int index)
{
    return String();
}

const String HighFrequencyToneControlAudioProcessor::getParameterText (int index)
{
    return String();
}

const String HighFrequencyToneControlAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String HighFrequencyToneControlAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool HighFrequencyToneControlAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool HighFrequencyToneControlAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool HighFrequencyToneControlAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool HighFrequencyToneControlAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool HighFrequencyToneControlAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double HighFrequencyToneControlAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int HighFrequencyToneControlAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int HighFrequencyToneControlAudioProcessor::getCurrentProgram()
{
    return 0;
}

void HighFrequencyToneControlAudioProcessor::setCurrentProgram (int index)
{
}

const String HighFrequencyToneControlAudioProcessor::getProgramName (int index)
{
    return String();
}

void HighFrequencyToneControlAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void HighFrequencyToneControlAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void HighFrequencyToneControlAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void HighFrequencyToneControlAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    if(zn_1.size() < getNumInputChannels())
    {
        zn_1.resize(getNumInputChannels());
    }
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
        float a1 = alpha;
        float a0 = alpha - 1.0f;
        float volumeLinear = pow(10.0, volume/20.0);
        volumeLinear = volumeLinear > 1.0f ? 1.0f : volumeLinear;
        
        for( int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float z = *channelData;
            float y = z*a0 + zn_1[channel]*a1;
            
            *channelData = volumeLinear*y;
            
            zn_1[channel] = z;
            ++channelData;
        }
    }
}

//==============================================================================
bool HighFrequencyToneControlAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* HighFrequencyToneControlAudioProcessor::createEditor()
{
    return new HighFrequencyToneControlAudioProcessorEditor (*this);
}

//==============================================================================
void HighFrequencyToneControlAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void HighFrequencyToneControlAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HighFrequencyToneControlAudioProcessor();
}
