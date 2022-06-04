#pragma once


// TestDialog 对话框

class TestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TestDialog)

public:
	TestDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TestDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	CButton test_button;
	CEdit test_edit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	CString test_str = L"";
};
