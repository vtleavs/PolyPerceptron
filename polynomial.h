#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <vector>
#include <math.h>
#include "define.h"
#include <stdio.h>

class Polynomial
{
    public:
        Polynomial(float a, float b): polyTerms(2)
        {
            coefficients.push_back(b);
            coefficients.push_back(a);
        }
        Polynomial(): polyTerms(2)
        {
            coefficients.push_back(SCREEN_HEIGHT/2.0);
            coefficients.push_back(0.0);
        }
        Polynomial(int n);


        Polynomial(float coeff[], int size);

        // returns f(x) given x
        float solve(float x);

        int getNumTerms() { return polyTerms; }

        float getCoefficient(int degree) { return coefficients[degree]; }
        void tweakCoefficient(int degree, float amount) { coefficients[degree] += amount; }

        int polyTerms;
        std::vector<float> coefficients;
};

inline Polynomial::Polynomial(int n)
{
    polyTerms = n;
    coefficients.push_back(SCREEN_HEIGHT/2.0);
    for(int i = 1; i < n; i++)
        coefficients.push_back(0);
}

inline Polynomial::Polynomial(float coeff[], int size)
{
    polyTerms = (float)size;
    for(int i = 0; i < size; ++i)
        coefficients.push_back(coeff[i]);
}

inline float Polynomial::solve(float x)
{
    int sum = 0;
    for(int i = 0; i < polyTerms; ++i)
        sum += coefficients[i] * pow(x, (float)i);
    return sum;
}

#endif
