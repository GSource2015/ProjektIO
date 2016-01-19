///-----------------------------------------------------------------
///
/// @file      FileTMWriter.h
/// @author    GSource
/// @section   OPIS
///            Służy do wczytywania plików do edytora Twisted Mind.
///				Dziedziczy po FileTM i może zapisywać mapy i motywy
///
///------------------------------------------------------------------
#ifndef _FILETMWRITER_H_
#define	_FILETMWRITER_H_
#include "FileTM.h"
#include "Level.h"

class FileTMWriter : public FileTM{
public:
	FileTMWriter(string path = "");
	///Zapisuje motyw na dysku
	void writeTheme(Theme& thm);
	///Zapisuje poziom na dysku wraz z motywem, jeśli motyw jest różny
	///od motywu domyślnego (w 1 pliku)
	void writeMap(Level& lvl);
private:
	void appendTheme(Theme& thm);///< Funkcja pomocnicza, zapisująca tylko wartości motywu.
};

#endif // !_FILEWRITER_H_
