
// MFCHomework4.2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCHomework4.2.h"
#include "MFCHomework4.2Dlg.h"
#include "afxdialogex.h"
#include "caculate.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCHomework42Dlg 对话框




CMFCHomework42Dlg::CMFCHomework42Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCHomework42Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_showText = _T("0");
}

void CMFCHomework42Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOW_TEXT, m_showText);
	DDX_Control(pDX, IDC_SHOW_TEXT, m_ctrlShowText);
}

BEGIN_MESSAGE_MAP(CMFCHomework42Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCHomework42Dlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCHomework42Dlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCHomework42Dlg::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCHomework42Dlg::OnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCHomework42Dlg::OnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCHomework42Dlg::OnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCHomework42Dlg::OnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCHomework42Dlg::OnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCHomework42Dlg::OnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCHomework42Dlg::OnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCHomework42Dlg::OnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCHomework42Dlg::OnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCHomework42Dlg::OnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCHomework42Dlg::OnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCHomework42Dlg::OnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCHomework42Dlg::OnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCHomework42Dlg::OnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCHomework42Dlg::OnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCHomework42Dlg::OnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFCHomework42Dlg::OnClickedButton20)
END_MESSAGE_MAP()


// CMFCHomework42Dlg 消息处理程序

BOOL CMFCHomework42Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCHomework42Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCHomework42Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCHomework42Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCHomework42Dlg::OnClickedButton1()
{
	// 加运算
	// 调用caculator
	string btn = "+";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton2()
{
	// 减运算
	// 调用caculator
	string btn = "-";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton3()
{
	// 乘运算
	// 调用caculator
	string btn = "*";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton4()
{
	// 除运算
	// 调用caculator
	string btn = "/";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton5()
{
	// 按钮“7”
	// 调用caculator
	string btn = "7";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton6()
{
	// 按钮“8”
	// 调用caculator
	string btn = "8";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton7()
{
	// 按钮“9”
	
	// 调用caculator
	string btn = "9";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton8()
{
	// 按钮“.”
	
	// 调用caculator
	string btn = ".";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton9()
{
	// 按钮“4”
	
	// 调用caculator
	string btn = "4";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton10()
{
	// 按钮“5”
	
	// 调用caculator
	string btn = "5";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton11()
{
	// 按钮“6”
	
	// 调用caculator
	string btn = "6";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton12()
{
	// 按钮“(”
	
	// 调用caculator
	string btn = "(";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton13()
{
	// 按钮“1”
	
	// 调用caculator
	string btn = "1";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton14()
{
	// 按钮“2”
	
	// 调用caculator
	string btn = "2";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton15()
{
	// 按钮“3”
	
	// 调用caculator
	string btn = "3";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton16()
{
	// 按钮“)”
	
	// 调用caculator
	string btn = ")";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton17()
{
	// 按钮“C”
	
	// 调用caculator
	string btn = "C";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(L"0");	
}


void CMFCHomework42Dlg::OnClickedButton18()
{
	// 按钮“0”
	
	// 调用caculator
	string btn = "0";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton19()
{
	// 按钮“del”

	// 调用caculator
	string btn = "del";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();

	if (str == "") {
		m_ctrlShowText.SetWindowTextW(L"0");
	}
	else {
		m_ctrlShowText.SetWindowTextW(m_showText);
	}
}


void CMFCHomework42Dlg::OnClickedButton20()
{
	// 按钮“=”
	// 调用caculator
	string btn = "=";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
	str = "";
}

