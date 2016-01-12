#ifndef _NEGATIVEINDEXEXCEPTION_H_
#define _NEGATIVEINDEXEXCEPTION_H_
#include "IndexException.h"

class NegativeIndexException : public IndexException {
public:
	NegativeIndexException(const int i) throw();
	~NegativeIndexException() throw();
	const char* what() const throw();
};

#endif
