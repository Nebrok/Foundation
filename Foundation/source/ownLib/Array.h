#pragma once
#include <stdexcept>

namespace KTools
{
	template <typename T>
	class Array
	{
	public:
		size_t Length;
	private:	
		T* _data;

	public:
		Array(size_t arrayLength);
		~Array();

		int& operator[](int index);
	};
}

namespace KTools
{
	template <typename T>
	Array<T>::Array(size_t arrayLength)
		: Length(arrayLength)
	{
		_data = new T[arrayLength];
		for (int i = 0; i < arrayLength; i++)
		{
			_data[i] = 0;
		}
	}

	template <typename T>
	Array<T>::~Array()
	{
		delete[] _data;
	}

	template <typename T>
	int& Array<T>::operator[](int index)
	{
		if (index < 0 or index > Length)
			throw std::out_of_range("Index out of range");
		else if (index == NULL)
			throw std::invalid_argument("Index cannot be null");

		return _data[index];
	}
}