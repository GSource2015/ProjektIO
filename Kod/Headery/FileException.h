///-----------------------------------------------------------------
///
/// @file      FileException.h
/// @author    GSource
/// @section   OPIS
///            Wyjątek mówiący, że coś poszło nie tak w obsłudze pliku
///
///------------------------------------------------------------------
#ifndef _FILEEXCEPTION_H_
#define _FILEEXCEPTION_H_
#include <iostream>

class FileException : public std::exception {
public:
	FileException(std::string path) throw();
	~FileException() throw();
	const char* what() const throw();
	std::string getPath() const throw();
private:
	std::string _path;
};

#endif
