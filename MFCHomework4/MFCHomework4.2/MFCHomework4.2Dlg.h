
// MFCHomework4.2Dlg.h : ͷ�ļ�
//

#pragma once
#include <string>
using namespace std;

// CMFCHomework42Dlg �Ի���
class CMFCHomework42Dlg : public CDialogEx
{
// ����
public:
	CMFCHomework42Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCHOMEWORK42_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_showText;
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
	afx_msg void OnClickedButton3();
	afx_msg void OnClickedButton4();
	afx_msg void OnClickedButton5();
	afx_msg void OnClickedButton6();
	afx_msg void OnClickedButton7();
	afx_msg void OnClickedButton8();
	afx_msg void OnClickedButton9();
	afx_msg void OnClickedButton10();
	afx_msg void OnClickedButton11();
	afx_msg void OnClickedButton12();
	afx_msg void OnClickedButton13();
	afx_msg void OnClickedButton14();
	afx_msg void OnClickedButton15();
	afx_msg void OnClickedButton16();
	afx_msg void OnClickedButton17();
	afx_msg void OnClickedButton18();
	afx_msg void OnClickedButton19();
	afx_msg void OnClickedButton20();
	CStatic m_ctrlShowText;
	string str;
};
