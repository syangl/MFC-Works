
// MFCWork2.2View.cpp: CMFCWork22View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCWork2.2.h"
#endif

#include "MFCWork2.2Doc.h"
#include "MFCWork2.2View.h"

#include "TestDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWork22View

IMPLEMENT_DYNCREATE(CMFCWork22View, CView)

BEGIN_MESSAGE_MAP(CMFCWork22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST_DIALOG, &CMFCWork22View::OnTestDialog)
END_MESSAGE_MAP()

// CMFCWork22View 构造/析构

CMFCWork22View::CMFCWork22View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCWork22View::~CMFCWork22View()
{
}

BOOL CMFCWork22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCWork22View 绘图

void CMFCWork22View::OnDraw(CDC* pDC)
{
	CMFCWork22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 显示打开后读出的文档内容
	pDC->TextOutW(0, 20, GetDocument()->open_str);

}


// CMFCWork22View 打印

BOOL CMFCWork22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCWork22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCWork22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCWork22View 诊断

#ifdef _DEBUG
void CMFCWork22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCWork22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCWork22Doc* CMFCWork22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCWork22Doc)));
	return (CMFCWork22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCWork22View 消息处理程序

//////////////////////////////////////////////////////////////////作业内容2主要代码///////////////////////////////////////////////////////////////////////////////

void CMFCWork22View::OnTestDialog()
{
	//打开对话框
	TestDialog dlg;
	dlg.DoModal();
	//对话框关闭后，在视图左上角输出编辑框内容
	CDC* pDC = GetDC();
	pDC->TextOutW(0, 0, GetDocument()->m_str);
}
