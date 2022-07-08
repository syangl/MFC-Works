#pragma once


// CTestDialog 对话框

class CTestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDialog)

public:
	CTestDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnRadioRect();
	afx_msg void OnRadioEllipse();
	int shape;
	afx_msg void OnClickedCheck1();
	afx_msg void OnClickedCheck2();
	afx_msg void OnClickedCheck3();
//	int m_color;
	int red;
	int green;
	int blue;
	virtual BOOL OnInitDialog();
	CSliderCtrl m_ctrlSlider;
	int m_slider;
//	afx_msg void OnCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
//	int m_combox;
	afx_msg void OnSelchangeCombo1();
	CComboBox m_ctrlCombox;
	CString m_combox;
	afx_msg void OnClickedButton1();
	COLORREF lineColor;
	CEdit m_name;
	CEdit m_num;
	CEdit m_x;
	CEdit m_y;
private:  
	CRect rect;

public:
	CButton m_ctrlDisplay;
	afx_msg void OnPaint();
};
