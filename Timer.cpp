#include "Timer.h"
#include <iostream>

Timer::Timer()
{
	this->start = time(0);
}

Timer::~Timer()
{
	this->end = time(0);
	std::cout << "Time game: " << this->getTotal() << " sec.";
}

unsigned int Timer::getTotal()
{
	this->total = this->end - this->start;
	return this->total;
}
