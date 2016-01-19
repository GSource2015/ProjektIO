///-----------------------------------------------------------------
///
/// @file      	NegativeIndexException.h
/// @author    	GSource
/// @section   	OPIS
///            	Klasa wyjątku, dziedzicząca po klasie IndexException, mająca na celu
///				zwracania informacji o odwołaniu się do ujemnego indeksu tablicy.
///
///------------------------------------------------------------------

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
