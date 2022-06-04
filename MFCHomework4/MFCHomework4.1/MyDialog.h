#pragma once


// MyDialog 对话框

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnChangeNameEdit();
	CString m_name;
//	afx_msg void OnChangeAgeEdit();
//	int m_age;
//	afx_msg void OnChangeNationEdit();
	CString m_nation;
//	afx_msg void OnChangeNumEdit();
	CString m_num;
//	afx_msg void OnCbnSelchangeCombo1();
	CString m_sex;
	CComboBox m_ctrlSex;
	virtual BOOL OnInitDialog();
	CSpinButtonCtrl m_ctrlAgeSpin;
	afx_msg void OnClickedPicButton();
	afx_msg void OnClickedCheck();

//	CString m_showCheck;
	CString m_showCheck;
	CSliderCtrl m_ctrlSlider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	// //年级
	CString m_static_grade;

private:  
	CRect rect; 

public:
//	CButton m_ctrlDisplay;
	CButton m_ctrlDisplay;
	afx_msg void OnPaint();
	afx_msg void OnChangeAgeEdit();
//	CEdit m_ageEdit;
	CEdit m_age_edit;
	CString m_strAge;
	CString picturePath;
	afx_msg void OnSelchangeSexCombo();
	afx_msg void OnChangeNationEdit();
	afx_msg void OnChangeNameEdit();
	afx_msg void OnChangeNumEdit();
	CEdit m_ctrlName;
	CEdit m_ctrlNation;
	CEdit m_ctrlNum;
};
