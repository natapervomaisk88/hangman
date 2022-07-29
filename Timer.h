#pragma once
class Timer
{
	unsigned int start, end, total;
public:
	Timer();
	~Timer();
	unsigned int getTotal();
};

