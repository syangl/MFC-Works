
// MFCWork1.1View.cpp: CMFCWork11View 类的实现

/*作业要求：
*	编程实现消息测试程序，满足以下要求：

（1）单文档应用程序，MFC标准类型，经典菜单，不带工具栏；

（2）单击鼠标左键，消息对话框中显示鼠标信息（鼠标左键 + 坐标）；

（3）单击鼠标左键 + Ctrl，消息对话框中显示鼠标信息（鼠标左键 + Ctrl键 + 坐标）；

（4）按下键盘任意字符键（至少识别两个功能键），客户区中显示按键信息（字符或功能键内容）；

（5）自定义WM_MY_MESSAGE消息，带两个参数（10和50），由“@”（不是“2”）键激活，客户区中显示相应信息（自定义消息 + 参数）。
*
*	****************************************作业的实现部分已在相应位置处明显注释标注*********************************************
*/

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCWork1.1.h"
#endif

#include "MFCWork1.1Doc.h"
#include "MFCWork1.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWork11View

IMPLEMENT_DYNCREATE(CMFCWork11View, CView)

BEGIN_MESSAGE_MAP(CMFCWork11View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	/**********************************鼠标和案件消息********************************/
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	/**********************************自定义消息********************************/
	ON_MESSAGE(WM_MYMESSAGE,OnMyMessage)				
	ON_WM_HOTKEY()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCWork11View 构造/析构

CMFCWork11View::CMFCWork11View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCWork11View::~CMFCWork11View()
{
}

BOOL CMFCWork11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCWork11View 绘图

void CMFCWork11View::OnDraw(CDC* /*pDC*/)
{
	CMFCWork11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCWork11View 打印

BOOL CMFCWork11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCWork11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCWork11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCWork11View 诊断

#ifdef _DEBUG
void CMFCWork11View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCWork11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCWork11Doc* CMFCWork11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCWork11Doc)));
	return (CMFCWork11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCWork11View 消息处理程序


/*****************************************************************作业1.1部分*****************************************************************/
/*********************************************************************************************************************************************/
void CMFCWork11View::OnLButtonDown(UINT nFlags, CPoint point)
{		
	/********************作业要求（3）实现，单击鼠标左键+Ctrl键，消息对话框中显示鼠标信息（鼠标左键+Ctrl键+坐标）********************/
	if (nFlags & MK_CONTROL) 
	{
		CString str2;
		str2.Format(L"鼠标左键 + Ctrl键 + (%d,%d)", point.x, point.y);
		MessageBox(str2);
	}
	else
	{/********************作业要求（2）实现，单击鼠标左键，消息对话框中显示鼠标信息（鼠标左键+坐标）********************/
		CString str1;
		str1.Format(L"鼠标左键 + 坐标(%d,%d)", point.x, point.y);
		MessageBox(str1);
	}

	CView::OnLButtonDown(nFlags, point);
}

void CMFCWork11View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{	/********************作业要求（5）实现，由“@”（不是“2”）键激活自定义消息********************/
	if ((char)nChar == '@') 
	{
		PostMessage(WM_MYMESSAGE, 10, 50);
	}

	/********************作业要求（4）实现，按下键盘任意字符键（至少识别两个功能键），客户区中显示按键信息（字符或功能键内容）********************/
	/********************在客户区显示按键信息***************/
	CString str;
	str.Format(L"%c 键被按下！",nChar);
	CDC* pDC = GetDC();
	pDC->TextOutW(0,0,str);					
	CView::OnChar(nChar, nRepCnt, nFlags);
}

BOOL CMFCWork11View::PreTranslateMessage(MSG* pMsg)
{
	/********************作业要求（4）实现，消息预处理，实现up，down，F7，F9四个功能键********************/
	if (pMsg->message == WM_KEYDOWN) 
	{
		CDC* pDC = GetDC();
		
		if (pMsg->wParam == VK_UP) 
		{
			pDC->TextOutW(0, 0, L"UP 键被按下！");
		}
		if (pMsg->wParam == VK_DOWN) 
		{
			pDC->TextOutW(0, 0, L"DOWN 键被按下！");
		}
		if (pMsg->wParam == VK_F7) 
		{
			pDC->TextOutW(0, 0, L"F7 键被按下！");
		}
		if (pMsg->wParam == VK_F9) 
		{
			pDC->TextOutW(0, 0, L"F9 键被按下！");
		}
	}


	return CView::PreTranslateMessage(pMsg);
}

/********************作业要求（5）实现，自定义WM_MY_MESSAGE消息，带两个参数（10和50），由“@”（不是“2”）键激活，客户区中显示相应信息（自定义消息+参数）********************/
LRESULT CMFCWork11View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	/********************在客户区显示自定义信息***************/
	CString str;
	str.Format(L"自定义消息 + 参数wParam %d, 参数lParam %d",wParam,lParam);
	CDC* pDC = GetDC();
	pDC->TextOutW(0, 30, str);				
	return LRESULT();
}


/***************************************额外功能：热键功能**************************************/
int CMFCWork11View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 注册热键
	RegisterHotKey(m_hWnd, 1001, MOD_CONTROL | MOD_SHIFT, 'a');
	RegisterHotKey(m_hWnd, 1002, MOD_CONTROL | MOD_SHIFT, 'A');
	return 0;
}


void CMFCWork11View::OnDestroy()
{
	CView::OnDestroy();

	// 解除热键
	UnregisterHotKey(m_hWnd, 1001);
	UnregisterHotKey(m_hWnd, 1002);
}

void CMFCWork11View::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	//额外功能，热键功能，显示热键执行的消息
	if (nHotKeyId == 1001||nHotKeyId == 1002) 
	{
		MessageBox(L"热键被按下！");
	}	
	CView::OnHotKey(nHotKeyId, nKey1, nKey2);
}
/*****************************************************************作业1.1部分*****************************************************************/
/*********************************************************************************************************************************************/















