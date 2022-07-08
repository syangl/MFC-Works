
// examView.cpp : CexamView 类的实现
//



#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exam.h"
#endif

#include "examDoc.h"
#include "examView.h"
#include "TestDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CexamView

IMPLEMENT_DYNCREATE(CexamView, CView)

BEGIN_MESSAGE_MAP(CexamView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_HELP_TEST, &CexamView::OnHelpTest)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_HOTKEY()
	ON_COMMAND(ID_TOOLBAR_TEST, &CexamView::OnToolbarTest)
	ON_COMMAND(ID_APP_ABOUT, &CexamView::OnAppAbout)
	ON_WM_TIMER()
	ON_WM_CHAR()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_POPMENU_ELLIPSE, &CexamView::OnPopmenuEllipse)
	ON_COMMAND(ID_POPMENU_RECT, &CexamView::OnPopmenuRect)
END_MESSAGE_MAP()

// CexamView 构造/析构

CexamView::CexamView()
	: m_step(20)
	, m_bm_x(0)
	, m_flag(0)
	, m_shape(0)
	, m_color(0)
	, red(255)
	, green(0)
	, blue(255)
	, m_wide(3)
	, m_combox(_T("斜十字线"))
{
	// TODO: 在此处添加构造代码
	linecolor = RGB(0,0,255);
}

CexamView::~CexamView()
{
}

BOOL CexamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式


	return CView::PreCreateWindow(cs);
}

// CexamView 绘制

void CexamView::OnDraw(CDC* pDC)
{
	CexamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if(m_flag == 0)
	{
		CRect rect;   
		GetClientRect(&rect);
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);  
		CDC memDC;   
		memDC.CreateCompatibleDC(pDC);  
		memDC.SelectObject(&bm);  
		BITMAP info;   
		bm.GetBitmap(&info);  
		pDC->BitBlt(rect.right-info.bmWidth,rect.top,info.bmWidth, info.bmHeight,&memDC,0,0,SRCCOPY);  
		bm.DeleteObject();
	
	}

	CRect rect;   
	GetClientRect(&rect);
	CString str1;
	pDC->SetTextColor(RGB(255,0,0));

	str1.Format(L"姓名：刘嗣旸");
	pDC->TextOutW(0,rect.bottom-40,str1);
	CString str2;
	str2.Format(L"学号：2013458");
	
	pDC->TextOutW(0,rect.bottom-20,str2);

	if(m_shape == 0)
	{
		CPen newPen;
		newPen.CreatePen(PS_SOLID,m_wide,RGB(red,green,blue)); 
		pDC->SelectObject(newPen); 
		pDC->Ellipse(CRect(rect.CenterPoint().x-50, rect.CenterPoint().y-50, rect.CenterPoint().x+50,rect.CenterPoint().y+50));
		CBrush newBrush;
		int style = HS_DIAGCROSS;
		if (m_combox == "斜十字线")
		{
			style = HS_DIAGCROSS;
		}
		else if (m_combox == "水平线")
		{
			style = HS_HORIZONTAL;
		}
		else if (m_combox == "垂直线")
		{
			style = HS_VERTICAL;
		}
		newBrush.CreateHatchBrush(style,linecolor);
		pDC->SelectObject(newBrush);  
		pDC->Ellipse(CRect(rect.CenterPoint().x-50, rect.CenterPoint().y-50, rect.CenterPoint().x+50,rect.CenterPoint().y+50));

	}
	else if (m_shape == 1)
	{
		CPen newPen;
		newPen.CreatePen(PS_SOLID,m_wide,RGB(red,green,blue)); 
		pDC->SelectObject(newPen); 
		pDC->Rectangle(rect.CenterPoint().x-50, rect.CenterPoint().y-50, rect.CenterPoint().x+50,rect.CenterPoint().y+50);
		CBrush newBrush;

		int style = HS_DIAGCROSS;
		if (m_combox == "斜十字线")
		{
			style = HS_DIAGCROSS;
		}
		else if (m_combox == "水平线")
		{
			style = HS_HORIZONTAL;
		}
		else if (m_combox == "垂直线")
		{
			style = HS_VERTICAL;
		}
		newBrush.CreateHatchBrush(style,linecolor);	
		pDC->SelectObject(newBrush);  
		pDC->Rectangle(rect.CenterPoint().x-50, rect.CenterPoint().y-50, rect.CenterPoint().x+50,rect.CenterPoint().y+50);
	}
	

}


// CexamView 打印

BOOL CexamView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CexamView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CexamView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CexamView 诊断

#ifdef _DEBUG
void CexamView::AssertValid() const
{
	CView::AssertValid();
}

void CexamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CexamDoc* CexamView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CexamDoc)));
	return (CexamDoc*)m_pDocument;
}
#endif //_DEBUG


// CexamView 消息处理程序


void CexamView::OnHelpTest()
{
	// 打开模态对话框
	CTestDialog dlg;
	if (IDOK == dlg.DoModal())  
	{  
	    //执行操作
		m_shape = dlg.shape;

		red = dlg.red;
		green = dlg.green;
		blue = dlg.blue;

		m_wide = dlg.m_slider;
		m_combox = dlg.m_combox;
		linecolor = dlg.lineColor;



		GetDocument()->m_wide = m_wide;
		GetDocument()->m_combox = m_combox;
		GetDocument()->linecolor = linecolor;
		GetDocument()->m_shape = m_shape;


		Invalidate(true);
	}


}


int CexamView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	RegisterHotKey(m_hWnd,1001,MOD_CONTROL| MOD_ALT, 't');  
	RegisterHotKey(m_hWnd,1002,MOD_CONTROL| MOD_ALT, 'T'); 

	


	return 0;
}


void CexamView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	UnregisterHotKey(m_hWnd,1001);  
	UnregisterHotKey(m_hWnd,1002);

	KillTimer(1);
	m_flag = 0;
}


void CexamView::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nHotKeyId==1001||nHotKeyId==1002)  
	{
		OnHelpTest();
	}


	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}


void CexamView::OnToolbarTest()
{
	// TODO: 在此添加命令处理程序代码
	OnHelpTest();
}


void CexamView::OnAppAbout()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"姓名：刘嗣旸 学号：2013458");
}


void CexamView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent==1) 
	{
		m_bm_x+=m_step;
		CDC *pDC = GetDC();
		CRect rect;   
		GetClientRect(&rect);
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);  
		CDC memDC;   
		memDC.CreateCompatibleDC(pDC);  
		memDC.SelectObject(&bm);  
		BITMAP info;   
		bm.GetBitmap(&info); 

		if(rect.right-info.bmWidth-m_bm_x<-20)
		{
			KillTimer(1);
			m_flag = 0;
			return;
		}
			

		Invalidate(true);UpdateWindow();
		pDC->BitBlt(rect.right-info.bmWidth-m_bm_x,rect.top,info.bmWidth, info.bmHeight,&memDC,0,0,SRCCOPY);  
		bm.DeleteObject();
	}

	CView::OnTimer(nIDEvent);
}


void CexamView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	 if ((char)nChar == 'N'||(char)nChar == 'n')
	 {
		SetTimer(1,100,NULL);
		m_flag = 1;
	 }


	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CexamView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_POPUPMENU);  
	CMenu* pMenu=menu.GetSubMenu(0);  
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this); 

}


void CexamView::OnPopmenuEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_shape = 0;
	Invalidate(true);
}


void CexamView::OnPopmenuRect()
{
	// TODO: 在此添加命令处理程序代码
	m_shape = 1;
	Invalidate(true);
}
