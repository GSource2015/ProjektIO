///-----------------------------------------------------------------
///
/// @file      NewFile.h
/// @author    GSource
/// @section   OPIS
///            Okno dialogowe, które będzie pozwalało na wpisanie parametrów
///				do utworzenia nowej planszy oraz sprawdzało ich poprawność.
///
///------------------------------------------------------------------

#ifndef __NEWFILE_H__
#define __NEWFILE_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef NewFile_STYLE
#define NewFile_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class NewFile : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		///Konstruktor klasy wxWidgets dla wxDialog
		NewFile(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Nowy plik"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = NewFile_STYLE);
		virtual ~NewFile();
		
		/// Funkcja, pozwalająca uzsykać dostęp do listy rozwijanej
		/// z okna dialogowego
		/// @return wskaźnik do listy rozwijanej wxChoice
		wxChoice* getThemeChoice();
		/// Zwraca nazwę poziomu, wpisaną do pola tekstowego WxNazwa
		/// @return tekst wpisany do pola tekstowego WxNazwa
		wxString getLevelName();
		/// Zwraca rozmiar, jaki został wpisany do pól tekstowych szerokość i wysokość
		/// @param x szerokość
		/// @param y wysokość
		void getSize(int &x, int &y);
		/// Zwraca obecnie wybraną nazwę motywu w obiekcie wxChoice.
		/// @return nazwa wybranego motywu w WxChoice
		wxString getThemeName();
		/// Handler, wywołujący się podczas naciśnięcia przycisku Nowy.
		/// Sprawdza poprawność danych i zamyka okno.
		/// @param event zdarzenie, na rzecz któreg jest wywoływany
		void PrzyciskOKClick(wxCommandEvent& event);
		/// Wywołuje się podczas naciśnięciu przycisku Anuluj.
		/// Zamyka okno.
		/// @param event zdarzenie, na rzecz któreg jest wywoływany
		void PrzyciskAnulujClick(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxChoice *Motyw;
		wxStaticText *WxStaticText4;
		wxTextCtrl *Wysokosc;
		wxStaticText *WxStaticText3;
		wxTextCtrl *Szerokosc;
		wxStaticText *WxStaticText2;
		wxTextCtrl *Nazwa;
		wxStaticText *WxStaticText1;
		wxFlexGridSizer *WxFlexGridSizer1;
		wxButton *PrzyciskAnuluj;
		wxButton *PrzyciskOK;
		wxBoxSizer *WxBoxSizer3;
		wxStaticBoxSizer *WxStaticBoxSizer1;
		wxBoxSizer *WxBoxSizer2;
		wxPanel *WxPanel1;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXCHOICE1 = 1073,
			ID_WXSTATICTEXT4 = 1072,
			ID_WXEDIT3 = 1070,
			ID_WXSTATICTEXT3 = 1069,
			ID_WXEDIT2 = 1067,
			ID_WXSTATICTEXT2 = 1066,
			ID_WXEDIT1 = 1064,
			ID_WXSTATICTEXT1 = 1057,
			ID_WXBUTTON2 = 1011,
			ID_WXBUTTON1 = 1010,
			ID_WXPANEL1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
