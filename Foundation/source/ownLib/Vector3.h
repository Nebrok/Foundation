#pragma once
#include <string>

namespace KTools
{
	template <typename T>
	class Vector3
	{
	public:
		T x = 0;
		T y = 0;
		T z = 0;

	private:

	public:
		Vector3();
		Vector3(T);
		Vector3(T, T, T);
		~Vector3();

		std::string ToString();

		//Vector3 operator+(T);
		void operator+=(T);
		//Vector3 operator+(Vector3);
		void operator+=(Vector3*);

		//Vector3 operator-(T);
		void operator-=(T);
		//Vector3 operator-(Vector3);
		void operator-=(Vector3);

		//Vector3 operator*(T);
		void operator*=(T);

		//Vector3 operator/(T);
		void operator/=(T);
	};
}

//Defintion
namespace KTools
{
	template <typename T>
	Vector3<T>::Vector3()
	{

	}

	template <typename T>
	Vector3<T>::Vector3(T n)
	{
		x = n;
		y = n;
		z = n;
	}

	template <typename T>
	Vector3<T>::Vector3(T setX, T setY, T setZ)
	{
		x = setX;
		y = setY;
		z = setZ;
	}

	template <typename T>
	Vector3<T>::~Vector3()
	{
		
	}
	
	template <typename T>
	void Vector3<T>::operator+=(T scalar)
	{
		x += scalar;
		y += scalar;
		z += scalar;
	}

	template <typename T>
	void Vector3<T>::operator+=(Vector3 *other)
	{
		x += other->x;
		y += other->y;
		z += other->z;
	}

	template <typename T>
	void Vector3<T>::operator-=(T scalar)
	{
		x -= scalar;
		y -= scalar;
		z -= scalar;
	}

	template <typename T>
	void Vector3<T>::operator-=(Vector3 other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	template <typename T>
	void Vector3<T>::operator*=(T scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}

	template <typename T>
	void Vector3<T>::operator/=(T scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}

	template <typename T>
	std::string Vector3<T>::ToString()
	{
		std::string outputString = "( ";
		outputString += std::to_string(x) + ", ";
		outputString += std::to_string(y) + ", ";
		outputString += std::to_string(z);
		outputString += " )";
		return outputString;
	}
}