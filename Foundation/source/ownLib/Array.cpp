#include "Array.h"

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
		return _data[index];
	}
}