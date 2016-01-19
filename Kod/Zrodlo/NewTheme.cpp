#include "NewTheme.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
#include <wx/dcbuffer.h>
//----------------------------------------------------------------------------
// NewTheme
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(NewTheme,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(NewTheme::OnClose)
	EVT_BUTTON(ID_WXBUTTON2,NewTheme::PrzyciskAnulujClick)
	
	EVT_UPDATE_UI(ID_WXPANEL2,NewTheme::PodgladPanelUpdateUI)
	EVT_BUTTON(ID_WXBUTTON1,NewTheme::PrzyciskStworzClick)
	EVT_BUTTON(ID_WXBITMAPBUTTON8,NewTheme::PrzyciskPodloga5Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON7,NewTheme::PrzyciskPodloga4Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON6,NewTheme::PrzyciskPodloga3Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON5,NewTheme::PrzyciskPodloga2Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON4,NewTheme::PrzyciskPodloga1Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON3,NewTheme::PrzyciskPodloga0Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON2,NewTheme::PrzyciskScianyClick)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,NewTheme::PrzyciskTloClick)
END_EVENT_TABLE()
////Event Table End

NewTheme::NewTheme(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

NewTheme::~NewTheme()
{
} 

void NewTheme::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(5, 5), wxSize(499, 324));
	WxBoxSizer1->Add(WxPanel1, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxPanel1->SetSizer(WxBoxSizer2);
	WxPanel1->SetAutoLayout(true);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(WxPanel1, wxID_ANY, _(""));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxVERTICAL);
	WxBoxSizer2->Add(WxStaticBoxSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer3 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer2->Add(WxBoxSizer3, 0, wxALIGN_RIGHT | wxALIGN_TOP | wxEXPAND | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer1->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer2_StaticBoxObj = new wxStaticBox(WxPanel1, wxID_ANY, _(""));
	WxStaticBoxSizer2 = new wxStaticBoxSizer(WxStaticBoxSizer2_StaticBoxObj, wxHORIZONTAL);
	WxStaticBoxSizer1->Add(WxStaticBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	SiatkaMotyw = new wxGridSizer(0, 4, 0, 0);
	WxStaticBoxSizer2->Add(SiatkaMotyw, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskTlo_BITMAP (wxNullBitmap);
	PrzyciskTlo = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON1, PrzyciskTlo_BITMAP, wxPoint(8, 5), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskTlo"));
	SiatkaMotyw->Add(PrzyciskTlo, 0, wxALIGN_CENTER | wxALL, 0);

	wxBitmap PrzyciskSciany_BITMAP (wxNullBitmap);
	PrzyciskSciany = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON2, PrzyciskSciany_BITMAP, wxPoint(75, 5), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskSciany"));
	SiatkaMotyw->Add(PrzyciskSciany, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga0_BITMAP (wxNullBitmap);
	PrzyciskPodloga0 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON3, PrzyciskPodloga0_BITMAP, wxPoint(142, 5), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga0"));
	SiatkaMotyw->Add(PrzyciskPodloga0, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga1_BITMAP (wxNullBitmap);
	PrzyciskPodloga1 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON4, PrzyciskPodloga1_BITMAP, wxPoint(209, 5), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga1"));
	SiatkaMotyw->Add(PrzyciskPodloga1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT1, _("Tło"), wxPoint(23, 80), wxDefaultSize, 0, _("WxStaticText1"));
	SiatkaMotyw->Add(WxStaticText1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT2, _("Ściany"), wxPoint(81, 80), wxDefaultSize, 0, _("WxStaticText2"));
	SiatkaMotyw->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, _("Podłoga 0"), wxPoint(139, 80), wxDefaultSize, 0, _("WxStaticText3"));
	SiatkaMotyw->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT4, _("Podłoga 1"), wxPoint(206, 80), wxDefaultSize, 0, _("WxStaticText4"));
	SiatkaMotyw->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga2_BITMAP (wxNullBitmap);
	PrzyciskPodloga2 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON5, PrzyciskPodloga2_BITMAP, wxPoint(8, 125), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga2"));
	SiatkaMotyw->Add(PrzyciskPodloga2, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga3_BITMAP (wxNullBitmap);
	PrzyciskPodloga3 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON6, PrzyciskPodloga3_BITMAP, wxPoint(75, 125), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga3"));
	SiatkaMotyw->Add(PrzyciskPodloga3, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga4_BITMAP (wxNullBitmap);
	PrzyciskPodloga4 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON7, PrzyciskPodloga4_BITMAP, wxPoint(142, 125), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga4"));
	SiatkaMotyw->Add(PrzyciskPodloga4, 0, wxALIGN_CENTER | wxALL, 5);

	wxBitmap PrzyciskPodloga5_BITMAP (wxNullBitmap);
	PrzyciskPodloga5 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON8, PrzyciskPodloga5_BITMAP, wxPoint(209, 125), wxSize(50, 50), wxBU_AUTODRAW, wxDefaultValidator, _("PrzyciskPodloga5"));
	SiatkaMotyw->Add(PrzyciskPodloga5, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText9 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT9, _("Podłoga 2"), wxPoint(5, 200), wxDefaultSize, 0, _("WxStaticText9"));
	SiatkaMotyw->Add(WxStaticText9, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText10 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT10, _("Podłoga 3"), wxPoint(72, 200), wxDefaultSize, 0, _("WxStaticText10"));
	SiatkaMotyw->Add(WxStaticText10, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText11 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT11, _("Podłoga 4"), wxPoint(139, 200), wxDefaultSize, 0, _("WxStaticText11"));
	SiatkaMotyw->Add(WxStaticText11, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText12 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT12, _("Podłoga 5"), wxPoint(206, 200), wxDefaultSize, 0, _("WxStaticText12"));
	SiatkaMotyw->Add(WxStaticText12, 0, wxALIGN_CENTER | wxALL, 5);

	Nazwa = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _("Nazwa Motywu"), wxPoint(5, 7), wxSize(121, 19), 0, wxDefaultValidator, _("Nazwa"));
	WxBoxSizer4->Add(Nazwa, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer5 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer3->Add(WxBoxSizer5, 0, wxALIGN_TOP | wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	PrzyciskStworz = new wxButton(WxPanel1, ID_WXBUTTON1, _("Stwórz"), wxPoint(5, 5), wxSize(90, 25), 0, wxDefaultValidator, _("PrzyciskStworz"));
	WxBoxSizer5->Add(PrzyciskStworz, 0, wxALIGN_CENTER | wxALL, 5);

	wxStaticBox* WxStaticBoxSizer3_StaticBoxObj = new wxStaticBox(WxPanel1, wxID_ANY, _(""));
	WxStaticBoxSizer3 = new wxStaticBoxSizer(WxStaticBoxSizer3_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer3->Add(WxStaticBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	PodgladPanel = new wxPanel(WxPanel1, ID_WXPANEL2, wxPoint(5, 15), wxSize(150, 150));
	WxStaticBoxSizer3->Add(PodgladPanel, 0, wxALIGN_CENTER | wxALL, 0);

	WyborKoloru =  new wxColourDialog(this);

	PrzyciskAnuluj = new wxButton(WxPanel1, ID_WXBUTTON2, _("Anuluj"), wxPoint(5, 40), wxSize(90, 25), 0, wxDefaultValidator, _("PrzyciskAnuluj"));
	WxBoxSizer5->Add(PrzyciskAnuluj, 0, wxALIGN_CENTER | wxALL, 5);

	wxArrayString arrayStringFor_ListaMotywowGlownych;
	arrayStringFor_ListaMotywowGlownych.Add(_("Winter"));
	arrayStringFor_ListaMotywowGlownych.Add(_("Forest"));
	arrayStringFor_ListaMotywowGlownych.Add(_("Desert"));
	arrayStringFor_ListaMotywowGlownych.Add(_("Cottage"));
	arrayStringFor_ListaMotywowGlownych.Add(_("Dungeon"));
	ListaMotywowGlownych = new wxChoice(WxPanel1, ID_LISTAMOTYWOWGLOWNYCH, wxPoint(136, 5), wxSize(104, 23), arrayStringFor_ListaMotywowGlownych, 0, wxDefaultValidator, _("ListaMotywowGlownych"));
	ListaMotywowGlownych->SetSelection(0);
	WxBoxSizer4->Add(ListaMotywowGlownych, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("Tworzenie motywu"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

void NewTheme::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * PrzyciskTloClick
 */
void NewTheme::PrzyciskTloClick(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		PrzyciskTlo->SetBackgroundColour(WyborKoloru->GetColourData().GetColour());
	}
}

/*
 * PrzyciskScianyClick
 */
void NewTheme::PrzyciskScianyClick(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		PrzyciskSciany->SetBackgroundColour(WyborKoloru->GetColourData().GetColour());
	}
}

/*
 * PrzyciskPodloga0Click
 */
void NewTheme::PrzyciskPodloga0Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		PrzyciskPodloga0->SetBackgroundColour(WyborKoloru->GetColourData().GetColour());
	}
}

/*
 * PrzyciskPodloga1Click
 */
void NewTheme::PrzyciskPodloga1Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		PrzyciskPodloga1->SetBackgroundColour(WyborKoloru->GetColourData().GetColour());
	}
}

/*
 * PrzyciskPodloga2Click
 */
void NewTheme::PrzyciskPodloga2Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		PrzyciskPodloga2->SetBackgroundColour(WyborKoloru->GetColourData().GetColour());
	}
}

/*
 * PrzyciskPodloga3Click
 */
void NewTheme::PrzyciskPodloga3Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		PrzyciskPodloga3->SetBackgroundColour(WyborKoloru->GetColourData().GetColour());
	}
}

