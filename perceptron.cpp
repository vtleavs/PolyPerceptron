
#include "perceptron.h"

#define STEP_GAIN 1

void Perceptron::findPerceptron(std::list<PerceptronPoint> input)
{
    int timeout = 1000000;

    int iterations = 0;

    bool boolean = false;

    //float prevHSum = 0;

    while(!boolean && iterations < timeout)
    {
        Polynomial tempCurve;
        tempCurve = perceptronCurve;

        float h = 0;
        PerceptronPoint point(*(input.begin()));

        bool boolSum = true;

        float hSum = 0;
        for(auto it = input.begin(); it != input.end(); ++it)
        {
            point = (*it);
            h = point.getPoint().y - tempCurve.solve(point.getPoint().x);

            boolSum = boolSum && (sgn(h) == point.getYValue());


            if(sgn(h) != point.getYValue())
            {
                int numDimensions = tempCurve.getNumTerms();
                int order = pow((rand()/(float)RAND_MAX), (float)(numDimensions)) * (float)(numDimensions);

                if(order != numDimensions)
                {
                    float step = STEP_GAIN * pow(.01, order);
                    tempCurve.tweakCoefficient(order, -1.0 * step * (float)point.getYValue());
                }

                h = point.getPoint().y - tempCurve.solve(point.getPoint().x);

#if 0
                printf("%f -> %f (%fx + %f) with R: %i\n", h, point.getYValue(),
                    perceptronCurve.getCoefficient(1), perceptronCurve.getCoefficient(0), order);
#endif
            }

            hSum += h;
        }
        boolean = boolSum;
        perceptronCurve = tempCurve;
        ++iterations;
    }
}
