///-----------------------------------------------------------------
///
/// @file      	MainWindow.h
/// @author    	GSource
/// @section   	OPIS
///            	Klasa reprezentująca główne okno programu, została
///				utworzona za pomocą programu wxDev-C++. Jest to
///				wxFrame, niezależny od innych okien. W nim dokonuje
///				się wszystkich operacji zaimplementowanych
///				w innych klasach. Okno jest scaleniem wszystkich wcześniej
///				utworzonych funkcji i pozwala użytkownikowi mieć do nich dostęp.
///				Okno w niej utworzone korzysta z biblioteki wxWidgets.
///
///------------------------------------------------------------------

#ifndef __MainWindow_H__
#define __MainWindow_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/colordlg.h>
#include <wx/statusbr.h>
#include <wx/spinctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/sizer.h>
////Header Include End
#include "NewFile.h"
#include "CustomPanelEditor.h"
////Dialog Style Start
#undef MainWindow_STYLE
#define MainWindow_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class MainWindow : public wxFrame
{
	private:
		/// Tabela wydarzeń do obsługi handlerów 
		DECLARE_EVENT_TABLE();		
	public:
		/// Konstruktor zdefiniowany przez program. Jeśli okno jest niezależne od innych, to parent powinien być null.
		/// Po dokładne informacje o parametrach należy zaglądnąć do dokumentacji biblioteki wxWidgets.
		/// @param parent okno, będące rodzicem tego okna
		/// @param id numer identyfikacyjny okna
		/// @param tile tytuł okna
		/// @param pos pozycja okna po uruchomieniu
		/// @param size rozmiar okna
		/// @param styl okna
		MainWindow(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("BezNazwy3"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = MainWindow_STYLE);
		virtual ~MainWindow();
		
		/// Handler, który aktualizuje zawartość panelu do rysowania podczas aktualizacji UI, a także
		/// ustawia wartości kolorów niektórych guzików
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PanelEdytorUpdateUI(wxUpdateUIEvent& event);
		/// Handler wywolywany, gdy kliknie się na przycisk reprezentujacy kolor tła planszy.
		/// W fazie obecnej jedynie wczytuje kolor i ustawia na siebie i tak ma zostać, gdyż reprezentuje
		/// kolor światła otoczenia.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PrzyciskTloClick(wxCommandEvent& event);
		/// Handler wywolywany, gdy kliknie się na przycisk reprezentujacy kolor ściany.
		/// W fazie obecnej jedynie wczytuje kolor i ustawia na siebie, jednak w przyszłości
		/// należy go zmodyfikować tak, by mógł wybierać także teksturę z pliku i pokazywać na sobie.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PrzyciskScianyClick(wxCommandEvent& event);
		/// Handler wywolywany, gdy kliknie się na przycisk reprezentujacy kolor podłoża planszy bez żadnego kliknięcia.
		/// W fazie obecnej jedynie wczytuje kolor i ustawia na siebie, jednak w przyszłości
		/// należy go zmodyfikować tak, by mógł wybierać także teksturę z pliku i pokazywać na sobie.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PrzyciskPodloga0Click(wxCommandEvent& event);
		/// Handler wywolywany, gdy kliknie się na przycisk reprezentujacy kolor podłoża planszy z jednym kliknięciem.
		/// W fazie obecnej jedynie wczytuje kolor i ustawia na siebie, jednak w przyszłości
		/// należy go zmodyfikować tak, by mógł wybierać także teksturę z pliku i pokazywać na sobie.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PrzyciskPodloga1Click(wxCommandEvent& event);
		/// Handler wywolywany, gdy kliknie się na przycisk reprezentujacy kolor podłoża planszy z dwoma kliknięciami.
		/// W fazie obecnej jedynie wczytuje kolor i ustawia na siebie, jednak w przyszłości
		/// należy go zmodyfikować tak, by mógł wybierać także teksturę z pliku i pokazywać na sobie.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PrzyciskPodloga2Click(wxCommandEvent& event);
		/// Handler wywolywany, gdy kliknie się na przycisk reprezentujacy kolor podłoża planszy z trzema kliknięciami.
		/// W fazie obecnej jedynie wczytuje kolor i ustawia na siebie, jednak w przyszłości
		/// należy go zmodyfikować tak, by mógł wybierać także teksturę z pliku i pokazywać na sobie.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PrzyciskPodloga3Click(wxCommandEvent& event);
		/// Handler wywolywany, gdy kliknie się na przycisk reprezentujacy kolor podłoża planszy z czterema kliknięciami.
		/// W fazie obecnej jedynie wczytuje kolor i ustawia na siebie, jednak w przyszłości
		/// należy go zmodyfikować tak, by mógł wybierać także teksturę z pliku i pokazywać na sobie.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PrzyciskPodloga4Click(wxCommandEvent& event);
		/// Handler wywolywany, gdy kliknie się na przycisk reprezentujacy kolor podłoża planszy z pięcioma kliknięciami.
		/// W fazie obecnej jedynie wczytuje kolor i ustawia na siebie, jednak w przyszłości
		/// należy go zmodyfikować tak, by mógł wybierać także teksturę z pliku i pokazywać na sobie.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		/// @param event
		void PrzyciskPodloga5Click(wxCommandEvent& event);
		/// Funkcja ładująca kolory na guziki z motywu.
		/// @param thm motyw, którego kolory mają być skopiowane (w przyszłości także tekstura)
		void zaladujMotyw(Theme &thm);
		
		
		/// Handler, który uruchamia się w chwili kliknięcia w menu opcji Nowy,
		/// lub naciśnięcia skrótu klawiszowego CTRL + N. Tworzy on nowy poziom,
		/// o wybranym rozmiarze, nazwie i motywie początkowym.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void MenuNowyClick(wxCommandEvent& event);
		/// Handler, wywołujący się podczas zmiany rozmiaru okna i oblicza
		/// na nowo skalowanie rysowanego obrazu.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void MainWindowSize0(wxSizeEvent& event);
		/// Handler, wywołujący się podczas wybrania czegoś z listy wyboru gotowych
		/// motywów. Ładuje wybrany motyw na ekran lub pozwala wczytać jakiś z dysku
		/// po wybraniu odpowiedniej opcji, a także utworzyć nowy.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void ListaMotywowSelected(wxCommandEvent& event );
		/// Handler, wywoływany podczas aktualizacji pola tekstowego, odpowiedzialnego
		/// za przedstawienie nazwy poziomów. Kopiuje nazwę z pola do obiektu, znajdującego
		/// się w obiekcie PanelEdytor. Obiekt ten jest typu Level.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void NazwaPoziomuUpdated(wxCommandEvent& event);
		/// Handler, wywoływany w momencie kliknięcie przycisku do zapisu motywu.
		/// Zmiany dokonywane w motywie nie są utrwalane, dopóki nie naciśnie się tego przycisku.
		/// Na razie maksymalnie 1 motyw może być zapamiętany, w przyszłości można dać większą możliwośc.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void PrzyciskZapiszMotywClick(wxCommandEvent& event);
		/// Handler, uruchamiający się podczas zmiany nazwy motywu i aktualizący ją.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void NazwaMotywuUpdated(wxCommandEvent& event);
		/// Handler, uruchamijący się podczas wyboru motywu głównego i aktualizujący
		/// go w obiekcie reprezentującym motyw.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void ListaMotywowGlownychSelected(wxCommandEvent& event );
		/// Handler wywoływany podczas kliknięcia opcji Otwórz w menu.
		/// Ładuje mapę i motyw z dysku, do pamięci z odpowiedniego pliku.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void MenuOtworzClick(wxCommandEvent& event);
		/// Handler wywoływany podczas naciśnięcia opcji Zapisz w menu i pwooduje zapis pliku mapy.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void MenuZapiszClick(wxCommandEvent& event);
		/// Podczas kliknięcia w menu w opcję Stwórz motyw, otwiera się nowe okno,
		/// które pozwala nam stworzyć nowy motyw wraz z podglądem (nie potrzeba mapy mieć wczytanej)
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void MenuStworzMotywClick(wxCommandEvent& event);
		/// Handler, wywoływany podczas kliknięcia opcji Zapisz Motyw w menu.
		/// Powoduje zapisanie motywu na dysku.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void MenuZapiszMotywClick(wxCommandEvent& event);
		/// Handler, wywoływany podczas kliknięcia opcji Wczytaj Motyw w menu.
		/// Powoduje wczytanie motywu z dysku. Zastąpi motyw obecnie zapamiętany w pamięci.
		///	@param event odnośnik do wydarzenia, które wywołało ten handler.
		void MenuWczytajMotywClick(wxCommandEvent& event);		

	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *WxSaveFileDialog1;
		wxMenuBar *WxMenuBar1;
		wxFileDialog *WxOpenFileDialog1;
		wxColourDialog *WyborKoloru;
		wxStatusBar *WxStatusBar1;
		CustomPanelEditor *PanelEdytor;
		wxStaticBoxSizer *WxStaticBoxSizer2;
		wxSpinCtrl *WxSpinCtrl1;
		wxPanel *PanelKsztalt7;
		wxPanel *PanelKsztalt6;
		wxPanel *PanelKsztalt5;
		wxPanel *PanelKsztalt4;
		wxPanel *PanelKsztalt3;
		wxPanel *PanelKsztalt2;
		wxPanel *PanelKsztalt1;
		wxGridSizer *SiatkaKsztalty;
		wxStaticBoxSizer *WxStaticBoxSizer4;
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
		wxChoice *ListaMotywowGlownych;
		wxButton *PrzyciskZapiszMotyw;
		wxGridSizer *WxGridSizer1;
		wxTextCtrl *NazwaMotywu;
		wxStaticText *WxStaticText5;
		wxBoxSizer *WxBoxSizer1;
		wxStaticBoxSizer *WxStaticBoxSizer3;
		wxChoice *ListaMotywow;
		wxStaticText *WxStaticText7;
		wxTextCtrl *NazwaPoziomu;
		wxStaticText *WxStaticText6;
		wxGridSizer *WxGridSizer2;
		wxBoxSizer *SizerMenuParametry;
		wxStaticBoxSizer *WxStaticBoxSizer1;
		wxBoxSizer *GlownySizer2;
		wxPanel *PanelTlo;
		wxBoxSizer *GlownySizer;
		////GUI Control Declaration End
		Theme* _userthm;
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_MNU_PLIK_1157 = 1157,
			ID_MNU__NOWY_1159 = 1159,
			ID_MNU_OTW_RZ_1181 = 1181,
			ID_MNU_SUBMENUITEM8_1184 = 1184,
			ID_MNU_ZAPISZJAKO_1185 = 1185,
			ID_MNU_WCZYTAJMOTYW_1187 = 1187,
			ID_MNU_ZAPISZMOTYW_1188 = 1188,
			ID_MNU_WCZYTAJKSZTA_T_1189 = 1189,
			ID_MNU_SUBMENUITEM16_1192 = 1192,
			ID_MNU_EKSPORTUJMAPENACHMUR__1193 = 1193,
			ID_MNU_WYJ_CIE_1195 = 1195,
			ID_MNU_EDYCJA_1158 = 1158,
			ID_MNU_COFNIJ_1196 = 1196,
			ID_MNU_PON_W_1197 = 1197,
			ID_MNU_STW_RZMOTYW_1199 = 1199,
			
			ID_WXSTATUSBAR1 = 1096,
			ID_PanelEdytor = 1006,
			ID_WXSPINCTRL1 = 1088,
			ID_PANELKSZTALT7 = 1090,
			ID_PANELKSZTALT6 = 1079,
			ID_PANELKSZTALT5 = 1077,
			ID_PANELKSZTALT4 = 1075,
			ID_PANELKSZTALT3 = 1012,
			ID_PANELKSZTALT2 = 1011,
			ID_PANELKSZTALT1 = 1010,
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
			ID_WXCHOICE1 = 1156,
			ID_WXBUTTON1 = 1155,
			ID_WXEDIT1 = 1162,
			ID_WXSTATICTEXT5 = 1161,
			ID_LISTAMOTYWOW = 1179,
			ID_WXSTATICTEXT7 = 1178,
			ID_WXEDIT2 = 1176,
			ID_WXSTATICTEXT6 = 1174,
			ID_PANELTLO = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
