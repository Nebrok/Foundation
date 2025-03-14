#pragma once
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

		//Copy constructor
		List(const List& other);

		~List();

		int Count() { return _currentIndex; }
		int Capacity() { return _capacity;  }

		T& operator[](int index);
		List<T>& operator=(const List& other);

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
		: _capacity((int)size)
	{
		_data = (T*)std::malloc(sizeof(T) * _capacity);
		_currentIndex = 0;

		if (_data == nullptr)
			throw std::runtime_error("Error allocation memory for list initialisation");
	}

	template <typename T>
	List<T>::List(const List<T>& other)
		: _currentIndex(other._currentIndex), _capacity(other._capacity), _capacityResizeRatio(other._capacityResizeRatio)
	{
		_data = new T[_capacity];
		std::memcpy(_data, other._data, sizeof(T) * _currentIndex);
	}

	template <typename T>
	List<T>::~List()
	{
		//std::cout << "Memory Location: " << _data << "\n";
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
	T& List<T>::operator[](int index)
	{
		//TODO: Should this be ">= _capacity" instead?
		if (index < 0 or index >= _currentIndex)
			throw std::out_of_range("Index out of range");

		return _data[index];
	}

	template <typename T>
	List<T>& List<T>::operator=(const List<T>& other)
	{

		if (this != &other)
		{
			_currentIndex = other._currentIndex;
			_capacityResizeRatio = other._capacityResizeRatio;

			if (_capacity != other._capacity)
			{
				delete[] _data;
				_capacity = other._capacity;
				_data = new T[_capacity];

			}
			std::memcpy(_data, other._data, sizeof(T) * _currentIndex);
		}

		return *this;
	}

}