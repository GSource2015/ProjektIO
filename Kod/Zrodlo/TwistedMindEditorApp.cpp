#include "TwistedMindEditorApp.h"
#include "MainWindow.h"

IMPLEMENT_APP(EditorFrmApp)

bool EditorFrmApp::OnInit()
{
    MainWindow* frame = new MainWindow(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int EditorFrmApp::OnExit()
{
	return 0;
}
