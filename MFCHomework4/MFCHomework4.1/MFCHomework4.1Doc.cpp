
// MFCHomework4.1Doc.cpp : CMFCHomework41Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCHomework4.1.h"
#endif

#include "MFCHomework4.1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCHomework41Doc

IMPLEMENT_DYNCREATE(CMFCHomework41Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCHomework41Doc, CDocument)
END_MESSAGE_MAP()


// CMFCHomework41Doc ����/����

CMFCHomework41Doc::CMFCHomework41Doc()
	: m_outStr(_T(""))
	, m_inStr(_T(""))
{
	// TODO: �ڴ����һ���Թ������

}

CMFCHomework41Doc::~CMFCHomework41Doc()
{
}

BOOL CMFCHomework41Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFCHomework41Doc ���л�

void CMFCHomework41Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar << m_outStr;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar >> m_inStr;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMFCHomework41Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMFCHomework41Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMFCHomework41Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCHomework41Doc ���

#ifdef _DEBUG
void CMFCHomework41Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCHomework41Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCHomework41Doc ����
