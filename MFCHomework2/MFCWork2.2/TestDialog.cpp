// TestDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCWork2.2.h"
#include "TestDialog.h"
#include "afxdialogex.h"
#include "MFCWork2.2Doc.h"
#include "MainFrm.h"
#include "MFCWork2.2View.h"

// TestDialog 对话框

IMPLEMENT_DYNAMIC(TestDialog, CDialogEx)

TestDialog::TestDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

TestDialog::~TestDialog()
{
}

void TestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, test_button);
	DDX_Control(pDX, IDC_EDIT1, test_edit);
}


BEGIN_MESSAGE_MAP(TestDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &TestDialog::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &TestDialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// TestDialog 消息处理程序


void TestDialog::OnBnClickedOk()
{
	//单击确认后，把编辑框内容存入文档
	CMFCWork22Doc* pDoc = ((CMFCWork22View*)((CMainFrame*)AfxGetMainWnd())->GetActiveView())->GetDocument();
	test_edit.GetWindowTextW(test_str);
	pDoc->m_str = test_str;
	CDialogEx::OnOK();
}


void TestDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。


	//编辑框内容同步到关联的test_edit变量
	UpdateData(1);
	
}
