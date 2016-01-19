#include "IndexException.h"

IndexException::IndexException(const int i) throw(){
	_ind = i;
}

IndexException::~IndexException() throw(){

}

const char* IndexException::what() const throw(){
	return "Wrong array index";
}

int IndexException::getIndex() const throw(){
	return _ind;
}
