#include "OutOfRangeIndexException.h"

OutOfRangeIndexException::OutOfRangeIndexException(const int i) throw() : IndexException(i){

}
OutOfRangeIndexException::~OutOfRangeIndexException() throw(){

}
const char* OutOfRangeIndexException::what() const throw(){
	return "Array index was out of range";
}
