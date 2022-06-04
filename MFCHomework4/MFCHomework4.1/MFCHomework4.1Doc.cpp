
// MFCHomework4.1Doc.cpp : CMFCHomework41Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CMFCHomework41Doc 构造/析构

CMFCHomework41Doc::CMFCHomework41Doc()
	: m_outStr(_T(""))
	, m_inStr(_T(""))
{
	// TODO: 在此添加一次性构造代码

}

CMFCHomework41Doc::~CMFCHomework41Doc()
{
}

BOOL CMFCHomework41Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCHomework41Doc 序列化

void CMFCHomework41Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		ar << m_outStr;
	}
	else
	{
		// TODO: 在此添加加载代码
		ar >> m_inStr;
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFCHomework41Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CMFCHomework41Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CMFCHomework41Doc 诊断

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


// CMFCHomework41Doc 命令
