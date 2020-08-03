#pragma once

#include <JuceHeader.h>
#include "LookAndFeelPractice.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

using namespace juce;

class MainComponent  : public juce::AudioAppComponent, public Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;
    //==============================================================================
    void sliderValueChanged(juce::Slider* slider) override;

private:
    //==============================================================================
    // Your private member variables go here...

    void toggleRecordMode();
    
    OwnedArray<TextButton> myButtons;
    
     OtherLookAndFeel myLookAndFeel; // [2]
    RecordButton myRecButt;
    PlayButton myPlayButt;
    SaveButton mySaveButt;
    OtherOptionsButton mySettingsButt;
    
    ownRecordButton otherButt;
    
    Slider mySlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
