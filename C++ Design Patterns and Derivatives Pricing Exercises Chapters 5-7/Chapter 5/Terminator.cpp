// C++ Design Patterns and Derivatives Pricing---Exercise 5.4, 5.5, page 100

#include "Terminator.h"

Timer::Timer(double StartTime_, double TimeLimit_) : StartTime(StartTime_), TimeLimit(TimeLimit_) {}

double Timer::elapsedTime() const
{ 
	return (clock() - StartTime) / CLOCKS_PER_SEC; 
}

bool Timer::isTimeUp() const
{ 
	return elapsedTime() > TimeLimit; 
}

PathCounter::PathCounter(unsigned long PathsDone_, unsigned long PathsLimit_) 
: PathsDone(PathsDone_), PathsLimit(PathsLimit_) {}

void PathCounter::IncrementPath() 
{ 
	PathsDone++; 
}

unsigned long PathCounter::getPathDone() const
{ 
	return PathsDone; 
}
	
bool PathCounter::isPathOut() const
{ 
	return PathsDone > PathsLimit; 
}

Terminator::Terminator(double StartTime_, 
					   double TimeLimit_, 
					   unsigned long PathsDone_, 
			           unsigned long PathsLimit_)
			           : Time(StartTime_, TimeLimit_), Path(PathsDone_, PathsLimit_) {}
	
Terminator::Terminator(const Timer& Time_, const PathCounter& Path_) : Time(Time_), Path(Path_) {}

const Timer& Terminator::getTime() const
{
	return Time;	
}

PathCounter& Terminator::getPath()
{
	return Path;
}

bool Terminator::isTerminated() const
{ 
	return Time.isTimeUp() || Path.isPathOut(); 
}