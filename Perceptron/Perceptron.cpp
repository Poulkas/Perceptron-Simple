/* Poulkas */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Perceptron.h"

using namespace std;

Perceptron::Perceptron(int activationFunction, float* inputs[], float* outputs, int w, int h){
    this->activationFunction = activationFunction;
    bias = DEFAULT_BIAS;
    y = 0;
    data = inputs;
    d_outputs = outputs;
    weight = w;
    height = h;
    weights = new float[weight];
    initializeWeights();
}

Perceptron::~Perceptron(){
    if(data)
        delete data;
    if(weights)
        delete weights;
    if(d_outputs)
        delete d_outputs;
}

void Perceptron::train(){
    float error = 0, resultsy = 0;

    for(int epoch=0; epoch<EPOCHS; epoch++){
        for(int k=0; k<height; k++){
            resultsy = calculateOutput(weights, data[k]);
            error = d_outputs[k] - resultsy;
            if(error!=0){
                upgradeWeights(weights, error, k);
            }
        }
    }
}

void Perceptron::analize(float* inputs){
    y = calculateOutput(weights, inputs);
}

void Perceptron::setBias(int newBias){
    bias = newBias;
}

int Perceptron::output(){
    return y;
}

float Perceptron::calculateOutput(float* w, float* x){
    float temp_y = 0;

    for(int p=0; p<weight; p++){
        temp_y = temp_y+w[p]*x[p];
    }
    temp_y = temp_y+bias;
    switch(activationFunction){
        case STEP_FUNCTION:
            return stepFunction(temp_y);
        case SIGN_FUNCTION:
            return signFunction(temp_y);
        case LINEAR_FUNCTION:
            return linearFunction(temp_y);
        default:
            return -7;
    }
}

void Perceptron::upgradeWeights(float* w, float error, int k){
    for(int j=0; j<weight; j++){
        w[j] = w[j]+LEARN_REASON*error*data[k][j];
    }
    bias = bias+error;
}

float Perceptron::stepFunction(float v){
    if(v>=0)
        return 1;
    else return 0;
}

float Perceptron::signFunction(float v){
    if(v>0)
        return 1;
    else if(v==0)
        return 0;
    else return -1;
}

float Perceptron::linearFunction(float v){
    if(v>=(1/2))
        return 1;
    else if(v<(1/2) && v>-(1/2))
        return v;
    else return 0;
}

void Perceptron::initializeWeights(){
    for(int i=0; i<weight; i++){
        weights[i] = (float)rand()/RAND_MAX*(MAX_RANDOM_VALUE)+LEARN_REASON;
    }
}

float Perceptron::getBias(){
    return bias;
}

int Perceptron::getWeight(){
    return weight;
}

int Perceptron::getHeight(){
    return height;
}

float* Perceptron::getWeights(){
    return weights;
}
