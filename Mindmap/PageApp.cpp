//PAGEAPP.CPP

#include "PageApp.h"
#include "PageForm.h"

BOOL PageApp::InitInstance()
{
	PageForm *pageForm = new PageForm;
	
	pageForm->Create(NULL,"¸¶ÀÎµå ¸Ê");
	pageForm->ShowWindow(SW_SHOW);
	pageForm->UpdateWindow();

	this->m_pMainWnd = pageForm;

	return TRUE;
}
PageApp pageApp;