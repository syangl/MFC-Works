
// MFCHomework4.1View.h : CMFCHomework41View ��Ľӿ�
//

#pragma once


class CMFCHomework41View : public CView
{
protected: // �������л�����
	CMFCHomework41View();
	DECLARE_DYNCREATE(CMFCHomework41View)

// ����
public:
	CMFCHomework41Doc* GetDocument() const;

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
	virtual ~CMFCHomework41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonDialog();
};

#ifndef _DEBUG  // MFCHomework4.1View.cpp �еĵ��԰汾
inline CMFCHomework41Doc* CMFCHomework41View::GetDocument() const
   { return reinterpret_cast<CMFCHomework41Doc*>(m_pDocument); }
#endif

