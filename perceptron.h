#ifndef _PERCEPTRON_H_
#define _PERCEPTRON_H_

#include "polynomial.h"
#include <SFML/Graphics.hpp>
#include "graphics.h"
#include <stdlib.h>
#include <math.h>

class Perceptron
{
    public:
        Perceptron() { }
        Perceptron(Polynomial curve): perceptronCurve(curve) {}
        void findPerceptron(std::list<PerceptronPoint> input);
        Polynomial getPerceptronCurve() { return perceptronCurve; }
        float sgn(float x);

        void setPerceptronCurve(Polynomial p) { perceptronCurve = p; }

    private:
        Polynomial perceptronCurve;
};

inline float Perceptron::sgn(float x)
{
    if(x >= 0) return 1;
    else return -1;
}


#endif
