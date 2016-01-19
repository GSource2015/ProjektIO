///-----------------------------------------------------------------
///
/// @file      OutOfRangeIndexException.h
/// @author    GSource
/// @section   OPIS
///            Wyjątek, informujący, że wyszliśmy poza zakres tablicy
///
///------------------------------------------------------------------
#ifndef _OUTOFRANGEINDEXEXCEPTION_H_
#define _OUTOFRANGEINDEXEXCEPTION_H_
#include "IndexException.h"

class OutOfRangeIndexException : public IndexException {
public:
	OutOfRangeIndexException(const int i) throw();
	~OutOfRangeIndexException() throw();
	const char* what() const throw();
};

#endif
