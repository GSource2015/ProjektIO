///-----------------------------------------------------------------
///
/// @file      ConfigReal.h
/// @author    GSource
/// @section   OPIS
///            Klasa, przechowująca informację konfiguracyjne układu rzeczywistego
///
///------------------------------------------------------------------
#ifndef _CONFIGREAL_H_
#define _CONFIGREAL_H_

class ConfigReal{
public:
	///Ustawia minimalne i maksymalne wartości układu współrzędnych oraz pozycję kamery i zbliżenie
	ConfigReal(const float xmin = -1, const float ymin = -1, const float xmax = 1, const float ymax = 1, const float camx = 0, const float camy = 0, const float zoom = 1);
	
	///Ustawia minimalną wartość x wukladzie współrzędnych
	ConfigReal& setXMin(const float xmin);
	///Ustawia maksymalną wartość x wukladzie współrzędnych
	ConfigReal& setXMax(const float xmax);
	///Ustawia minimalną wartość y wukladzie współrzędnych
	ConfigReal& setYMin(const float ymin);
	///Ustawia maksymalną wartość y wukladzie współrzędnych
	ConfigReal& setYMax(const float ymax);
	///Ustawia na nowo wielkość układu współrzędnych
	ConfigReal& setCoords(const float xmin, const float ymin, const float xmax, const float ymax);
	///Ustawia pozycję kamery względem osi x
	ConfigReal& setCamX(const float camx);
	///Ustawia pozycję kamery względem osi y
	ConfigReal& setCamY(const float camy);
	///Ustawia pozycję kamery
	ConfigReal& setCamera(const float camx, const float camy);
	///Ustawia zbliżenie
	ConfigReal& setZoom(const float zoom);
	
	///Zwraca przyjętą minimalną wartość x w układzie współrzędnych
	float getXMin() const;
	///Zwraca przyjętą maksymalną wartość x w układzie współrzędnych
	float getXMax() const;
	///Zwraca przyjętą minimalną wartość y w układzie współrzędnych
	float getYMin() const;
	///Zwraca przyjętą maksymalną wartość y w układzie współrzędnych
	float getYMax() const;
	///Zwraca przyjete minimalne i maksymalne wartości w ukladzie współrzędnym
	void getCoords(float &xmin, float &ymin, float &xmax, float &ymax) const;
	///Zwraca pozycję kamery względem osi x
	float getCamX() const;
	///Zwraca pozycję kamery względem osi y
	float getCamY() const;
	///Zwraca pozycję kamery
	void getCamera(float &camx, float &camy) const;
	///Zwraca współczynnik przybliżenia
	float getZoom() const;

protected:
	float _xmin, _ymin, _xmax, _ymax; ///< Wielkość układu współrzędnych
	float _camx, _camy, _zoom;	///<Pozcyja kamery i zbliżenie
	float _zoomx, _zoomy;	///<Współczynniki, jak bardzo nie są równe w stosunku do siebie rozmiary x i y
	float _border;	///< krawędź dodatkowa wokół układu ze wszytkich stron
};

#endif
