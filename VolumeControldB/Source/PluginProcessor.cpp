/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


#define DEFAULT_GAIN_DB 0.0f

//==============================================================================
VolumeControldBAudioProcessor::VolumeControldBAudioProcessor()
{
    gainInDB = DEFAULT_GAIN_DB;
}

VolumeControldBAudioProcessor::~VolumeControldBAudioProcessor()
{
}

//==============================================================================
const String VolumeControldBAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int VolumeControldBAudioProcessor::getNumParameters()
{
    return 0;
}

float VolumeControldBAudioProcessor::getParameter (int index)
{
    switch (index) {
        case gainParam:
            return gainInDB;
            
        default:
            break;
    }
    
    return 0.0f;
}

void VolumeControldBAudioProcessor::setParameter (int index, float newValue)
{
    switch (index) {
        case gainParam:
            gainInDB = newValue;
            break;
            
        default:
            break;
    }
}

const String VolumeControldBAudioProcessor::getParameterName (int index)
{
    return String();
}

const String VolumeControldBAudioProcessor::getParameterText (int index)
{
    return String();
}

const String VolumeControldBAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String VolumeControldBAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool VolumeControldBAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool VolumeControldBAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool VolumeControldBAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool VolumeControldBAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool VolumeControldBAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double VolumeControldBAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VolumeControldBAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int VolumeControldBAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VolumeControldBAudioProcessor::setCurrentProgram (int index)
{
}

const String VolumeControldBAudioProcessor::getProgramName (int index)
{
    return String();
}

void VolumeControldBAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void VolumeControldBAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void VolumeControldBAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void VolumeControldBAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
        
        float linearGain = pow(10, gainInDB/20.f);
        
        for(int sample = 0; sample < buffer.getNumSamples(); ++sample)
            channelData[sample] *= linearGain;
    }
}

//==============================================================================
bool VolumeControldBAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* VolumeControldBAudioProcessor::createEditor()
{
    return new VolumeControldBAudioProcessorEditor (*this);
}

//==============================================================================
void VolumeControldBAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void VolumeControldBAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VolumeControldBAudioProcessor();
}
