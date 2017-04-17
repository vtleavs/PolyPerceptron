#ifndef _PERCEPTRONPOINT_H_
#define _PERCEPTRONPOINT_H_

class PerceptronPoint
{
    public:
        PerceptronPoint(sf::Vector2f point, char y): x_vector(point),
            y_value(y) {}

        sf::Vector2f getPoint() { return x_vector; }
        float getYValue() { return y_value; }

        void recurse(int n, int max_n, bool & boolean);

    private:
        sf::Vector2f x_vector;
        float y_value;
};

#endif
