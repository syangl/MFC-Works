
// MFCWork2.1View.h: CMFCWork21View 类的接口
//

#pragma once


class CMFCWork21View : public CView
{
protected: // 仅从序列化创建
	CMFCWork21View() noexcept;
	DECLARE_DYNCREATE(CMFCWork21View)

// 特性
public:
	CMFCWork21Doc* GetDocument() const;

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
	virtual ~CMFCWork21View();
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
	afx_msg void OnPopupEllipse();

	int shape = 3;
	afx_msg void OnPopupRect();
	afx_msg void OnPopupColorrect();
	int m_flag = 0;
	COLORREF m_color;
};

#ifndef _DEBUG  // MFCWork2.1View.cpp 中的调试版本
inline CMFCWork21Doc* CMFCWork21View::GetDocument() const
   { return reinterpret_cast<CMFCWork21Doc*>(m_pDocument); }
#endif

