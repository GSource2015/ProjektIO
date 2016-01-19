///-----------------------------------------------------------------
///
/// @file      Level.h
/// @author    GSource
/// @section   OPIS
///            Scala motyw z poziomem.
///
///------------------------------------------------------------------
#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "Board.h"
#include "Theme.h"

class Level{
public:
	Level();
	///Tworzy od razu poziom o określonych rozmiarach
	Level(const int width, const int height);
	///Kopiuje cały poziom
	Level& operator=(const Level& source);
	///Zwraca referencję do obiektu Board
	Board& getBoard();
	///Zwraca referencę do obiektu Theme
	Theme& getTheme();
	///Zwraca poziom trudności, obecnie nieużywane
	unsigned char getDifficulty() const;
	///Sprawdza, czy obiekt ma własne kształty (niedomyślne), obecnie nieużywane
	bool isCustomShape() const;

	///Ustawia poziom trudności, nic nie zmienia obecnie
	void setDifficulty(const unsigned char difficulty);
	void setCustomShape(const bool custom);
	///Ustaiwa nazwe poziomu
	void setName(const char *name);
	///Ustaiwa nazwe poziomu
	void setName(string name);
	///Zwraca nazwe poziomu
	string getName();
private:
	Board _board;
	Theme _theme;
	unsigned char _difficulty;
	bool _custom_shapes;
	string _name;
};

#endif
