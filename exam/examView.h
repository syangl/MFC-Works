
// examView.h : CexamView ��Ľӿ�
//

#pragma once


class CexamView : public CView
{
protected: // �������л�����
	CexamView();
	DECLARE_DYNCREATE(CexamView)

// ����
public:
	CexamDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CexamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // examView.cpp �еĵ��԰汾
inline CexamDoc* CexamView::GetDocument() const
   { return reinterpret_cast<CexamDoc*>(m_pDocument); }
#endif

