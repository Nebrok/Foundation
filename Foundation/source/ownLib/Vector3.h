#pragma once
#include <string>
#include <iostream>

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

		T DotProduct(Vector3&);
		Vector3 CrossProduct(Vector3&);
		Vector3<double> Normalise();

		Vector3* operator+(T);
		void operator+=(T);
		Vector3* operator+(Vector3);
		void operator+=(Vector3);

		Vector3* operator-(T);
		void operator-=(T);
		Vector3* operator-(Vector3);
		void operator-=(Vector3);

		Vector3* operator*(T);
		void operator*=(T);

		Vector3* operator/(T);
		void operator/=(T);


	private:
		double Magnitude();
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
	T Vector3<T>::DotProduct(Vector3& other)
	{
		T runningSum = 0;
		runningSum += x * other.x;
		runningSum += y * other.y;
		runningSum += z * other.z;
		return runningSum;
	}

	template <typename T>
	Vector3<T> Vector3<T>::CrossProduct(Vector3& other)
	{
		T iComponent = y * other.z - z * other.y;
		T jComponent = z * other.x - x * other.z;
		T kComponent = x * other.y - y * other.x;
		Vector3<T> newVector(iComponent, jComponent, kComponent);
		
		return newVector;
	}

	template <typename T>
	Vector3<double> Vector3<T>::Normalise()
	{
		double xComponent = x / Magnitude();
		double yComponent = y / Magnitude();
		double zComponent = z / Magnitude();
		Vector3<double> normalisedVector(xComponent, yComponent, zComponent);

		return normalisedVector;
	}

	template <typename T>
	Vector3<T>* Vector3<T>::operator+(T scalar)
	{
		Vector3<T> outVector = *new Vector3<T>(x, y, z);
		outVector += scalar;
		return &outVector;
	}

	template <typename T>
	void Vector3<T>::operator+=(T scalar)
	{
		x += scalar;
		y += scalar;
		z += scalar;
	}

	template <typename T>
	Vector3<T>* Vector3<T>::operator+(Vector3 other)
	{
		Vector3<T> outVector = *new Vector3<T>(x, y, z);
		outVector += other;
		return &outVector;
	}

	template <typename T>
	void Vector3<T>::operator+=(Vector3 other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	template <typename T>
	Vector3<T>* Vector3<T>::operator-(T scalar)
	{
		Vector3<T> outVector = *new Vector3<T>(x, y, z);
		outVector -= scalar;
		return &outVector;
	}

	template <typename T>
	void Vector3<T>::operator-=(T scalar)
	{
		x -= scalar;
		y -= scalar;
		z -= scalar;
	}

	template <typename T>
	Vector3<T>* Vector3<T>::operator-(Vector3 other)
	{
		Vector3<T> outVector = *new Vector3<T>(x, y, z);
		outVector -= other;
		return &outVector;
	}

	template <typename T>
	void Vector3<T>::operator-=(Vector3 other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	template <typename T>
	Vector3<T>* Vector3<T>::operator*(T scalar)
	{
		Vector3<T> outVector = *new Vector3<T>(x, y, z);
		outVector *= scalar;
		return &outVector;
	}

	template <typename T>
	void Vector3<T>::operator*=(T scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
	}

	template <typename T>
	Vector3<T>* Vector3<T>::operator/(T scalar)
	{
		Vector3<T> outVector = *new Vector3<T>(x, y, z);
		outVector /= scalar;
		return &outVector;
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

	template <typename T>
	double Vector3<T>::Magnitude()
	{
		double magSqrd = x * x + y * y + z * z;
		return sqrt(magSqrd);
	}
}