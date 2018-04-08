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
#include "TextFont.h"
#include "SelectText.h"
#include "TextDrag.h"
#include "TextDoubleClick.h"
#include "TextDoubleClickSelectAction.h"
#include "TextFormSize.h"
#include "TextSelectDelete.h"
#include "TextCopy.h"
#include "TextClipboard.h"
#include "WordWrap.h"
#include "TextPaste.h"
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
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

TextForm::TextForm() {
	this->text = NULL;
	this->caret = NULL;
	this->writeKorean = NULL;
	this->writeEnglish = NULL;
	this->selectText = NULL;
	this->textFormSize = NULL;
	this->textFont = NULL;
	this->textClipboard = NULL;
	this->textCopy = NULL;
	this->textPaste = NULL;
	this->hangul = FALSE;
	this->compose = FALSE;
}

int TextForm::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CWnd::OnCreate(lpCreateStruct);
	this->caret = new Caret;
	this->text = new Text;
	this->selectText = new SelectText;
	this->textFormSize = new TextFormSize;
	this->writeKorean = new WriteKorean;
	this->writeEnglish = new WriteEnglish;
	this->textClipboard = new TextClipboard;
	this->textFont = new TextFont(30,15, FW_NORMAL, FALSE, FALSE, FALSE,"굴림체");
	this->text->Write(new Row);
	this->textPaste = new TextPaste;
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

	if (this->textCopy != NULL)
	{
		delete this->textCopy;
		this->textCopy = NULL;
	}

	if (this->textPaste != NULL)
	{
		delete this->textPaste;
		this->textPaste = NULL;
	}
	PageForm *pageForm;
	pageForm = (PageForm*)this->GetParent();
	AfxGetApp()->m_pMainWnd = pageForm;

	CWnd::DestroyWindow();
}

