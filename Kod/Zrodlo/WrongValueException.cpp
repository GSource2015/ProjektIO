#include "WrongValueException.h"

WrongValueException::WrongValueException(const double val) throw(){
	_value = val;
}

WrongValueException::~WrongValueException() throw(){

}
const char* WrongValueException::what() const throw(){
	return "Not allowed value was passed";
}
double WrongValueException::getValue() const throw(){
	return _value;
}
