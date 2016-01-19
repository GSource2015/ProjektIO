///-----------------------------------------------------------------
///
/// @file      	Matrix2D.h
/// @author    	GSource
/// @section   	OPIS
///            	Jest reprezentacją macierzy 3x3, która jest potrzebna do wykonywania
///				wszelkich transformacji na obrazie (translacja, skalowanie etc.).
///				Nie jest to zwykła macierz 3x3, nadaje się głównie do transformacji obrazu.
///
///------------------------------------------------------------------

#ifndef _MATRIX2D_H_
#define _MATRIX2D_H_
#include "Vector2D.h"
#include "NegativeIndexException.h"
#include "OutOfRangeIndexException.h"

class Matrix2D{
public:
	/// Konstruktor domniemany.
	Matrix2D();
	/// Konstrutkor kopiujący drugą macierz, bez jej zmiany.
	Matrix2D(const Matrix2D& source);
	/// Przeładowanie operatora =, które kopiuje drugą macierz, bez jej zmiany
	Matrix2D& operator=(const Matrix2D& source);
	/// Przeładowanie operatora *, robiące mnożenie Macierz * Wektor.
	/// @param vector wektor, przez który ma być pomnożona macierz
	/// @return wynik, będący wektorem
	Vector2D operator*(const Vector2D& vector) const;
	/// Dokonuje operacji mnożenia każdego elementu przez podaną wartość.
	/// @param value wartość, przez którą ma być pomnożona macierz.
	/// @return macierz wynikowa
	Matrix2D operator*(const float value) const;
	/// Dokonuje operacji mnożenia macierz*macierz.
	/// @param matrix macierz, przez którą będzemy mnożyć obecną
	/// @return macierz wynikowa
	Matrix2D operator*(const Matrix2D& matrix) const;
	/// Dodaje do każdego elementu macierzy daną wartość.
	/// @param value wartość, która będzie dodawana do macierzy
	/// @return macierz wynikowa
	Matrix2D operator+(const float value) const;
	/// Dodaje każdy element macierzy do elementu drugiej macierzy,
	/// jemu odpowiadjącemu.
	/// @param matrix macierz, która ma być dodana
	/// @return macierz wynikowa
	Matrix2D operator+(const Matrix2D& matrix) const;	
	/// Dodaje do każdego elementu obecnej macierzy pewną wartość.
	/// @param value wartośc, która ma być dodana
	/// @return referencja do siebie
	Matrix2D& operator+=(const float value);
	/// Dodaje każdy element macierzy do elementu drugiej macierzy,
	/// jemu odpowiadjącemu.
	/// @param matrix macierz, która ma być dodana
	/// @return referencaj do siebie
	Matrix2D& operator+=(const Matrix2D& matrix);
	/// Dokonuje operacji mnożenia macierz*macierz i zastępuje swoje wartości wynikiem.
	/// @param matrix macierz, przez którą będzemy mnożyć obecną
	/// @return referencja do siebie
	Matrix2D& operator*=(const Matrix2D& matrix);
	/// Zwraca element, który znajduje się na danej pozycji, który można edytować,
	/// przez co można operować na macierzy jak na tablicy 2D.
	/// @param h pozycja względem wysokości
	/// @param w pozcyja względem szerokości
	/// @return referencja do obiektu, znajdującego się w tym miejscu
	float& operator()(const int h, const int w);

	/// Mnoży macierz przez macierz translacji i modyfikuje swoje rekordy
	/// @param przesunięcie względem osi x
	/// @param przesunięcie względem osi y
	/// @return referencja do siebie
	Matrix2D& translate(const float x, const float y);
	/// Mnoży macierz przez macierz skalowania i modyfikuje swoje rekordy
	/// @param skalowanie względem osi x
	/// @param skalowanie względem osi y
	/// @return referencja do siebie
	Matrix2D& scale(const float x, const float y);
	/// Powoduje ustawienie macierzy do wartości początkowej (wszędzie 0, prócz prawego dolnego rogu)
	/// @return referencja do siebie
	Matrix2D& resetValues();
	/// Statyczna metoda, zwracająca maceirz translacji.
	/// @param przesunięcie względem osi x
	/// @param przesunięcie względem osi y
	/// @return referencja do siebie
	static Matrix2D getTranslate(const float x, const float y);
	/// Statyczna metoda, zwracająca macierz skalowania.
	/// @param skalowanie względem osi x
	/// @param skalowanie względem osi y
	/// @return macierz skalowania
	static Matrix2D getScale(const float x, const float y);
	/// Statyczna metoda, zwraca podstawową macierz do operacji na obrazach, mająca 1 na przekątnej.
	/// @return macierz z jedynkami na przekątnej
	static Matrix2D getBasic();

private:
	float _mat[3][3]; ///< przechowuje wartości macierzy
};

#endif
