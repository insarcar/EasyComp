#pragma once

#include<JuceHeader.h>

class MyLookAndFeel : public LookAndFeel_V4
{
public:
	MyLookAndFeel() 
	{
		setColour(Slider::thumbColourId, Colours::red);
	};

	void drawRotarySlider(Graphics& g, int x, int y, int width, int heigth,
		float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override 
	{
		//temp variables
		auto radius = (jmin(width * 0.5f, heigth * 0.5f) - 4.0f) * 0.85f;
		auto centreX = x + width * 0.5f;
		auto centreY = y + heigth * 0.5f;
		auto rx = centreX - radius;
		auto ry = centreY - radius;
		auto rw = radius * 2.0f;

		Colour brightColour = Colour(0xff40b6b6);
		Colour darkColour = Colour(0xff2e8787);
		//rotary body
		g.setGradientFill(ColourGradient(brightColour, rx, ry, darkColour.brighter(0.05f), rx, ry + rw, false));
		g.fillEllipse(rx, ry, rw, rw);

		//rotary bound
		g.setGradientFill(ColourGradient(brightColour.brighter(0.2f), rx, ry, darkColour.brighter(0.05f), rx, ry + rw, false));
		g.drawEllipse(rx, ry, rw, rw, 1.5f);

		//pointer shape
		Path p;
		auto pointerLength = radius * 0.33f;
		auto pointerThickness = 2.0f;
		p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);

		//draw pointer in a current position, applico la rotazione al rettangolo
		auto angle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
		p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
		g.setGradientFill(ColourGradient(Colours::white, rx, ry, Colours::white.darker(0.2f), rx, ry + rw, false));
		g.fillPath(p);

		//draw ticks
		Path originalTickShape, temp;
		auto numTicks = 21;
		auto tickSize = 2.0f;
		originalTickShape.addEllipse(-tickSize * 0.5f, -radius * 1.17f, tickSize, tickSize);
		g.setColour(Colours::white);
		for (int i = 0; i < numTicks; ++i)
		{
			temp = originalTickShape;
			float angle = rotaryStartAngle + pow(i / (numTicks - 1.0f), slider.getSkewFactor()) * (rotaryEndAngle - rotaryStartAngle);
			temp.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
			g.fillPath(temp);
		}
	};

	void drawToggleButton(Graphics& g, Button& b, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) 
	{
		shouldDrawButtonAsDown = true;
	}
};