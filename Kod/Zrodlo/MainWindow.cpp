#include "MainWindow.h"
#include <wx/aboutdlg.h> 
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
#include <wx/dcbuffer.h>
#include "DefaultThemes.h"
#include "FileTMWriter.h"
#include "FileTMReader.h"
#include "NewTheme.h"
//----------------------------------------------------------------------------
// MainWindow
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(MainWindow,wxFrame)
	////Manual Code Start
	//EVT_MOTION(MainWindow::ruchMysza)
	////Manual Code End
	
	EVT_CLOSE(MainWindow::OnClose)
	EVT_SIZE(MainWindow::MainWindowSize0)
	EVT_MENU(ID_MNU__NOWY_1159, MainWindow::MenuNowyClick)
	EVT_MENU(ID_MNU_OTW_RZ_1181, MainWindow::MenuOtworzClick)
	EVT_MENU(ID_MNU_SUBMENUITEM8_1184, MainWindow::MenuZapiszClick)
	EVT_MENU(ID_MNU_WCZYTAJMOTYW_1187, MainWindow::MenuWczytajMotywClick)
	EVT_MENU(ID_MNU_ZAPISZMOTYW_1188, MainWindow::MenuZapiszMotywClick)
	EVT_MENU(ID_MNU_STW_RZMOTYW_1199, MainWindow::MenuStworzMotywClick)
	
	EVT_UPDATE_UI(ID_PanelEdytor,MainWindow::PanelEdytorUpdateUI)
	EVT_BUTTON(ID_WXBITMAPBUTTON8,MainWindow::PrzyciskPodloga5Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON7,MainWindow::PrzyciskPodloga4Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON6,MainWindow::PrzyciskPodloga3Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON5,MainWindow::PrzyciskPodloga2Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON4,MainWindow::PrzyciskPodloga1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON3,MainWindow::PrzyciskPodloga0Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON2,MainWindow::PrzyciskScianyClick)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,MainWindow::PrzyciskTloClick)
	EVT_CHOICE(ID_WXCHOICE1,MainWindow::ListaMotywowGlownychSelected)
	EVT_BUTTON(ID_WXBUTTON1,MainWindow::PrzyciskZapiszMotywClick)
	
	EVT_TEXT(ID_WXEDIT1,MainWindow::NazwaMotywuUpdated)
	EVT_CHOICE(ID_LISTAMOTYWOW,MainWindow::ListaMotywowSelected)
	
	EVT_TEXT(ID_WXEDIT2,MainWindow::NazwaPoziomuUpdated)
END_EVENT_TABLE()
////Event Table End




