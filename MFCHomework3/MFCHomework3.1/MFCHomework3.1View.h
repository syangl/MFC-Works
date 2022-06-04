
// MFCHomework3.1View.h: CMFCHomework31View 类的接口
//

#pragma once


class CMFCHomework31View : public CView
{
protected: // 仅从序列化创建
	CMFCHomework31View() noexcept;
	DECLARE_DYNCREATE(CMFCHomework31View)

// 特性
public:
	CMFCHomework31Doc* GetDocument() const;

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
	virtual ~CMFCHomework31View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnPopupRect();
	afx_msg void OnPopupPolygon();
	int shape = 2;
//	afx_msg void OnIdrPopupmenu();
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int time = 50;
	int x = 300;
	int y = 200;
	int step = 10;
	int flag = 0;
	int turnover = 1; 
};

#ifndef _DEBUG  // MFCHomework3.1View.cpp 中的调试版本
inline CMFCHomework31Doc* CMFCHomework31View::GetDocument() const
   { return reinterpret_cast<CMFCHomework31Doc*>(m_pDocument); }
#endif