void TextForm::OnPaint() {
	CPaintDC dc(this);

	CFont fnt;

	fnt.CreateFont(this->textFont->GetHeight(), this->textFont->GetWidth(), 0, 0, this->textFont->GetWeight(), this->textFont->GetItalic(), this->textFont->GetUnderline(), this->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T(this->textFont->GetLpszFacename()));
	
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
	//선택해제
	this->selectText->SetIsNotSelect();

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
	//선택해제
	this->selectText->SetIsNotSelect();
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
	Long i = 0;
	Long length = 0;
	Character *character;
	CFont fnt;
	CDC *cdc = GetDC();
	fnt.CreateFont(this->textFont->GetHeight(), this->textFont->GetWidth(), 0, 0, this->textFont->GetWeight(), this->textFont->GetItalic(), this->textFont->GetUnderline(), this->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T(this->textFont->GetLpszFacename()));

	cdc->SelectObject(&fnt);

	if (wParam == VK_RETURN) {
		if (this->caret->GetCharacterIndex() == 0)
		{
			this->text->Insert(this->caret->GetRowIndex(), new Row);
		}
		else
		{
			this->text->Insert(this->caret->GetRowIndex() + 1, new Row);
			i = this->caret->GetCharacterIndex();

			while (i < this->text->GetAt(this->caret->GetRowIndex())->GetLength())
			{
				character = this->text->GetAt(this->caret->GetRowIndex())->GetAt(i);

				this->text->GetAt(this->caret->GetRowIndex()+1)->Write(character);

				i++;
			}
			i = this->caret->GetCharacterIndex();
			length = this->text->GetAt(this->caret->GetRowIndex())->GetLength();
			while (i < length)
			{
				this->text->GetAt(this->caret->GetRowIndex())->Delete(i);

				i++;
			}
		}
		this->caret->MoveToDown();
		this->textFormSize->TextFormHeightSizeLong(this, cdc);
		this->caret->SetCharacterIndex(0);
	}
	else if (wParam == VK_UP)
	{
		Long i = 0;

		if (this->caret->GetRowIndex() > 0)
		{
			while (i < this->text->GetAt(this->caret->GetRowIndex()-1)->GetLength() && 
				  this->text->GetAt(this->caret->GetRowIndex())->GetRowWidth(cdc, 0, this->caret->GetCharacterIndex()) > this->text->GetAt(this->caret->GetRowIndex()-1)->GetRowWidth(cdc, 0, i))
			{
				i++;
			}
			this->caret->SetRowIndex(this->caret->GetRowIndex() - 1);
			this->caret->SetCharacterIndex(i);
		}
	}
	else if (wParam == VK_DOWN)
	{
		Long i = 0;

		if (this->caret->GetRowIndex() < this->text->GetLength() - 1)
		{
			while (i < this->text->GetAt(this->caret->GetRowIndex() + 1)->GetLength() &&
				   this->text->GetAt(this->caret->GetRowIndex())->GetRowWidth(cdc, 0, this->caret->GetCharacterIndex()) > this->text->GetAt(this->caret->GetRowIndex() + 1)->GetRowWidth(cdc, 0, i))
			{
				i++;
			}
			this->caret->SetRowIndex(this->caret->GetRowIndex() + 1);
			this->caret->SetCharacterIndex(i);
		}


	}
	else if (wParam == VK_BACK)
	{
		if (this->selectText->GetIsSelect() == true)
		{
			this->textSelectDelete->TextSelectDeleteAction(this);
			this->textFormSize->TextFormWidthSizeShort(this, cdc);
		}
		else if (this->caret->GetRowIndex()>0 && this->caret->GetCharacterIndex() == 0 && this->text->GetAt(this->caret->GetRowIndex())->GetIsWordWrap() == true)
		{
			this->text->GetAt(this->caret->GetRowIndex() - 1)->Delete(this->text->GetAt(this->caret->GetRowIndex() - 1)->GetLength() - 1);
			this->caret->SetRowIndex(this->caret->GetRowIndex() - 1);
			this->caret->SetCharacterIndex(this->text->GetAt(this->caret->GetRowIndex())->GetLength());
		}
		else if (this->caret->GetRowIndex() > 0 && this->caret->GetCharacterIndex() == 0 && this->text->GetAt(this->caret->GetRowIndex())->GetIsWordWrap() == false)
		{
			this->caret->SetRowIndex(this->caret->GetRowIndex() - 1);
			this->caret->SetCharacterIndex(this->text->GetAt(this->caret->GetRowIndex())->GetLength());
		}
		else if (this->caret->GetCharacterIndex() > 0)
		{
			this->text->GetAt(this->caret->GetRowIndex())->Delete(this->caret->GetCharacterIndex() - 1);
			this->caret->MoveToLeft();
		}

		if (this->text->GetLength()-1 != this->caret->GetRowIndex())
		{
			WordWrap wordWrap;
			wordWrap.Deleting(this, cdc);
		}
		this->textFormSize->TextFormHeightSizeShort(this, cdc);
		this->textFormSize->TextFormWidthSizeShort(this, cdc);
	}
	else if (wParam == VK_RIGHT)
	{
		if (this->caret->GetCharacterIndex() < this->text->GetAt(this->caret->GetRowIndex())->GetLength())
		{
			this->caret->MoveToRight();
		}
		else if (this->caret->GetRowIndex() < this->text->GetLength()-1 && this->caret->GetCharacterIndex() == this->text->GetAt(this->caret->GetRowIndex())->GetLength())
		{
			this->caret->SetRowIndex(this->caret->GetRowIndex() + 1);
			this->caret->SetCharacterIndex(0);
		}
	}
	else if (wParam == VK_LEFT)
	{
		if (this->caret->GetCharacterIndex() >0)
		{
			this->caret->MoveToLeft();
		}
		else if (this->caret->GetRowIndex() > 0 && this->caret->GetCharacterIndex() == 0)
		{
			this->caret->SetRowIndex(this->caret->GetRowIndex()-1);
			this->caret->SetCharacterIndex(this->text->GetAt(this->caret->GetRowIndex())->GetLength());
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
		this->textFormSize->TextFormWidthSizeLong(this, cdc);
		this->caret->MoveToRight();
	}
	else if (::GetKeyState(VK_CONTROL) < 0 && wParam == 67)//얜 선택해제 안되게 해야하는데 어떻게 하면 되려나?
	{
		this->textCopy->Copy(this);
	}
	else if (wParam == VK_SHIFT)
	{
		this->textPaste->Paste(this);
		this->textFormSize->TextFormHeightSizeLong(this, cdc);
		this->textFormSize->TextFormWidthSizeLong(this, cdc);
		this->textPaste->CaretMove(this);
	
	}
	//선택해제

	this->selectText->SetIsNotSelect();

	fnt.DeleteObject();
	RedrawWindow();
}

void TextForm::OnSetFocus(CWnd* pOldWnd) {

	CWnd::OnSetFocus(pOldWnd);
	//선택해제
	this->selectText->SetIsNotSelect();
	
}

void TextForm::OnKillFocus(CWnd* pNewWnd) {
	CWnd::OnKillFocus(pNewWnd);
	//선택해제
	this->selectText->SetIsNotSelect();
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

	//선택해제
	this->selectText->SetIsNotSelect();

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
		fnt.CreateFont(this->textFont->GetHeight(), this->textFont->GetWidth(), 0, 0, this->textFont->GetWeight(), this->textFont->GetItalic(), this->textFont->GetUnderline(), this->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T(this->textFont->GetLpszFacename()));
		cdc->SelectObject(&fnt);

		white = cdc->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
		blue = cdc->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));

		this->selectText->TextDragAction(this,cdc,point);
		this->selectText->SetIsSelect();

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
	fnt.CreateFont(this->textFont->GetHeight(), this->textFont->GetWidth(), 0, 0, this->textFont->GetWeight(), this->textFont->GetItalic(), this->textFont->GetUnderline(), this->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T(this->textFont->GetLpszFacename()));
	cdc->SelectObject(&fnt);

	white = cdc->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT));
	blue = cdc->SetBkColor(GetSysColor(COLOR_HIGHLIGHT));

	this->selectText->TextDoubleClickAction(this, cdc,point);
	//선택됨
	this->selectText->SetIsSelect();
	fnt.DeleteObject();
	CWnd::OnLButtonDblClk(nFlags, point);
}


BOOL TextForm::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(&rect, RGB(255,255,255));

	return TRUE;
}