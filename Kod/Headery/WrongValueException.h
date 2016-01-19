///-----------------------------------------------------------------
///
/// @file      WrongSizeException.h
/// @author    GSource
/// @section   OPIS
///            Wyjątek mówiący, że przekazano do funkcji niedozwolną wartość
///
///------------------------------------------------------------------
#ifndef _WRONGVALUEEXCEPTION_H_
#define _WRONGVALUEEXCEPTION_H_
#include <iostream>

class WrongValueException : public std::exception {
public:
	WrongValueException(const double val) throw();
	~WrongValueException() throw();
	const char* what() const throw();
	double getValue() const throw();
private:
	double _value;
};

#endif
