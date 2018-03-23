// C++ Design Patterns and Derivatives Pricing---Listing 4.14, page 72

#include "PayOffBridge.h"
#include <algorithm>    // std::minmax

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
	ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff) 
{
	ThePayOffPtr = innerPayOff.clone();
}

PayOffBridge::~PayOffBridge()
{
	delete ThePayOffPtr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
	if (this != &original)
	{
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}
	return *this;
}