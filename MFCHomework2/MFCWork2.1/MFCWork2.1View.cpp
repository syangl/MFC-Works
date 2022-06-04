
// MFCWork2.1View.cpp: CMFCWork21View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCWork2.1.h"
#endif

#include "MFCWork2.1Doc.h"
#include "MFCWork2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWork21View

IMPLEMENT_DYNCREATE(CMFCWork21View, CView)

BEGIN_MESSAGE_MAP(CMFCWork21View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
//	ON_COMMAND(ID_POPUP_LINE, &CMFCWork21View::OnPopupLine)
ON_COMMAND(ID_POPUP_ELLIPSE, &CMFCWork21View::OnPopupEllipse)
//ON_COMMAND(ID_POPUP_LINE, &CMFCWork21View::OnPopupRect)
ON_COMMAND(ID_POPUP_RECT, &CMFCWork21View::OnPopupRect)
ON_COMMAND(ID_POPUP_COLORRECT, &CMFCWork21View::OnPopupColorrect)
END_MESSAGE_MAP()

// CMFCWork21View 构造/析构

CMFCWork21View::CMFCWork21View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCWork21View::~CMFCWork21View()
{
}

BOOL CMFCWork21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCWork21View 绘图

void CMFCWork21View::OnDraw(CDC* pDC)
{
	CMFCWork21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//窗口调整后重绘图像
	if (shape == 0) {
		OnPopupEllipse();
	}
	else if (shape == 1) {
		OnPopupRect();
	}
	else if (shape == 2) {
		pDC = GetDC();
		//创建填充画刷
		CRect rect;
		GetClientRect(&rect);
		CBrush m_brush;
		m_brush.CreateSolidBrush(m_color);
		pDC->SelectObject(m_brush);
		pDC->Rectangle(rect.CenterPoint().x - 100, rect.CenterPoint().y - 100,
			rect.CenterPoint().x + 100, rect.CenterPoint().y + 100);
		ReleaseDC(pDC);
	}
	//打开显示文档
	CRect rect;
	GetClientRect(&rect);
	pDC->TextOutW(rect.CenterPoint().x/2,rect.CenterPoint().y,GetDocument()->m_str_open);

}


// CMFCWork21View 打印

BOOL CMFCWork21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCWork21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCWork21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCWork21View 诊断

#ifdef _DEBUG
void CMFCWork21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCWork21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCWork21Doc* CMFCWork21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCWork21Doc)));
	return (CMFCWork21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCWork21View 消息处理程序

////////////////////////////////////////////////////////////作业内容1的代码/////////////////////////////////////////////////////////////
void CMFCWork21View::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// 实现浮动菜单
	CMenu menu;
	menu.LoadMenu(IDR_POPUPMENU);
	CMenu* pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x, point.y, this);

}

void CMFCWork21View::OnPopupEllipse()
{
	shape = 3;
	//视图中央刷新后仅显示椭圆
	Invalidate();
	UpdateWindow();
	//椭圆
	CRect rect;
	GetClientRect(&rect);
	CDC* pDC = GetDC();
	pDC->Ellipse(rect.CenterPoint().x - 100, rect.CenterPoint().y - 100, 
		rect.CenterPoint().x + 100, rect.CenterPoint().y + 100);
	ReleaseDC(pDC);	
	//将椭圆 左上角坐标、宽度、高度存入文档
	CString tmp_str;
	tmp_str.Format(L"椭圆 坐标（%d,%d）宽度 %d 高度 %d", rect.CenterPoint().x - 100, rect.CenterPoint().y - 100,200,200);
	GetDocument()->m_str = tmp_str;
	//标志窗口刷新后重新绘制椭圆
	shape = 0;
}


void CMFCWork21View::OnPopupRect()
{
	shape = 3;
	//视图中央刷新后仅显示矩形
	Invalidate();
	UpdateWindow();
	//矩形
	CRect rect;
	GetClientRect(&rect);
	CDC* pDC = GetDC();
	pDC->Rectangle(rect.CenterPoint().x - 100, rect.CenterPoint().y - 100,
		rect.CenterPoint().x + 100, rect.CenterPoint().y + 100);
	ReleaseDC(pDC);
	//将矩形 左上角坐标、宽度、高度存入文档
	CString tmp_str;
	tmp_str.Format(L"矩形 坐标（%d,%d）宽度 %d 高度 %d", rect.CenterPoint().x - 100, rect.CenterPoint().y - 100, 200, 200);
	GetDocument()->m_str = tmp_str;
	//标志窗口刷新后重新绘制矩形
	shape = 1;
}


void CMFCWork21View::OnPopupColorrect()
{
	// 额外功能，单击浮动式菜单栏彩色矩形，绘制彩色填充的矩形
	shape = 3;
	//视图中央刷新后仅显示矩形
	Invalidate();
	UpdateWindow();
	//矩形
	CRect rect;
	GetClientRect(&rect);
	//设置颜色选择对话框
	COLORREF color;
	CColorDialog color_dialog;
	if (color_dialog.DoModal() == IDOK) {
		color = color_dialog.GetColor();
		m_color = color;
	}
	CDC* pDC = GetDC();
	//创建填充画刷
	CBrush m_brush;
	m_brush.CreateSolidBrush(color);
	pDC->SelectObject(m_brush);
	pDC->Rectangle(rect.CenterPoint().x - 100, rect.CenterPoint().y - 100,
		rect.CenterPoint().x + 100, rect.CenterPoint().y + 100);
	ReleaseDC(pDC);
	//将矩形 左上角坐标、宽度、高度存入文档
	CString tmp_str;
	tmp_str.Format(L"填充色矩形 坐标（%d,%d）宽度 %d 高度 %d", rect.CenterPoint().x - 100, rect.CenterPoint().y - 100, 200, 200);
	GetDocument()->m_str = tmp_str;
	//标志窗口刷新后重新绘制矩形
	shape = 2;
}