/*
 * PrzyciskPodloga4Click
 */
void NewTheme::PrzyciskPodloga4Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		PrzyciskPodloga4->SetBackgroundColour(WyborKoloru->GetColourData().GetColour());
	}
}

/*
 * PrzyciskPodloga5Click
 */
void NewTheme::PrzyciskPodloga5Click(wxCommandEvent& event)
{
	if(WyborKoloru->ShowModal() ==	wxID_OK){	
		PrzyciskPodloga5->SetBackgroundColour(WyborKoloru->GetColourData().GetColour());
	}
}

/*
 * PodgladPanelUpdateUI
 */
void NewTheme::PodgladPanelUpdateUI(wxUpdateUIEvent& event)
{
	wxClientDC dc1(PodgladPanel);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(PrzyciskTlo->GetBackgroundColour());
	dc.Clear();
	dc.SetPen(wxColour("black"));
	dc.SetBrush(PrzyciskSciany->GetBackgroundColour());
	dc.DrawRectangle(10, 30, 130, 90);	
	dc.SetBrush(PrzyciskPodloga0->GetBackgroundColour());
	dc.DrawRectangle(20, 40, 30, 30);
	dc.SetBrush(PrzyciskPodloga1->GetBackgroundColour());
	dc.DrawRectangle(60, 40, 30, 30);
	dc.SetBrush(PrzyciskPodloga2->GetBackgroundColour());
	dc.DrawRectangle(100, 40, 30, 30);	
	dc.SetBrush(PrzyciskPodloga3->GetBackgroundColour());
	dc.DrawRectangle(20, 80, 30, 30);
	dc.SetBrush(PrzyciskPodloga4->GetBackgroundColour());
	dc.DrawRectangle(60, 80, 30, 30);
	dc.SetBrush(PrzyciskPodloga5->GetBackgroundColour());
	dc.DrawRectangle(100, 80, 30, 30);		
}

