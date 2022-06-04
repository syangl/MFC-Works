
// MFCWork2.2View.h: CMFCWork22View 类的接口
//

#pragma once


class CMFCWork22View : public CView
{
protected: // 仅从序列化创建
	CMFCWork22View() noexcept;
	DECLARE_DYNCREATE(CMFCWork22View)

// 特性
public:
	CMFCWork22Doc* GetDocument() const;

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
	virtual ~CMFCWork22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnTest();

//	afx_msg void OnIddDialog1();
	afx_msg void OnTestDialog();
};

#ifndef _DEBUG  // MFCWork2.2View.cpp 中的调试版本
inline CMFCWork22Doc* CMFCWork22View::GetDocument() const
   { return reinterpret_cast<CMFCWork22Doc*>(m_pDocument); }
#endif

