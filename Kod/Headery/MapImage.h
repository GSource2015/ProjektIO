///-----------------------------------------------------------------
///
/// @file      	MapImage.h
/// @author    	GSource
/// @section   	OPIS
///            	Klasa, posiadająca informację o obrazie (rzeczywiste i obrazowe),
///				odpowiedzialna za rysowanie reprezentacji mapy na ekranie.
///				Dziedziczy po klasach ConfigImage i ConfigReal, ponieważ jest ich połączniem.
///
///------------------------------------------------------------------

#ifndef _MAPIMAGE_H_
#define _MAPIMAGE_H_
#include "ConfigImage.h"
#include "ConfigReal.h"
#include "Level.h"
#include <wx/dc.h>
class MapImage : public ConfigImage, public ConfigReal{
public:
	/// Konstruktor, będący zarówno konstruktorem domyślnym
	/// @param wimg szerokość obrazu na którym ma być rysowany poziom
	/// @param himg wysokość obrazu  na którym ma być rysowany poziom
	/// @param xmin minimalna wartość x rzeczywista, z jakiej ma być fitowany obraz
	/// @param ymin minimalna wartość y rzeczywista, z jakiej ma być fitowany obraz
	/// @param xmax maksymalna wartość x rzeczywista, z jakiej ma być fitowany obraz
	/// @param ymax maksymalna wartość y rzeczywista, z jakiej ma być fitowany obraz
	/// @param camx położenie kamery względem osi x
	/// @param camy położenie kamery względem osi y
	/// @param zoom wartośc zbliżenia obrazu
	MapImage(const int wimg = 0, const int himg = 0, const float xmin = -1, const float ymin = -1, const float xmax = 1, const float ymax = 1, const float camx = 0, const float camy = 0, const float zoom = 1);
	/// Konstruktor, który sam oblicza wartośći rzeczywiste na podstawie poziomu
	/// @param map referencja do poziomu, który będzie rysowany
	/// @param wimg szerokość obrazu na którym ma być rysowany poziom
	/// @param himg wysokość obrazu  na którym ma być rysowany poziom
	MapImage(Level& map, const int wimg = 0, const int himg = 0);
	/// Rysuje mapę na danym konteście, z biblioteki wxWidgets. Należy pamiętać, by wcześniej
	/// odpowiednio ustawić kamerę, przybliżenie, a także zeskalować parametry odpowiednimi metodami
	/// w zależności od potrzeb.
	/// @param map poziom, który będzie narysowany
	/// @param dc device context biblioteki wx, czyli obszar, na którym ma być rysowany poziom
	void drawMap(Level& map, wxDC& dc);
	/// Skaluje odpowiedni parametry rzeczywiste na podstawie wielkości poziomu tak,
	/// aby ich proporcje i odległości od krawędzi były odpowiednie.
	/// Ponadto ustawia parametry rzeczywiste obszaru rysowania.
	/// @param map poziom, na podstawie którego należy ustawić parametry
	void adjustParameters(Level& map);
	/// Refituje współrzędne obrazowe na rzeczywiste i zapamiętuje
	/// na które kwadraty w mapie pokazuje w tej chwili mysz.
	/// @param mouseX położenie myszy na obrazie względem osi x
	/// @param mouseY położenie myszy na obrazie względem osi y
	void updateActiveField(int mouseX, int mouseY);
	/// Przemieszcza kamerę w zależności od szybkości zmiany położenia myszy
	/// @param mx obecne położenie myszy na obrazie względem osi x
	/// @param my obecne położenie myszy na obrazie względem osi y
	/// @param px poprzednie położenie myszy na obrazie względem osi x
	/// @param py poprzednie położenie myszy na obrazie względem osi y
	void moveCamera(int mx, int my, int px, int py);
	/// Zbliża i oddala obraz o pewien procent, jednak wyłącznie do pewnej wartości 
	/// (skalowanie 0.1 i 10, czyli 10 krotne).
	/// @param perc procentowe zbliżenie ekranu
	void zoomPercent(float perc);
	/// Aktywny kwadrat, który został wyliczony metodą UpdateActiveField.
	/// @return obecnie zaznaczony kwadrat (szerokość)
	int getActiveX();
	/// Aktywny kwadrat, który został wyliczony metodą UpdateActiveField.
	/// @return obecnie zaznaczony kwadrat (wysokość)
	int getActiveY();
	///Rzeczywiste współrzędne kursora w układzie wspólrzędnych mapy
	/// @return połozenie względem osi x kursora
	float getRealX();
	///Rzeczywiste współrzędne kursora w układzie wspólrzędnych mapy
	/// @return połozenie względem osi x kursora
	float getRealY();
private:
	bool _obramowanie; ///< Czy obramowanie ma być rysowanie czy nie
	float _thick;	///< Grubość "ramki" wokół planszy, czyli wolnej przestrzeni (minimalna)
	int _activex, _activey;	///< Obecnie zaznaczony kwadrat na planszy przez myszke
	float _realx, _realy; ///< Rzeczywiste położenie myszki w układzie współrzędnych mapy

	void drawWalls(Level& map, wxDC& dc);	///< Funkcja pomocnicza do drawMap, rysująca ścianki planszy
	void drawFloor(Level& map, wxDC& dc);	///< Funkcja pomocnicza do drawMap, rysująca podłoża planszy
};

#endif
