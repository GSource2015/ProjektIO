#include "NullArrayException.h"


NullArrayException::~NullArrayException() throw(){

}

const char* NullArrayException::what() const throw(){
	return "Trying to access element of null pointer";
}
