///-----------------------------------------------------------------
///
/// @file      ConfigImage.h
/// @author    GSource
/// @section   OPIS
///            Klasa, przechowująca informację konfiguracyjne obrazu
///
///------------------------------------------------------------------
#ifndef _CONFIGIMAGE_H_
#define _CONFIGIMAGE_H_

class ConfigImage{
public:
	///Inicjalizuje szerokość i wysokość obrazu
	ConfigImage(const int wimg = 0, const int himg = 0);
	
	///Zwraca szerokość obrazu
	int getImgWidth();
	///Zwraca wysokość obrazu
	int getImgHeight();
	///Zwraca rozmiar obra
	void getImgSize(int& width, int& height);
	///Jeśli obraz jest szerszy niż wyższy, to zwraca stosunek szerokość/wysokość, inaczej zwraca 1.
	float getScaleX();
	///Jeśli obraz jest szerszy niż wyższy, to zwraca stosunek szerokość/wysokość, inaczej zwraca 1.
	float getScaleY();
	///Zwraca obie proporcje, większą i mniejszą
	void getScale(float& scalex, float& scaley);
	
	///Ustawia szerokośc obrazu
	ConfigImage& setImgWidth(const int width);
	///Ustawia wysokość obrazu
	ConfigImage& setImgHeight(const int height);
	///Ustawia wielkość obrazu
	ConfigImage& setImgSize(const int width, const int height);
	///Ustawia współczynnik skalowania względem osi X ręcznie
	ConfigImage& setScaleX(const float scalex);
	///Ustawia współczynnik skalowania względem osi Y ręcznie
	ConfigImage& setScaleY(const float scaley);
	///Ustawia współczynniki skalowania ręcznie
	ConfigImage& setScale(const float scalex, const float scaley);
	
	///Oblicza współczynnik większego parametru rozmiaru do mniejszego
	void calculateRatio(); 
protected:
	int _wimg, _himg; ///< szerokość i wysokość obrazu
	float _scalex, _scaley; ///< współczynnik większego parametru rozmiaru do mniejszego 
};

#endif
