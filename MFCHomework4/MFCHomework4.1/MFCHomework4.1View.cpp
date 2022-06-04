
// MFCHomework4.1View.cpp : CMFCHomework41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCHomework4.1.h"
#endif

#include "MFCHomework4.1Doc.h"
#include "MFCHomework4.1View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHomework41View

IMPLEMENT_DYNCREATE(CMFCHomework41View, CView)

BEGIN_MESSAGE_MAP(CMFCHomework41View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTON_DIALOG, &CMFCHomework41View::OnButtonDialog)
END_MESSAGE_MAP()

// CMFCHomework41View 构造/析构

CMFCHomework41View::CMFCHomework41View()
{
	// TODO: 在此处添加构造代码

}

CMFCHomework41View::~CMFCHomework41View()
{
}

BOOL CMFCHomework41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCHomework41View 绘制

void CMFCHomework41View::OnDraw(CDC* pDC)
{
	CMFCHomework41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 打开文档
	pDC->TextOutW(20,20,GetDocument()->m_inStr);
}


// CMFCHomework41View 打印

BOOL CMFCHomework41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCHomework41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCHomework41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCHomework41View 诊断

#ifdef _DEBUG
void CMFCHomework41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCHomework41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCHomework41Doc* CMFCHomework41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCHomework41Doc)));
	return (CMFCHomework41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCHomework41View 消息处理程序

void CMFCHomework41View::OnButtonDialog()
{
	// 工具栏按钮，打开标准对话框
	MyDialog dlg;
	CString str;
	if (IDOK == dlg.DoModal())
	{
		str.Format(L"姓名：%s; 性别：%s; 学号：%s;  年龄：%s; 民族：%s; 状态：%s; 年级：%s",
			dlg.m_name, dlg.m_sex, dlg.m_num, dlg.m_strAge, dlg.m_nation, dlg.m_showCheck, dlg.m_static_grade);
		//写入文档
		GetDocument()->m_outStr = str;

		//视图区绘制
		CDC *pDC = GetDC();
		pDC->TextOutW(20,20,str);

		CImage image;
		image.Load(dlg.picturePath);
		CRect rectControl; //矩形对象
		CRect rectPicture; //图片矩形对象
		GetClientRect(rectControl);
		SetStretchBltMode(pDC->m_hDC, STRETCH_HALFTONE);
		CPoint point = rectControl.TopLeft();
		point.y += (int)rectControl.Height()/8;
		rectPicture = CRect(point, CSize((int)rectControl.Width()/9, (int)rectControl.Height()/4));
		//绘制图片
		image.Draw(pDC->m_hDC, rectPicture); 
		image.Destroy();
		ReleaseDC(pDC);
	}
}
