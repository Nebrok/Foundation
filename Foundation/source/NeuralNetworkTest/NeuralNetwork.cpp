#include "NeuralNetwork.h"

double FASigmoid(double input)
{
	return input / (1 + abs(input));
}


void FASigmoidOnMatrix(KTools::Matrix<double>& input)
{
	for (int i = 0; i < input.GetRows(); i++)
	{
		for (int j = 0; j < input.GetCols(); j++)
		{
			input.Set(i, j, FASigmoid(input.Get(i, j)));
		}
	}
}

NeuralNetwork::NeuralNetwork(int numInputs, int numOutputs, int numHidden, double learningRate)
	: _numInputs(numInputs), _numOutputs(numOutputs), _numHidden(numHidden), _learningRate(learningRate)
{
	_weightsInputToHidden = new KTools::Matrix<double>(_numHidden, _numInputs);
	_weightsHiddenToOutput = new KTools::Matrix<double>(_numOutputs, _numHidden);

	_weightsInputToHidden->SetAllOne();
	_weightsHiddenToOutput->SetAllOne();
}

NeuralNetwork::~NeuralNetwork()
{
	delete _weightsInputToHidden;
	delete _weightsHiddenToOutput;
}


void NeuralNetwork::PrintNetwork()
{
	std::cout << "Number Inputs: " << _numInputs << '\n';
	std::cout << "Number Outputs: " << _numOutputs << '\n';
	std::cout << "Number Hidden Neurons: " << _numHidden << '\n';

	std::cout << "Weights In to Hidden Memory Location: " << _weightsInputToHidden << " Number of weights : " << _weightsInputToHidden->Count() << '\n';
	std::cout << "Weights Hidden to Out Memory Location: " << _weightsHiddenToOutput << " Number of weights : " << _weightsHiddenToOutput->Count() << '\n';
}

void NeuralNetwork::Query(KTools::Matrix<double>& inputs)
{
	KTools::Matrix<double>* hiddenOutput = _weightsInputToHidden->Mult(inputs);
	FASigmoidOnMatrix(*hiddenOutput);

	KTools::Matrix<double>* output = _weightsHiddenToOutput->Mult(*hiddenOutput);
	FASigmoidOnMatrix(*output);

	std::cout << "Neural Network Query Output: " << output->ToString();

	delete output;
	delete hiddenOutput;
}