// C++ Design Patterns and Derivatives Pricing---Exercise 5.4, 5.5, page 100

#ifndef TERMINATOR_H
#define TERMINATOR_H

#include <ctime>

class Timer
{
private:
	double StartTime;
	double TimeLimit;

public:
	Timer(double StartTime_ = clock(), double TimeLimit_ = 1.0);
	double elapsedTime() const;
	bool isTimeUp() const;
};

class PathCounter
{
private:
	unsigned long PathsDone;
	unsigned long PathsLimit;
public:
	PathCounter(unsigned long PathsDone_ = 0UL, unsigned long PathsLimit_ = 1000000);
	void IncrementPath();
	unsigned long getPathDone() const;
	bool isPathOut() const;
};

class Terminator
{
public:
	Terminator(double StartTime_ = clock(), 
		       double TimeLimit_ = 1.0, 
		       unsigned long PathsDone_ = 0UL, 
		       unsigned long PathsLimit_ = 1000000);
	Terminator(const Timer& Time_, const PathCounter& Path_);
	const Timer& getTime() const;
	PathCounter& getPath();
	bool isTerminated() const;
private:
	Timer Time;
	PathCounter Path;
};

#endif