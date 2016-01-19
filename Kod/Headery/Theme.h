///-----------------------------------------------------------------
///
/// @file      Theme.h
/// @author    GSource
/// @section   OPIS
///            Klasa, przedstawiająca motyw. Na razie posiada jedynie informacje
///				o kolorach, jedank w przyszłości będzie takze przechowywała informaje o
///				teksturach.
///
///------------------------------------------------------------------
#ifndef _THEME_H
#define _THEME_H
#include <wx/colour.h>
#include "OutOfRangeIndexException.h"
#include "NegativeIndexException.h"

using namespace std;
class Theme{
public:
	///Typ wyliczeniowy, definiujący podstawowe motywy, które są
	///dostępne w grze (chodzi o sscenę 3D)
	enum main_theme {WINTER, FOREST, DESERT, COTTAGE, DUNGEON};
	///Konstruktor domniemany, inicjujący wszystko zerami.
	Theme();
	//Theme(const Theme& source);
	///Przeciążenie operatora =, kopiujące każdy element ze źrodła.
	/// @param source źródło, z którego dane mają być kopiowane
	Theme& operator=(const Theme& source);
	
	/// Ustawia kolor tła.
	/// @param background obiekt, reprezentujący kolor tła
	Theme& loadBackground(const wxColour& background);
	/// Ustawia kolor tła.
	/// @param R składowa czerwona koloru
	/// @param G składowa zielona koloru
	/// @param B składowa niebieska koloru
	Theme& loadBackground(unsigned char R, unsigned char G, unsigned char B);
	/// Ustawia kolor tła.
	/// @param colour kolor przedstawiony w postaci 0x00BBGGRR
	Theme& loadBackground(unsigned long colour);
	/// Ustawia kolor ścianek.
	/// @param walls obiekt, reprezentujący kolor ścianek
	Theme& loadWalls(const wxColour& walls);
	/// Ustawia kolor ścianek.
	/// @param R składowa czerwona koloru
	/// @param G składowa zielona koloru
	/// @param B składowa niebieska koloru
	Theme& loadWalls(unsigned char R, unsigned char G, unsigned char B);
	/// Ustawia kolor ścianek.
	/// @param colour kolor przedstawiony w postaci 0x00BBGGRR
	Theme& loadWalls(unsigned long colour);
	/// Ustawia kolor danego podłoża.
	/// @param i numer danego podłoża (0-5)
	/// @param walls obiekt, reprezentujący kolor ścianek
	Theme& loadFloor(const int i, const wxColour& floor);
	/// Ustawia kolor danego podłoża.
	/// @param i numer danego podłoża (0-5)
	/// @param R składowa czerwona koloru
	/// @param G składowa zielona koloru
	/// @param B składowa niebieska koloru
	Theme& loadFloor(const int i, unsigned char R, unsigned char G, unsigned char B);
	/// Ustawia kolor danego podłoża.
	/// @param i numer danego podłoża (0-5)
	/// @param colour kolor przedstawiony w postaci 0x00BBGGRR
	Theme& loadFloor(const int i, unsigned long colour);
	///Ustawia nowy motyw główny (scene 3D)
	/// @param new_theme motyw główny
	Theme& setTheme(main_theme new_theme);

	/// Zwraca obiekt biblioteki wx, reprezentujący kolor tła
	/// @return referencja do koloru tła
	wxColour& getBackground();
	/// Zwraca obiekt biblioteki wx, reprezentujący kolor ścianek
	/// @return referencja do koloru ścianek
	wxColour& getWalls();
	/// Zwraca obiekt biblioteki wx, reprezentujący kolor podłoża
	/// @param i numer danego podłoża (0-5)
	/// @return referencja do koloru podłoża
	wxColour& getFloor(int number);
	
	/// Zwraca motyw główny 
	/// @return motyw główny motywu
	main_theme getTheme() const;
	/// Ustawia nazwe motywu
	/// @name nowa nazwa motywu
	Theme& setName(const char *name);
	/// Ustawia nazwe motywu
	/// @name nowa nazwa motywu
	Theme& setName(std::string name);
	/// Zwraca nazwę motywu
	/// @return name
	string getName();

	bool isDefault; ///< Parametr określający, czy dany motyw jest domyślny czy nie (ważne do zapisu plików)
private:
	wxColour _background; ///< Kolor tła
	wxColour _walls;	///< Kolor ścianek
	wxColour _floors[6];	///< Kolor podłoża
	main_theme _mtheme;	/// Motyw główny
	std::string _name;	/// Nazwa motywu
};

#endif