/*
 * PrzyciskStworzClick
 */
void NewTheme::PrzyciskStworzClick(wxCommandEvent& event)
{
	EndModal(wxID_OK);
}

/*
 * PrzyciskAnulujClick
 */
void NewTheme::PrzyciskAnulujClick(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}

wxString NewTheme::getName(){
	return Nazwa->GetValue();
}
int NewTheme::getMainTheme(){
	return ListaMotywowGlownych->GetCurrentSelection();
}
wxColour NewTheme::getBackground(){
	return PrzyciskTlo->GetBackgroundColour();	
}
wxColour NewTheme::getWalls(){
	return PrzyciskSciany->GetBackgroundColour();	
}
wxColour NewTheme::getFloor0(){
	return PrzyciskPodloga0->GetBackgroundColour();	
}
wxColour NewTheme::getFloor1(){
	return PrzyciskPodloga1->GetBackgroundColour();	
}
wxColour NewTheme::getFloor2(){
	return PrzyciskPodloga2->GetBackgroundColour();	
}
wxColour NewTheme::getFloor3(){
	return PrzyciskPodloga3->GetBackgroundColour();	
}
wxColour NewTheme::getFloor4(){
	return PrzyciskPodloga4->GetBackgroundColour();	
}
wxColour NewTheme::getFloor5(){
	return PrzyciskPodloga5->GetBackgroundColour();	
}
