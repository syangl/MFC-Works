
// MFCHomework3.2View.cpp: CMFCHomework32View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCHomework3.2.h"
#endif

#include "MFCHomework3.2Doc.h"
#include "MFCHomework3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHomework32View

IMPLEMENT_DYNCREATE(CMFCHomework32View, CScrollView)

BEGIN_MESSAGE_MAP(CMFCHomework32View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_1, &CMFCHomework32View::OnOriginBMP)
	ON_COMMAND(ID_14, &CMFCHomework32View::On14BMP)
	ON_COMMAND(ID_4, &CMFCHomework32View::On4BMP)
END_MESSAGE_MAP()

// CMFCHomework32View 构造/析构

CMFCHomework32View::CMFCHomework32View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCHomework32View::~CMFCHomework32View()
{
}

BOOL CMFCHomework32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CMFCHomework32View 绘图

void CMFCHomework32View::OnDraw(CDC* pDC)
{
	CMFCHomework32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 绘制原图
	if (flag == 1) {
		pDC = GetDC();
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;
		bm.GetBitmap(&info);

		pDC->StretchBlt(0, 0, 400,
			300, &memDC, 0, 0, info.bmWidth,
			info.bmHeight, SRCCOPY);
		bm.DeleteObject();
		ReleaseDC(pDC);
	}//绘制1/4图
	else if (flag == 2) {
		pDC = GetDC();
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;
		bm.GetBitmap(&info);

		pDC->StretchBlt(0, 0, 100,
			75, &memDC, 0, 0, info.bmWidth,
			info.bmHeight, SRCCOPY);
		bm.DeleteObject();
		ReleaseDC(pDC);
	}
	else if (flag == 3) {//绘制4倍图
		pDC = GetDC();
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		memDC.SelectObject(&bm);
		BITMAP info;
		bm.GetBitmap(&info);

		pDC->StretchBlt(0, 0, 1600,
			1200, &memDC, 0, 0, info.bmWidth,
			info.bmHeight, SRCCOPY);
		bm.DeleteObject();
		ReleaseDC(pDC);
	}


}

void CMFCHomework32View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	/*********************************************滚动条实现********************************************/
	sizeTotal.cx = 800;
	sizeTotal.cy = 600;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMFCHomework32View 打印

BOOL CMFCHomework32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCHomework32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCHomework32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCHomework32View 诊断

#ifdef _DEBUG
void CMFCHomework32View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFCHomework32View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCHomework32Doc* CMFCHomework32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCHomework32Doc)));
	return (CMFCHomework32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCHomework32View 消息处理程序
/*********************************************菜单项实现********************************************/

void CMFCHomework32View::OnOriginBMP()
{
	// 设置在OnDraw中绘制原图			
	flag = 1;
	Invalidate();
}


void CMFCHomework32View::On14BMP()
{
	// 设置在OnDraw中绘制1/4图
	flag = 2;
	Invalidate();
}


void CMFCHomework32View::On4BMP()
{
	// 设置在OnDraw中绘制4倍图
	flag = 3;
	Invalidate();
}
