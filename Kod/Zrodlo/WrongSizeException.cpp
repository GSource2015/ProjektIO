#include "WrongSizeException.h"

WrongSizeException::WrongSizeException(const int val) throw(){
	_value = val;
}

WrongSizeException::~WrongSizeException() throw(){

}
const char* WrongSizeException::what() const throw(){
	return "Size of array must be greater or lesser than given";
}
int WrongSizeException::getValue() const throw(){
	return _value;
}
