#include "IndexException.h"

IndexException::IndexException(const int i){
	_ind = i;
}

IndexException::~IndexException(){

}

const char* IndexException::what() const{
	return "Wrong array index";
}

int IndexException::getIndex() const{
	return _ind;
}
