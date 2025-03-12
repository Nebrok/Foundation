#pragma once
#include <stdexcept>
#include <string>


namespace KTools
{
	template <typename T>
	class Matrix
	{
	private:
		T* _data;
		int _rows;
		int _cols;

	public:
		Matrix(int rows, int cols);
		~Matrix();

		T Get(int row, int col);
		void Set(int row, int, T item);
		int Count() { return _rows * _cols; }
		int GetRows() { return _rows; }
		int GetCols() { return _cols; }

		void SetAll(T item);
		void SetAllOne();
		void SetAllZero();

		Matrix<T>* Mult(Matrix& other);

		std::string ToString();

		void operator=(const Matrix& other) = delete;
	};
}

namespace KTools
{
	template <typename T>
	Matrix<T>::Matrix(int rows, int cols)
		: _rows(rows), _cols(cols)
	{
		_data = new T[rows * cols];
	}

	template <typename T>
	Matrix<T>::~Matrix()
	{
		delete[] _data;
	}

	template <typename T>
	T Matrix<T>::Get(int row, int col)
	{
		return _data[col + row * _cols];
	}

	template <typename T>
	void Matrix<T>::Set(int row, int col, T item)
	{
		_data[col + row * _cols] = item;
	}

	template <typename T>
	void Matrix<T>::SetAll(T item)
	{
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _cols; j++)
			{
				_data[j + i * _cols] = item;
			}
		}
	}

	template <typename T>
	void Matrix<T>::SetAllOne()
	{
		SetAll(1);
	}

	template <typename T>
	void Matrix<T>::SetAllZero()
	{
		SetAll(0);
	}

	template <typename T>
	Matrix<T>* Matrix<T>::Mult(Matrix& other)
	{
		if (_cols != other._rows)
			throw std::invalid_argument("Cannot multiply Matrix with incompatible dimensions");

		Matrix<T>* matrixProduct = new Matrix<T>(_rows, other._cols);

		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < other._cols; j++)
			{
				double runningValue = 0;
				for (int k = 0; k < _cols; k++)
				{
					runningValue += _data[k + i * _cols] * other._data[j + k * other._cols];
				}
				matrixProduct->Set(i, j, runningValue);
			}
		}
		return matrixProduct;
	}

	template <typename T>
	std::string Matrix<T>::ToString()
	{
		std::string output = "";
		output += "\n[";
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _cols; j++)
			{
				output += std::to_string(_data[j + i * _cols]);
				output += ", ";
			}
			if (i != _rows - 1)
				output += "\n ";
			else
				output += "]\n";
		}
		return output;
	}
}