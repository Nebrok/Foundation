#pragma once
#include <iostream>
#include <string>
#include "../ownlib/Matrix.h"


class NeuralNetwork
{
private:
	int _numInputs;
	int _numOutputs;
	int _numHidden;
	double _learningRate;

	KTools::Matrix<double>* _weightsInputToHidden;
	KTools::Matrix<double>* _weightsHiddenToOutput;


public:
	NeuralNetwork(int numInputs, int numOutputs, int numHidden, double learningRate);
	~NeuralNetwork();

	void Train();
	void Query(KTools::Matrix<double>& inputs);

	void PrintNetwork();


};