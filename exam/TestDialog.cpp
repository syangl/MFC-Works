// TestDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "exam.h"
#include "TestDialog.h"
#include "afxdialogex.h"


// CTestDialog 对话框

IMPLEMENT_DYNAMIC(CTestDialog, CDialogEx)

CTestDialog::CTestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDialog::IDD, pParent)
	, shape(0)
	, red(0)
	, green(0)
	, blue(0)
{

	m_slider = 0;
	//  m_combox = 0;
	m_combox = _T("斜十字线");
}

CTestDialog::~CTestDialog()
{
}

void CTestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
	DDX_Slider(pDX, IDC_SLIDER1, m_slider);
	//  DDX_CBIndex(pDX, IDC_COMBO1, m_combox);
	DDX_Control(pDX, IDC_COMBO1, m_ctrlCombox);
	DDX_CBString(pDX, IDC_COMBO1, m_combox);
	DDX_Control(pDX, IDC_EDIT1, m_name);
	DDX_Control(pDX, IDC_EDIT2, m_num);
	DDX_Control(pDX, IDC_EDIT3, m_x);
	DDX_Control(pDX, IDC_EDIT4, m_y);
	DDX_Control(pDX, IDC_DISPLAY, m_ctrlDisplay);
}


BEGIN_MESSAGE_MAP(CTestDialog, CDialogEx)
	ON_COMMAND(IDC_RADIO1, &CTestDialog::OnRadioRect)
	ON_COMMAND(IDC_RADIO2, &CTestDialog::OnRadioEllipse)
	ON_BN_CLICKED(IDC_CHECK1, &CTestDialog::OnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CTestDialog::OnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CTestDialog::OnClickedCheck3)
//	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CTestDialog::OnCustomdrawSlider1)
ON_WM_HSCROLL()
ON_CBN_SELCHANGE(IDC_COMBO1, &CTestDialog::OnSelchangeCombo1)
ON_BN_CLICKED(IDC_BUTTON1, &CTestDialog::OnClickedButton1)
ON_WM_PAINT()
END_MESSAGE_MAP()


// CTestDialog 消息处理程序





void CTestDialog::OnRadioRect()
{
	// TODO: 在此添加命令处理程序代码
	shape = 1;
	InvalidateRect(&rect);
}


void CTestDialog::OnRadioEllipse()
{
	// TODO: 在此添加命令处理程序代码
	shape = 0;
	InvalidateRect(&rect);
}


void CTestDialog::OnClickedCheck1()
{
	// 红
	red = 255;
	InvalidateRect(&rect);
}


void CTestDialog::OnClickedCheck2()
{
	// 绿
	green = 255;
	InvalidateRect(&rect);
}


void CTestDialog::OnClickedCheck3()
{
	// 蓝
	blue = 255;
	InvalidateRect(&rect);
}


BOOL CTestDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ctrlSlider.SetRange(1,6);
	m_ctrlSlider.SetTicFreq(1);
	m_ctrlSlider.SetPos(3);

	m_ctrlCombox.SetCurSel(2);  
    m_ctrlCombox.GetLBText(2,m_combox);

	m_name.SetWindowTextW(L"刘嗣旸");
	m_num.SetWindowTextW(L"2013458");

	m_x.SetWindowTextW(L"200");
	m_y.SetWindowTextW(L"200");

	m_ctrlDisplay.GetWindowRect(&rect);  
	ScreenToClient(&rect);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}





void CTestDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_slider = m_ctrlSlider.GetPos();	
	InvalidateRect(&rect);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CTestDialog::OnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ctrlCombox.GetLBText(m_ctrlCombox.GetCurSel(),m_combox);  
	InvalidateRect(&rect);

}


void CTestDialog::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog dlg(RGB(0,0,255));
	dlg.DoModal();
	lineColor = dlg.GetColor();
	InvalidateRect(&rect);
}


void CTestDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint() 
	dc.SetBkMode(TRANSPARENT);  
	if(shape == 0)
	{
		CPen newPen;
		newPen.CreatePen(PS_SOLID,m_slider,RGB(red,green,blue)); 
		dc.SelectObject(newPen); 
		dc.Ellipse(CRect(rect.CenterPoint().x-50, rect.CenterPoint().y-50, rect.CenterPoint().x+50,rect.CenterPoint().y+50));
		CBrush newBrush;
		int style = HS_DIAGCROSS;
		if (m_combox == "斜十字线")
		{
			style = HS_DIAGCROSS;
		}
		else if (m_combox == "水平线")
		{
			style = HS_HORIZONTAL;
		}
		else if (m_combox == "垂直线")
		{
			style = HS_VERTICAL;
		}
		newBrush.CreateHatchBrush(style,lineColor);
		dc.SelectObject(newBrush);  
		dc.Ellipse(CRect(rect.CenterPoint().x-50, rect.CenterPoint().y-50, rect.CenterPoint().x+50,rect.CenterPoint().y+50));

	}
	else if (shape == 1)
	{
		CPen newPen;
		newPen.CreatePen(PS_SOLID,m_slider,RGB(red,green,blue)); 
		dc.SelectObject(newPen); 
		dc.Rectangle(rect.CenterPoint().x-50, rect.CenterPoint().y-50, rect.CenterPoint().x+50,rect.CenterPoint().y+50);
		CBrush newBrush;

		int style = HS_DIAGCROSS;
		if (m_combox == "斜十字线")
		{
			style = HS_DIAGCROSS;
		}
		else if (m_combox == "水平线")
		{
			style = HS_HORIZONTAL;
		}
		else if (m_combox == "垂直线")
		{
			style = HS_VERTICAL;
		}
		newBrush.CreateHatchBrush(style,lineColor);	
		dc.SelectObject(newBrush);  
		dc.Rectangle(rect.CenterPoint().x-50, rect.CenterPoint().y-50, rect.CenterPoint().x+50,rect.CenterPoint().y+50);
	}

}