MainWindow::MainWindow(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{

	CreateGUIControls();
}

MainWindow::~MainWindow()
{
//	
}

void MainWindow::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	GlownySizer = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(GlownySizer);
	this->SetAutoLayout(true);

	PanelTlo = new wxPanel(this, ID_PANELTLO, wxPoint(0, 0), wxSize(830, 600));
	GlownySizer->Add(PanelTlo, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	GlownySizer2 = new wxBoxSizer(wxHORIZONTAL);
	PanelTlo->SetSizer(GlownySizer2);
	PanelTlo->SetAutoLayout(true);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(PanelTlo, wxID_ANY, _(""));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxVERTICAL);
	GlownySizer2->Add(WxStaticBoxSizer1, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 5);

	SizerMenuParametry = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer1->Add(SizerMenuParametry, 0, wxALIGN_CENTER | wxALL, 5);

	WxGridSizer2 = new wxGridSizer(0, 2, 0, 0);
	SizerMenuParametry->Add(WxGridSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText6 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT6, _("Nazwa poziomu"), wxPoint(21, 7), wxDefaultSize, 0, _("WxStaticText6"));
	WxGridSizer2->Add(WxStaticText6, 0, wxALIGN_CENTER | wxALL, 5);

	NazwaPoziomu = new wxTextCtrl(PanelTlo, ID_WXEDIT2, _(""), wxPoint(136, 7), wxSize(121, 19), 0, wxDefaultValidator, _("NazwaPoziomu"));
	WxGridSizer2->Add(NazwaPoziomu, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText7 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT7, _("Motyw"), wxPoint(45, 40), wxDefaultSize, 0, _("WxStaticText7"));
	WxGridSizer2->Add(WxStaticText7, 0, wxALIGN_CENTER | wxALL, 5);

	wxArrayString arrayStringFor_ListaMotywow;
	ListaMotywow = new wxChoice(PanelTlo, ID_LISTAMOTYWOW, wxPoint(136, 38), wxSize(120, 23), arrayStringFor_ListaMotywow, 0, wxDefaultValidator, _("ListaMotywow"));
	ListaMotywow->SetSelection(-1);
	WxGridSizer2->Add(ListaMotywow, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer3_StaticBoxObj = new wxStaticBox(PanelTlo, wxID_ANY, _("Ustawienia motywu"));
	WxStaticBoxSizer3 = new wxStaticBoxSizer(WxStaticBoxSizer3_StaticBoxObj, wxVERTICAL);
	WxStaticBoxSizer1->Add(WxStaticBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer3->Add(WxBoxSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText5 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT5, _("Nazwa motywu"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticText5"));
	WxBoxSizer1->Add(WxStaticText5, 0, wxALIGN_CENTER | wxALL, 5);

	NazwaMotywu = new wxTextCtrl(PanelTlo, ID_WXEDIT1, _("NazwaMotywu"), wxPoint(101, 5), wxSize(125, 19), 0, wxDefaultValidator, _("NazwaMotywu"));
	WxBoxSizer1->Add(NazwaMotywu, 0, wxALIGN_CENTER | wxALL, 5);

	WxGridSizer1 = new wxGridSizer(0, 2, 0, 0);
	WxStaticBoxSizer3->Add(WxGridSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	PrzyciskZapiszMotyw = new wxButton(PanelTlo, ID_WXBUTTON1, _("Zapisz motyw"), wxPoint(12, 5), wxSize(89, 25), 0, wxDefaultValidator, _("PrzyciskZapiszMotyw"));
	WxGridSizer1->Add(PrzyciskZapiszMotyw, 0, wxALIGN_CENTER | wxALL, 5);

	wxArrayString arrayStringFor_ListaMotywowGlownych;
	arrayStringFor_ListaMotywowGlownych.Add(_("Winter"));
	arrayStringFor_ListaMotywowGlownych.Add(_("Forest"));
	arrayStringFor_ListaMotywowGlownych.Add(_("Desert"));
	arrayStringFor_ListaMotywowGlownych.Add(_("Cottage"));
	arrayStringFor_ListaMotywowGlownych.Add(_("Dungeon"));
	ListaMotywowGlownych = new wxChoice(PanelTlo, ID_WXCHOICE1, wxPoint(119, 6), wxSize(104, 23), arrayStringFor_ListaMotywowGlownych, 0, wxDefaultValidator, _("ListaMotywowGlownych"));
	ListaMotywowGlownych->SetSelection(-1);
	WxGridSizer1->Add(ListaMotywowGlownych, 0, wxALIGN_CENTER | wxALL, 5);

	SiatkaMotyw = new wxGridSizer(0, 4, 0, 0);
	WxStaticBoxSizer3->Add(SiatkaMotyw, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskTlo_BITMAP (wxNullBitmap);
	PrzyciskTlo = new wxBitmapButton(PanelTlo, ID_WXBITMAPBUTTON1, PrzyciskTlo_BITMAP, wxPoint(8, 5), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskTlo"));
	SiatkaMotyw->Add(PrzyciskTlo, 0, wxALIGN_CENTER | wxALL, 0);

	wxBitmap PrzyciskSciany_BITMAP (wxNullBitmap);
	PrzyciskSciany = new wxBitmapButton(PanelTlo, ID_WXBITMAPBUTTON2, PrzyciskSciany_BITMAP, wxPoint(75, 5), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskSciany"));
	SiatkaMotyw->Add(PrzyciskSciany, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga0_BITMAP (wxNullBitmap);
	PrzyciskPodloga0 = new wxBitmapButton(PanelTlo, ID_WXBITMAPBUTTON3, PrzyciskPodloga0_BITMAP, wxPoint(142, 5), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga0"));
	SiatkaMotyw->Add(PrzyciskPodloga0, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga1_BITMAP (wxNullBitmap);
	PrzyciskPodloga1 = new wxBitmapButton(PanelTlo, ID_WXBITMAPBUTTON4, PrzyciskPodloga1_BITMAP, wxPoint(209, 5), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga1"));
	SiatkaMotyw->Add(PrzyciskPodloga1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT1, _("Tło"), wxPoint(23, 80), wxDefaultSize, 0, _("WxStaticText1"));
	SiatkaMotyw->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT2, _("Ściany"), wxPoint(81, 80), wxDefaultSize, 0, _("WxStaticText2"));
	SiatkaMotyw->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT3, _("Podłoga 0"), wxPoint(139, 80), wxDefaultSize, 0, _("WxStaticText3"));
	SiatkaMotyw->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT4, _("Podłoga 1"), wxPoint(206, 80), wxDefaultSize, 0, _("WxStaticText4"));
	SiatkaMotyw->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga2_BITMAP (wxNullBitmap);
	PrzyciskPodloga2 = new wxBitmapButton(PanelTlo, ID_WXBITMAPBUTTON5, PrzyciskPodloga2_BITMAP, wxPoint(8, 125), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga2"));
	SiatkaMotyw->Add(PrzyciskPodloga2, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga3_BITMAP (wxNullBitmap);
	PrzyciskPodloga3 = new wxBitmapButton(PanelTlo, ID_WXBITMAPBUTTON6, PrzyciskPodloga3_BITMAP, wxPoint(75, 125), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga3"));
	SiatkaMotyw->Add(PrzyciskPodloga3, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga4_BITMAP (wxNullBitmap);
	PrzyciskPodloga4 = new wxBitmapButton(PanelTlo, ID_WXBITMAPBUTTON7, PrzyciskPodloga4_BITMAP, wxPoint(142, 125), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga4"));
	SiatkaMotyw->Add(PrzyciskPodloga4, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga5_BITMAP (wxNullBitmap);
	PrzyciskPodloga5 = new wxBitmapButton(PanelTlo, ID_WXBITMAPBUTTON8, PrzyciskPodloga5_BITMAP, wxPoint(209, 125), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga5"));
	SiatkaMotyw->Add(PrzyciskPodloga5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText9 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT9, _("Podłoga 2"), wxPoint(5, 200), wxDefaultSize, 0, _("WxStaticText9"));
	SiatkaMotyw->Add(WxStaticText9, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText10 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT10, _("Podłoga 3"), wxPoint(72, 200), wxDefaultSize, 0, _("WxStaticText10"));
	SiatkaMotyw->Add(WxStaticText10, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText11 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT11, _("Podłoga 4"), wxPoint(139, 200), wxDefaultSize, 0, _("WxStaticText11"));
	SiatkaMotyw->Add(WxStaticText11, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText12 = new wxStaticText(PanelTlo, ID_WXSTATICTEXT12, _("Podłoga 5"), wxPoint(206, 200), wxDefaultSize, 0, _("WxStaticText12"));
	SiatkaMotyw->Add(WxStaticText12, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer4_StaticBoxObj = new wxStaticBox(PanelTlo, wxID_ANY, _("Ustawienia kształtów"));
	WxStaticBoxSizer4 = new wxStaticBoxSizer(WxStaticBoxSizer4_StaticBoxObj, wxHORIZONTAL);
	WxStaticBoxSizer1->Add(WxStaticBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	SiatkaKsztalty = new wxGridSizer(0, 3, 0, 0);
	WxStaticBoxSizer4->Add(SiatkaKsztalty, 0, wxALIGN_CENTER | wxALL, 5);

	PanelKsztalt1 = new wxPanel(PanelTlo, ID_PANELKSZTALT1, wxPoint(5, 5), wxSize(40, 40));
	SiatkaKsztalty->Add(PanelKsztalt1, 0, wxALIGN_CENTER | wxALL, 5);

	PanelKsztalt2 = new wxPanel(PanelTlo, ID_PANELKSZTALT2, wxPoint(55, 5), wxSize(40, 40));
	SiatkaKsztalty->Add(PanelKsztalt2, 0, wxALIGN_CENTER | wxALL, 5);

	PanelKsztalt3 = new wxPanel(PanelTlo, ID_PANELKSZTALT3, wxPoint(105, 5), wxSize(40, 40));
	SiatkaKsztalty->Add(PanelKsztalt3, 0, wxALIGN_CENTER | wxALL, 5);

	PanelKsztalt4 = new wxPanel(PanelTlo, ID_PANELKSZTALT4, wxPoint(5, 55), wxSize(40, 40));
	SiatkaKsztalty->Add(PanelKsztalt4, 0, wxALIGN_CENTER | wxALL, 5);

	PanelKsztalt5 = new wxPanel(PanelTlo, ID_PANELKSZTALT5, wxPoint(55, 55), wxSize(40, 40));
	SiatkaKsztalty->Add(PanelKsztalt5, 0, wxALIGN_CENTER | wxALL, 5);

	PanelKsztalt6 = new wxPanel(PanelTlo, ID_PANELKSZTALT6, wxPoint(105, 55), wxSize(40, 40));
	SiatkaKsztalty->Add(PanelKsztalt6, 0, wxALIGN_CENTER | wxALL, 5);

	PanelKsztalt7 = new wxPanel(PanelTlo, ID_PANELKSZTALT7, wxPoint(5, 105), wxSize(40, 40));
	SiatkaKsztalty->Add(PanelKsztalt7, 0, wxALIGN_CENTER | wxALL, 5);

	WxSpinCtrl1 = new wxSpinCtrl(PanelTlo, ID_WXSPINCTRL1, _("5"), wxPoint(160, 78), wxSize(40, 24), wxSP_ARROW_KEYS, 3, 7, 5);
	WxStaticBoxSizer4->Add(WxSpinCtrl1, 0, wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer2_StaticBoxObj = new wxStaticBox(PanelTlo, wxID_ANY, _(""));
	WxStaticBoxSizer2 = new wxStaticBoxSizer(WxStaticBoxSizer2_StaticBoxObj, wxHORIZONTAL);
	GlownySizer2->Add(WxStaticBoxSizer2, 1, wxALIGN_RIGHT | wxALIGN_TOP | wxALIGN_BOTTOM | wxALIGN_CENTER_VERTICAL | wxEXPAND | wxRIGHT | wxTOP | wxBOTTOM, 5);

	PanelEdytor = new CustomPanelEditor(PanelTlo, ID_PanelEdytor, wxPoint(10, 20), wxSize(500, 41));
	PanelEdytor->SetBackgroundColour(wxColour(_("WHITE")));
	WxStaticBoxSizer2->Add(PanelEdytor, 1, wxALIGN_RIGHT | wxALIGN_TOP | wxALIGN_BOTTOM | wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxStatusBar1 = new wxStatusBar(this, ID_WXSTATUSBAR1);
	WxStatusBar1->SetFieldsCount(3);
	WxStatusBar1->SetStatusText(_("Pozycja"),0);
	WxStatusBar1->SetStatusText(_("(x, y)"),1);
	WxStatusBar1->SetStatusText(_(""),2);
	int WxStatusBar1_Widths[3];
	WxStatusBar1_Widths[0] = 100;
	WxStatusBar1_Widths[1] = 100;
	WxStatusBar1_Widths[2] = -1;
	WxStatusBar1->SetStatusWidths(3,WxStatusBar1_Widths);

	WyborKoloru =  new wxColourDialog(this);

	WxOpenFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_PLIK_1157_Mnu_Obj = new wxMenu();
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU__NOWY_1159, _("&Nowy\tCtrl+N"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_OTW_RZ_1181, _("&Otwórz\tCtrl+O"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->AppendSeparator();
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_SUBMENUITEM8_1184, _("Zapi&sz\tCtrl+S"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_ZAPISZJAKO_1185, _("Zapisz Jako"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->Enable(ID_MNU_ZAPISZJAKO_1185,false);
	ID_MNU_PLIK_1157_Mnu_Obj->AppendSeparator();
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_WCZYTAJMOTYW_1187, _("Wczytaj motyw"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_ZAPISZMOTYW_1188, _("Zapisz motyw"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_WCZYTAJKSZTA_T_1189, _("Importuj kształt"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->Enable(ID_MNU_WCZYTAJKSZTA_T_1189,false);
	ID_MNU_PLIK_1157_Mnu_Obj->AppendSeparator();
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_SUBMENUITEM16_1192, _("Importuj mapę z chmury"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->Enable(ID_MNU_SUBMENUITEM16_1192,false);
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_EKSPORTUJMAPENACHMUR__1193, _("Eksportuj mape na chmurę"), _(""), wxITEM_NORMAL);
	ID_MNU_PLIK_1157_Mnu_Obj->Enable(ID_MNU_EKSPORTUJMAPENACHMUR__1193,false);
	ID_MNU_PLIK_1157_Mnu_Obj->AppendSeparator();
	ID_MNU_PLIK_1157_Mnu_Obj->Append(ID_MNU_WYJ_CIE_1195, _("Wyjście\tCtrl+&X"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_PLIK_1157_Mnu_Obj, _("Plik"));
	
	wxMenu *ID_MNU_EDYCJA_1158_Mnu_Obj = new wxMenu();
	ID_MNU_EDYCJA_1158_Mnu_Obj->Append(ID_MNU_COFNIJ_1196, _("Cofnij\tCtrl+&Z"), _(""), wxITEM_NORMAL);
	ID_MNU_EDYCJA_1158_Mnu_Obj->Enable(ID_MNU_COFNIJ_1196,false);
	ID_MNU_EDYCJA_1158_Mnu_Obj->Append(ID_MNU_PON_W_1197, _("Ponów\tCtrl+&Y"), _(""), wxITEM_NORMAL);
	ID_MNU_EDYCJA_1158_Mnu_Obj->Enable(ID_MNU_PON_W_1197,false);
	ID_MNU_EDYCJA_1158_Mnu_Obj->AppendSeparator();
	ID_MNU_EDYCJA_1158_Mnu_Obj->Append(ID_MNU_STW_RZMOTYW_1199, _("Stwórz motyw"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_EDYCJA_1158_Mnu_Obj, _("Edycja"));
	SetMenuBar(WxMenuBar1);

	WxSaveFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);

	SetStatusBar(WxStatusBar1);
	SetTitle(_("Twisted Mind Editor"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	PanelEdytor->Bind(wxEVT_MOTION, &CustomPanelEditor::mouseMove, PanelEdytor);
	PanelEdytor->Bind(wxEVT_LEFT_DOWN, &CustomPanelEditor::mouseLDown, PanelEdytor);
	PanelEdytor->Bind(wxEVT_LEFT_UP, &CustomPanelEditor::mouseLUp, PanelEdytor);
	PanelEdytor->Bind(wxEVT_RIGHT_UP, &CustomPanelEditor::mouseRUp, PanelEdytor);
	PanelEdytor->Bind(wxEVT_RIGHT_DOWN, &CustomPanelEditor::mouseRDown, PanelEdytor);
	PanelEdytor->Bind(wxEVT_MOUSEWHEEL, &CustomPanelEditor::mouseWheel, PanelEdytor);
	
	Level *lvl = new Level(0, 0);
	PanelEdytor->setLevel(lvl);
	ListaMotywowGlownych->Select(0);
	
	loadPremadeThm();
	for(int i = 0; i < num_thm; ++i){
		ListaMotywow->Append(mainthm[i].getName());
	}
	ListaMotywow->Append("Wczytaj...");
	ListaMotywow->Append("Nowy...");
	_userthm = NULL;
	NazwaPoziomu->SetLabel(lvl->getName());
	NazwaMotywu->SetLabel(lvl->getTheme().getName());
}

void MainWindow::OnClose(wxCloseEvent& event)
{
	if(_userthm != NULL)
		delete _userthm;
	Destroy();
}

/*
 * PanelEdytorUpdateUI
 */
void MainWindow::PanelEdytorUpdateUI(wxUpdateUIEvent& event)
{
	wxClientDC dc1(PanelEdytor);
	wxBufferedDC dc(&dc1);
	MapImage& img = PanelEdytor->getMapImage();
	Level* map = PanelEdytor->getLevel();
	Board& brd = map->getBoard();
	wxMenuItem* save = WxMenuBar1->FindItem(ID_MNU_SUBMENUITEM8_1184);
	if (map != NULL){		
		int w, h;
		PanelEdytor->GetSize(&w, &h);
		img.setImgSize(w, h);
		if(map->getBoard().isValid()){
			img.drawMap(*map, dc);			
			save->Enable(true);
		}
		else{
			dc.SetBackground(wxBrush(wxColour(RGB(255, 255, 255))));
			dc.Clear();
			save->Enable(false);
		}
	}
	else{
		save->Enable(false);		
	}
	wxString str = "Pozycja: ";
	str << PanelEdytor->getMouseX() << ", " << PanelEdytor->getMouseY();
	WxStatusBar1->SetStatusText(str, 0);
	str = "Aktywny: ";
	wxString str2 = "Wartość: ";
	if(img.getActiveX() == -1){
		str << "brak";
		str2 << "N/A";
	}
	else{
		str << "[" << img.getActiveX() << "][" << img.getActiveY() << "]";
		str2  << brd(img.getActiveX(), img.getActiveY());
	}
	WxStatusBar1->SetStatusText(str, 1);
	WxStatusBar1->SetStatusText(str2, 2);

	zaladujMotyw(map->getTheme());	

}

/*
 * PrzyciskTloClick
 */
void MainWindow::PrzyciskTloClick(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.loadBackground(WyborKoloru->GetColourData().GetColour());
		PrzyciskSciany->SetBackgroundColour(thm.getWalls());
		thm.isDefault = false;	
	}
}

/*
 * PrzyciskScianyClick
 */
void MainWindow::PrzyciskScianyClick(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.loadWalls(WyborKoloru->GetColourData().GetColour());
		PrzyciskSciany->SetBackgroundColour(thm.getWalls());
		thm.isDefault = false;	
	}
}

/*
 * PrzyciskPodloga0Click
 */
void MainWindow::PrzyciskPodloga0Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.loadFloor(0, WyborKoloru->GetColourData().GetColour());
		PrzyciskPodloga0->SetBackgroundColour(thm.getFloor(0));
		thm.isDefault = false;	
	}
}

/*
 * PrzyciskPodloga1Click
 */
void MainWindow::PrzyciskPodloga1Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.loadFloor(1, WyborKoloru->GetColourData().GetColour());
		PrzyciskPodloga1->SetBackgroundColour(thm.getFloor(1));	
		thm.isDefault = false;	
	}
}

/*
 * PrzyciskPodloga2Click
 */
void MainWindow::PrzyciskPodloga2Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.loadFloor(2, WyborKoloru->GetColourData().GetColour());
		PrzyciskPodloga2->SetBackgroundColour(thm.getFloor(2));
		thm.isDefault = false;
	}
}

/*
 * PrzyciskPodloga3Click
 */
void MainWindow::PrzyciskPodloga3Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.loadFloor(3, WyborKoloru->GetColourData().GetColour());
		PrzyciskPodloga3->SetBackgroundColour(thm.getFloor(3));	
		thm.isDefault = false;
	}
}

/*
 * PrzyciskPodloga4Click
 */
void MainWindow::PrzyciskPodloga4Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.loadFloor(4, WyborKoloru->GetColourData().GetColour());
		PrzyciskPodloga4->SetBackgroundColour(thm.getFloor(4));
		thm.isDefault = false;
	}
}

/*
 * PrzyciskPodloga5Click
 */
void MainWindow::PrzyciskPodloga5Click(wxCommandEvent& event)
{
	
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.loadFloor(5, WyborKoloru->GetColourData().GetColour());
		PrzyciskPodloga5->SetBackgroundColour(thm.getFloor(5));
		thm.isDefault = false;	
	}
}


void MainWindow::zaladujMotyw(Theme &thm){
	PrzyciskTlo->SetBackgroundColour(thm.getBackground());
	PrzyciskSciany->SetBackgroundColour(thm.getWalls());	
	PrzyciskPodloga0->SetBackgroundColour(thm.getFloor(0));
	PrzyciskPodloga1->SetBackgroundColour(thm.getFloor(1));
	PrzyciskPodloga2->SetBackgroundColour(thm.getFloor(2));
	PrzyciskPodloga3->SetBackgroundColour(thm.getFloor(3));
	PrzyciskPodloga4->SetBackgroundColour(thm.getFloor(4));
	PrzyciskPodloga5->SetBackgroundColour(thm.getFloor(5));
}

void MainWindow::MenuNowyClick(wxCommandEvent& event){
	NewFile nowy(NULL);
	for(int i = 0; i < num_thm; ++i)
		nowy.getThemeChoice()->Append(mainthm[i].getName());
		if(_userthm != NULL)
			nowy.getThemeChoice()->Append(_userthm->getName());
		nowy.getThemeChoice()->Append("Wczytaj...");
		nowy.getThemeChoice()->Append("Nowy...");
		if(nowy.ShowModal() == wxID_OK){
		PanelEdytor->getLevel()->setName(nowy.getLevelName());
		Board& brd = PanelEdytor->getLevel()->getBoard();
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		int w, h;
		nowy.getSize(w, h);
		brd.resize(0, 0);
		brd.resize(w, h);
 		wxChoice* choice = nowy.getThemeChoice();
 		int ind = choice->GetCurrentSelection();
 		if(ind < choice->GetCount() - 2){
			if(ind == choice->GetCount() - 3 && _userthm != NULL){
				thm = *_userthm;
			}
			else{
				thm = mainthm[ind];
				thm.isDefault = true;
			}
		}
		else if(ind == choice->GetCount() - 2){
			
		}
		ListaMotywow->SetSelection(ind);
		zaladujMotyw(thm);                  
		MapImage& img = PanelEdytor->getMapImage();
		img.calculateRatio();		
		img.adjustParameters(*PanelEdytor->getLevel());
		img.setCamera(0, 0);
		img.setZoom(1);
		
		NazwaPoziomu->SetLabel(PanelEdytor->getLevel()->getName());	
		NazwaMotywu->SetLabel(thm.getName());
		ListaMotywowGlownych->SetSelection(thm.getTheme());
	}
}


/*
 * MainWindowSize0
 */
void MainWindow::MainWindowSize0(wxSizeEvent& event)
{	
	MapImage& img = PanelEdytor->getMapImage();		
	int w, h;
	PanelEdytor->GetSize(&w, &h);
	img.setImgSize(w, h);
	img.calculateRatio();
	event.Skip();
}

/*
 * ListaMotywowSelected
 */
void MainWindow::ListaMotywowSelected(wxCommandEvent& event )
{
	Theme& thm = PanelEdytor->getLevel()->getTheme();
	int ind = ListaMotywow->GetCurrentSelection();
	if(ind < ListaMotywow->GetCount() - 2){
		if(ind == ListaMotywow->GetCount() - 3 && _userthm != NULL){
			thm = *_userthm;
			thm.isDefault = false;
		}
		else{
			thm = mainthm[ind];
			thm.isDefault = true;
		}
		
		NazwaMotywu->SetLabel(thm.getName());
	}
	else if(ind == ListaMotywow->GetCount() - 1){
		 MenuStworzMotywClick(event);
	}
	else if (ind == ListaMotywow->GetCount() - 2){
		MenuWczytajMotywClick(event);	
	}
	zaladujMotyw(thm);
	NazwaMotywu->SetLabel(thm.getName());
	ListaMotywowGlownych->SetSelection(thm.getTheme());
}

/*
 * NazwaPoziomuUpdated
 */
void MainWindow::NazwaPoziomuUpdated(wxCommandEvent& event)
{
	PanelEdytor->getLevel()->setName(NazwaPoziomu->GetValue());

}

/*
 * PrzyciskZapiszMotywClick
 */
void MainWindow::PrzyciskZapiszMotywClick(wxCommandEvent& event)
{
	bool zlanazwa = false;;
	for(int i = 0; i < num_thm; ++i){
		if(mainthm[i].getName() == PanelEdytor->getLevel()->getTheme().getName()){
			zlanazwa = true;
		}
	}
	bool pusta = false;
	if(PanelEdytor->getLevel()->getTheme().getName() == "")
		pusta = true;
	if(zlanazwa){
		wxMessageBox(wxString("Nazwa motywu musi być różna od nazwy domyślnego motywu."), wxString("Błąd zapisu"));
	}
	else if(pusta){
		wxMessageBox(wxString("Nazwa motywu nie może być pusta"), wxString("Błąd zapisu"));
	}
	else{
		/*
		try{
			if (WxSaveFileDialog1->ShowModal() == wxID_CANCEL){
				return;
			}
			FileTMWriter f(string(WxSaveFileDialog1->GetPath().mb_str()));
		}
		catch(FileException e){
			wxLogError("Nie można zapisać motywu.");
		}
		*/
		
		if(_userthm ==NULL){
			_userthm = new Theme;
			ListaMotywow->Insert(PanelEdytor->getLevel()->getTheme().getName(), ListaMotywow->GetCount() - 2);
		}
		else{
			ListaMotywow->SetString(ListaMotywow->GetCount() - 3, PanelEdytor->getLevel()->getTheme().getName());
		}
		ListaMotywow->SetSelection(ListaMotywow->GetCount() - 3);
		*_userthm = PanelEdytor->getLevel()->getTheme();
	}
}

/*
 * NazwaMotywuUpdated
 */
void MainWindow::NazwaMotywuUpdated(wxCommandEvent& event)
{
	Theme& thm = PanelEdytor->getLevel()->getTheme();
	thm.setName(NazwaMotywu->GetValue());
	thm.isDefault = false;
}

/*
 * ListaMotywowGlownychSelected
 */
void MainWindow::ListaMotywowGlownychSelected(wxCommandEvent& event )
{
	Theme& thm = PanelEdytor->getLevel()->getTheme();
	thm.setTheme((Theme::main_theme)ListaMotywowGlownych->GetSelection());
	thm.isDefault = false;
}




/*
 * MenuZapiszClick
 */
void MainWindow::MenuZapiszClick(wxCommandEvent& event)
{
	Level* lvl = PanelEdytor->getLevel();
	Board& brd = lvl->getBoard();
	try{
		WxSaveFileDialog1->SetWildcard("Plik mapy TwistedMind(*.tmm)|*.tmm"); 
		if (WxSaveFileDialog1->ShowModal() == wxID_CANCEL){
			return;
		}
		FileTMWriter f(string(WxSaveFileDialog1->GetPath().mb_str()));
		f.writeMap(*lvl);
	}
	catch(FileException e){
		wxLogError("Nie można zapisać pliku.");
	}
}

/*
 * MenuOtworzClick0
 */
void MainWindow::MenuOtworzClick(wxCommandEvent& event)
{
	Level* lvl = PanelEdytor->getLevel();
	
	try{
		WxOpenFileDialog1->SetWildcard("Plik mapy TwistedMind(*.tmm)|*.tmm"); 
		if (WxOpenFileDialog1->ShowModal() == wxID_CANCEL){
			return;
		}
		FileTMReader f(string(WxOpenFileDialog1->GetPath().mb_str()));
		Level wczytany = f.readMap();
		*lvl = wczytany;
		
		Theme& thm = lvl->getTheme();
		Board& brd = lvl->getBoard();
	
		if(thm.isDefault){
			thm = mainthm[thm.getTheme()];
			ListaMotywowGlownych->SetSelection(thm.getTheme());
			ListaMotywow->SetSelection(thm.getTheme());
		}
		else{
			if(_userthm == NULL){
				_userthm = new Theme;
				ListaMotywow->Insert(thm.getName(), ListaMotywow->GetCount() - 2);
			}		
			else {

			ListaMotywow->SetString(ListaMotywow->GetCount() - 3, thm.getName());					
			}
			ListaMotywow->SetSelection(ListaMotywow->GetCount() - 3);	
			*_userthm = thm;		
		}
		zaladujMotyw(thm);
		NazwaMotywu->SetLabel(thm.getName());
		NazwaPoziomu->SetLabel(lvl->getName());
		MapImage& img = PanelEdytor->getMapImage();
		img.calculateRatio();		
		img.adjustParameters(*PanelEdytor->getLevel());
		img.setCamera(0, 0);
		img.setZoom(1);
	}
	catch(FileException e){
		wxLogError("Nie można otworzyć pliku.");
	}
	catch(exception e){
		wxLogError("Ups");		
	}
}

void MainWindow::MenuStworzMotywClick(wxCommandEvent& event){
	NewTheme nowy(NULL);
	if(nowy.ShowModal() == wxID_OK){
		Theme& thm = PanelEdytor->getLevel()->getTheme();
		thm.setName(nowy.getName());
		thm.setTheme((Theme::main_theme) nowy.getMainTheme());
		thm.loadBackground(nowy.getBackground());
		thm.loadWalls(nowy.getWalls());
		thm.loadFloor(0, nowy.getFloor0());
		thm.loadFloor(1, nowy.getFloor1());
		thm.loadFloor(2, nowy.getFloor2());
		thm.loadFloor(3, nowy.getFloor3());
		thm.loadFloor(4, nowy.getFloor4());
		thm.loadFloor(5, nowy.getFloor5());
		if(_userthm == NULL){
			_userthm = new Theme;
			ListaMotywow->Insert(thm.getName(), ListaMotywow->GetCount() - 2);
		}
		thm.isDefault = false;
		*_userthm = thm;
		ListaMotywow->SetSelection(ListaMotywow->GetCount() - 3);
		ListaMotywowGlownych->SetSelection(thm.getTheme());
		zaladujMotyw(thm);
		NazwaMotywu->SetLabel(thm.getName());
	}
}


void MainWindow::MenuZapiszMotywClick(wxCommandEvent& event){
	bool zlanazwa = false;;
	for(int i = 0; i < num_thm; ++i){
		if(mainthm[i].getName() == PanelEdytor->getLevel()->getTheme().getName()){
			zlanazwa = true;
		}
	}
	bool pusta = false;
	if(PanelEdytor->getLevel()->getTheme().getName() == "")
		pusta = true;
	if(zlanazwa){
		wxMessageBox(wxString("Nazwa motywu musi być różna od nazwy domyślnego motywu."), wxString("Błąd zapisu"));
	}
	else if(pusta){
		wxMessageBox(wxString("Nazwa motywu nie może być pusta"), wxString("Błąd zapisu"));
	}
	else{	
		Level* lvl = PanelEdytor->getLevel();
		Theme& thm = lvl->getTheme();
		try{
			WxSaveFileDialog1->SetWildcard("Plik motywu TwistedMind(*.tmt)|*.tmt"); 
			if (WxSaveFileDialog1->ShowModal() == wxID_CANCEL){
				return;
			}
			FileTMWriter f(string(WxSaveFileDialog1->GetPath().mb_str()));
			f.writeTheme(thm);
		}
		catch(FileException e){
			wxLogError("Nie można zapisać pliku.");
		}	
	}
}

void MainWindow::MenuWczytajMotywClick(wxCommandEvent& event){
	Theme& thm = PanelEdytor->getLevel()->getTheme();
	try{
		WxOpenFileDialog1->SetWildcard("Plik motywu TwistedMind(*.tmt)|*.tmt"); 
		if (WxOpenFileDialog1->ShowModal() == wxID_CANCEL){
			return;
		}
		FileTMReader f(string(WxOpenFileDialog1->GetPath().mb_str()));
		thm = f.readTheme();
		if(_userthm == NULL){
			_userthm = new Theme;
			ListaMotywow->Insert(thm.getName(), ListaMotywow->GetCount() - 2);
		}		
		else{
			ListaMotywow->SetString(ListaMotywow->GetCount() - 3, thm.getName());					
		}
		ListaMotywow->SetSelection(ListaMotywow->GetCount() - 3);	
		*_userthm = thm;		
		ListaMotywowGlownych->SetSelection(thm.getTheme());
		zaladujMotyw(thm);
		NazwaMotywu->SetLabel(thm.getName());

	}
	catch(FileException e){
		wxLogError("Nie można otworzyć pliku.");
	}
	catch(exception e){
		wxLogError("Ups");		
	}
}

