
#include "NewFile.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// NewFile
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(NewFile,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(NewFile::OnClose)
	EVT_BUTTON(ID_WXBUTTON2,NewFile::PrzyciskAnulujClick)
	EVT_BUTTON(ID_WXBUTTON1,NewFile::PrzyciskOKClick)
END_EVENT_TABLE()
////Event Table End

NewFile::NewFile(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

NewFile::~NewFile()
{
} 

void NewFile::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(388, 146));
	WxBoxSizer1->Add(WxPanel1, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxPanel1->SetSizer(WxBoxSizer2);
	WxPanel1->SetAutoLayout(true);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(WxPanel1, wxID_ANY, _(""));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer2->Add(WxStaticBoxSizer1, 1, wxALIGN_CENTER | wxALL, 1);

	WxBoxSizer3 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer2->Add(WxBoxSizer3, 0, wxALIGN_RIGHT | wxALIGN_TOP | wxALL, 5);

	PrzyciskOK = new wxButton(WxPanel1, ID_WXBUTTON1, _("Nowy"), wxPoint(5, 5), wxSize(75, 25), 0, wxDefaultValidator, _("PrzyciskOK"));
	WxBoxSizer3->Add(PrzyciskOK, 0, wxALIGN_CENTER | wxALL, 5);

	PrzyciskAnuluj = new wxButton(WxPanel1, ID_WXBUTTON2, _("Anuluj"), wxPoint(5, 40), wxSize(75, 25), 0, wxDefaultValidator, _("PrzyciskAnuluj"));
	WxBoxSizer3->Add(PrzyciskAnuluj, 0, wxALIGN_CENTER | wxALL, 5);

	WxFlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	WxStaticBoxSizer1->Add(WxFlexGridSizer1, 1, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT1, _("Nazwa poziomu"), wxPoint(6, 5), wxDefaultSize, 0, _("WxStaticText1"));
	WxFlexGridSizer1->Add(WxStaticText1, 0, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

	Nazwa = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _("Nazwa"), wxPoint(106, 5), wxSize(172, 19), 0, wxDefaultValidator, _("Nazwa"));
	WxFlexGridSizer1->Add(Nazwa, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT2, _("Szerokość (3-30)"), wxPoint(5, 34), wxDefaultSize, 0, _("WxStaticText2"));
	WxFlexGridSizer1->Add(WxStaticText2, 0, wxALIGN_CENTER | wxALL, 5);

	Szerokosc = new wxTextCtrl(WxPanel1, ID_WXEDIT2, _("10"), wxPoint(136, 34), wxSize(112, 19), 0, wxTextValidator(wxFILTER_NUMERIC, NULL), _("Szerokosc"));
	WxFlexGridSizer1->Add(Szerokosc, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, _("Wysokość (3-30)"), wxPoint(5, 63), wxDefaultSize, 0, _("WxStaticText3"));
	WxFlexGridSizer1->Add(WxStaticText3, 0, wxALIGN_CENTER | wxALL, 5);

	Wysokosc = new wxTextCtrl(WxPanel1, ID_WXEDIT3, _("10"), wxPoint(136, 63), wxSize(112, 19), 0, wxDefaultValidator, _("Wysokosc"));
	WxFlexGridSizer1->Add(Wysokosc, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText4 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT4, _("Motyw"), wxPoint(30, 94), wxDefaultSize, 0, _("WxStaticText4"));
	WxFlexGridSizer1->Add(WxStaticText4, 0, wxALIGN_CENTER | wxALL, 5);

	wxArrayString arrayStringFor_Motyw;
	Motyw = new wxChoice(WxPanel1, ID_WXCHOICE1, wxPoint(119, 92), wxSize(145, 23), arrayStringFor_Motyw, 0, wxDefaultValidator, _("Motyw"));
	Motyw->SetSelection(-1);
	WxFlexGridSizer1->Add(Motyw, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("Nowy plik"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

void NewFile::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}





wxString NewFile::getLevelName(){
	return Nazwa->GetValue();
}
void NewFile::getSize(int &x, int &y){
	long w, h;
	Szerokosc->GetValue().ToLong(&w);
	Wysokosc->GetValue().ToLong(&h);
	x = w;
	y = h;
}
wxString NewFile::getThemeName(){
	return Motyw->GetString(Motyw->GetSelection());
}
wxChoice* NewFile::getThemeChoice(){
	return Motyw;
}

/*
 * PrzyciskOKClick
 */
void NewFile::PrzyciskOKClick(wxCommandEvent& event)
{
	long w, h;

	if(!Szerokosc->GetValue().ToLong(&w) ||	!Wysokosc->GetValue().ToLong(&h)){
		wxMessageBox(wxString("Podaj poprawną wielkość planszy"), wxString("Błąd"));
	}
	else if(w < 3 || w > 30 || h < 3 || h > 30){
		wxMessageBox(wxString("Wielkość poziomu musi się zawierać między 3, a 30"), wxString("Błąd"));		
	}
	else if(getLevelName().IsEmpty()){
		wxMessageBox(wxString("Nazwa poziomu nie może być pusta"), wxString("Błąd"));		
	}
	else if(Motyw->GetSelection() == -1){
		wxMessageBox(wxString("Wybierz jakiś motyw"), wxString("Błąd"));		
	}
	else{
		EndModal(wxID_OK);		
	}
}

/*
 * PrzyciskAnulujClick
 */
void NewFile::PrzyciskAnulujClick(wxCommandEvent& event)
{
	EndModal(wxID_CANCEL);
}
