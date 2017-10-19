/* Poulkas */
#ifndef PERCEPTRON_H_INCLUDE
#define PERCEPTRON_H_INCLUDE

#include <vector>
#include <stdlib.h>

#define DEFAULT_BIAS -1
#define EPOCHS 7
#define STEP_FUNCTION 1
#define SIGN_FUNCTION 2
#define LINEAR_FUNCTION 3
#define MAX_RANDOM_VALUE 2
#define LEARN_REASON 10/100

class Perceptron{
    float** data;
    float* weights;
    float* d_outputs;
    int y;
    float bias;
    int activationFunction, weight, height;
public:
    Perceptron(int activationFuction, float* inputs[], float* outputs, int w, int h);
    ~Perceptron();
    void train();
    void analize(float* inputs);
    void setBias(int newBias);
    int output();
    float calculateOutput(float* w, float* x);
    void upgradeWeights(float* w, float error, int k);
    float scalarProdcut(float* v);
    float stepFunction(float v);
    float signFunction(float v);
    float linearFunction(float v);
    float sigmoidFunction(float v);
    void initializeWeights();
    float getBias();
    int getWeight();
    int getHeight();
    float* getWeights();
};

#endif // PERCEPTRON_H_INCLUDED
