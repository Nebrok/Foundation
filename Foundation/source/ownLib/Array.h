#pragma once
#include <stdexcept>
#include <string>

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

		std::string ToString();

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

		/* undecided how array class should treat junk memory 
		for (int i = 0; i < arrayLength; i++)
		{
			_data[i] = 0;
		}
		*/
	}

	template <typename T>
	Array<T>::~Array()
	{
		/* data safety - clears memory so it can't be rebuilt after deletion
		for (int i = 0; i < arrayLength; i++)
		{
			_data[i] = 0;
		}
		*/
		delete[] _data;
	}

	template <typename T>
	std::string Array<T>::ToString()
	{
		std::string outputString = "[ ";
		for (int i = 0; i < Length; i++)
		{
			outputString += std::to_string(_data[i]);
			if (i != Length - 1)
				outputString += ", ";
		}
		outputString += " ]";
		return outputString;
	}

	template <typename T>
	int& Array<T>::operator[](int index)
	{
		if (index < 0 or index > Length)
			throw std::out_of_range("Index out of range");

		return _data[index];
	}

}