#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //setLookAndFeel(&myLookAndFeel);
    
    auto* button = myButtons.add(new TextButton("Test 1"));
    button -> setClickingTogglesState(true);
    button -> setButtonText("Test 1");
    button -> setColour(TextButton::textColourOnId, Colours::lightpink);
    button -> setColour(TextButton::textColourOffId, Colours::lightgreen);
    button -> setRadioGroupId(12223);
    addAndMakeVisible(button);
    
    button = myButtons.add(new TextButton("Test 2"));
    button -> setClickingTogglesState(true);
    button -> setButtonText("Test 2");
    button -> setColour(TextButton::textColourOnId, Colours::lightpink);
    button -> setColour(TextButton::textColourOffId, Colours::lightgreen);
    button -> setRadioGroupId(12223);
    button -> setLookAndFeel(&myLookAndFeel);
    addAndMakeVisible(button);
    
    button = myButtons.add(new TextButton("Test 3"));
    button -> setClickingTogglesState(true);
    button -> setButtonText("");
    button -> onClick = [this]() { toggleRecordMode(); };
    button -> setColour(TextButton::textColourOnId, Colours::lightpink);
    button -> setColour(TextButton::textColourOffId, Colours::lightgreen);
    button -> setLookAndFeel(&myPlayButt);
    addAndMakeVisible(button);
    
    button = myButtons.add(new TextButton("Test 4"));
    button -> setClickingTogglesState(true);
    button -> setButtonText("");
    button -> setColour(TextButton::textColourOnId, Colours::lightpink);
    button -> setColour(TextButton::textColourOffId, Colours::lightgreen);
    button -> setLookAndFeel(&myRecButt);
    addAndMakeVisible(button);
    
    button = myButtons.add(new TextButton("Test 5"));
    button -> setClickingTogglesState(true);
    button -> setButtonText("");
    button -> setColour(TextButton::textColourOnId, Colours::lightpink);
    button -> setColour(TextButton::textColourOffId, Colours::lightgreen);
    button -> setLookAndFeel(&mySaveButt);
    addAndMakeVisible(button);
    
    button = myButtons.add(new TextButton("Test 6"));
    button -> setClickingTogglesState(true);
    button -> setButtonText("");
    button -> setColour(TextButton::textColourOnId, Colours::lightpink);
    button -> setColour(TextButton::textColourOffId, Colours::lightgreen);
    button -> setLookAndFeel(&mySettingsButt);
    addAndMakeVisible(button);
    
    otherButt.setName("RecButt");
    otherButt.setClickingTogglesState(true);
    otherButt.setButtonText("");
    otherButt.setColour(TextButton::textColourOnId, Colours::black);
    otherButt.setColour(TextButton::textColourOffId, Colours::lightgreen);
    addAndMakeVisible(&otherButt);
    
    mySlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    mySlider.setName("Slide");
    mySlider.setRange(0.0f, 1.0f, 0.01f);
    addAndMakeVisible(&mySlider);
    mySlider.addListener(this);
    
    myButtons[0] -> setToggleState(true, true);
    
    
    
    
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    for(auto* button : myButtons)
    {
        button -> setLookAndFeel(nullptr);
    }
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    float height = getHeight();
    float width = getWidth();
    
    float widthSplit = getWidth()/(float)myButtons.size();
    
    for(int i = 0; i < myButtons.size(); ++i)
    {
        if(i != 2 && i != 4)
        {
            myButtons[i] -> setBounds(i * widthSplit, 0, widthSplit, 0.2 * height);
        }
        else if(i == 2)
        {
            myButtons[i] -> setBounds((i + 0.5f) * widthSplit, (0.1f - 0.7f * 0.1) * height, 0.7f * widthSplit, 0.7f * 0.2 * height);
        }
        else if(i == 4)
        {
            myButtons[i] -> setBounds((i - 0.2f) * widthSplit, (0.1f - 0.7f * 0.1) * height, 0.7f * widthSplit, 0.7f * 0.2 * height);
        }
    }
    
    
    otherButt.setBounds(1 * widthSplit, 0.3f * height, widthSplit, 0.2 * height);
    
    mySlider.setBounds(width * 0.25f, 0.8f * height, width * 0.5f, 0.2f * height);
    
}


void MainComponent::sliderValueChanged(juce::Slider *slider)
{
    otherButt.setPercentage((float)slider -> getValue());
    otherButt.setButtonTextWithNumber(slider -> getValue() * 5);
}

void MainComponent::toggleRecordMode()
{
    otherButt.setRecordMode(true);
}
