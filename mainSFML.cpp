#include "graphics.h"
#include "perceptronPoint.h"
#include "perceptron.h"
#include <ctime>

float sgn(float x)
{
    if(x >= 0) return 1;
    else return -1;
}

int main()
{
    std::list<PerceptronPoint> pointSet;

    int maxPolynomialOrder = 10;

    graphicsInit();

    Polynomial perceptronCurve(maxPolynomialOrder + 1);
    Perceptron perceptron(perceptronCurve);

    sf::Color white(255, 255, 255, 255);
    sf::Color red(255,0,0,255);
    sf::Color lineColor(255,255,255,255);

    std::clock_t start;
    double duration;

    graphicsDraw(pointSet, perceptronCurve, lineColor);

    bool running = true;
    while(running)
    {
        if(graphicsCheckWindowEvents(running, pointSet))
        {
            graphicsDraw(pointSet, perceptronCurve, lineColor);
            start = std::clock();

            perceptron.findPerceptron(pointSet);

            duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

            printf("Perceptron [");
            printf("%f", perceptron.getPerceptronCurve().getCoefficient(0));
            printf(" + %fx", perceptron.getPerceptronCurve().getCoefficient(1));
            for(int i = 2; i < perceptron.getPerceptronCurve().getNumTerms(); ++i)
            {
                    printf(" + %fx^%i", perceptron.getPerceptronCurve().getCoefficient(i), i);
            }
            printf("]\nFound in %f seconds\n\n", duration);

            perceptronCurve = perceptron.getPerceptronCurve();
            graphicsDraw(pointSet, perceptronCurve, lineColor);

            Polynomial refreshPolynomial(maxPolynomialOrder + 1);
            perceptron.setPerceptronCurve(refreshPolynomial);
        }
    }

    return 0;
}
