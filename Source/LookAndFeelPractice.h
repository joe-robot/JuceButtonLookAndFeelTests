/*
  ==============================================================================

    LookAndFeelPractice.h
    Created: 25 Jul 2020 9:08:56pm
    Author:  Joseph Cresswell

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class OtherLookAndFeel : public juce::LookAndFeel_V4
{
public:
    OtherLookAndFeel()
    {}

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        auto buttonArea = button.getLocalBounds();
        auto edge = 4;

        buttonArea.removeFromLeft (edge);
        buttonArea.removeFromTop (edge);

        // shadow
        g.setColour (juce::Colours::darkgrey.withAlpha (0.5f));
        g.fillRect (buttonArea);

        auto offset = isButtonDown ? -edge / 2 : -edge;
        buttonArea.translate (offset, offset);

        g.setColour (backgroundColour);
        g.fillRect (buttonArea);
        
        if(button.getToggleState())
        {
            buttonArea.removeFromTop(buttonArea.getHeight() * 0.95f);
            g.setColour(button.findColour(juce::TextButton::textColourOnId));
            g.fillRect(buttonArea);
        }
        
    }

    void drawButtonText (juce::Graphics& g, juce::TextButton& button, bool, bool isButtonDown) override
    {
        auto font = getTextButtonFont (button, button.getHeight());
        g.setFont (font);
        g.setColour (button.findColour (button.getToggleState() ? juce::TextButton::textColourOnId
                                                                : juce::TextButton::textColourOffId)
                             .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f));

        auto yIndent = juce::jmin (4, button.proportionOfHeight (0.3f));
        auto cornerSize = juce::jmin (button.getHeight(), button.getWidth()) / 2;

        auto fontHeight = juce::roundToInt (font.getHeight() * 0.6f);
        auto leftIndent  = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft()  ? 4 : 2));
        auto rightIndent = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
        auto textWidth = button.getWidth() - leftIndent - rightIndent;

        auto edge = 4;
        auto offset = isButtonDown ? edge / 2 : 0;

        if (textWidth > 0)
            g.drawFittedText (button.getButtonText(),
                              leftIndent + offset, yIndent + offset, textWidth, button.getHeight() - yIndent * 2 - edge,
                              juce::Justification::centred, 2);
    }

};




class RecordButton : public juce::LookAndFeel_V4
{
public:
    RecordButton()
    {}

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        auto buttonArea = button.getLocalBounds();
        auto edge = 4;

        buttonArea.removeFromLeft (edge);
        buttonArea.removeFromTop (edge);
        
        float sideLength = juce::jmin (buttonArea.getHeight() - 2, buttonArea.getWidth() - 2);

        juce::Rectangle<float> circleRect{2, 2, sideLength, sideLength};
        
        circleRect.translate((buttonArea.getWidth() - sideLength)/2.0f, (buttonArea.getHeight() - sideLength)/2.0f);

        // shadow
        g.setColour (juce::Colours::slategrey);
        g.fillEllipse(circleRect);
        
        g.setColour(button.getToggleState() ? juce::Colours::orangered : juce::Colours::darkgrey);
        g.drawEllipse(circleRect, sideLength * 0.05f);

//        auto offset = isButtonDown ? -edge / 2 : -edge;
//        circleRect.translate (offset, offset);
//
//        g.setColour (backgroundColour);
//        g.fillEllipse(circleRect);
//
//        if(button.getToggleState())
//        {
//            buttonArea.removeFromTop(buttonArea.getHeight() * 0.95f);
//            g.setColour(button.findColour(juce::TextButton::textColourOnId));
//            g.fillRect(buttonArea);
//        }
        float innerCircleSize = button.getToggleState() ? 0.55f * sideLength : 0.8f * sideLength;
        
        juce::Rectangle<float> innerCircleRect{2, 2, innerCircleSize, innerCircleSize};
        
        innerCircleRect.translate((buttonArea.getWidth() - innerCircleSize)/2.0f, (buttonArea.getHeight() - innerCircleSize)/2.0f);
        

        g.setColour(button.getToggleState() ? juce::Colours::orangered : juce::Colours::red);

        if(button.getToggleState())
        {
            g.fillRect(innerCircleRect);
        }
        else
        {
            g.fillEllipse(innerCircleRect);
        }
        
    }

    void drawButtonText (juce::Graphics& g, juce::TextButton& button, bool, bool isButtonDown) override
    {
        auto font = getTextButtonFont (button, button.getHeight());
        g.setFont (font);
        g.setColour (button.findColour (button.getToggleState() ? juce::TextButton::textColourOnId
                                                                : juce::TextButton::textColourOffId)
                             .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f));

        auto yIndent = juce::jmin (4, button.proportionOfHeight (0.3f));
        auto cornerSize = juce::jmin (button.getHeight(), button.getWidth()) / 2;

        auto fontHeight = juce::roundToInt (font.getHeight() * 0.6f);
        auto leftIndent  = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft()  ? 4 : 2));
        auto rightIndent = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
        auto textWidth = button.getWidth() - leftIndent - rightIndent;

        auto edge = 4;
        auto offset = isButtonDown ? edge / 2 : 0;

        if (textWidth > 0)
            g.drawFittedText (button.getButtonText(),
                              leftIndent + offset, yIndent + offset, textWidth, button.getHeight() - yIndent * 2 - edge,
                              juce::Justification::centred, 2);
    }

};

class PlayButton : public juce::LookAndFeel_V4
{
public:
    PlayButton()
    {}

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        auto buttonArea = button.getLocalBounds();
        auto edge = 4;

        buttonArea.removeFromLeft (edge);
        buttonArea.removeFromTop (edge);
        
        float sideLength = juce::jmin (buttonArea.getHeight() - 2, buttonArea.getWidth() - 2);

        juce::Rectangle<float> circleRect{2, 2, sideLength, sideLength};
        
        circleRect.translate((buttonArea.getWidth() - sideLength)/2.0f, (buttonArea.getHeight() - sideLength)/2.0f);

        // shadow
        g.setColour (juce::Colours::slategrey);
        g.fillEllipse(circleRect);
        
        g.setColour(button.getToggleState() ? juce::Colours::red : juce::Colours::green);
        g.drawEllipse(circleRect, sideLength * 0.05f);

//        auto offset = isButtonDown ? -edge / 2 : -edge;
//        circleRect.translate (offset, offset);
//
//        g.setColour (backgroundColour);
//        g.fillEllipse(circleRect);
//
//        if(button.getToggleState())
//        {
//            buttonArea.removeFromTop(buttonArea.getHeight() * 0.95f);
//            g.setColour(button.findColour(juce::TextButton::textColourOnId));
//            g.fillRect(buttonArea);
//        }
        float innerCircleSize = button.getToggleState() ? 0.55f * sideLength : 0.55f * sideLength;
        
        juce::Rectangle<float> innerCircleRect{2, 2, innerCircleSize, innerCircleSize};
        
        innerCircleRect.translate((buttonArea.getWidth() - innerCircleSize)/2.0f, (buttonArea.getHeight() - innerCircleSize)/2.0f);
        

        g.setColour(button.getToggleState() ? juce::Colours::red : juce::Colours::green);

        if(!button.getToggleState())
        {
            juce::Path myPath;
            myPath.startNewSubPath(innerCircleRect.getX() + 0.1f * innerCircleSize, innerCircleRect.getY());
            myPath.lineTo(innerCircleRect.getX() + 0.1f * innerCircleSize, innerCircleRect.getY() + innerCircleSize);
            myPath.lineTo(innerCircleRect.getX() + 1.1f * innerCircleSize, innerCircleRect.getY() + innerCircleSize/2.0f);
            myPath.closeSubPath();
            g.fillPath(myPath);
        }
        else
        {
            g.fillRect(innerCircleRect);
        }
        
    }

};

class OtherOptionsButton : public juce::LookAndFeel_V4
{
public:
    OtherOptionsButton()
    {}

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        auto buttonArea = button.getLocalBounds();
        
        float sideLength = juce::jmin (buttonArea.getHeight() - 2, buttonArea.getWidth() - 2);

        float circleSize = sideLength/6.0f;
        
        juce::Rectangle<float> circleRect{2, 2, circleSize, circleSize};
        
        if(isButtonDown)
        {
            g.setColour(juce::Colours::darkslategrey);
            g.fillRoundedRectangle(buttonArea.toFloat(), 5);
        }
        
        circleRect.translate((buttonArea.getWidth() - circleSize)/2.0f, -circleSize * 0.5f);

        g.setColour (juce::Colours::white);
        for(int i = 0; i < 3; ++i)
        {
            circleRect.translate(0, (buttonArea.getHeight())/4.0f);
            g.fillEllipse(circleRect);
        }
    }
};


class SaveButton : public juce::LookAndFeel_V4
{
public:
    SaveButton()
    {}

    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                               bool, bool isButtonDown) override
    {
        auto buttonArea = button.getLocalBounds();
        auto edge = 4;

        buttonArea.removeFromLeft (edge);
        buttonArea.removeFromTop (edge);
        
        float sideLength = juce::jmin (buttonArea.getHeight() - 2, buttonArea.getWidth() - 2);

        juce::Rectangle<float> circleRect{2, 2, sideLength, sideLength};
        
        circleRect.translate((buttonArea.getWidth() - sideLength)/2.0f, (buttonArea.getHeight() - sideLength)/2.0f);

        // shadow
        g.setColour (juce::Colours::slategrey);
        g.fillEllipse(circleRect);
        
        g.setColour(button.getToggleState() ? juce::Colours::red : juce::Colours::green);
        g.drawEllipse(circleRect, sideLength * 0.05f);
        
        float innerCircleSize = button.getToggleState() ? 0.55f * sideLength : 0.55f * sideLength;
        
        juce::Rectangle<float> innerCircleRect{2, 2, innerCircleSize, innerCircleSize};
        
        innerCircleRect.translate((buttonArea.getWidth() - innerCircleSize)/2.0f, (buttonArea.getHeight() - innerCircleSize)/2.0f);
        

        g.setColour(button.getToggleState() ? juce::Colours::red : juce::Colours::green);

        g.fillRoundedRectangle(innerCircleRect, 5.0f);
        
        float border = innerCircleSize * 0.05f;
        
        float objectSizes[8]{0.9f, 0.3f,
                             0.15f, 0.2f,
                             0.8f, 0.45f,
                             0.7f, 0.1f};
        
        g.setColour(juce::Colours::white);
        g.fillRoundedRectangle(innerCircleRect.getX() + border, innerCircleRect.getY() + border, innerCircleSize * objectSizes[0], innerCircleSize * objectSizes[1], 5);
        
        g.setColour(juce::Colours::green);
        g.fillRoundedRectangle(innerCircleRect.getX() + innerCircleSize * 0.75f, innerCircleRect.getY() + border * 2, innerCircleSize * objectSizes[2], innerCircleSize * objectSizes[3], 2);
        
        g.setColour(juce::Colours::white);
        
        juce::Rectangle<float> textRect{innerCircleRect.getX() + innerCircleSize * (1.0f - objectSizes[4])/2.0f, innerCircleRect.getY() + border + (objectSizes[1] + 0.1f) * innerCircleSize, innerCircleSize * objectSizes[4], innerCircleSize * objectSizes[5]};
        
        g.drawRoundedRectangle(textRect, 3, border);
        
        
        textRect.removeFromRight(border);
        textRect.removeFromLeft(border);
        float rectHeight = textRect.getHeight();
        textRect.removeFromBottom(rectHeight * 0.65f);
        textRect.removeFromTop(rectHeight * 0.25f);
        for(int i = 0; i < 2; ++i)
        {
            g.fillRoundedRectangle(textRect, 2);
            textRect.translate(0, border * 2);
        }
    }

    void drawButtonText (juce::Graphics& g, juce::TextButton& button, bool, bool isButtonDown) override
    {
        auto font = getTextButtonFont (button, button.getHeight());
        g.setFont (font);
        g.setColour (button.findColour (button.getToggleState() ? juce::TextButton::textColourOnId
                                                                : juce::TextButton::textColourOffId)
                             .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f));

        auto yIndent = juce::jmin (4, button.proportionOfHeight (0.3f));
        auto cornerSize = juce::jmin (button.getHeight(), button.getWidth()) / 2;

        auto fontHeight = juce::roundToInt (font.getHeight() * 0.6f);
        auto leftIndent  = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft()  ? 4 : 2));
        auto rightIndent = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
        auto textWidth = button.getWidth() - leftIndent - rightIndent;

        auto edge = 4;
        auto offset = isButtonDown ? edge / 2 : 0;

        if (textWidth > 0)
            g.drawFittedText (button.getButtonText(),
                              leftIndent + offset, yIndent + offset, textWidth, button.getHeight() - yIndent * 2 - edge,
                              juce::Justification::centred, 2);
    }

};

//RecordButton

class ownRecordButton : public juce::TextButton
{
public:
//    ownRecordButton(const juce::String& buttonName) : Button(buttonName)
//    {}
    
    void setPercentage(float percentage)
    {
        percentageComplete = juce::jlimit(0.0f, 100.0f, percentage);
        repaint();
    }
    
    void setButtonTextWithNumber(int name)
    {
        if(getToggleState())
        {
            juce::String nameStr = juce::String(name);
            setButtonText(nameStr);
        }
    }
    
    void setRecordMode(bool mode)
    {
        recordMode = mode;
        setButtonText("");
        repaint();
    }
    
    void clicked() override
    {
        if(!getToggleState())
        {
            recordMode = false;
            percentageComplete = 0;
            setButtonText("");
            repaint();
        }
        else
        {
            setButtonText("0");
        }
    }
    
    void paintButton (juce::Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        drawButtonBackground (g, *this, findColour (getToggleState() ? buttonOnColourId : buttonColourId), shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);

        drawButtonText (g, *this, shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);
    }
    
    void drawButtonBackground (juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour,
                                   bool, bool isButtonDown)
        {
            auto buttonArea = button.getLocalBounds();
            auto edge = 4;

            buttonArea.removeFromLeft (edge);
            buttonArea.removeFromTop (edge);
            
            float sideLength = juce::jmin (buttonArea.getHeight() - 2, buttonArea.getWidth() - 2);

            juce::Rectangle<float> circleRect{2, 2, sideLength, sideLength};
            
            circleRect.translate((buttonArea.getWidth() - sideLength)/2.0f, (buttonArea.getHeight() - sideLength)/2.0f);

            float centrePos[2]{circleRect.getX() + 0.5f * sideLength, circleRect.getY() + 0.5f * sideLength};
            // shadow
            g.setColour(button.getToggleState() ? juce::Colours::orangered : juce::Colours::darkgrey);
            
            juce::Colour ringColour = button.getToggleState() ? (recordMode ? juce::Colours::orangered : juce::Colours::yellow) : juce::Colours::darkgrey;
            
            g.setColour(button.getToggleState() ? (recordMode ? juce::Colours::orangered : juce::Colours::indianred) : juce::Colours::darkgrey);
            
            g.drawEllipse(circleRect, sideLength * 0.05f);
            
            
            if(button.getToggleState() && !recordMode)
            {
                g.setColour(ringColour);
                g.fillPath(getCircleSegmentPath(centrePos, sideLength * 0.525f));
            
            }
            
    
            
            circleRect = circleRect.reduced(sideLength * 0.025f, sideLength * 0.025f);
            
            g.setColour (juce::Colours::slategrey);
            g.fillEllipse(circleRect);

            float innerCircleSize = (button.getToggleState() && recordMode) ? 0.55f * sideLength : 0.8f * sideLength;
            
            juce::Rectangle<float> innerCircleRect{2, 2, innerCircleSize, innerCircleSize};
            
            innerCircleRect.translate((buttonArea.getWidth() - innerCircleSize)/2.0f, (buttonArea.getHeight() - innerCircleSize)/2.0f);
            

            juce::Colour innerCol = button.getToggleState() ? (recordMode ? juce::Colours::orangered : juce::Colours::yellow) : juce::Colours::red;
            
            if(button.getToggleState() && !recordMode)
            {
                g.setColour(juce::Colours::indianred);
                g.fillEllipse(innerCircleRect);
            }
            else if(!button.getToggleState())
            {
                g.setColour(innerCol);
                g.fillEllipse(innerCircleRect);
            }
            
                
            g.setColour(innerCol);
            if(button.getToggleState())
            {
                if(recordMode)
                {
                    g.fillRect(innerCircleRect);
                }
                else
                {
                    g.fillPath(getCircleSegmentPath(centrePos, innerCircleSize * 0.5f));
                    
                }
            }
            
            
        }

        void drawButtonText (juce::Graphics& g, juce::TextButton& button, bool, bool isButtonDown)
        {
            auto font = *(new juce::Font(0.5f * getHeight()));
            g.setFont (font);
            juce::Colour mainColour = button.findColour (button.getToggleState() ? juce::TextButton::textColourOnId : juce::TextButton::textColourOffId).withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);

            g.setColour (mainColour);

            auto yIndent = juce::jmin (4, button.proportionOfHeight (0.3f));
            auto cornerSize = juce::jmin (button.getHeight(), button.getWidth()) / 2;

            auto fontHeight = juce::roundToInt (font.getHeight() * 0.6f);
            auto leftIndent  = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft()  ? 4 : 2));
            auto rightIndent = juce::jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
            auto textWidth = button.getWidth() - leftIndent - rightIndent;

            auto edge = 4;
            auto offset = isButtonDown ? edge / 2 : 0;

            if (textWidth > 0)
            {
                g.setColour(juce::Colours::white);
                g.drawFittedText (button.getButtonText(),
                leftIndent + offset, yIndent + offset, textWidth + 2, button.getHeight() - yIndent * 2 - edge + 2,
                juce::Justification::centred, 2);
                g.setColour(mainColour);
                g.drawFittedText (button.getButtonText(),
                                  leftIndent + offset, yIndent + offset, textWidth, button.getHeight() - yIndent * 2 - edge,
                                  juce::Justification::centred, 2);
            }
        }
    
    
private:
    
    juce::Path getCircleSegmentPath(float centrePos[2], float size)
    {
        juce::Path p;
        p.startNewSubPath(centrePos[0], centrePos[1]);
        p.lineTo(centrePos[0], centrePos[1] + size);
        p.addCentredArc(centrePos[0], centrePos[1], size, size, 0, 0, 2 * juce::double_Pi * percentageComplete);
        
        return p;
    }
    
    bool recordMode{false};
    float percentageComplete{0};
};
