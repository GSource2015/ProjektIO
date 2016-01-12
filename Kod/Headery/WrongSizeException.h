#ifndef _WRONGSIZEEXPCETION_H_
#define _WRONGSIZEEXPCETION_H_
#include <iostream>

class WrongSizeException : public std::exception {
public:
	WrongSizeException(const int val) throw();
	~WrongSizeException() throw();
	const char* what() const throw();
	int getValue() const throw();
private:
	int _value;
};

#endif
