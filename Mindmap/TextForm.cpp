#include "TextForm.h"
#include "PageForm.h"
#include "Topic.h"
#include "WriteKorean.h"
#include "Text.h"
#include "Row.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
#include "WriteVisitor.h"
#include "WriteEnglish.h"
#include <afxdb.h>  
#include "Caret.h"
#include "SelectText.h"
#include "TextDrag.h"
#include "TextDoubleClick.h"
#include "TextDoubleClickSelectAction.h"
#include "TextFormSize.h"
#include <imm.h>
#pragma comment(lib, "imm32.LIB")

BEGIN_MESSAGE_MAP(TextForm, CWnd)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

TextForm::TextForm() {
	this->text = NULL;
	this->caret = NULL;
	this->writeKorean = NULL;
	this->writeEnglish = NULL;
	this->selectText = NULL;
	this->textFormSize = NULL;
	this->hangul = FALSE;
	this->compose = FALSE;
	this->fontHeight = 0;
	this->fontWidth = 0;
}

int TextForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CWnd::OnCreate(lpCreateStruct);
	this->caret = new Caret;
	this->text = new Text;
	this->selectText = new SelectText;
	this->textFormSize = new TextFormSize;
	this->writeKorean = new WriteKorean;
	this->writeEnglish = new WriteEnglish;

	this->text->Write(new Row);
	return 0;
}

void TextForm::OnClose() {
	if (this->caret != NULL)
	{
		delete this->caret;
		this->caret = NULL;
	}

	if (this->text != NULL)
	{
		delete this->text;
		this->text = NULL;
	}
	if (this->selectText != NULL)
	{
		delete this->selectText;
		this->selectText = NULL;
	}
	PageForm *pageForm;
	pageForm = (PageForm*)this->GetParent();
	AfxGetApp()->m_pMainWnd = pageForm;

	CWnd::DestroyWindow();
}

void TextForm::OnPaint() {
	CPaintDC dc(this);

	CFont fnt;

	fnt.CreateFont(30, 16, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("굴림체"));
	this->fontHeight = 30;
	this->fontWidth = 16;
	dc.SelectObject(&fnt);

	WriteVisitor visitor(&dc, this);

	this->text->Accept(visitor);
	this->caret->MoveToIndex(this,&dc);

	fnt.DeleteObject();
}

BOOL TextForm::PreTranslateMessage(MSG* pMsg) {
	bool x = FALSE;

	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		this->OnKeyDown(pMsg->wParam);
		break;
	default:break;
	}
	switch (pMsg->message)
	{
	case WM_IME_STARTCOMPOSITION:
		return TRUE;
	case WM_IME_COMPOSITION:
		this->OnComposition(pMsg->lParam);
		break;
	case WM_IME_NOTIFY:
		x = this->OnNotify();
		return x;
	case WM_CHAR:
		x = this->OnChar(pMsg->wParam);
		return x;
	default:break;
	}
	return CWnd::PreTranslateMessage(pMsg);
}

//한글입력시 실행
bool TextForm::OnComposition(LPARAM lParam) {
	HWND hWnd;
	HIMC hIMC;
	CDC *cdc;
	cdc = GetDC();

	hWnd = GetSafeHwnd();
	hIMC = ImmGetContext(hWnd);

	//조합안된 한글
	if (lParam & GCS_COMPSTR)
	{
		this->writeKorean->KoreanMixing(this,hIMC,hWnd,cdc);
	}
	//조합된 한글
	if (lParam & GCS_RESULTSTR)
	{
		this->writeKorean->KoreanMixed(this, hIMC, hWnd);
	}
	RedrawWindow();
	ImmReleaseContext(hWnd, hIMC);

	return TRUE;
}

//영어 실행
bool TextForm::OnChar(WPARAM wParam) {
	char word = wParam;
	CDC *cdc = GetDC();

	if (this->hangul == FALSE && wParam != VK_RETURN && wParam != VK_BACK && wParam != VK_ESCAPE && wParam >= 32 && wParam <= 128)
	{
		this->writeEnglish->Write(this,cdc,word);
	}
	RedrawWindow();

	return TRUE;
}

