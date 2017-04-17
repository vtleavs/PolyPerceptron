
LIBS = -lGL -lsfml-system -lsfml-window -lsfml-graphics
all: mainSFML.cpp
	g++ -Wall -std=c++11 -o perceptron mainSFML.cpp graphics.cpp perceptron.cpp $(LIBS) 
clean:
	$(RM) perceptron
