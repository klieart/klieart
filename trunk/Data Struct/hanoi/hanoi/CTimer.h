#include <iostream>
#include <windows.h>

class CTimer
{
public:
	CTimer() {
		QueryPerformanceFrequency(&mqFreq);
	}
	~CTimer() {}

	void Start() {
		QueryPerformanceCounter(&mqStart);
	}
	void End() {
		QueryPerformanceCounter(&mqEnd);
	}
	double GetTimeInSeconds() {
		return (mqEnd.QuadPart - mqStart.QuadPart)/(double)mqFreq.QuadPart;
	}
	double GetTimeInMilliseconds() {
		return (1.0e3*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
	}
	double GetTimeInMicroseconds() {
		return (1.0e6*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
	}
	double GetTimeInNanoseconds() {
		return (1.0e9*(mqEnd.QuadPart - mqStart.QuadPart))/mqFreq.QuadPart;
	}

private:
	LARGE_INTEGER mqStart;
	LARGE_INTEGER mqEnd;
	LARGE_INTEGER mqFreq;
};