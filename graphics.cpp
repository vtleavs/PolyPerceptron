#ifndef _GRAPHICS_CPP_
#define _GRAPHICS_CPP_

#include "graphics.h"

bool mousePressed;
sf::ContextSettings settings;
sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Perceptron", sf::Style::Close, settings);

void graphicsInit()
{
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 0; // Optional

    mousePressed = false;
}

bool graphicsCheckWindowEvents(bool & running,
    std::list<PerceptronPoint> & pointSet)
{
    bool mouseClicked = false;

    sf::Event windowEvent;
    while(window.pollEvent(windowEvent))
    {
        switch(windowEvent.type)
        {
            // Close window if close event is captured
            case sf::Event::Closed:
                running = false;
                break;

            // If key pressed...
            case sf::Event::KeyPressed:
                // If key pressed is Escape, close the window
                if(windowEvent.key.code == sf::Keyboard::Escape)
                    running = false;
                break;

            case sf::Event::MouseButtonPressed:
                mouseClicked = true;
                if(!mousePressed && windowEvent.mouseButton.button == sf::Mouse::Button::Left)
                {
                    int mouse_x = windowEvent.mouseButton.x;
                    int mouse_y = windowEvent.mouseButton.y;

                    if(mouse_x >= 0 && mouse_x <= SCREEN_WIDTH
                        && mouse_y >= 0 && mouse_y <= SCREEN_HEIGHT)
                    {
                        sf::Vector2f newP((float)mouse_x,(float)(SCREEN_HEIGHT - mouse_y));
                        PerceptronPoint newPP(newP, 1);
                        pointSet.push_back(newPP);

                        printf("New Point [%i] @ (%f, %f)\n", 1, newPP.getPoint().x, newPP.getPoint().x );
                    }

                    mousePressed = true;
                }
                if(!mousePressed && windowEvent.mouseButton.button == sf::Mouse::Button::Right)
                {
                    int mouse_x = windowEvent.mouseButton.x;
                    int mouse_y = windowEvent.mouseButton.y;

                    if(mouse_x >= 0 && mouse_x <= SCREEN_WIDTH
                        && mouse_y >= 0 && mouse_y <= SCREEN_HEIGHT)
                    {
                        sf::Vector2f newP((float)mouse_x,(float)(SCREEN_HEIGHT - mouse_y));
                        PerceptronPoint newPP(newP, -1);
                        pointSet.push_back(newPP);

                        printf("New Point [%i] @ (%f, %f)\n", -1, newPP.getPoint().x, newPP.getPoint().x );
                    }

                    mousePressed = true;
                }
                    break;

            case sf::Event::MouseButtonReleased:
                mousePressed = false;
                break;

            case sf::Event::GainedFocus:
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::TextEntered:
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            case sf::Event::JoystickButtonPressed:
                break;
            case sf::Event::JoystickButtonReleased:
                break;
            case sf::Event::JoystickMoved:
                break;
            case sf::Event::JoystickConnected:
                break;
            case sf::Event::JoystickDisconnected:
                break;
            case sf::Event::TouchBegan:
                break;
            case sf::Event::TouchMoved:
                break;
            case sf::Event::TouchEnded:
                break;
            case sf::Event::SensorChanged:
                break;
            case sf::Event::Count:
                break;
            case sf::Event::Resized:
                break;

        }
    }
    return mouseClicked;
}

void graphicsDraw(std::list<PerceptronPoint> pointSet,
            Polynomial perceptronCurve,
            sf::Color lineColor)
{
    sf::Color lightgray(200, 200, 200, 255);
    sf::Color black(0, 0, 0, 255);
    sf::Color blue(100, 100, 255, 255);
    sf::Color red(255, 100, 100, 255);
    sf::Color green(100, 255, 100, 255);
    sf::Color white(255, 255, 255, 255);
    sf::Color orange(255, 150, 0, 255);

    window.clear(/*gray*/);

/*
    // Draw perceptron
    Polynomial tempCurve(-perceptronCurve.getCoefficient(1),
        SCREEN_HEIGHT - perceptronCurve.getCoefficient(0));
    sf::Vertex percL[] = {
        sf::Vertex(sf::Vector2f(0, tempCurve.getCoefficient(0))),
        sf::Vertex(sf::Vector2f((float)SCREEN_WIDTH, tempCurve.solve(SCREEN_WIDTH)))
    };
    percL[0].color = white;
    percL[1].color = white;
    window.draw(percL, 2, sf::Lines);
*/


    for(int i = 0; i < SCREEN_WIDTH; ++i)
    {
        sf::Vertex segment[] = {
            sf::Vertex(sf::Vector2f(i, (float)SCREEN_HEIGHT - perceptronCurve.solve(i))),
            sf::Vertex(sf::Vector2f(i+1, (float)SCREEN_HEIGHT - perceptronCurve.solve(i+1)))
        };
        segment[0].color = lineColor;
        segment[1].color = lineColor;
        window.draw(segment, 2, sf::Lines);
    }



#if 0
    for(auto it = pointSet.begin(); it != pointSet.end(); ++it)
    {
        sf::Vertex height[] = {
            sf::Vertex(sf::Vector2f((*it).getPoint().x, SCREEN_HEIGHT-(*it).getPoint().y)),
            sf::Vertex(sf::Vector2f((*it).getPoint().x, SCREEN_HEIGHT-perceptronCurve.solve((*it).getPoint().x)))
        };
        if(((*it).getPoint().y) - perceptronCurve.solve((*it).getPoint().x) >= 0)
        {
            height[0].color = green;
            height[1].color = green;
        }
        else
        {
            height[0].color = orange;
            height[1].color = orange;
        }
        window.draw(height, 2, sf::Lines);
    }
#endif


    for(auto it = pointSet.begin(); it != pointSet.end(); ++it)
    {
        sf::CircleShape shape(6.f);
        shape.setOrigin(6.f, 6.f);

        sf::Vector2f tempVector((*it).getPoint().x, SCREEN_HEIGHT - (*it).getPoint().y);

        shape.setPosition(tempVector);

        if((*it).getYValue() == 1)
            shape.setFillColor(red);
        else if((*it).getYValue() == -1)
            shape.setFillColor(blue);

        window.draw(shape);
    }

/*
    for(auto it = pointSetB.begin(); it != pointSetB.end(); ++it)
    {
        sf::CircleShape shape(10.f);
        shape.setOrigin(10.f, 10.f);
        shape.setPosition((*it).getPoint());
        shape.setFillColor(blue);
        window.draw(shape);
    }
    */

    window.display();
}

#endif
