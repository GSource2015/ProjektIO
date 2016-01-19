///-----------------------------------------------------------------
///
/// @file      Vector2D.h
/// @author    GSource
/// @section   OPIS
///            Vector2D jest to reprezentacja punktu 2D w postaci wektora 3 elementowego
///				tak, aby możliwe było dokonywanie jego transformacji za pomocą macierzy.
///				Nie nadaje się do operacji trójwymiarowych, jest po prostu inną reprezentacją punktu
///				dwuwymiarowego.
///
///------------------------------------------------------------------

#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_
#include "OutOfRangeIndexException.h"
#include "NegativeIndexException.h"

class Matrix2D;

class Vector2D{
	friend class Matrix2D;
public:
	///Ustawia pozycje wektora oraz 1 w 3 elemencie wektora.
	/// @param x pozycja względem osi x punktu
	/// @param y pozycja względem osi y punktu
	Vector2D(const float x = 0, const float y = 0);
	///Konstruktor kopiujący
	Vector2D(const Vector2D &source);

	
	///Przeładowanie operatora =, działa jak konstruktor kopiujący
	Vector2D& operator=(const Vector2D& source);
	///Przypisuje wektorowi daną wartość, 3 element pozostawiając niezmienny
	///@value wartość jaka ma być przypisana do wektora
	Vector2D& operator=(const float value);
	///Przesuwa wektor o wektor
	///@param vect wektor o jaki ma być przesunięty
	Vector2D& operator+=(const Vector2D& vect);
	///Przesuwa wektor o pewną wielkość skalarną wzdłuż obu osi
	///@param wartość przesunięcia
	Vector2D& operator+=(const float value);
	///Przesuwa wektor o wektor
	///@param vect wektor o jaki ma być przesunięty
	///@return wektor przesunięty
	Vector2D operator+(const Vector2D& vect) const;
	///Przesuwa wektor o pewną wielkość skalarną wzdłuż obu osi
	///@param wartość przesunięcia
	///@return wektor przesunięty
	Vector2D operator+(const float value) const;
	///Przesuwa wektor o wektor przeciwny
	///@param vect wektor o jakiego przeciwieństwo ma być przesunięty
	Vector2D& operator-=(const Vector2D& vect);
	///Przesuwa wektor o pewną przeciwną wielkość skalarną wzdłuż obu osi
	///@param wartość przesunięcia
	Vector2D& operator-=(const float value);
	///Przesuwa wektor o wektor przeciwny
	///@param vect wektor o jakiego przeciwieństwo ma być przesunięt
	///@return wektor przesunięty
	Vector2D operator-(const Vector2D& vect) const;
	///Przesuwa wektor o pewną przeciwną wielkość skalarną wzdłuż obu osi
	///@param wartość przesunięcia
	///@return wektor przesunięty
	Vector2D operator-(const float value) const;
	///Operator, pozwalający posługiwać się wektorem jak tablicą.
	///@index element do którego się odwołujemy (0-3)
	///@return wartość leżąca pod danym indeksem
	float& operator[](const int index);

	///Ustawia pozycje punktu
	Vector2D& setXY(const float x, const float y);
	///Ustawia pozycje punktu
	Vector2D& setX(const float x);
	///Ustawia pozycje punktu
	Vector2D& setY(const float y);
	///Resetuje wartosci wektora do [0, 0, 1]
	Vector2D& resetValues();
	
	///Zwraca pozycje x punktu
	float getX() const;
	///Zwraca pozycje y punktu
	float getY() const;
	///Zwraca pozycje x i y punktu
	void getXY(float& x, float& y);
	///Fituje wektor ze współrzędnych rzeczywistych do współrzędnych obrazowych.
	///@param x_real_min minimalna wartość x rzeczywista
	///@param y_real_min minimalna wartość y rzeczywista
	///@param x_real_max maksymalna wartość x rzeczywista
	///@param y_real_max maksymalna wartość y rzeczywista
	///@param x_img_min minimalna wartość x obrazowa
	///@param y_img_min minimalna wartość y obrazowa
	///@param x_img_max maksymalna wartość x obrazowa
	///@param y_img_max maksymalna wartość y obrazowa
	Vector2D& fit(const float x_real_min, const float y_real_min, const float x_real_max, const float y_real_max, const float x_img_min, const float y_img_min, const float x_img_max, const float y_img_max);
	///Dokonuje operacji odwrotnej fitowania. Przekształcenie ze współrzędnych obrazowych do rzeczywistych.
	///@param x_real_min minimalna wartość x rzeczywista
	///@param y_real_min minimalna wartość y rzeczywista
	///@param x_real_max maksymalna wartość x rzeczywista
	///@param y_real_max maksymalna wartość y rzeczywista
	///@param x_img_min minimalna wartość x obrazowa
	///@param y_img_min minimalna wartość y obrazowa
	///@param x_img_max maksymalna wartość x obrazowa
	///@param y_img_max maksymalna wartość y obrazowa
	Vector2D& refit(const float x_real_min, const float y_real_min, const float x_real_max, const float y_real_max, const float x_img_min, const float y_img_min, const float x_img_max, const float y_img_max);
private:
	float _vect[3]; ///< Przechowuje wartości wektora

};


#endif
