///-----------------------------------------------------------------
///
/// @file      Board.h
/// @author    GSource
/// @section   OPIS
///            Klasa reprezentująca kwadratową planszę NxM.
///
///------------------------------------------------------------------

#ifndef _BOARD_H_
#define _BOARD_H_
#include "OutOfRangeIndexException.h"
#include "NegativeIndexException.h"
#include "WrongValueException.h"
#include "NullArrayException.h"
#include "WrongSizeException.h"
class FileTMWriter;

class Board{
	friend class FileTMWriter;
public:
	///Tworzy pustą planszę
	Board();
	///Tworzy planszę o podanej szerokości i wysokości
	/// @param width szerokośc maksymalnie 30, minimalnie 3
	/// @param height wysokość maksymalnie 30, minimalnie 3
	Board(const int width, const int height);
	///Tworzy planszę na podstawie innej planszy
	Board(const Board& source);
	~Board();
	
	///Kopiuje planszę
	Board& operator=(const Board& source);
	///Operator zwracający wartość, może być stosowany do funkcji stałych
	int operator()(const int width, const int height) const;
	///Operator przypisujący w odpowiednim miejscu odpowiednią wartość
	int operator()(const int width, const int height, const char value);
	
	///Zwraca wartość w danym miejscu
	int getValue(const int width, const int height) const;
	///Zwraca szerokość planszy
	int getWidth() const;
	/// Zwraca wysokość planszy
	int getHeight() const;
	///Zwraca rozmiar planszy
	void getSize(int& width, int& height) const;
	///Ustawia wartość planszy w podanym miejscu
	int setValue(const int width, const int height, const char value);
	///Uzupelnia całą plansze daną wartością.
	Board& fillWith(const char value);
	///Zmienia rozmiar planszy, nie zmieniając zawartości w środku (chyba że plansza się zmniejsza)
	/// @param new_width szerokośc maksymalnie 30, minimalnie 3
	/// @param new_height wysokość maksymalnie 30, minimalnie 3
	void resize(const int new_width, const int new_height);
	///Sprawdza, czy plansza istnieje
	/// @return true jeśli tak
	bool isValid() const;

private:
	char **_fields; ///< Tablica reprezentująca planszę
	int _width; ///< Przechowuje szerokość planszy
	int _height; ///< Przechowuje wysokość planszy

	void reserveFields(); ///< Funkcja pomocnicza, rezerwująca miejsce w pamięci dla planszy
	void freeFields(); ///< Funkcja pomocnicza, zwalniająca planszę z pamięci
};

#endif
