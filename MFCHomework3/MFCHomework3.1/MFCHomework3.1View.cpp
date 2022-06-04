
// MFCHomework3.1View.cpp: CMFCHomework31View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCHomework3.1.h"
#endif

#include "MFCHomework3.1Doc.h"
#include "MFCHomework3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHomework31View

IMPLEMENT_DYNCREATE(CMFCHomework31View, CView)

BEGIN_MESSAGE_MAP(CMFCHomework31View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_POPUP_RECT, &CMFCHomework31View::OnPopupRect)
	ON_COMMAND(ID_POPUP_POLYGON, &CMFCHomework31View::OnPopupPolygon)
//	ON_COMMAND(IDR_POPUPMENU, &CMFCHomework31View::OnIdrPopupmenu)
ON_WM_HOTKEY()
ON_WM_CREATE()
ON_WM_DESTROY()
ON_WM_KEYUP()
ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCHomework31View 构造/析构

CMFCHomework31View::CMFCHomework31View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCHomework31View::~CMFCHomework31View()
{
}

BOOL CMFCHomework31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCHomework31View 绘图
/*******************************************************************作业绘图主要代码***************************************************/
void CMFCHomework31View::OnDraw(CDC* pDC)
{
	CMFCHomework31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 绘制矩形或多边形
	pDC = GetDC();
	UpdateWindow();
	if (shape == 0) {
		//OnPopupRect();
		//矩形
		CRect rect;
		GetClientRect(&rect);
		int wide = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		pDC->Rectangle(300, 200,
			1000, 600);
		ReleaseDC(pDC);
		
	}
	else if (shape == 1) {
		//OnPopupPolygon();
		CRect rect;
		GetClientRect(&rect);
		//CDC* pDC = GetDC();
		int wide = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		//绘制六边形上下平行边
		pDC->MoveTo(300, 200);//p1
		pDC->LineTo(500, 200);//p2
		pDC->MoveTo(300, 500);//p5
		pDC->LineTo(500, 500);//p4
		//绘制六边形的剩余四条斜边
		pDC->MoveTo(200, 300);//p6
		pDC->LineTo(300, 200);
		pDC->MoveTo(200, 300);
		pDC->LineTo(300, 500);
		pDC->MoveTo(600, 300);//p3
		pDC->LineTo(500, 200);
		pDC->MoveTo(600, 300);
		pDC->LineTo(500, 500);//p4
		ReleaseDC(pDC);
	}

	
}


// CMFCHomework31View 打印

BOOL CMFCHomework31View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCHomework31View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCHomework31View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCHomework31View 诊断

#ifdef _DEBUG
void CMFCHomework31View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCHomework31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCHomework31Doc* CMFCHomework31View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCHomework31Doc)));
	return (CMFCHomework31Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCHomework31View 消息处理程序
/*******************************************************************作业内容主要代码***************************************************/

void CMFCHomework31View::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// 实现浮动菜单
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}


void CMFCHomework31View::OnPopupRect()
{
	//视图中央刷新后仅显示矩形
	shape = 0;
	KillTimer(1);
	Invalidate();

}


void CMFCHomework31View::OnPopupPolygon()
{

	//视图中央刷新后仅显示六边形
	shape = 1;
	KillTimer(1);
	Invalidate();

}




void CMFCHomework31View::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// 实现Popup的快捷键Ctrl+R和Ctrl+P
	if (nHotKeyId == 1001 || nHotKeyId == 1002) {
		OnPopupRect();
	}
	if (nHotKeyId == 1003 || nHotKeyId == 1004) {
		OnPopupPolygon();
	}

	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}


int CMFCHomework31View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 注册快捷键
	RegisterHotKey(m_hWnd, 1001, MOD_CONTROL,'r');
	RegisterHotKey(m_hWnd, 1002, MOD_CONTROL, 'R');
	RegisterHotKey(m_hWnd, 1003, MOD_CONTROL, 'p');
	RegisterHotKey(m_hWnd, 1004, MOD_CONTROL, 'P');
	return 0;
}


