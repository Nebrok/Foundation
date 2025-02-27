#pragma once

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