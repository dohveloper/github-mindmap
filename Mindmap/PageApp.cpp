//PAGEAPP.CPP

#include "PageApp.h"
#include "PageForm.h"

BOOL PageApp::InitInstance()
{
	PageForm *pageForm = new PageForm;
	
	pageForm->Create(NULL,"¸¶ÀÎµå ¸Ê", WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL);
	pageForm->SetWindowPos(&CFrameWnd::wndBottom, 0, 0, 1280, 720, SWP_NOZORDER);
	pageForm->SetScrolls();
	pageForm->ShowWindow(SW_SHOW);
	pageForm->UpdateWindow();

	this->m_pMainWnd = pageForm;

	return TRUE;
}
PageApp pageApp;