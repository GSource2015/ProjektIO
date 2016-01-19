///-----------------------------------------------------------------
///
/// @file      NewTheme.h
/// @author    GSource
/// @section   OPIS
///            Okno dialogowe mające na celu tworzenie nowych motywow
///				i ich podgląd podczas procesu tworzenia. Klasa przechowuje
///				jedynie same ustawienia, a nie motyw. Trzeba je pobrać do motywu.
///
///------------------------------------------------------------------

#ifndef __NEWTHEME_H__
#define __NEWTHEME_H__

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
#include <wx/colordlg.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/bmpbuttn.h>
#include <wx/panel.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef NewTheme_STYLE
#define NewTheme_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class NewTheme : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		///Konstruktom tworzony dla wxDialog
		NewTheme(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Tworzenie motywu"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = NewTheme_STYLE);
		virtual ~NewTheme();
		
		/// Handler, uruchamiający się podczas naciśnięcia przycisku tła i pozwala na 
		/// wybór jego koloru, który jest obrazowany z obszarze podglądu.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskTloClick(wxCommandEvent& event);
		/// Handler, uruchamiający się podczas naciśnięcia przycisku ścianki i pozwala na 
		/// wybór jej koloru, a w przyszłości teksturę. Rezultat jest obrazowany w obszarze
		/// podglądu.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskScianyClick(wxCommandEvent& event);
		/// Handler, uruchamiający się podczas naciśnięcia przycisku podłogi i pozwala na 
		/// wybór jej koloru, a w przyszłości teksturę. Rezultat jest obrazowany w obszarze
		/// podglądu.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskPodloga0Click(wxCommandEvent& event);
		/// Handler, uruchamiający się podczas naciśnięcia przycisku podłogi i pozwala na 
		/// wybór jej koloru, a w przyszłości teksturę. Rezultat jest obrazowany w obszarze
		/// podglądu.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskPodloga1Click(wxCommandEvent& event);
		/// Handler, uruchamiający się podczas naciśnięcia przycisku podłogi i pozwala na 
		/// wybór jej koloru, a w przyszłości teksturę. Rezultat jest obrazowany w obszarze
		/// podglądu.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskPodloga2Click(wxCommandEvent& event);
		/// Handler, uruchamiający się podczas naciśnięcia przycisku podłogi i pozwala na 
		/// wybór jej koloru, a w przyszłości teksturę. Rezultat jest obrazowany w obszarze
		/// podglądu.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskPodloga3Click(wxCommandEvent& event);
		/// Handler, uruchamiający się podczas naciśnięcia przycisku podłogi i pozwala na 
		/// wybór jej koloru, a w przyszłości teksturę. Rezultat jest obrazowany w obszarze
		/// podglądu.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskPodloga4Click(wxCommandEvent& event);
		/// Handler, uruchamiający się podczas naciśnięcia przycisku podłogi i pozwala na 
		/// wybór jej koloru, a w przyszłości teksturę. Rezultat jest obrazowany w obszarze
		/// podglądu.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskPodloga5Click(wxCommandEvent& event);
		
		///Odpowiada za rysowanie w obszarze podglądu obecnie wybranej konfiguracji.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PodgladPanelUpdateUI(wxUpdateUIEvent& event);
		
		///Handler uruchamiany w momencie naciśnięcia przycisku stwórz. Powoduje on zwrócenie wartości wxID_OK
		/// i zniknięcie okna.
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskStworzClick(wxCommandEvent& event);
		///Handler uruchamiany w momencie naciśnięcia przycisku Anuluj. Powoduje on zwrócenie wartości wxID_CANCEL
		/// i zniknięcie okna.		
		/// @param event zdarzenie, na rzecz którego został wywołany
		void PrzyciskAnulujClick(wxCommandEvent& event);
		
		/// Zwraca nazwę wpisaną w pole Nazwa
		/// @return nazwa motywu
		wxString getName();
		/// Zwraca wybrany motyw główny z listy wxChoice.
		/// @numer wybranego motywu głównego
		int getMainTheme();
		
		/// Zwraca kolor przycisku, odpowiedzialnego za kolor tła.
		/// @return kolor tła.
		wxColour getBackground();
		/// Zwraca kolor przycisku, odpowiedzialnego za kolor ścianek.
		/// @return kolor ścianek.
		wxColour getWalls();
		/// Zwraca kolor przycisku, odpowiedzialnego za kolor podłogi.
		/// @return kolor podłogi 0.
		wxColour getFloor0();
		/// Zwraca kolor przycisku, odpowiedzialnego za kolor podłogi.
		/// @return kolor podłogi 1.
		wxColour getFloor1();
		/// Zwraca kolor przycisku, odpowiedzialnego za kolor podłogi.
		/// @return kolor podłogi 2.
		wxColour getFloor2();
		/// Zwraca kolor przycisku, odpowiedzialnego za kolor podłogi.
		/// @return kolor podłogi 3.
		wxColour getFloor3();
		/// Zwraca kolor przycisku, odpowiedzialnego za kolor podłogi.
		/// @return kolor podłogi 4.
		wxColour getFloor4();
		/// Zwraca kolor przycisku, odpowiedzialnego za kolor podłogi.
		/// @return kolor podłogi 5.
		wxColour getFloor5();
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxChoice *ListaMotywowGlownych;
		wxButton *PrzyciskAnuluj;
		wxColourDialog *WyborKoloru;
		wxPanel *PodgladPanel;
		wxStaticBoxSizer *WxStaticBoxSizer3;
		wxButton *PrzyciskStworz;
		wxBoxSizer *WxBoxSizer5;
		wxTextCtrl *Nazwa;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxBitmapButton *PrzyciskPodloga5;
		wxBitmapButton *PrzyciskPodloga4;
		wxBitmapButton *PrzyciskPodloga3;
		wxBitmapButton *PrzyciskPodloga2;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxBitmapButton *PrzyciskPodloga1;
		wxBitmapButton *PrzyciskPodloga0;
		wxBitmapButton *PrzyciskSciany;
		wxBitmapButton *PrzyciskTlo;
		wxGridSizer *SiatkaMotyw;
		wxStaticBoxSizer *WxStaticBoxSizer2;
		wxBoxSizer *WxBoxSizer4;
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
			ID_LISTAMOTYWOWGLOWNYCH = 1166,
			ID_WXBUTTON2 = 1165,
			ID_WXPANEL2 = 1163,
			ID_WXBUTTON1 = 1157,
			ID_WXEDIT1 = 1017,
			ID_WXSTATICTEXT12 = 1152,
			ID_WXSTATICTEXT11 = 1151,
			ID_WXSTATICTEXT10 = 1150,
			ID_WXSTATICTEXT9 = 1149,
			ID_WXBITMAPBUTTON8 = 1142,
			ID_WXBITMAPBUTTON7 = 1141,
			ID_WXBITMAPBUTTON6 = 1140,
			ID_WXBITMAPBUTTON5 = 1139,
			ID_WXSTATICTEXT4 = 1113,
			ID_WXSTATICTEXT3 = 1112,
			ID_WXSTATICTEXT2 = 1111,
			ID_WXSTATICTEXT1 = 1110,
			ID_WXBITMAPBUTTON4 = 1103,
			ID_WXBITMAPBUTTON3 = 1102,
			ID_WXBITMAPBUTTON2 = 1101,
			ID_WXBITMAPBUTTON1 = 1100,
			ID_WXPANEL1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
