#pragma once
#include <chrono>
#include <iostream>


namespace KTools
{
	class Timer
	{
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> _startTime;

	public:
		Timer();


		void StartClock();
		void StopClock();


	};
}

namespace KTools
{
	Timer::Timer()
	{
		_startTime = std::chrono::high_resolution_clock::now();
	}

	void Timer::StartClock()
	{
		_startTime = std::chrono::high_resolution_clock::now();
	}

	void Timer::StopClock() 
	{
		std::chrono::time_point<std::chrono::high_resolution_clock> endTime = std::chrono::high_resolution_clock::now();
		auto runtime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - _startTime);
		std::cout << "Stopclock time: " << runtime.count() << " milliseconds." << "\n";
	}
}