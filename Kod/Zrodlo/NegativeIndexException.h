#include "NegativeIndexException.h"

NegativeIndexException::NegativeIndexException(const int i) throw() : IndexException(i){

}

NegativeIndexException::~NegativeIndexException() throw(){

}

const char* NegativeIndexException::what() const throw(){
	return "Array index was negative";
}