void CMFCHomework31View::OnDestroy()
{
	CView::OnDestroy();

	// 销毁热键
	UnregisterHotKey(m_hWnd, 1001);
	UnregisterHotKey(m_hWnd, 1002);
	UnregisterHotKey(m_hWnd, 1003);
	UnregisterHotKey(m_hWnd, 1004);
	KillTimer(1);

}


void CMFCHomework31View::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// V键创建计时器，浮动菜单栏切换后，按下V将重置位图开始沿着新图形边框移动
	if (nChar == 'v' || nChar == 'V') {
		x = 300;//重置初始化
		y = 200;
		SetTimer(1, time, NULL);
	}
	// T键让位图反向移动
	if (nChar == 't' || nChar == 'T') {
		turnover = -turnover;
	}

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}


void CMFCHomework31View::OnTimer(UINT_PTR nIDEvent)
{
	// 实现位图移动
	if (nIDEvent == 1) {
		CDC* pDC = GetDC();

		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;
		bm.GetBitmap(&info);

		//沿矩形移动
		if (shape == 0) {
			int x1 = 300;
			int y1 = 200;
			int x2 = 1000;
			int y2 = 200;
			int x3 = 300;
			int y3 = 600;
			int x4 = 1000;
			int y4 = 600;

			Invalidate();
			if (turnover == 1) {//顺时针移动
				if (x1 <= x && x <= (x2 - 10) && y == y1) {
					x += step;
				}
				if (x == x2 && y1 <= y && y <= (y4 - 10)) {
					y += step;
				}
				if (y == y4 && (x1 + 10) <= x && x <= x2) {
					x -= step;
				}
				if (x == x1 && (y1 + 10) <= y && y <= y4) {
					y -= step;
				}
			}
			else if (turnover == -1) {//逆时针移动
				if (x1 == x && y1 <= y && y < y3) {
					y += step;
				}
				if (x3 <= x && x < x4 && y == y3) {
					x += step;
				}
				if (x == x2 && y2 < y && y <= y4) {
					y -= step;
				}
				if (y == y2 && x1 < x && x <= x2) {
					x -= step;
				}
			}
			UpdateWindow();
			pDC->BitBlt(x, y, 8,
				8, &memDC, 0, 0, SRCCOPY);

		}//沿六边形移动
		else if (shape == 1)
		{
			int x1 = 300, x2 = 500, x3 = 600, x4 = 500, x5 = 300, x6 = 200;
			int y1 = 200, y2 = 200, y3 = 300, y4 = 500, y5 = 500, y6 = 300;
			Invalidate();

			if (turnover == 1) {//顺时针移动
				if (x1 <= x && x < x2 && y == y1) {
					x += step;
				}
				else if (x2 <= x && x < x3 && y2 <= y && y < y3) {
					x += step;
					y += step;
				}
				else if (x > x4 && x <= x3 && y3 <= y && y < y4) {
					x -= step;
					y += step * 2;
				}
				else if (y == y5 && x5 < x && x <= x4) {
					x -= step;
				}
				else if (x5 >= x && x > x6 && y5 >= y && y > y6) {
					x -= step;
					y -= step * 2;
				}
				else if (x6 <= x && x < x1 && y6 >= y && y > y1) {
					x += step;
					y -= step;
				}
			}
			else if (turnover == -1) {//逆时针移动
				if (x6 < x && x <= x1 && y1 <= y && y < y6) {
					x -= step;
					y += step;
				}
				else if (x6 <= x && x < x5 && y6 <= y && y < y5) {
					x += step;
					y += step*2;
				}
				else if (x5 <= x && x < x4 && y == y5) {
					x += step;
				}
				else if (y3 < y && y <= y4 && x4 <= x && x < x3) {
					x += step;
					y -= step * 2;
				}
				else if (x2 < x && x <= x3 && y2 < y && y <= y3) {
					x -= step;
					y -= step;
				}
				else if (x1 < x && x <= x2 && y == y1) {
					x -= step;
				}
			}
			UpdateWindow();
			pDC->BitBlt(x, y, 8,
				8, &memDC, 0, 0, SRCCOPY);
		}
		bm.DeleteObject();
	}
	CView::OnTimer(nIDEvent);
}
