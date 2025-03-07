#pragma once
#include <cstdlib>
#include <stdexcept>
#include <string>

namespace KTools
{
	template <typename T> 
	class List
	{
	public:

	private:
		T* _data;
		int _currentIndex;

		int _capacity = 32;
		int _capacityResizeRatio = 2; //ie val of 2 doubles capacity when list resized

	public:
		List();
		List(size_t size);
		~List();

		int Count() { return _currentIndex; }
		int Capacity() { return _capacity;  }

		int& operator[](int index);

		void Add(T);
		void ResizeList();
		T RemoveAt(int);
		//void RemoveRange();
		//void Clear();
		//void Contains();
		//void Insert(int, T);
		//void Slice(int, int);
		//void ToArray();
		std::string ToString();
	};
}

namespace KTools
{
	template <typename T>
	List<T>::List()
	{
		_data = (T*)std::malloc(sizeof(T) * _capacity);
		_currentIndex = 0;

		if (_data == nullptr)
			throw std::runtime_error("Error allocation memory for list initialisation");
	}

	template <typename T>
	List<T>::List(size_t size)
	{
		_capacity = size;
		_data = (T*)std::malloc(sizeof(T) * _capacity);
		_currentIndex = 0;

		if (_data == nullptr)
			throw std::runtime_error("Error allocation memory for list initialisation");
	}

	template <typename T>
	List<T>::~List()
	{
		for (int i = 0; i < _currentIndex; i++)
		{
			delete _data[i];
		}
		free(_data);
	}

	template <typename T>
	void List<T>::Add(T addition)
	{
		_data[_currentIndex] = addition;
		_currentIndex++;

		if (_currentIndex == _capacity)
			ResizeList();
	}

	template <typename T>
	void List<T>::ResizeList()
	{
		if (_currentIndex == _capacity)
		{
			_capacity *= _capacityResizeRatio;
			T* newData = (T*)std::realloc((void*)_data, sizeof(T) * _capacity);

			if (newData == nullptr)
				throw std::runtime_error("Error in allocation of memory at list resize");

			_data = newData;
		}
		else if (_currentIndex < _capacity / 2)
		{
			_capacity = _capacity / 2;
			T* newData = (T*)std::realloc((void*)_data, sizeof(T) * _capacity);

			if (newData == nullptr)
				throw std::runtime_error("Error in allocation of memory at list resize");

			_data = newData;
		}
	}

	template <typename T>
	T List<T>::RemoveAt(int index)
	{
		if (index < 0 or index > _currentIndex)
			throw std::out_of_range("Index out of range");

		T removedItem = _data[index];
		for (int i = index + 1; i < _currentIndex; i++)
		{
			_data[i - 1] = _data[i];
		}

		_currentIndex--;

		//TODO: Potential optimisation here regarding what happens when removing/adding singular items around midpoint
		if (_currentIndex < (_capacity / 2))
			ResizeList();

		return removedItem;
	}

	template <typename T>
	std::string List<T>::ToString()
	{
		std::string outputString = "[ ";
		for (int i = 0; i < _currentIndex; i++)
		{
			outputString += std::to_string(_data[i]);
			if (i != _currentIndex - 1)
				outputString += ", ";
		}
		outputString += " ]";
		return outputString;
	}

	template <typename T>
	int& List<T>::operator[](int index)
	{
		if (index < 0 or index >= _currentIndex)
			throw std::out_of_range("Index out of range");

		return _data[index];
	}


}