//한/영키 
bool TextForm::OnNotify() {
	if (this->hangul == FALSE)
	{
		this->hangul = TRUE;
	}
	else if (this->hangul == TRUE)
	{
		this->hangul = FALSE;
	}
	return TRUE;
}

void TextForm::OnKeyDown(WPARAM wParam) {
	if (wParam == VK_RETURN) {
		Row *row = new Row;
		this->text->Write(row);
		this->caret->MoveToDown();
		CDC *cdc = GetDC();
		this->textFormSize->TextFormHeightSize(this, cdc);
		this->caret->SetCharacterIndex(0);
	}
	else if (wParam == VK_BACK)
	{
			this->text->GetAt(this->caret->GetRowIndex())->Delete(this->caret->GetCharacterIndex() - 1);
			this->caret->MoveToLeft();

	}
	else if (wParam == VK_RIGHT)
	{
		if (this->caret->GetCharacterIndex() < this->text->GetAt(this->caret->GetRowIndex())->GetLength())
		{
			this->caret->MoveToRight();
		}
	}
	else if (wParam == VK_LEFT)
	{
		if (this->caret->GetCharacterIndex() >0)
		{
			this->caret->MoveToLeft();
		}
	}
	else if (wParam == VK_ESCAPE)
	{
		this->OnClose();
		return;
	}
	else if (wParam == VK_TAB)
	{
		if (this->caret->GetCharacterIndex() > this->text->GetAt(this->caret->GetRowIndex())->GetLength() - 1)
		{
			this->text->GetAt(this->caret->GetRowIndex())->Write(new SingleByteCharacter('\t'));
		}
		else if (this->caret->GetCharacterIndex() < this->text->GetAt(this->caret->GetRowIndex())->GetLength())
		{
			this->text->GetAt(this->caret->GetRowIndex())->Insert(this->caret->GetCharacterIndex(), new SingleByteCharacter('\t'));
		}
		this->caret->MoveToRight();
	}
	RedrawWindow();
}

void TextForm::OnSetFocus(CWnd* pOldWnd) {
	CWnd::OnSetFocus(pOldWnd);
	
}

void TextForm::OnKillFocus(CWnd* pNewWnd) {
	CWnd::OnKillFocus(pNewWnd);

	DestroyCaret();
}

void TextForm::OnLButtonDown(UINT nFlags, CPoint point) {
	this->compose = FALSE;

	if (point.y < 0 || point.x<0)
	{
		this->OnClose();
		
		return;
	}
	
	CDC *dc = GetDC();
	
	this->caret->MoveToPoint(this, dc,point);

	this->selectText->SetStartCharacterIndex(this->caret->GetCharacterIndex());
	this->selectText->SetStartRowIndex(this->caret->GetRowIndex());
	this->selectText->SetEndCharacterIndex(this->caret->GetCharacterIndex());
	this->selectText->SetEndRowIndex(this->caret->GetRowIndex());

	RedrawWindow();
	CWnd::OnLButtonDown(nFlags, point);
}

void TextForm::OnMouseMove(UINT nFlags, CPoint point) {
	if (nFlags == MK_LBUTTON)
	{	
		RedrawWindow();
		
		CDC *cdc = GetDC();
		COLORREF blue;
		COLORREF white;

		CFont fnt;
		fnt.CreateFont(30, 16, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("굴림체"));
		cdc->SelectObject(&fnt);

		white = cdc->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
		blue = cdc->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));

		this->selectText->TextDragAction(this,cdc,point);

		fnt.DeleteObject();
	}
	CWnd::OnMouseMove(nFlags, point);
}

void TextForm::OnLButtonUp(UINT nFlags, CPoint point) {
	
	CWnd::OnLButtonUp(nFlags, point);
}

void TextForm::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CDC *cdc = GetDC();
	COLORREF blue;
	COLORREF white;

	CFont fnt;
	fnt.CreateFont(30, 16, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("굴림체"));
	cdc->SelectObject(&fnt);

	white = cdc->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
	blue = cdc->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));

	this->selectText->TextDoubleClickAction(this, cdc);

	fnt.DeleteObject();

	CWnd::OnLButtonDblClk(nFlags, point);
}
