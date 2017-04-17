
#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "perceptronPoint.h"
#include "polynomial.h"
#include "define.h"

extern sf::ContextSettings settings;

// create window of size VideoMode(Width, Height) with the above settings
extern sf::RenderWindow window;

extern bool mousePressed;

bool graphicsCheckWindowEvents(bool & running,
        std::list<PerceptronPoint> & pointSet);

void graphicsDraw(std::list<PerceptronPoint> pointSet,
            Polynomial perceptronCurve,
            sf::Color lineColor);

// form: a*x+b
//void graphicsUpdatePerceptronCurve(Polynomial l);

void graphicsInit();

#endif // _GRAPHICS_H_
