#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


class Meter : public Component, public Timer
{
public:
    Meter() 
    {
        setSize(W, H);
        setReleaseTime(DEFAULT_RELEASE);
        startTimer(TIMER);
    };
    ~Meter() 
    {
        stopTimer();
    };

    void paint(Graphics& g) override 
    {
        g.fillAll(Colours::black);
        g.setColour(Colours::white);
        g.drawRect(0, 0, W, H, 1);

        if (observedEnvelope != nullptr)
        {
            auto barHeight = 0.0f;
            auto envelopeSnap = observedEnvelope->get();
            auto peak = Decibels::gainToDecibels(envelopeSnap);
            //decay
            observedEnvelope->set(envelopeSnap * alpha);

            barHeight = (H - 2) * (peak - DB_FLOOR)/ fabs(DB_FLOOR);
            barHeight = jlimit(0.0f, H - 2.0f, barHeight);

            //gradient
            auto topCol = (peak >= 0.0f) ? Colours::red : Colours::yellow;
            Colour brightColour = Colour(0xff40b6b6);
            Colour darkColour = Colour(0xff2e8787);
            ColourGradient filler = ColourGradient(brightColour.darker(0.7f), 0, H, topCol, 0, 0, false);
            filler.addColour(0.8, darkColour.brighter(0.5f));
            
            //fill 
            g.setGradientFill(filler);
            g.fillRect(1.0f, H - 1.0f - barHeight, W - 2.0f, barHeight);
        }
    };
    void resized() override 
    {
        W = getWidth();
        H = getHeight();
    };

    void connectTo(Atomic<float>& targetVar)
    {
        observedEnvelope = &targetVar;
    };

    void setReleaseTime(float releaseTime) 
    {
        auto n = releaseTime * 1000.0f / TIMER;
        alpha = pow(DECAY_TARGET, 1.0f / n);
    }

private:

    void timerCallback() override 
    {
        repaint();
    };

    int W, H = 1;
    Atomic<float>* observedEnvelope = nullptr;

    float alpha;
};

class CompMeter : public Component, public Timer
{
public:

    CompMeter()
    {
        setSize(W, H);
        setReleaseTime(DEFAULT_RELEASE);
        startTimer(TIMER);
    };
    ~CompMeter()
    {
        stopTimer();
    };

    void paint(Graphics& g) override
    {
        g.fillAll(Colours::black);
        g.setColour(Colours::white);
        g.drawRect(0, 0, W, H, 1);

        if (observedEnvelope != nullptr)
        {
            auto barHeight = 0.0f;
            auto envelopeSnap = observedEnvelope->get();
            auto peak = Decibels::gainToDecibels(envelopeSnap);
            //decay
            observedEnvelope->set(envelopeSnap * alpha);

            barHeight = (H - 2) * (peak - DB_FLOOR) / fabs(DB_FLOOR);
            barHeight = jlimit(0.0f, H - 2.0f, barHeight);

            //gradient
            Colour fillerColour = Colour(0xffdd8767);
            Colour botColour = Colour(0xffa7a70d);
            Colour topColour = Colour(0xff8e2338);
            ColourGradient filler = ColourGradient(topColour.brighter(0.2f), 0, H, botColour.brighter(0.2f), 0, 0, false);
            filler.addColour(0.6, fillerColour.darker(0.2f));

            //fill
            g.setGradientFill(filler);
            g.fillRect(1.0f, 1.0f, W - 2.0f, barHeight);
        }
    };

    void resized() override
    {
        W = getWidth();
        H = getHeight();
    };

    void connectTo(Atomic<float>& targetVar)
    {
        observedEnvelope = &targetVar;
    };

    void setReleaseTime(float releaseTime)
    {
        auto n = releaseTime * 1000.0f / TIMER;
        alpha = pow(DECAY_TARGET, 1.0f / n);
    }

private:

    void timerCallback() override
    {
        repaint();
    };

    int W, H = 1;
    Atomic<float>* observedEnvelope = nullptr;

    float alpha;
};