///-----------------------------------------------------------------
///
/// @file      IndexException.h
/// @author    GSource
/// @section   OPIS
///            Informuje, że wystąpił jakiś problem z indeksem tablicy (nie specyfikuje jaki)
///
///------------------------------------------------------------------
#ifndef _INDEXECEPTION_H_
#define _INDEXECEPTION_H_
#include <iostream>

class IndexException : public std::exception {
public:
	IndexException(const int i) throw();
	~IndexException() throw();
	const char* what() const throw();
	int getIndex()const throw();
private:
	int _ind;
};

#endif
