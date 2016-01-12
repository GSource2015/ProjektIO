#ifndef _NULLARRAYEXCEPTION_H
#define _NULLARRAYEXCEPTION_H
#include <iostream>

class NullArrayException : public std::exception {
public:
	~NullArrayException() throw();
	const char* what() const throw();
};

#endif
