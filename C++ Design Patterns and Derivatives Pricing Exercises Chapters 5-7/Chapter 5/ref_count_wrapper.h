// C++ Design Patterns and Derivatives Pricing---Exercise 5.5, page 100

/*
Re: Exercise 5.6

Postby mj » Wed Dec 01, 2010 2:32 am
well, boost::shared_ptr would be the obvious thing to look at.

My instinct is to create a public class and a private class:

publicshared_ptr: points to a privateshared_ptr

privateshared_ptr :: contains the pointer to the inner object and an integer

the private class would only be accessible to publicshared

*/

/*
Remark:
Since C++11 boost::shared_pointer part of std library. #include<memory>
*/

#ifndef SHARED_WRAPPER_H
#define SHARED_WRAPPER_H

#include "PayOff3.h"

/*
Taken from quant finance books forum at www.markjoshi.com
Re: Exercise 5.6

Postby emza0114 » Wed Feb 06, 2013 12:31 pm
*/

template< class T>
class SharedWrapper
{
public:
	SharedWrapper() {
		DataPtr = 0;
		Counter++;
	}

	SharedWrapper(const T& inner) {
		DataPtr = inner.clone();
		Counter++;
	}

	~SharedWrapper()
	{
		Counter--;
		std::cout << "Class object left = " << Counter << std::endl;
		if ((DataPtr != 0) && Counter == 0){
			delete DataPtr;
		}
	}

	SharedWrapper(const SharedWrapper<T>& original)
	{
		if (original.DataPtr != 0)
			DataPtr = original.DataPtr;
		else
			DataPtr = 0;
		Counter = original.Counter + 1;
	}

	SharedWrapper& operator=(const SharedWrapper<T>& original)
	{
		if (this != &original)
		{
			if (DataPtr != 0)
				delete DataPtr;

			if (original.DataPtr != 0){
				DataPtr = original.DataPtr;
			}
			else
				DataPtr = 0;
		}

		Counter = original.Counter;

		return *this;
	}


	T& operator*()
	{
		return *DataPtr;
	}

	const T& operator*() const
	{
		return *DataPtr;
	}

	const T* const operator->() const
	{
		return DataPtr;
	}

	T* operator->()
	{
		return DataPtr;
	}

private:
	T* DataPtr;
	static int Counter;
};

// initializing static class member
template< class T>
int SharedWrapper<T>::Counter = 0;

#endif