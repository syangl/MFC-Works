
// MFCHomework4.1View.h : CMFCHomework41View 类的接口
//

#pragma once


class CMFCHomework41View : public CView
{
protected: // 仅从序列化创建
	CMFCHomework41View();
	DECLARE_DYNCREATE(CMFCHomework41View)

// 特性
public:
	CMFCHomework41Doc* GetDocument() const;

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
	virtual ~CMFCHomework41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonDialog();
};

#ifndef _DEBUG  // MFCHomework4.1View.cpp 中的调试版本
inline CMFCHomework41Doc* CMFCHomework41View::GetDocument() const
   { return reinterpret_cast<CMFCHomework41Doc*>(m_pDocument); }
#endif

