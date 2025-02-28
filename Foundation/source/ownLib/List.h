#pragma once
#include <cstdlib>
#include <stdexcept>


namespace KTools
{
	template <typename T> 
	class List
	{
	public:
		
		int Capacity = 32;

	private:
		T* _data;
		int _currentIndex;

	public:
		List();
		List(size_t size);
		~List();

		int Count() { return _currentIndex + 1; }

		int& operator[](int index);

		void Add(T);
		T RemoveAt(int);
		//void RemoveRange();
		//void Clear();
		//void Contains();
		//void Insert(int, T);
		//void Slice(int, int);
		//void ToArray();
		//void ToString();
	};
}

namespace KTools
{
	template <typename T>
	List<T>::List()
	{
		_data = (T*)std::malloc(sizeof(T) * Capacity);

		if (_data = nullptr)
			throw std::runtime_error("Error allocation memory for list initialisation");
	}

	template <typename T>
	List<T>::List(size_t size)
	{
		Capacity = size;
		_data = (T*)std::malloc(sizeof(T) * Capacity);

		if (_data = nullptr)
			throw std::runtime_error("Error allocation memory for list initialisation");
	}

	template <typename T>
	List<T>::~List()
	{
		free(_data);
	}

	template <typename T>
	void List<T>::Add(T addition)
	{
		_data[_currentIndex] = addition;
		_currentIndex++;
	}

	template <typename T>
	T List<T>::RemoveAt(int index)
	{
		if (index < 0 or index > _currentIndex)
			throw std::out_of_range("Index out of range");
		else if (index == NULL)
			throw std::invalid_argument("Index cannot be null");

		T removedItem = _data[index];
		for (int i = index + 1; i < _currentIndex; i++)
		{

		}

	}


}