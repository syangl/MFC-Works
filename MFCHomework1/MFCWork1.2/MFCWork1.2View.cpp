
// MFCWork1.2View.cpp: CMFCWork12View 类的实现



/*作业要求：
*	编程实现SmallBall程序，满足以下要求：
	（1）单文档应用程序，MFC标准类型，经典菜单，带停靠式工具栏；
	（2）黑色小球，从左上角开始，向右下方沿着45度方向移动，遇到边界反弹；
	（3）整个窗口固定大小为600*500像素；
	（4）计时器的初始时间间隔为500ms，小球每次移动幅度为10像素；
	（5）通过主菜单中的两个菜单项（加速与减速），通过调整计时器的时间间隔大小，调节小球的移动速度（加快或减慢）；
	（6）通过工具栏中的两个按钮，控制小球停止与再次启动。
*
*	****************************************作业的实现部分已在相应位置处明显注释标注*********************************************
*/



#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCWork1.2.h"
#endif

#include "MFCWork1.2Doc.h"
#include "MFCWork1.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWork12View

IMPLEMENT_DYNCREATE(CMFCWork12View, CView)

BEGIN_MESSAGE_MAP(CMFCWork12View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_COMMAND(ID_SPEED_UP, &CMFCWork12View::OnSpeedUp)
	ON_COMMAND(ID_SLOW_DOWN, &CMFCWork12View::OnSlowDown)
	ON_COMMAND(ID_BUTTON_MOVE, &CMFCWork12View::OnButtonMove)
	ON_COMMAND(ID_BUTTON_STOP, &CMFCWork12View::OnButtonStop)
	ON_COMMAND(ID_REVERSE, &CMFCWork12View::OnReverse)
	ON_COMMAND(ID_LEFT, &CMFCWork12View::OnLeft)
	ON_COMMAND(ID_RIGHT, &CMFCWork12View::OnRight)
	ON_COMMAND(ID_UP, &CMFCWork12View::OnUp)
	ON_COMMAND(ID_DOWN, &CMFCWork12View::OnDown)
	ON_COMMAND(ID_RESET, &CMFCWork12View::OnReset)
END_MESSAGE_MAP()

// CMFCWork12View 构造/析构

CMFCWork12View::CMFCWork12View()
	:x(0)
	,y(0)
	,movex(0)
	,movey(0)
	,time(500)
{
	/*****************设置移动幅度为10*****************/
	movex = movey = 10;
}

CMFCWork12View::~CMFCWork12View()
{
}

BOOL CMFCWork12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCWork12View 绘图

void CMFCWork12View::OnDraw(CDC* pDC)
{
	CMFCWork12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	/*********************************************左上角绘制黑色小球****************************************/
	pDC->SetROP2(R2_XORPEN);
	pDC->Ellipse(x,y,x+15, y+15);

}


// CMFCWork12View 打印

BOOL CMFCWork12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCWork12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCWork12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCWork12View 诊断

#ifdef _DEBUG
void CMFCWork12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCWork12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCWork12Doc* CMFCWork12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCWork12Doc)));
	return (CMFCWork12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCWork12View 消息处理程序


int CMFCWork12View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	/****************************************设置计时器1, 间隔500ms****************************************/
	SetTimer(1, time, NULL);
	
	return 0;
}


void CMFCWork12View::OnDestroy()
{
	CView::OnDestroy();

	/***************** 销毁计时器*****************/
	KillTimer(1);

}


void CMFCWork12View::OnTimer(UINT_PTR nIDEvent)
{
	/**************************************** 实现小球异或绘制，边框反弹，45度角移动****************************************/
	if (nIDEvent == 1) 
	{
		CDC* pDC = GetDC();
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x, y, x + 15, y + 15);
		CRect rect;
		GetClientRect(&rect);
		if (x<0||x > rect.right - 15)
		{
			movex = -movex;
		}
		if (y<0 || y > rect.bottom - 15)
		{
			movey = -movey;
		}
		x += movex;
		y += movey;
		pDC->Ellipse(x, y, x + 15, y + 15);
		
	}

	CView::OnTimer(nIDEvent);
}


void CMFCWork12View::OnSpeedUp()
{
	/****************************************调整计时器时间间隔，加速小球，设置最小时间间隔100ms，否则视觉效果不佳****************************************/
	if (time != 100) {
		time -= 100;
	}
	KillTimer(1);
	SetTimer(1, time, NULL);
}


void CMFCWork12View::OnSlowDown()
{
	/**************************************** 调整计时器时间间隔，减速小球****************************************/
	time += 100;
	KillTimer(1);
	SetTimer(1, time, NULL);
}


void CMFCWork12View::OnButtonMove()
{
	/****************************************工具栏move按钮，使小球启动****************************************/
	SetTimer(1, time, NULL);
}


void CMFCWork12View::OnButtonStop()
{
	/****************************************工具栏stop按钮，使小球停止****************************************/
	KillTimer(1);
}


/*****************改变小球方向*****************/

void CMFCWork12View::OnReverse()
{
	/*****************反向*****************/
	movex = -movex;
	movey = -movey;
}


void CMFCWork12View::OnLeft()
{
	/*****************水平向左*****************/
	if (movex == 0) {
		movex = 10;
	}
	if (movex > 0) 
	{
		movex = -movex;
	}
	movey = 0;
}


void CMFCWork12View::OnRight()
{
	/*****************水平向右*****************/
	if (movex == 0) {
		movex = 10;
	}
	if (movex < 0)
	{
		movex = -movex;
	}
	movey = 0;
}


void CMFCWork12View::OnUp()
{
	/*****************竖直向上*****************/
	if (movey == 0) {
		movey = 10;
	}
	if (movey > 0)
	{
		movey = -movey;
	}
	movex = 0;
}


void CMFCWork12View::OnDown()
{
	/*****************竖直向下*****************/
	if (movey == 0) {
		movey = 10;
	}
	if (movey < 0)
	{
		movey = -movey;
	}
	movex = 0;
}


void CMFCWork12View::OnReset()
{
	/*****************重置为45度角移动*****************/
	movex = 10;
	movey = 10;
}
