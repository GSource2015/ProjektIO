///-----------------------------------------------------------------
///
/// @file      FileTMReader.h
/// @author    GSource
/// @section   OPIS
///            Służy do wczytywania plików do edytora Twisted Mind.
///				Dziedziczy po FileTM i może wczytywać mapy i motywy
///
///------------------------------------------------------------------
#ifndef _FILETMREADER_H_
#define	_FILETMREADER_H_
#include "FileTM.h"
#include "Level.h"
class FileTMReader : public FileTM{
public:
	FileTMReader(string path = "");
	///Wczytuje z dysku sam motyw.
	///@return wczytany motyw
	Theme readTheme();
	///Wczytuje z dysku cały poziom wraz z motywem
	///jeśli motyw jest różny od domyslnego.
	///@return wczytany poziom
	Level readMap();
private:
	Theme getTheme(); ///<Funkcja pomocnicza, wczytująca wartości motywu;
};

#endif // !_FILETMWRITER_H_
