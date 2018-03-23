// C++ Design Patterns and Derivatives Pricing---Listing 7.2, page 126

#include "PathDependent.h"

PathDependent::PathDependent(const MJArray& LookAtTimes_) : LookAtTimes(LookAtTimes_) {}

const MJArray& PathDependent::GetLookAtTimes() const
{
	return LookAtTimes;
}