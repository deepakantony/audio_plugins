/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "HighFrequencyToneControlComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
HighFrequencyToneControlComponent::HighFrequencyToneControlComponent ()
{
    addAndMakeVisible (sliderAlpha = new Slider ("new slider"));
    sliderAlpha->setTooltip (TRANS("Alpha"));
    sliderAlpha->setRange (0, 0.5, 0);
    sliderAlpha->setSliderStyle (Slider::LinearBar);
    sliderAlpha->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderAlpha->addListener (this);

    addAndMakeVisible (sliderVolume = new Slider ("new slider"));
    sliderVolume->setRange (-80, 0, 0);
    sliderVolume->setSliderStyle (Slider::LinearBar);
    sliderVolume->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderVolume->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Volume in dB")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Alpha in linear scale")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    processor = NULL;
    //[/Constructor]
}

HighFrequencyToneControlComponent::~HighFrequencyToneControlComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderAlpha = nullptr;
    sliderVolume = nullptr;
    label = nullptr;
    label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    processor = NULL;
    //[/Destructor]
}

//==============================================================================
void HighFrequencyToneControlComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void HighFrequencyToneControlComponent::resized()
{
    sliderAlpha->setBounds (32, 16, 150, 24);
    sliderVolume->setBounds (32, 56, 150, 24);
    label->setBounds (200, 56, 150, 24);
    label2->setBounds (200, 16, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void HighFrequencyToneControlComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderAlpha)
    {
        //[UserSliderCode_sliderAlpha] -- add your slider handling code here..
        if (processor) {
            processor->setParameterNotifyingHost(HighFrequencyToneControlAudioProcessor::alphaParam, sliderAlpha->getValue());
        }
        //[/UserSliderCode_sliderAlpha]
    }
    else if (sliderThatWasMoved == sliderVolume)
    {
        //[UserSliderCode_sliderVolume] -- add your slider handling code here..
        if (processor) {
            processor->setParameterNotifyingHost(HighFrequencyToneControlAudioProcessor::volumeParam, sliderVolume->getValue());
        }
        //[/UserSliderCode_sliderVolume]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void HighFrequencyToneControlComponent::setProcessor(HighFrequencyToneControlAudioProcessor *p)
{
    processor = p;
    
    sliderAlpha->setValue( processor->getParameter(HighFrequencyToneControlAudioProcessor::alphaParam) );
    sliderVolume->setValue( processor->getParameter(HighFrequencyToneControlAudioProcessor::volumeParam) );
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="HighFrequencyToneControlComponent"
                 componentName="" parentClasses="public Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="41fcd5bbaf544f3f" memberName="sliderAlpha"
          virtualName="" explicitFocusOrder="0" pos="32 16 150 24" tooltip="Alpha"
          min="0" max="0.5" int="0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="587fdb010040d42" memberName="sliderVolume"
          virtualName="" explicitFocusOrder="0" pos="32 56 150 24" min="-80"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="241cfd8d91f8c59c" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="200 56 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume in dB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="afac63c6793d5e2" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="200 16 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Alpha in linear scale" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
