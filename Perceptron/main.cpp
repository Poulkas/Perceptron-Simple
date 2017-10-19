/* Poulkas
* Example of OR, AND, XOR
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Perceptron.h"

#define C_0 0
#define C_1 1
#define C_2 2
#define C_3 3
#define H_ENTRIES 4
#define W_ENTRIES 2

using namespace std;

int main(){
    Perceptron* perceptron;
    float **entries;

    float outputs[H_ENTRIES] = {-C_1, C_1, C_1, C_1}; //OR
    //float outputs[H_ENTRIES] = {-C_1, -C_1, -C_1, C_1}; //AND
    //float outputs[H_ENTRIES] = {-C_1, C_1, C_1, -C_1}; //XOR
    float prove[W_ENTRIES] = {-C_1, -C_1};
    int output;

    entries = new float*[H_ENTRIES];
    for(int i=C_0; i<H_ENTRIES; i++)
        entries[i] = new float[W_ENTRIES];

    entries[C_0][C_0] = -C_1;
    entries[C_0][C_1] = -C_1;
    entries[C_1][C_0] = -C_1;
    entries[C_1][C_1] = C_1;
    entries[C_2][C_0] = C_1;
    entries[C_2][C_1] = -C_1;
    entries[C_3][C_0] = C_1;
    entries[C_3][C_1] = C_1;

    srand(time(NULL));
    cout<<"Hello Perceptron"<<endl;

    cout<<"Initialize Perceptron"<<endl;
    perceptron = new Perceptron(SIGN_FUNCTION, entries, outputs, W_ENTRIES, H_ENTRIES);

    cout<<"First Weights"<<endl;
    for(int i=C_0, j=perceptron->getWeight(); i<j; i++){
        cout<<"W: "<< perceptron->getWeights()[i] <<endl;
    }

    cout<<"Training"<<endl;
    perceptron->train();

    cout<<"Analazing proof"<<endl;
    cout<<"Weights"<<endl;
    for(int i=C_0, j=perceptron->getWeight(); i<j; i++){
        cout<<"W: "<< perceptron->getWeights()[i] <<endl;
    }
    cout<<"Prove: "<< prove[C_0] <<", "<< prove[C_1] <<endl;
    perceptron->analize(prove);

    cout<<"Outputs"<<endl;
    cout<<"bias: "<< perceptron->getBias() <<endl;
    output = perceptron->output();
    cout<<"Output: "<< output <<" - Prove: "<< prove[C_0] <<", "<< prove[C_1] <<endl;
    cout<<"Output - Weights"<<endl;
    for(int i=C_1; i<H_ENTRIES; i++){
        cout<< output <<", d: "<< outputs[i] <<endl;
    }

    delete perceptron;

    return EXIT_SUCCESS;
}
