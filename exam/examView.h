
// examView.h : CexamView 类的接口
//

#pragma once


class CexamView : public CView
{
protected: // 仅从序列化创建
	CexamView();
	DECLARE_DYNCREATE(CexamView)

// 特性
public:
	CexamDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CexamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHelpTest();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg void OnToolbarTest();
	afx_msg void OnAppAbout();
	int m_step;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_bm_x;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	int m_flag;
	int m_shape;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnPopmenuEllipse();
	afx_msg void OnPopmenuRect();
//	int m_color;
	int m_color;
	int red;
	int green;
	int blue;
	int m_wide;
	CString m_combox;
	COLORREF linecolor;
};

#ifndef _DEBUG  // examView.cpp 中的调试版本
inline CexamDoc* CexamView::GetDocument() const
   { return reinterpret_cast<CexamDoc*>(m_pDocument); }
#endif

