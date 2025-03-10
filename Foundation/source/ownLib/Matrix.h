#pragma once

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

		void SetAll(T item);
		void SetAllOne();
		void SetAllZero();

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
		return _data[col * row + _cols];
	}

	template <typename T>
	void Matrix<T>::Set(int row, int col, T item)
	{
		_data[col * row + _cols] = item;
	}

	template <typename T>
	void Matrix<T>::SetAll(T item)
	{
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _cols; j++)
			{
				_data[i * j] = item;
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

}