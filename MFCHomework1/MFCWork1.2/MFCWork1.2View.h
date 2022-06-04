
// MFCWork1.2View.h: CMFCWork12View 类的接口
//

#pragma once


class CMFCWork12View : public CView
{
protected: // 仅从序列化创建
	CMFCWork12View() ;
	DECLARE_DYNCREATE(CMFCWork12View)

// 特性
public:
	CMFCWork12Doc* GetDocument() const;

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
	virtual ~CMFCWork12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	//小球起始点
	int x;
	int y;
	int movex;
	int movey;
public:
	afx_msg void OnSpeedUp();
	afx_msg void OnSlowDown();
private:
	// 调速时间间隔
	int time;
public:
	afx_msg void OnButtonMove();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonTurn();
	afx_msg void OnReverse();
	afx_msg void OnLeft();
	afx_msg void OnRight();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnReset();
};

#ifndef _DEBUG  // MFCWork1.2View.cpp 中的调试版本
inline CMFCWork12Doc* CMFCWork12View::GetDocument() const
   { return reinterpret_cast<CMFCWork12Doc*>(m_pDocument); }
#endif

