//---------------------------------------------------------------------------
//
// Name:        TwistedMindEditorApp.h
// Author:      GSource
// Description: Klasa inicjująca GUI
//
//---------------------------------------------------------------------------

#ifndef __EDITORFRMApp_h__
#define __EDITORFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class EditorFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
