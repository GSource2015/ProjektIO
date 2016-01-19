///-----------------------------------------------------------------
///
/// @file      CustomPanelEditor.h
/// @author    GSource
/// @section   OPIS
///            Klasa będąca rozszerzeniem wxPanel, obsługująca zdarzenia myszki i
///				śledzaca jej pozycję.
///
///------------------------------------------------------------------
#ifndef _CUSTOMPANELEDITOR_H
#define _CUSTOMPANELEDITOR_H
#include <wx/wx.h>
#include <wx/sizer.h>
#include "MapImage.h"
#include "Level.h"
#include <wx/aboutdlg.h> 
class CustomPanelEditor : public wxPanel{
public:	
	///Konstruktor wxPanel
	CustomPanelEditor(wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL | wxNO_BORDER, const wxString& name = wxPanelNameStr);
	~CustomPanelEditor();

	///Zwraca obiekt rysujący mapę
	MapImage& getMapImage();
	///Zwraca poziom, który obecnie jest używany
	Level* getLevel();
	///Zwraca pozycję x myszy
	int getMouseX();
	///Zwraca pozycję y myszy
	int getMouseY();
	///Zwraca pozycje myszy
	void getMousePos(int& x, int& y);

	///Ustawia nowy poziom
	void setLevel(Level *lvl);

	///Handler, obsługujący ruch myszki i aktualizujący na bieżąco obecnie zaznaczony kwadrat 
	///obiektu klasy Board.
	void mouseMove(wxMouseEvent& event);
	///Handler, obsługujący wcisnięcie lewego przycisku myszy, pozwalający na przesuwanie ekranu
	void mouseLDown(wxMouseEvent& event);
	///Handler, obsługujący zwolnienie lewego przycisku myszy. Jeśli mysz się nie poruszyła, to zwiększa wartośc w aktywnym polu
	void mouseLUp(wxMouseEvent& event);
	///Handler obsługujący wcisnięcie prawego przycisku myszy, kasuje flagi.
	void mouseRDown(wxMouseEvent& event);
	///Handler obsługujący zwolnienie prawego przycisku myszy, jeśli mysz się nie poruszyła, to odejmuje wartość w aktywnym polu
	void mouseRUp(wxMouseEvent& event);
	///Obsługuje kółko i zbliżanie i oddalanie mapy.
	void mouseWheel(wxMouseEvent& event);
private:
	MapImage _img; ///Obiekt rysujący mapę
	Level *_map;	///Wskaźnik do obiektu, reprezentującego poziom
	int _x, _y;	///Pozycja x i y myszki (obecna)
	bool _drag;	///Określa, czy kamera będzie przesuwana
	bool _can_click;	///Sprawdza, czy poruszono się podczas wciśnięcia przycisku myszy
	int _prev_x, _prev_y;	///Poprzednia pozycja myszy


};

#endif
