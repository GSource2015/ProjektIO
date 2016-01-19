///-----------------------------------------------------------------
///
/// @file      FileException.h
/// @author    GSource
/// @section   OPIS
///            Klasa będąca szablonem dla klas operujących na plikach. 
///				Sama w sobie nie może operować na plikach, ale udostępnia funkcje
///				klasom dzieciczącym.
///
///------------------------------------------------------------------
#ifndef _FILETM_H_
#define _FILETM_H_
#include <iostream>
#include <stdio.h>
#include "FileException.h"
using namespace std;

class FileTM{
public:
	///Konstruktor, ustawiający ścięzkę operacji na plikach, przed operacjami trzeba ją ustawić
	FileTM(string path = "");
	///Sprawdza, czy powiązano obiekt z jakimś plikiem (sprawdzając ścieżkę)
	bool isAssociated();
	///Ustawia ścięzkę pliku, na której będą operować metody
	void setPath(const string &path);
	///Ustawia ścięzkę pliku, na której będą operować metody
	void setPath(const char *path);
	///Pobiera obecną ścieżkę pliku
	void getPath(const string &path);

protected:
	FILE* _file;
	string _path;
	unsigned char _header[2]; ///< Nagłówek, sprawdzający poprawność formatu pliku 
};


#endif // !_FILETM_H_
