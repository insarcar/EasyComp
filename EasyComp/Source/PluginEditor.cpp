/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (EasyCompAudioProcessor& p,  AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), processor(p), valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    thresholdSlider.reset (new juce::Slider ("Threshold"));
    addAndMakeVisible (thresholdSlider.get());
    thresholdSlider->setRange (-70, 6, 0.001);
    thresholdSlider->setSliderStyle (juce::Slider::Rotary);
    thresholdSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    thresholdSlider->addListener (this);
    thresholdSlider->setSkewFactor (0.001);

    thresholdSlider->setBounds (10, 139, 120, 96);

    ratioSlider.reset (new juce::Slider ("Ratio"));
    addAndMakeVisible (ratioSlider.get());
    ratioSlider->setRange (1, 20, 0.001);
    ratioSlider->setSliderStyle (juce::Slider::Rotary);
    ratioSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    ratioSlider->addListener (this);
    ratioSlider->setSkewFactor (0.001);

    ratioSlider->setBounds (138, 139, 112, 96);

    attackSlider.reset (new juce::Slider ("Attack"));
    addAndMakeVisible (attackSlider.get());
    attackSlider->setRange (0.5, 1000, 0.001);
    attackSlider->setSliderStyle (juce::Slider::Rotary);
    attackSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    attackSlider->addListener (this);
    attackSlider->setSkewFactor (0.001);

    attackSlider->setBounds (342, 137, 152, 88);

    kneeSlider.reset (new juce::Slider ("Knee"));
    addAndMakeVisible (kneeSlider.get());
    kneeSlider->setRange (0, 12, 0.001);
    kneeSlider->setSliderStyle (juce::Slider::Rotary);
    kneeSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    kneeSlider->addListener (this);
    kneeSlider->setSkewFactor (0.001);

    kneeSlider->setBounds (67, 257, 136, 80);

    releaseSlider.reset (new juce::Slider ("Release"));
    addAndMakeVisible (releaseSlider.get());
    releaseSlider->setRange (0.5, 1000, 0.001);
    releaseSlider->setSliderStyle (juce::Slider::Rotary);
    releaseSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    releaseSlider->addListener (this);
    releaseSlider->setSkewFactor (0.001);

    releaseSlider->setBounds (342, 252, 152, 88);

    inputGainSlider.reset (new juce::Slider ("Input Gain"));
    addAndMakeVisible (inputGainSlider.get());
    inputGainSlider->setRange (-70, 15, 0.001);
    inputGainSlider->setSliderStyle (juce::Slider::Rotary);
    inputGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    inputGainSlider->addListener (this);
    inputGainSlider->setSkewFactor (0.001);

    inputGainSlider->setBounds (467, 162, 140, 80);

    makeupGainSlider.reset (new juce::Slider ("Make Up Gain"));
    addAndMakeVisible (makeupGainSlider.get());
    makeupGainSlider->setRange (-70, 15, 0.001);
    makeupGainSlider->setSliderStyle (juce::Slider::Rotary);
    makeupGainSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, true, 80, 20);
    makeupGainSlider->addListener (this);
    makeupGainSlider->setSkewFactor (0.001);

    makeupGainSlider->setBounds (467, 262, 140, 80);

    vuMeter.reset (new Meter());
    addAndMakeVisible (vuMeter.get());
    vuMeter->setName ("VU Meter");

    vuMeter->setBounds (277, 119, 32, 236);

    compMeter.reset (new CompMeter());
    addAndMakeVisible (compMeter.get());
    compMeter->setName ("Compression VU Meter");

    compMeter->setBounds (310, 119, 32, 236);

    cachedImage_back_png_1 = juce::ImageCache::getFromMemory (back_png, back_pngSize);
    cachedImage_logoFullWhite_png_2 = juce::ImageCache::getFromMemory (logoFullWhite_png, logoFullWhite_pngSize);
    internalPath3.startNewSubPath (488.0f, 352.0f);
    internalPath3.lineTo (488.0f, 140.0f);
    internalPath3.lineTo (588.0f, 140.0f);
    internalPath3.lineTo (588.0f, 352.0f);
    internalPath3.closeSubPath();


    //[UserPreSize]

    vuMeter->connectTo(processor.envelope);
    compMeter->connectTo(processor.compEnvelope);

    thresholdAttachment.reset(new SliderAttachment(vts, NAME_THRESHOLD, *thresholdSlider));
    ratioAttachment.reset(new SliderAttachment(vts, NAME_RATIO, *ratioSlider));
    kneeAttachment.reset(new SliderAttachment(vts, NAME_KNEE, *kneeSlider));
    attackAttachment.reset(new SliderAttachment(vts, NAME_ATTACK, *attackSlider));
    releaseAttachment.reset(new SliderAttachment(vts, NAME_RELEASE, *releaseSlider));
    inputGainAttachment.reset(new SliderAttachment(vts, NAME_INPUT, *inputGainSlider));
    makeupGainAttachment.reset(new SliderAttachment(vts, NAME_MAKEUP, *makeupGainSlider));

    this->setLookAndFeel(&myTheme);
    //[/UserPreSize]

    setSize (596, 376);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    this->setLookAndFeel(nullptr);
    thresholdAttachment.reset();
    ratioAttachment.reset();
    kneeAttachment.reset();
    attackAttachment.reset();
    releaseAttachment.reset();
    inputGainAttachment.reset();
    makeupGainAttachment.reset();
    //[/Destructor_pre]

    thresholdSlider = nullptr;
    ratioSlider = nullptr;
    attackSlider = nullptr;
    kneeSlider = nullptr;
    releaseSlider = nullptr;
    inputGainSlider = nullptr;
    makeupGainSlider = nullptr;
    vuMeter = nullptr;
    compMeter = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 0, y = 0, width = 596, height = 376;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_back_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_back_png_1.getWidth(), cachedImage_back_png_1.getHeight());
    }

    {
        int x = 8, y = 116, width = 252, height = 236;
        juce::Colour strokeColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 3);

    }

    {
        int x = 360, y = 116, width = 116, height = 236;
        juce::Colour strokeColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 3);

    }

    {
        int x = 35, y = 84, width = 200, height = 30;
        juce::String text (TRANS("Compression"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 27.80f, juce::Font::bold).withExtraKerningFactor (0.097f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 320, y = 84, width = 200, height = 30;
        juce::String text (TRANS("Ballistics"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 27.80f, juce::Font::bold).withExtraKerningFactor (0.097f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 437, y = 105, width = 200, height = 30;
        juce::String text (TRANS("Gain"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 26.40f, juce::Font::bold).withExtraKerningFactor (0.055f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 160, y = 12, width = 276, height = 68;
        juce::String text (TRANS("EASY COMP"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 45.50f, juce::Font::bold).withExtraKerningFactor (0.097f));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 496, y = 12, width = 88, height = 84;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_logoFullWhite_png_2,
                     x, y, width, height,
                     0, 0, cachedImage_logoFullWhite_png_2.getWidth(), cachedImage_logoFullWhite_png_2.getHeight());
    }

    {
        float x = 0, y = 0;
        juce::Colour strokeColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath3, juce::PathStrokeType (2.600f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        int x = 95, y = 120, width = 200, height = 30;
        juce::String text (TRANS("Ratio"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 23.70f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = -28, y = 120, width = 200, height = 30;
        juce::String text (TRANS("Threshold"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 23.70f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 36, y = 236, width = 200, height = 30;
        juce::String text (TRANS("Knee"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 23.70f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 320, y = 116, width = 200, height = 30;
        juce::String text (TRANS("Attack"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 23.70f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 320, y = 228, width = 200, height = 30;
        juce::String text (TRANS("Release"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 23.70f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 437, y = 140, width = 200, height = 30;
        juce::String text (TRANS("Input"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 23.70f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 437, y = 242, width = 200, height = 30;
        juce::String text (TRANS("Make-up"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 23.70f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 420, y = 350, width = 200, height = 30;
        juce::String text (TRANS("Coded by Matteo Insarauto"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Baskerville Old Face", 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = -68, y = 348, width = 200, height = 30;
        juce::String text (TRANS("v.1.0.0"));
        juce::Colour fillColour = juce::Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == thresholdSlider.get())
    {
        //[UserSliderCode_thresholdSlider] -- add your slider handling code here..
        //[/UserSliderCode_thresholdSlider]
    }
    else if (sliderThatWasMoved == ratioSlider.get())
    {
        //[UserSliderCode_ratioSlider] -- add your slider handling code here..
        //[/UserSliderCode_ratioSlider]
    }
    else if (sliderThatWasMoved == attackSlider.get())
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == kneeSlider.get())
    {
        //[UserSliderCode_kneeSlider] -- add your slider handling code here..
        //[/UserSliderCode_kneeSlider]
    }
    else if (sliderThatWasMoved == releaseSlider.get())
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
        //[/UserSliderCode_releaseSlider]
    }
    else if (sliderThatWasMoved == inputGainSlider.get())
    {
        //[UserSliderCode_inputGainSlider] -- add your slider handling code here..
        //[/UserSliderCode_inputGainSlider]
    }
    else if (sliderThatWasMoved == makeupGainSlider.get())
    {
        //[UserSliderCode_makeupGainSlider] -- add your slider handling code here..
        //[/UserSliderCode_makeupGainSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="EasyCompAudioProcessor&amp; p,  AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor(&amp;p), processor(p), valueTreeState(vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="596" initialHeight="376">
  <BACKGROUND backgroundColour="ff323e44">
    <IMAGE pos="0 0 596 376" resource="back_png" opacity="1.0" mode="0"/>
    <RECT pos="8 116 252 236" fill="solid: 0" hasStroke="1" stroke="2.6, mitered, butt"
          strokeColour="solid: fff0ffff"/>
    <RECT pos="360 116 116 236" fill="solid: 0" hasStroke="1" stroke="2.6, mitered, butt"
          strokeColour="solid: fff0ffff"/>
    <TEXT pos="35 84 200 30" fill="solid: fff0ffff" hasStroke="0" text="Compression"
          fontname="Baskerville Old Face" fontsize="27.8" kerning="0.097"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="320 84 200 30" fill="solid: fff0ffff" hasStroke="0" text="Ballistics"
          fontname="Baskerville Old Face" fontsize="27.8" kerning="0.097"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="437 105 200 30" fill="solid: fff0ffff" hasStroke="0" text="Gain"
          fontname="Baskerville Old Face" fontsize="26.4" kerning="0.055"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="160 12 276 68" fill="solid: fff0ffff" hasStroke="0" text="EASY COMP"
          fontname="Baskerville Old Face" fontsize="45.5" kerning="0.097"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <IMAGE pos="496 12 88 84" resource="logoFullWhite_png" opacity="1.0"
           mode="0"/>
    <PATH pos="-4 0 100 100" fill="solid: 0" hasStroke="1" stroke="2.6, curved, rounded"
          strokeColour="solid: fff0ffff" nonZeroWinding="1">s 488 352 l 488 140 l 588 140 l 588 352 x</PATH>
    <TEXT pos="95 120 200 30" fill="solid: fff0ffff" hasStroke="0" text="Ratio"
          fontname="Baskerville Old Face" fontsize="23.7" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="-28 120 200 30" fill="solid: fff0ffff" hasStroke="0" text="Threshold"
          fontname="Baskerville Old Face" fontsize="23.7" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="36 236 200 30" fill="solid: fff0ffff" hasStroke="0" text="Knee"
          fontname="Baskerville Old Face" fontsize="23.7" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="320 116 200 30" fill="solid: fff0ffff" hasStroke="0" text="Attack"
          fontname="Baskerville Old Face" fontsize="23.7" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="320 228 200 30" fill="solid: fff0ffff" hasStroke="0" text="Release"
          fontname="Baskerville Old Face" fontsize="23.7" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="437 140 200 30" fill="solid: fff0ffff" hasStroke="0" text="Input"
          fontname="Baskerville Old Face" fontsize="23.7" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="437 242 200 30" fill="solid: fff0ffff" hasStroke="0" text="Make-up"
          fontname="Baskerville Old Face" fontsize="23.7" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="420 350 200 30" fill="solid: fff0ffff" hasStroke="0" text="Coded by Matteo Insarauto"
          fontname="Baskerville Old Face" fontsize="15.0" kerning="0.0"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="-68 348 200 30" fill="solid: fff0ffff" hasStroke="0" text="v.1.0.0"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="Threshold" id="de4b0e2592d80fd9" memberName="thresholdSlider"
          virtualName="" explicitFocusOrder="0" pos="10 139 120 96" min="-70.0"
          max="6.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.001"
          needsCallback="1"/>
  <SLIDER name="Ratio" id="a69a662772a00792" memberName="ratioSlider" virtualName=""
          explicitFocusOrder="0" pos="138 139 112 96" min="1.0" max="20.0"
          int="0.001" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="0.001" needsCallback="1"/>
  <SLIDER name="Attack" id="c641156e0a7ad51c" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="342 137 152 88" min="0.5"
          max="1000.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.001"
          needsCallback="1"/>
  <SLIDER name="Knee" id="fd9b21dad85b3625" memberName="kneeSlider" virtualName=""
          explicitFocusOrder="0" pos="67 257 136 80" min="0.0" max="12.0"
          int="0.001" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="0.001" needsCallback="1"/>
  <SLIDER name="Release" id="3e2038cf03ff81d9" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="342 252 152 88" min="0.5"
          max="1000.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.001"
          needsCallback="1"/>
  <SLIDER name="Input Gain" id="5be9cdb9a420e3f9" memberName="inputGainSlider"
          virtualName="" explicitFocusOrder="0" pos="467 162 140 80" min="-70.0"
          max="15.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.001"
          needsCallback="1"/>
  <SLIDER name="Make Up Gain" id="c072b18a9a9573b1" memberName="makeupGainSlider"
          virtualName="" explicitFocusOrder="0" pos="467 262 140 80" min="-70.0"
          max="15.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.001"
          needsCallback="1"/>
  <GENERICCOMPONENT name="VU Meter" id="5c74490598881530" memberName="vuMeter" virtualName=""
                    explicitFocusOrder="0" pos="277 119 32 236" class="Meter" params=""/>
  <GENERICCOMPONENT name="Compression VU Meter" id="7337139689e79022" memberName="compMeter"
                    virtualName="" explicitFocusOrder="0" pos="310 119 32 236" class="CompMeter"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: logoFullWhite_png, 10032, "../Images/Logo Full White.png"
static const unsigned char resource_PluginEditor_logoFullWhite_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,234,0,0,1,234,8,6,0,0,0,203,109,13,58,0,0,6,149,105,84,88,116,88,77,76,58,99,
111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,
78,84,99,122,107,99,57,100,34,63,62,10,60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,
65,100,111,98,101,32,88,77,80,32,67,111,114,101,32,53,46,51,45,99,48,49,49,32,54,54,46,49,52,53,54,54,49,44,32,50,48,49,50,47,48,50,47,48,54,45,49,52,58,53,54,58,50,55,32,32,32,32,32,32,32,32,34,62,10,
32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,
97,120,45,110,115,35,34,62,10,32,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,117,116,61,34,34,10,32,32,32,32,120,109,108,110,115,58,120,109,112,77,77,61,
34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,109,109,47,34,10,32,32,32,32,120,109,108,110,115,58,115,116,69,118,116,61,34,104,116,116,112,58,47,47,
110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,47,82,101,115,111,117,114,99,101,69,118,101,110,116,35,34,10,32,32,32,32,120,109,108,110,115,58,120,109,112,61,
34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,34,10,32,32,32,32,120,109,108,110,115,58,120,109,112,68,77,61,34,104,116,116,112,58,47,47,110,115,46,
97,100,111,98,101,46,99,111,109,47,120,109,112,47,49,46,48,47,68,121,110,97,109,105,99,77,101,100,105,97,47,34,10,32,32,32,32,120,109,108,110,115,58,115,116,68,105,109,61,34,104,116,116,112,58,47,47,110,
115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,84,121,112,101,47,68,105,109,101,110,115,105,111,110,115,35,34,10,32,32,32,120,109,112,77,77,58,73,110,115,116,97,110,99,101,73,
68,61,34,120,109,112,46,105,105,100,58,57,54,67,69,69,55,49,67,65,69,65,57,69,65,49,49,65,55,54,68,66,65,54,49,69,55,68,57,54,51,68,57,34,10,32,32,32,120,109,112,77,77,58,68,111,99,117,109,101,110,116,
73,68,61,34,120,109,112,46,100,105,100,58,57,52,67,69,69,55,49,67,65,69,65,57,69,65,49,49,65,55,54,68,66,65,54,49,69,55,68,57,54,51,68,57,34,10,32,32,32,120,109,112,77,77,58,79,114,105,103,105,110,97,
108,68,111,99,117,109,101,110,116,73,68,61,34,120,109,112,46,100,105,100,58,57,52,67,69,69,55,49,67,65,69,65,57,69,65,49,49,65,55,54,68,66,65,54,49,69,55,68,57,54,51,68,57,34,10,32,32,32,120,109,112,58,
77,101,116,97,100,97,116,97,68,97,116,101,61,34,50,48,50,48,45,48,54,45,48,56,84,50,51,58,48,51,58,52,49,43,48,50,58,48,48,34,10,32,32,32,120,109,112,58,77,111,100,105,102,121,68,97,116,101,61,34,50,48,
50,48,45,48,54,45,48,56,84,50,51,58,48,51,58,52,48,43,48,50,58,48,48,34,10,32,32,32,120,109,112,68,77,58,118,105,100,101,111,80,105,120,101,108,65,115,112,101,99,116,82,97,116,105,111,61,34,49,48,48,48,
48,48,48,47,49,48,48,48,48,48,48,34,10,32,32,32,120,109,112,68,77,58,118,105,100,101,111,65,108,112,104,97,77,111,100,101,61,34,115,116,114,97,105,103,104,116,34,10,32,32,32,120,109,112,68,77,58,118,105,
100,101,111,70,114,97,109,101,82,97,116,101,61,34,48,46,48,48,48,48,48,48,34,62,10,32,32,32,60,120,109,112,77,77,58,72,105,115,116,111,114,121,62,10,32,32,32,32,60,114,100,102,58,83,101,113,62,10,32,32,
32,32,32,60,114,100,102,58,108,105,10,32,32,32,32,32,32,115,116,69,118,116,58,97,99,116,105,111,110,61,34,115,97,118,101,100,34,10,32,32,32,32,32,32,115,116,69,118,116,58,105,110,115,116,97,110,99,101,
73,68,61,34,120,109,112,46,105,105,100,58,57,53,67,69,69,55,49,67,65,69,65,57,69,65,49,49,65,55,54,68,66,65,54,49,69,55,68,57,54,51,68,57,34,10,32,32,32,32,32,32,115,116,69,118,116,58,119,104,101,110,
61,34,50,48,50,48,45,48,54,45,48,56,84,50,51,58,48,51,58,52,48,43,48,50,58,48,48,34,10,32,32,32,32,32,32,115,116,69,118,116,58,115,111,102,116,119,97,114,101,65,103,101,110,116,61,34,65,100,111,98,101,
32,80,114,101,109,105,101,114,101,32,80,114,111,32,67,83,54,32,40,87,105,110,100,111,119,115,41,34,10,32,32,32,32,32,32,115,116,69,118,116,58,99,104,97,110,103,101,100,61,34,47,34,47,62,10,32,32,32,32,
32,60,114,100,102,58,108,105,10,32,32,32,32,32,32,115,116,69,118,116,58,97,99,116,105,111,110,61,34,115,97,118,101,100,34,10,32,32,32,32,32,32,115,116,69,118,116,58,105,110,115,116,97,110,99,101,73,68,
61,34,120,109,112,46,105,105,100,58,57,54,67,69,69,55,49,67,65,69,65,57,69,65,49,49,65,55,54,68,66,65,54,49,69,55,68,57,54,51,68,57,34,10,32,32,32,32,32,32,115,116,69,118,116,58,119,104,101,110,61,34,
50,48,50,48,45,48,54,45,48,56,84,50,51,58,48,51,58,52,49,43,48,50,58,48,48,34,10,32,32,32,32,32,32,115,116,69,118,116,58,115,111,102,116,119,97,114,101,65,103,101,110,116,61,34,65,100,111,98,101,32,80,
114,101,109,105,101,114,101,32,80,114,111,32,67,83,54,32,40,87,105,110,100,111,119,115,41,34,10,32,32,32,32,32,32,115,116,69,118,116,58,99,104,97,110,103,101,100,61,34,47,109,101,116,97,100,97,116,97,
34,47,62,10,32,32,32,32,60,47,114,100,102,58,83,101,113,62,10,32,32,32,60,47,120,109,112,77,77,58,72,105,115,116,111,114,121,62,10,32,32,32,60,120,109,112,68,77,58,118,105,100,101,111,70,114,97,109,101,
83,105,122,101,10,32,32,32,32,115,116,68,105,109,58,119,61,34,52,57,48,34,10,32,32,32,32,115,116,68,105,109,58,104,61,34,52,57,48,34,10,32,32,32,32,115,116,68,105,109,58,117,110,105,116,61,34,112,105,
120,101,108,34,47,62,10,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,32,60,47,114,100,102,58,82,68,70,62,10,60,47,120,58,120,109,112,109,101,116,97,62,10,60,63,120,112,97,
99,107,101,116,32,101,110,100,61,34,114,34,63,62,69,142,251,251,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,19,1,0,154,156,24,0,0,0,32,99,72,82,77,0,0,122,37,0,0,128,131,0,0,249,255,0,0,128,233,0,0,117,48,
0,0,234,96,0,0,58,152,0,0,23,111,146,95,197,70,0,0,32,21,73,68,65,84,120,218,236,221,237,117,219,70,250,55,224,27,207,217,239,127,110,5,97,42,8,93,129,169,10,34,87,16,170,2,203,21,72,170,64,118,5,162,
43,176,92,129,152,10,194,173,192,220,10,204,84,48,207,7,142,178,52,13,128,0,9,190,95,215,57,58,113,36,18,24,12,94,126,24,96,48,40,82,74,1,0,28,167,255,167,10,0,64,80,3,0,130,26,0,4,53,0,32,168,1,0,65,
13,0,130,26,0,16,212,0,32,168,1,0,65,13,0,8,106,0,16,212,0,128,160,6,0,65,13,0,8,106,0,64,80,3,128,160,6,0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,224,252,252,235,16,51,45,138,66,205,115,113,
82,74,163,136,232,151,252,105,82,20,197,228,72,202,120,95,177,207,222,91,131,23,179,157,246,34,98,80,241,231,105,81,20,243,19,92,166,198,219,117,74,105,88,181,236,17,113,144,101,47,82,74,7,169,55,187,
67,103,39,61,206,122,78,231,96,241,18,17,101,7,129,135,99,9,194,84,113,64,176,157,93,212,118,58,140,136,151,138,63,95,29,203,73,229,174,182,235,84,29,138,87,17,113,144,101,119,233,27,0,142,216,191,84,
1,64,103,45,183,151,138,150,219,149,218,225,28,130,122,18,17,159,35,98,102,181,252,100,16,17,111,35,226,90,85,192,81,27,170,2,206,49,168,231,17,113,83,20,197,179,213,81,123,18,243,49,119,70,122,82,29,
0,151,227,24,238,81,127,18,210,205,20,69,49,142,3,117,102,0,224,114,91,212,99,171,161,149,175,225,242,26,176,187,6,193,36,34,138,11,94,254,202,101,63,208,83,82,135,111,81,23,69,49,179,107,180,50,85,5,
0,151,195,227,89,0,112,196,60,158,5,103,32,165,212,143,136,247,177,184,45,50,88,250,211,60,22,253,26,190,230,62,14,219,204,99,148,231,177,60,253,73,68,124,110,51,237,60,157,223,115,89,123,155,148,53,15,
202,49,44,249,211,184,40,138,89,30,93,107,121,62,149,151,52,183,173,187,154,17,231,150,63,115,191,244,191,179,170,233,149,149,123,249,123,177,184,162,246,105,221,160,35,85,245,243,58,176,78,158,207,109,
158,207,32,22,163,227,93,117,180,29,142,150,166,187,90,254,73,44,6,248,153,117,188,253,143,34,226,143,149,101,126,173,171,241,57,236,224,135,248,249,135,67,108,235,245,53,84,127,39,187,238,94,82,185,251,
45,167,123,159,154,249,43,165,52,88,51,173,42,79,107,166,253,212,160,156,253,92,134,166,101,237,109,176,204,195,252,243,125,245,15,101,161,152,82,122,220,182,60,53,235,181,202,75,197,116,6,41,165,111,
13,167,241,101,147,250,121,13,181,146,250,121,105,178,76,235,194,178,172,222,43,60,118,184,95,173,219,54,43,215,79,155,245,121,192,188,116,233,27,78,60,252,159,34,226,174,225,199,7,17,241,146,91,61,109,
141,214,253,189,238,224,155,67,229,37,170,199,144,174,42,107,175,101,57,255,200,243,105,242,189,151,220,170,220,101,121,154,174,199,65,46,79,211,117,115,29,17,95,54,152,207,99,44,30,241,236,117,92,254,
235,150,211,189,237,34,172,243,73,238,186,109,115,120,234,251,185,160,134,211,13,233,38,7,169,85,189,216,221,179,248,183,53,39,1,143,45,66,104,57,28,219,30,204,71,13,235,238,177,197,73,195,114,121,118,
85,119,155,132,231,48,165,116,219,118,29,237,96,59,220,116,155,186,173,121,1,70,147,249,246,91,156,164,10,106,96,239,33,221,139,197,125,213,77,12,183,57,64,182,13,202,165,251,150,27,77,175,235,86,108,
46,207,166,129,117,189,225,21,137,186,242,12,55,56,105,120,245,254,8,54,199,209,22,45,244,109,202,127,125,41,251,187,160,134,211,84,119,112,252,16,17,111,34,226,93,84,63,206,247,199,6,243,124,136,197,
27,132,110,162,250,117,127,111,91,28,80,231,185,172,87,121,218,243,142,15,200,179,88,116,94,122,253,89,23,14,243,188,108,87,185,238,230,77,194,165,40,138,171,34,171,42,72,241,163,171,134,235,98,185,60,
15,21,159,233,175,235,119,80,99,186,84,55,211,45,182,197,63,106,166,255,46,151,255,185,230,196,103,211,144,127,219,176,222,230,231,112,102,174,51,217,105,173,47,157,201,78,119,221,117,214,153,44,119,38,
90,59,173,213,237,101,185,115,84,197,116,171,220,174,124,238,186,226,115,223,91,148,117,180,242,185,81,211,142,106,107,58,208,125,207,247,76,219,174,135,81,195,101,124,169,153,118,218,160,19,86,85,7,187,
225,202,231,30,155,110,63,107,234,231,219,186,43,42,109,58,147,213,172,131,94,195,122,31,110,184,63,125,219,114,187,210,153,12,216,169,170,86,200,120,165,37,55,137,242,23,221,180,109,133,173,78,247,185,
69,185,250,21,173,204,241,202,175,170,166,217,111,89,214,119,107,134,37,110,84,158,154,105,244,59,94,151,101,235,98,86,242,8,214,215,138,239,255,210,98,94,243,92,63,147,174,26,14,21,127,154,20,69,49,111,
88,254,225,134,179,111,186,30,199,167,190,179,123,142,26,78,211,231,136,248,179,228,32,85,22,202,179,109,195,165,228,160,27,177,184,100,58,44,57,120,247,87,202,81,22,68,211,178,121,164,148,202,202,218,
230,64,62,105,16,66,159,183,172,251,206,130,186,230,126,247,172,164,126,38,21,141,192,54,229,25,23,69,49,221,195,246,249,159,38,235,124,7,166,231,184,179,11,106,56,65,71,222,74,232,199,250,215,213,206,
107,2,106,155,32,252,179,65,221,221,31,89,93,109,180,28,107,174,98,68,7,211,109,98,216,114,253,150,121,219,225,9,206,252,28,247,119,151,190,129,157,217,213,115,199,252,96,208,226,179,251,10,178,105,217,
21,129,61,156,224,156,37,65,13,116,118,48,222,50,68,234,2,127,160,186,35,98,253,149,10,4,53,112,140,173,214,148,210,109,238,173,90,54,116,230,112,71,179,254,123,143,139,217,219,67,221,181,234,173,45,168,
217,23,247,168,225,180,67,250,58,118,48,36,228,133,212,221,40,22,35,159,169,59,4,53,176,179,160,121,82,19,234,142,243,230,210,55,156,102,208,244,163,253,56,216,196,63,247,187,133,52,90,212,192,78,221,
69,249,37,219,121,68,124,138,31,135,204,220,228,5,20,231,94,119,81,81,119,31,226,199,251,192,47,170,11,65,13,108,226,186,226,247,63,141,58,149,82,154,239,168,12,191,236,113,121,103,29,181,166,123,53,117,
119,181,58,24,200,17,246,39,115,194,117,129,92,250,134,19,147,47,221,150,181,166,167,29,63,171,186,78,127,221,7,186,42,79,197,136,107,93,6,221,243,158,70,236,218,86,239,132,183,219,158,189,87,80,195,165,
168,58,224,77,84,205,198,117,247,159,35,43,231,255,181,248,236,49,174,247,97,139,147,164,249,6,211,159,94,210,70,43,168,225,124,252,189,231,86,88,213,116,155,180,126,251,45,90,188,243,14,203,220,223,241,
58,152,181,108,77,206,154,214,195,145,182,72,187,56,73,104,125,146,84,49,246,252,62,214,175,160,6,182,242,182,226,224,62,216,118,194,21,33,49,168,56,136,206,26,28,204,251,37,175,65,236,85,132,127,151,
173,167,170,105,253,82,178,204,155,28,244,171,130,247,186,97,93,213,5,206,96,139,19,163,93,169,10,204,223,26,182,178,59,63,17,171,216,174,4,53,112,20,7,199,97,201,80,155,183,29,205,243,118,229,224,119,
219,162,108,85,65,50,106,88,214,233,30,234,244,186,36,152,55,121,252,173,106,89,31,87,223,147,220,224,68,102,53,216,222,119,213,34,237,74,205,125,253,235,229,109,49,135,229,31,29,175,223,105,195,237,106,
116,234,59,188,94,223,112,120,119,41,165,187,6,159,187,42,138,98,82,20,197,180,166,55,242,75,74,233,33,31,196,254,232,240,32,117,151,82,250,37,34,254,155,91,159,163,22,7,207,63,43,62,255,152,82,250,173,
193,52,187,12,162,170,131,123,111,169,238,230,185,238,174,55,152,126,213,178,246,34,226,41,165,244,20,139,87,113,94,173,148,169,172,181,249,37,165,52,142,197,45,141,183,53,45,210,201,129,183,223,231,138,
186,122,73,41,125,202,255,254,189,226,42,193,124,139,14,135,179,138,171,12,77,183,171,211,145,82,58,196,207,49,143,165,123,236,235,107,168,254,78,118,221,149,142,39,221,194,112,105,90,95,182,156,86,170,
40,227,182,110,75,166,217,43,27,131,188,161,239,101,151,46,83,74,247,21,159,191,111,176,30,254,218,69,221,45,77,255,123,155,239,167,148,6,91,20,229,175,138,50,220,175,219,134,54,217,86,43,62,59,218,162,
252,79,91,236,79,163,29,237,3,149,203,126,160,188,116,233,27,78,212,167,35,44,211,60,34,198,171,191,204,29,127,54,45,239,167,154,142,67,199,90,119,55,109,62,156,47,31,63,111,56,175,135,67,175,244,252,
110,244,217,1,202,255,28,103,250,254,233,85,130,26,78,80,190,92,56,110,248,241,217,150,179,107,122,48,124,168,10,213,162,40,238,163,253,189,200,73,254,222,46,130,101,210,240,227,211,13,166,255,220,54,
172,243,231,219,206,107,156,231,117,12,222,109,16,154,55,219,60,31,159,183,181,15,130,26,56,230,176,190,105,16,214,31,35,226,243,150,179,154,54,8,158,143,69,81,124,92,243,153,171,92,158,38,62,230,131,
255,46,131,101,93,200,221,68,196,215,45,78,6,222,52,109,41,231,208,185,106,113,2,241,144,215,255,177,108,139,211,92,254,38,193,59,143,197,8,122,227,14,230,59,110,208,42,127,136,19,31,99,64,103,50,216,
159,207,177,232,108,180,169,89,89,88,167,148,62,199,162,243,83,63,22,157,107,102,249,231,83,81,20,147,166,247,37,151,14,106,63,205,183,40,138,113,74,105,18,139,113,178,7,121,94,211,60,159,207,77,58,4,
189,182,128,150,202,59,200,127,26,46,29,72,167,185,220,235,14,248,147,150,191,47,43,203,187,92,55,171,117,55,125,93,166,150,117,87,22,94,239,150,30,145,235,71,205,115,190,175,97,157,231,249,123,254,78,
111,169,174,35,159,56,60,111,81,63,179,93,109,171,121,121,127,205,189,219,223,174,44,239,44,7,244,107,249,231,93,237,84,69,81,220,231,109,179,110,61,142,90,44,207,182,251,105,247,39,66,7,234,143,148,150,
42,185,112,252,110,81,113,139,157,248,69,253,1,236,253,248,123,144,249,186,244,13,0,71,76,80,3,128,160,6,0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,130,26,0,16,212,0,112,212,188,61,
11,246,36,191,193,167,95,242,167,73,147,183,79,237,184,108,189,136,184,142,255,189,245,168,23,17,3,47,125,57,185,109,236,190,226,79,7,223,198,16,212,112,10,254,136,197,43,29,75,15,164,7,62,184,191,207,
225,204,105,187,171,249,155,160,22,212,192,9,182,192,158,34,98,164,38,64,80,3,199,23,210,247,66,250,168,215,79,233,203,143,221,142,184,60,58,147,193,101,134,64,47,234,47,147,2,90,212,192,1,213,181,164,
103,17,241,28,17,127,171,38,16,212,192,97,188,173,248,253,52,34,174,138,162,152,171,34,16,212,192,225,244,42,126,255,32,164,79,151,251,215,231,201,61,106,96,249,64,255,172,22,64,139,26,232,72,74,105,152,
255,57,47,138,98,122,224,50,68,68,204,138,162,152,237,96,30,189,136,24,68,196,180,77,139,127,233,123,177,110,192,143,148,82,63,254,55,32,205,116,219,43,11,203,245,114,74,131,141,172,212,195,69,215,133,
160,6,214,29,220,94,74,126,61,141,136,135,136,120,140,149,14,97,41,165,121,68,140,163,226,242,117,74,233,241,53,180,150,254,91,59,207,162,40,174,42,62,55,138,197,32,41,131,146,191,69,46,199,167,117,39,
15,21,203,248,185,40,138,113,14,217,219,88,12,20,243,26,28,87,145,7,238,72,41,13,114,61,172,250,144,255,251,24,75,3,204,228,114,61,231,250,153,174,44,203,221,74,56,69,74,105,150,151,225,99,139,117,86,
90,47,121,222,211,136,248,26,17,31,171,130,111,101,29,53,169,179,105,81,20,31,58,10,231,187,88,140,78,215,43,249,251,44,34,62,215,149,125,131,186,248,220,166,110,47,253,96,112,136,159,127,88,3,237,207,
76,213,223,233,6,111,42,119,95,241,249,50,127,229,159,58,127,229,144,107,58,255,74,101,45,212,6,243,95,54,90,83,39,165,245,145,82,26,164,148,190,149,252,109,88,181,47,44,121,106,82,174,188,44,77,62,251,
212,96,221,14,90,212,203,183,124,146,17,29,172,163,151,149,239,223,87,124,110,88,23,168,41,165,239,219,150,125,165,46,190,53,156,94,233,182,42,47,127,252,113,143,26,78,203,96,93,139,43,255,253,101,71,
243,127,105,48,255,101,79,235,194,186,196,111,121,62,253,13,203,216,100,126,79,121,30,77,62,59,202,45,221,186,214,104,155,122,233,71,196,203,49,4,84,14,240,167,104,62,124,108,109,217,115,136,183,89,119,
131,99,169,139,99,38,168,225,76,3,125,131,128,92,119,80,31,181,12,233,87,143,45,15,196,215,177,159,113,199,219,44,203,109,14,228,170,208,111,91,222,94,254,222,161,109,82,134,94,148,223,114,216,180,46,
6,97,240,29,65,13,23,234,247,149,255,159,198,226,254,238,36,34,230,21,223,153,172,252,44,219,244,96,218,139,243,24,170,244,186,228,228,229,58,170,95,180,178,118,122,37,225,63,173,168,251,170,117,52,221,
242,196,107,227,171,22,171,39,95,91,156,200,189,158,8,105,85,11,106,56,27,243,136,120,151,159,153,125,87,19,186,63,28,52,139,162,248,80,20,197,85,238,32,86,122,128,127,253,251,210,231,94,15,194,253,154,
131,250,135,92,150,95,99,209,89,171,201,73,67,83,211,88,116,158,123,253,153,53,252,222,115,46,207,191,243,247,214,205,227,77,254,108,93,199,172,223,74,126,247,71,205,52,127,205,245,242,166,166,220,163,
154,117,20,13,214,209,54,29,201,222,54,40,251,77,205,246,117,189,65,93,92,181,152,30,75,59,160,206,100,167,181,190,116,38,59,221,117,215,69,103,178,159,58,6,213,116,170,74,109,203,82,215,250,106,210,209,
42,119,208,250,222,116,218,91,118,68,171,90,238,111,37,159,173,234,52,246,189,164,101,120,223,164,227,86,254,236,183,134,235,232,186,233,52,215,213,205,154,58,105,220,153,172,166,236,253,134,211,124,108,
184,46,251,155,108,75,242,82,103,50,56,89,171,207,161,230,255,159,239,120,182,85,173,233,175,43,101,153,87,181,214,215,245,22,94,241,80,20,197,120,195,178,150,181,234,63,87,181,246,74,30,55,122,222,178,
94,230,37,235,232,249,8,55,165,126,69,125,172,182,254,199,77,174,216,212,212,239,234,244,38,45,183,177,139,231,57,106,56,15,211,216,252,94,105,19,191,85,252,126,86,242,187,63,43,202,210,107,49,191,143,
91,148,181,205,203,68,254,44,57,17,154,182,184,88,85,118,137,122,126,236,27,75,205,73,211,188,164,62,102,41,165,135,6,235,254,170,197,244,236,177,130,26,232,88,175,162,117,63,221,118,26,37,38,167,50,222,
248,9,143,178,213,107,122,226,146,151,243,254,140,235,226,232,185,244,13,236,203,64,21,128,22,53,112,120,243,75,175,128,53,189,228,213,5,130,26,56,168,233,133,6,210,48,22,99,91,95,11,231,52,138,197,35,
121,215,118,7,65,13,112,12,193,244,20,231,49,168,203,182,245,208,139,197,232,100,2,90,80,3,8,233,35,212,118,44,120,26,208,153,12,96,243,144,30,9,233,127,234,226,94,72,11,106,224,52,244,47,104,89,171,198,
63,159,70,196,155,98,201,5,212,197,251,138,223,63,95,96,93,116,202,165,111,64,80,111,214,130,28,84,44,235,60,34,174,78,229,89,240,142,234,98,24,229,207,102,207,34,226,230,146,234,66,139,26,56,101,231,
118,176,30,84,252,126,124,129,193,52,172,248,253,103,33,173,69,13,28,182,37,213,107,113,32,158,94,200,149,131,191,79,120,153,126,169,105,49,255,116,226,213,96,100,186,137,189,68,80,95,162,89,172,127,109,
31,116,109,90,209,106,26,148,28,140,127,81,93,39,177,62,219,156,124,188,84,132,240,213,154,249,244,74,66,191,175,250,219,113,233,251,196,20,69,49,43,138,226,254,245,71,141,176,39,85,173,196,65,195,223,
157,99,139,186,113,171,52,165,116,189,225,73,121,89,235,246,182,131,227,200,188,233,250,172,41,251,172,193,172,202,222,121,61,180,59,9,106,160,123,147,138,223,191,95,126,159,115,126,92,169,44,168,103,
103,120,175,178,170,78,174,151,223,78,149,235,231,174,195,86,239,99,126,71,116,127,7,229,239,149,156,8,84,245,230,254,207,210,191,171,214,237,104,101,251,216,180,46,4,53,192,154,22,216,164,226,96,220,
143,136,111,41,165,199,148,210,151,88,140,74,213,38,212,78,89,85,139,178,23,17,47,185,78,238,35,226,175,216,236,249,226,175,53,127,187,203,245,254,178,69,249,191,214,156,8,188,150,255,91,77,11,120,210,
96,253,246,150,182,143,215,186,232,219,163,218,113,143,26,104,234,57,202,7,247,232,69,196,237,154,239,126,62,195,147,151,89,74,105,90,17,194,77,234,164,73,125,223,237,48,216,158,35,226,177,226,111,195,
168,191,68,61,89,238,72,150,223,225,61,171,40,107,23,117,161,69,13,208,192,67,108,246,136,213,243,25,191,171,248,211,14,79,4,230,17,113,179,203,19,141,136,248,184,197,182,112,246,39,99,130,26,56,185,22,
100,68,124,104,249,181,233,46,195,230,8,234,100,28,17,227,6,31,157,71,179,206,87,171,211,159,228,250,155,239,168,252,31,162,125,39,191,155,178,19,175,220,185,117,178,171,186,16,212,0,205,131,233,170,225,
129,118,28,23,48,66,87,81,20,55,107,90,166,243,22,117,86,85,231,111,242,60,102,59,40,255,155,134,45,235,89,68,188,203,229,169,242,110,205,137,203,108,155,186,184,216,253,46,165,116,136,249,166,165,141,
196,184,175,92,132,220,19,184,87,118,240,202,173,213,213,207,15,107,90,89,141,166,93,117,201,185,237,231,43,166,113,29,139,251,179,191,45,77,107,22,139,222,192,207,101,203,212,112,25,155,12,164,241,218,
131,120,208,164,62,219,124,118,211,114,229,94,216,163,165,250,152,71,196,159,145,71,42,171,168,243,70,203,90,179,44,63,124,63,151,161,95,118,101,99,221,9,83,158,238,117,46,255,96,233,36,227,63,249,251,
207,45,183,245,235,248,223,227,89,243,88,116,94,123,238,178,46,14,176,15,11,106,0,16,212,63,114,233,27,0,142,152,160,6,0,65,13,0,108,194,128,39,71,164,166,179,81,68,69,167,23,0,4,53,221,134,113,63,22,
61,42,7,177,232,17,217,139,134,195,11,46,117,100,152,45,253,252,55,22,207,46,10,114,128,51,164,215,247,126,194,121,24,17,191,199,226,113,133,254,14,103,53,139,197,224,5,127,70,195,199,99,0,104,124,44,
23,212,103,216,114,126,191,135,112,174,51,141,197,176,126,66,27,64,80,11,234,165,214,243,107,64,31,147,231,136,248,116,198,99,46,3,8,106,65,93,187,2,7,177,120,19,205,112,203,48,253,51,126,28,123,119,16,
139,23,209,119,213,50,159,68,196,131,192,6,56,141,160,142,148,210,33,126,254,113,6,43,174,151,223,181,186,141,199,229,151,171,215,181,214,243,123,98,187,240,212,100,158,0,28,52,47,5,245,182,173,232,148,
210,183,45,194,242,123,213,120,206,107,230,59,202,223,221,214,70,243,7,16,212,130,250,20,86,216,168,131,144,28,108,121,146,240,189,163,214,245,189,93,16,224,56,131,218,61,234,13,67,58,34,158,182,156,204,
155,109,223,20,147,131,254,37,170,7,73,105,99,156,95,215,199,238,182,155,199,248,249,153,249,121,81,20,239,54,152,86,47,34,190,148,252,105,154,223,49,124,78,117,116,178,203,181,212,119,229,172,214,211,
37,7,245,37,157,33,156,108,139,186,131,150,116,167,45,216,148,210,117,234,206,147,93,113,167,219,78,85,255,130,235,14,183,195,151,51,173,163,151,19,93,158,225,57,174,39,45,234,253,254,24,235,187,229,78,
215,65,75,122,30,205,94,210,222,72,126,71,236,184,163,201,141,114,139,134,253,250,125,131,239,252,161,218,224,50,8,234,230,33,221,139,242,75,141,109,141,215,189,192,125,3,31,242,9,64,23,110,55,105,225,
177,149,235,54,61,240,243,96,58,67,213,6,130,154,31,61,70,55,247,130,191,118,93,176,28,252,159,58,156,164,71,183,246,171,23,237,6,200,113,34,5,130,154,146,22,204,168,163,80,157,236,168,152,31,59,14,14,
151,192,247,171,205,165,236,247,170,11,46,135,183,103,237,247,192,56,221,85,1,139,162,152,167,148,198,93,157,80,196,226,126,245,131,49,194,247,102,152,82,234,175,171,239,220,139,184,127,198,245,48,221,
247,190,3,130,250,60,92,119,52,157,249,142,203,249,181,195,160,142,60,173,123,171,127,175,219,217,199,14,91,222,39,199,35,75,240,51,151,190,215,200,151,189,187,106,193,236,180,37,148,123,128,119,121,50,
160,103,241,126,53,185,114,51,82,77,160,69,205,238,194,181,191,135,242,78,58,188,2,208,111,114,57,150,238,182,143,148,210,160,106,32,156,220,27,191,119,66,39,183,195,124,226,56,141,197,0,31,243,61,204,
187,23,139,1,83,94,203,48,203,63,27,207,63,223,110,24,116,53,189,45,150,109,152,215,255,96,169,94,103,246,207,203,104,49,26,240,100,205,206,145,186,53,216,113,121,111,59,46,239,181,189,164,179,117,243,
178,205,160,51,41,165,47,13,190,255,210,102,222,45,203,57,92,179,124,163,53,99,223,191,52,152,70,63,239,115,171,63,253,117,97,218,160,126,95,154,238,127,249,101,59,247,107,134,233,125,106,80,174,173,6,
60,105,88,142,181,245,202,73,231,165,160,62,64,80,143,118,92,222,65,199,229,189,183,123,238,53,168,191,215,28,176,211,49,6,117,46,219,95,109,222,22,87,83,71,247,109,183,195,13,70,11,28,53,216,135,154,
142,163,255,189,110,122,219,4,245,6,47,253,25,217,203,206,51,168,221,163,222,191,223,118,57,241,109,199,15,231,224,122,21,7,220,163,188,178,145,47,53,191,68,249,248,220,85,110,187,58,1,220,112,180,192,
167,154,147,142,65,180,27,63,191,151,167,55,216,81,189,246,91,46,151,43,96,103,72,80,175,215,117,240,13,246,80,230,137,213,118,210,202,134,20,61,214,103,167,239,54,220,166,239,214,93,54,110,26,78,29,127,
239,41,54,235,7,240,180,131,122,221,164,28,198,63,16,212,151,39,119,24,153,117,56,201,225,9,158,92,176,95,63,12,41,154,3,109,112,108,133,204,229,186,93,115,194,56,91,19,70,219,204,255,122,77,139,179,238,
132,181,191,218,10,206,211,171,170,231,121,158,222,188,234,4,188,227,214,236,104,205,254,61,175,89,174,145,93,72,80,95,162,78,91,168,123,232,248,241,95,171,236,228,141,26,30,180,15,122,66,81,19,36,191,
22,69,113,85,20,197,175,17,241,208,242,251,77,189,173,153,255,191,139,162,184,138,136,127,215,156,184,174,62,126,248,251,186,229,137,136,95,107,142,7,111,59,58,62,92,87,180,166,231,177,120,61,238,155,
92,142,241,46,203,129,160,62,53,93,143,207,189,235,160,238,178,69,61,177,250,119,110,182,38,68,202,158,103,127,62,130,114,87,5,194,15,35,218,21,69,113,95,177,77,246,182,28,83,190,170,245,123,243,250,232,
84,254,239,135,134,223,175,154,222,187,13,167,215,245,114,125,120,237,131,178,166,28,67,187,148,160,190,56,121,32,145,89,135,147,252,253,68,22,125,190,195,177,201,169,15,221,65,238,245,59,136,159,47,239,
206,34,226,63,71,80,238,94,139,147,187,201,14,194,109,80,177,205,78,87,246,223,170,121,247,155,148,101,245,57,229,154,14,155,253,142,234,245,183,38,245,154,195,122,178,195,114,112,36,12,120,210,220,67,
116,215,97,100,112,34,3,137,124,178,218,247,226,239,28,214,215,37,173,234,222,145,182,166,235,12,75,202,248,41,202,175,76,77,59,62,81,168,154,222,135,88,223,57,235,106,203,229,238,42,32,123,77,78,24,150,
78,218,126,98,160,34,65,125,169,173,234,113,74,233,125,116,119,121,107,20,187,27,71,123,216,69,107,58,186,125,35,23,245,190,150,4,245,117,197,65,251,115,28,199,227,90,243,138,223,223,165,148,38,203,35,
119,229,208,232,44,56,218,94,50,47,138,226,99,131,207,76,142,100,91,104,19,248,255,173,153,134,160,62,19,46,125,183,115,211,225,180,222,239,240,157,207,93,60,171,253,176,239,33,18,47,220,115,197,193,118,
117,27,153,29,209,179,242,127,86,252,126,16,17,223,242,64,36,187,218,198,7,103,188,45,244,91,156,20,161,69,205,202,25,247,52,165,116,19,221,92,2,239,197,226,209,150,78,91,213,249,145,153,109,91,91,147,
38,45,16,58,221,182,230,41,165,231,6,235,238,249,200,78,46,30,107,182,239,167,136,120,204,175,95,253,116,138,151,98,151,198,45,31,196,97,199,89,159,87,12,18,163,135,183,160,166,228,128,58,78,41,253,22,
245,207,143,182,105,85,127,236,184,229,122,183,229,247,167,17,241,206,154,62,136,175,13,130,250,243,17,237,11,179,148,210,135,168,31,100,227,245,132,244,118,41,176,167,199,190,34,242,179,200,119,113,60,
29,179,250,29,236,219,156,40,151,190,55,59,64,125,136,110,238,223,246,162,195,17,141,242,243,217,163,45,67,250,202,37,239,131,182,80,235,204,142,45,228,242,149,151,135,134,31,31,69,196,95,117,99,125,31,
65,64,247,82,74,127,229,253,178,111,147,68,80,159,126,88,119,113,207,250,58,165,180,117,235,60,95,162,251,34,164,79,122,155,154,175,9,235,231,35,45,247,125,44,122,76,55,61,137,184,173,123,75,216,129,125,
137,243,190,255,205,9,114,233,123,187,3,212,56,165,52,205,59,247,54,103,223,143,41,165,121,81,20,227,13,67,122,16,155,143,81,28,177,24,225,232,131,144,62,10,117,151,191,63,31,241,190,48,137,136,55,249,
170,206,93,172,127,242,96,148,82,250,111,14,249,99,105,77,143,214,148,123,26,255,235,212,53,220,115,241,230,209,238,81,54,251,178,160,102,233,0,53,77,41,189,201,7,167,109,90,198,79,41,165,183,109,3,51,
15,55,184,105,72,207,243,252,198,214,228,209,120,142,242,219,33,179,83,184,183,155,3,123,146,175,240,220,69,253,173,152,247,177,187,71,20,55,113,215,244,68,246,0,175,232,157,231,33,76,185,64,46,125,119,
115,112,154,231,75,225,117,227,239,54,49,138,197,61,188,181,143,181,228,81,171,190,228,214,252,38,33,61,142,197,248,197,66,250,200,182,165,40,191,196,253,124,98,203,49,43,138,226,38,234,199,198,238,237,
97,220,251,166,39,188,131,168,126,44,234,24,174,54,245,237,29,90,212,116,116,112,138,136,155,148,210,67,62,59,191,222,32,68,251,185,69,245,148,82,154,196,226,114,215,223,75,127,255,37,22,151,221,54,221,
113,199,177,50,22,51,71,167,236,242,247,231,19,222,39,174,82,74,223,42,182,217,97,108,54,158,124,215,87,23,170,246,167,241,1,66,122,38,152,17,212,251,11,236,15,249,128,251,123,108,246,108,243,48,186,185,
23,54,203,7,250,177,128,62,9,207,241,227,229,239,163,188,236,93,213,26,174,24,225,235,115,116,248,120,81,126,238,188,203,178,14,42,190,250,247,1,170,182,113,80,47,61,231,253,211,137,140,62,39,130,154,
134,7,147,220,130,29,231,75,217,215,177,24,160,96,155,22,113,155,22,199,36,34,62,159,194,189,77,126,218,110,138,61,133,109,111,139,3,250,75,213,34,236,161,5,92,101,208,162,172,179,88,92,154,63,132,222,
6,235,106,80,178,47,63,86,52,2,174,194,155,239,206,134,123,212,123,60,248,22,69,49,46,138,226,38,191,163,247,223,121,103,122,200,97,62,137,205,199,230,157,229,239,63,196,98,176,146,127,23,69,241,166,40,
138,15,66,154,53,202,90,154,77,79,34,39,45,90,175,85,35,104,109,211,234,43,155,127,47,183,50,87,91,157,85,251,205,186,19,137,183,37,203,119,221,98,191,175,10,203,65,205,253,249,63,91,156,132,12,90,206,
23,45,106,90,182,154,38,45,15,118,63,181,82,92,222,98,75,119,41,165,233,235,45,145,252,124,115,211,160,174,58,177,124,74,41,189,123,61,73,204,193,118,219,38,236,27,154,86,156,104,60,166,148,110,242,229,
241,94,84,143,47,48,109,112,194,48,76,41,141,94,59,93,230,233,181,189,132,63,171,168,211,47,121,180,182,175,177,184,189,49,91,115,210,240,152,215,213,116,205,186,154,217,172,207,76,74,233,16,63,255,176,
6,184,160,125,237,37,149,187,223,96,90,247,21,211,122,105,249,249,127,190,151,82,250,182,230,51,195,213,147,201,53,159,255,107,205,52,191,181,40,231,125,89,203,182,102,218,223,243,50,125,175,249,204,245,
202,244,214,45,203,186,233,165,138,186,127,76,235,221,47,125,190,183,229,186,122,180,183,157,85,94,186,244,13,23,98,93,203,117,24,45,251,77,188,62,51,93,243,145,193,154,105,62,108,179,64,69,81,60,215,
180,30,123,121,153,122,85,173,220,252,253,101,207,107,150,165,110,122,117,62,69,139,75,252,75,125,91,54,93,87,222,35,127,102,4,53,92,128,28,170,211,29,76,250,38,54,187,207,252,220,209,51,252,31,182,40,
247,94,2,46,95,210,254,176,193,114,109,82,175,30,189,20,212,192,9,107,26,170,141,3,253,245,57,233,150,161,242,28,29,189,219,61,183,138,219,78,235,166,172,179,85,254,93,147,105,205,163,229,125,224,124,
82,242,174,105,61,229,86,117,219,122,29,31,211,144,172,8,106,160,125,168,77,35,226,77,84,95,174,158,231,48,249,186,193,116,155,140,202,55,139,197,40,95,239,186,236,4,153,67,240,170,65,120,78,99,241,226,
153,241,22,129,58,109,56,175,170,147,138,95,115,107,121,210,98,125,53,173,215,27,91,249,153,238,187,7,234,207,149,150,54,198,194,106,128,61,239,128,139,33,51,135,241,191,123,174,211,136,152,108,27,160,
185,87,244,235,180,151,79,0,166,251,120,100,40,47,215,32,126,188,135,59,203,243,159,182,156,214,117,252,248,248,211,180,228,190,246,190,214,87,63,151,101,112,136,122,229,159,245,32,168,1,64,80,255,200,
165,111,0,56,98,130,26,0,4,53,0,32,168,1,64,80,3,0,130,26,0,16,212,0,32,168,1,0,65,13,0,130,26,0,16,212,0,128,160,6,0,65,13,0,8,106,0,16,212,0,128,160,6,0,4,53,0,8,106,0,64,80,3,128,160,6,0,4,53,0,32,
168,1,64,80,3,0,130,26,0,4,53,0,32,168,1,128,136,136,248,151,42,104,46,165,52,140,136,151,51,94,196,73,81,20,87,214,244,206,182,159,116,230,139,120,85,20,197,228,72,234,250,62,34,238,206,184,174,31,138,
162,184,183,109,239,71,81,20,133,22,53,0,32,168,1,64,80,3,0,130,26,0,4,53,0,32,168,1,0,65,13,0,130,26,0,16,212,0,32,168,1,0,65,13,0,8,106,0,16,212,0,128,160,6,0,65,13,0,8,106,0,64,80,3,128,160,6,0,4,53,
0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,130,26,0,16,212,0,32,168,1,0,65,13,0,130,26,0,16,212,0,128,160,6,0,65,13,0,8,106,0,16,212,0,128,160,6,0,4,53,0,8,106,0,64,80,3,128,160,6,0,4,53,0,
32,168,1,64,80,3,0,130,26,0,4,53,0,32,168,1,0,65,13,0,130,26,0,16,212,0,32,168,1,0,65,13,0,8,106,0,16,212,0,128,160,6,0,65,13,0,8,106,0,64,80,3,128,160,6,0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,
168,1,64,80,3,0,130,26,0,16,212,0,32,168,1,0,65,13,0,130,26,0,16,212,0,128,160,6,0,65,13,0,8,106,0,16,212,0,128,160,6,0,4,53,0,8,106,0,64,80,3,128,160,6,0,4,53,0,32,168,1,64,80,3,0,130,26,0,4,53,0,32,
168,1,0,65,13,0,130,26,0,16,212,0,32,168,1,0,65,13,0,8,106,0,16,212,0,128,160,6,0,65,13,0,8,106,0,64,80,3,128,160,6,0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,130,26,0,16,212,0,32,168,
1,0,65,13,0,130,26,0,16,212,0,128,160,6,0,65,13,0,8,106,0,16,212,0,128,160,6,0,4,53,0,8,106,0,64,80,3,128,160,6,0,4,53,0,32,168,1,64,80,3,0,130,26,0,4,53,0,32,168,1,0,65,13,0,130,26,0,16,212,0,32,168,
1,0,65,13,0,8,106,0,16,212,0,128,160,6,0,65,13,0,8,106,0,64,80,3,128,160,6,0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,130,26,0,16,212,0,32,168,1,0,65,13,0,130,90,21,0,128,160,6,0,4,
53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,130,26,0,16,212,0,32,168,1,128,141,252,75,21,0,64,181,148,146,22,53,0,32,168,1,64,80,3,0,130,26,0,4,53,0,32,168,1,0,65,13,0,130,26,0,16,212,0,
32,168,1,0,65,13,0,8,106,0,16,212,0,128,160,6,0,65,13,0,8,106,0,64,80,3,128,160,6,0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,130,26,0,16,212,0,32,168,1,0,65,13,0,130,26,0,16,212,0,128,
160,6,0,65,13,0,8,106,0,16,212,0,128,160,6,0,4,53,0,8,106,0,64,80,3,128,160,6,0,4,53,0,32,168,1,64,80,3,0,130,26,0,4,53,0,32,168,1,0,65,13,0,130,26,0,16,212,0,32,168,1,0,65,13,0,8,106,0,16,212,0,128,160,
6,0,65,13,0,8,106,0,64,80,3,128,160,6,0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,130,26,0,16,212,0,32,168,1,0,65,13,0,130,26,0,16,212,0,128,160,6,0,65,13,0,8,106,0,16,212,0,128,160,
6,0,4,53,0,8,106,0,64,80,3,128,160,6,0,4,53,0,32,168,1,64,80,3,0,130,26,0,4,53,0,32,168,1,0,65,13,0,130,26,0,16,212,0,32,168,1,0,65,13,0,8,106,0,16,212,0,128,160,6,0,65,13,0,8,106,0,64,80,3,128,160,6,
0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,199,167,72,41,29,98,190,203,51,157,156,80,125,245,34,98,112,198,219,195,60,34,166,118,139,157,25,158,249,242,77,243,54,116,12,250,249,231,
92,205,242,143,109,123,79,89,121,233,65,13,0,130,186,130,75,223,0,112,196,254,117,137,103,39,0,112,42,180,168,1,64,80,3,0,130,26,0,4,53,0,32,168,1,0,65,13,0,130,26,0,16,212,0,32,168,1,0,65,13,0,8,106,
0,16,212,0,128,160,6,0,65,13,0,8,106,0,64,80,3,128,160,6,0,4,53,0,8,106,0,64,80,3,0,130,26,0,4,53,0,32,168,1,64,80,3,0,251,244,255,7,0,93,27,89,28,28,57,117,93,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::logoFullWhite_png = (const char*) resource_PluginEditor_logoFullWhite_png;
const int PluginEditor::logoFullWhite_pngSize = 10032;

// JUCER_RESOURCE: back_png, 143, "../Images/back.png"
static const unsigned char resource_PluginEditor_back_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,44,0,0,0,168,8,3,0,0,0,109,245,35,61,0,0,0,3,80,76,84,69,142,206,216,145,160,171,118,
0,0,0,71,73,68,65,84,120,156,237,193,1,1,0,0,0,130,32,255,175,110,72,64,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,239,6,197,136,0,1,189,35,67,247,
0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::back_png = (const char*) resource_PluginEditor_back_png;
const int PluginEditor::back_pngSize = 143;


//[EndFile] You can add extra defines here...
//[/EndFile]

