
// MFCWork1.1View.h: CMFCWork11View 类的接口
//

#pragma once
///////////////////////////////////////////////////////自定义消息部分///////////////////////////////////////////////////////////////////
#define WM_MYMESSAGE WM_USER+1


class CMFCWork11View : public CView
{
protected: // 仅从序列化创建
	CMFCWork11View() noexcept;
	DECLARE_DYNCREATE(CMFCWork11View)

// 特性
public:
	CMFCWork11Doc* GetDocument() const;

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
	virtual ~CMFCWork11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	
public:
	// 自定义WM_MY_MESSAGE消息，带两个参数（10和50），由“@”（不是“2”）键激活，客户区中显示相应信息（自定义消息+参数）
	LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // MFCWork1.1View.cpp 中的调试版本
inline CMFCWork11Doc* CMFCWork11View::GetDocument() const
   { return reinterpret_cast<CMFCWork11Doc*>(m_pDocument); }
#endif

