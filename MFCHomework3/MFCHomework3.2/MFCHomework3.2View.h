
// MFCHomework3.2View.h: CMFCHomework32View 类的接口
//

#pragma once


class CMFCHomework32View : public CScrollView
{
protected: // 仅从序列化创建
	CMFCHomework32View() noexcept;
	DECLARE_DYNCREATE(CMFCHomework32View)

// 特性
public:
	CMFCHomework32Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCHomework32View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOriginBMP();
	afx_msg void On14BMP();
	afx_msg void On4BMP();
	int flag = 0;
};

#ifndef _DEBUG  // MFCHomework3.2View.cpp 中的调试版本
inline CMFCHomework32Doc* CMFCHomework32View::GetDocument() const
   { return reinterpret_cast<CMFCHomework32Doc*>(m_pDocument); }
#endif

