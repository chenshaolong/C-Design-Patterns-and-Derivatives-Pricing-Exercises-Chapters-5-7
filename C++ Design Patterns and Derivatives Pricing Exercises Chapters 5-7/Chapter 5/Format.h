// formatting stuff, from C++ Primer Plus(6th Edition)-Stephen Prata, page 747, 765 and 767

#ifndef FORMAT_H
#define FORMAT_H

#include <iostream>

class Formatting {
public:
	Formatting(const std::ios_base::fmtflags& flag_ = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield), 
		       const std::streamsize& pr_ = std::cout.precision(8)) : flag(flag_), pr(pr_) {}
	void restore() { std::cout.setf(flag, std::ios_base::floatfield); std::cout.precision(pr); }
private:
  std::ios_base::fmtflags flag;
  std::streamsize pr; 
};

#endif