
// MFCHomework4.2Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCHomework42Dlg �Ի���




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


// CMFCHomework42Dlg ��Ϣ�������

BOOL CMFCHomework42Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCHomework42Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCHomework42Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCHomework42Dlg::OnClickedButton1()
{
	// ������
	// ����caculator
	string btn = "+";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton2()
{
	// ������
	// ����caculator
	string btn = "-";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton3()
{
	// ������
	// ����caculator
	string btn = "*";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton4()
{
	// ������
	// ����caculator
	string btn = "/";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton5()
{
	// ��ť��7��
	// ����caculator
	string btn = "7";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton6()
{
	// ��ť��8��
	// ����caculator
	string btn = "8";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton7()
{
	// ��ť��9��
	
	// ����caculator
	string btn = "9";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton8()
{
	// ��ť��.��
	
	// ����caculator
	string btn = ".";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton9()
{
	// ��ť��4��
	
	// ����caculator
	string btn = "4";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton10()
{
	// ��ť��5��
	
	// ����caculator
	string btn = "5";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton11()
{
	// ��ť��6��
	
	// ����caculator
	string btn = "6";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton12()
{
	// ��ť��(��
	
	// ����caculator
	string btn = "(";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton13()
{
	// ��ť��1��
	
	// ����caculator
	string btn = "1";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton14()
{
	// ��ť��2��
	
	// ����caculator
	string btn = "2";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton15()
{
	// ��ť��3��
	
	// ����caculator
	string btn = "3";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton16()
{
	// ��ť��)��
	
	// ����caculator
	string btn = ")";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton17()
{
	// ��ť��C��
	
	// ����caculator
	string btn = "C";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(L"0");	
}


void CMFCHomework42Dlg::OnClickedButton18()
{
	// ��ť��0��
	
	// ����caculator
	string btn = "0";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
}


void CMFCHomework42Dlg::OnClickedButton19()
{
	// ��ť��del��

	// ����caculator
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
	// ��ť��=��
	// ����caculator
	string btn = "=";
	caculate(btn,str);
	//settext
	m_showText = str.c_str();
	m_ctrlShowText.SetWindowTextW(m_showText);
	str = "";
}

