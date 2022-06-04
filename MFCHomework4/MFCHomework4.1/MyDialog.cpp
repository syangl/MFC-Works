// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCHomework4.1.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent)
	, picturePath(_T(""))
{

	m_name = _T("请输入姓名");
	//  m_age = 0;
	m_nation = _T("请输入民族");
	m_num = _T("请输入学号");
	m_sex = _T("");
	m_showCheck = _T("未返校");
	m_static_grade = _T("大一年级");
	m_strAge = _T("0");
}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME_EDIT, m_name);
	//  DDX_Text(pDX, IDC_AGE_EDIT, m_age);
	//  DDV_MinMaxInt(pDX, m_age, 0, 120);
	DDX_Text(pDX, IDC_NATION_EDIT, m_nation);
	DDX_Text(pDX, IDC_NUM_EDIT, m_num);
	DDX_CBString(pDX, IDC_SEX_COMBO, m_sex);
	DDX_Control(pDX, IDC_SEX_COMBO, m_ctrlSex);
	DDX_Control(pDX, IDC_AGE_SPIN, m_ctrlAgeSpin);
	DDX_Text(pDX, IDC_SHOW_CHECK, m_showCheck);
	DDX_Control(pDX, IDC_SLIDER_GRADE, m_ctrlSlider);
	//  DDX_Control(pDX, IDC_STATIC_GRADE, m_static_grade);
	DDX_Text(pDX, IDC_STATIC_GRADE, m_static_grade);
	//  DDX_Control(pDX, IDC_DISPLAY, m_ctrlDisplay);
	DDX_Control(pDX, IDC_DISPLAY, m_ctrlDisplay);
	//  DDX_Control(pDX, IDC_AGE_EDIT, m_ageEdit);
	DDX_Control(pDX, IDC_AGE_EDIT, m_age_edit);
	DDX_Text(pDX, IDC_AGE_EDIT, m_strAge);
	DDX_Control(pDX, IDC_NAME_EDIT, m_ctrlName);
	DDX_Control(pDX, IDC_NATION_EDIT, m_ctrlNation);
	DDX_Control(pDX, IDC_NUM_EDIT, m_ctrlNum);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_PIC_BUTTON, &MyDialog::OnClickedPicButton)
	ON_BN_CLICKED(IDC_CHECK, &MyDialog::OnClickedCheck)
	ON_WM_HSCROLL()
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_AGE_EDIT, &MyDialog::OnChangeAgeEdit)
	ON_CBN_SELCHANGE(IDC_SEX_COMBO, &MyDialog::OnSelchangeSexCombo)
	ON_EN_CHANGE(IDC_NATION_EDIT, &MyDialog::OnChangeNationEdit)
	ON_EN_CHANGE(IDC_NAME_EDIT, &MyDialog::OnChangeNameEdit)
	ON_EN_CHANGE(IDC_NUM_EDIT, &MyDialog::OnChangeNumEdit)
END_MESSAGE_MAP()


// MyDialog 消息处理程序



BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctrlDisplay.GetWindowRect(&rect);  
	ScreenToClient(&rect);
	// 性别combobox初始化
	m_ctrlSex.SetCurSel(0);  
	m_ctrlSex.GetLBText(0,m_sex);
	// 年龄初始化
	m_ctrlAgeSpin.SetRange(0,120);
	m_ctrlAgeSpin.SetPos(0);  
	//滑动条初始化
	m_ctrlSlider.SetRange(0,3);
	m_ctrlSlider.SetTicFreq(1);
	m_ctrlSlider.SetPos(0);
	
	



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MyDialog::OnClickedPicButton()
{
	// 打开文件对话框
	CFileDialog dlg(true,NULL,NULL,   
		OFN_HIDEREADONLY,L"Pictures|*.png;*.jpg;*.jpeg|所有文件|*.*||");
	if (IDOK == dlg.DoModal())
	{
		picturePath = dlg.GetPathName();
		// 得到 Picture Control 句柄
		CWnd* pWnd = GetDlgItem(IDC_PICTURE_FRAME); 
		CImage image;
		image.Load(picturePath);
		CRect rectControl; //控件矩形对象
		CRect rectPicture; //图片矩形对象
		int x = image.GetWidth();
		int y = image.GetHeight();
		pWnd->GetClientRect(rectControl);
		CDC* pDc = pWnd->GetDC();
		SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
		rectPicture = CRect(rectControl.TopLeft(), CSize((int)rectControl.Width(), (int)rectControl.Height()));
		((CStatic*)pWnd)->SetBitmap(NULL);
		//绘制图片
		image.Draw(pDc->m_hDC, rectPicture); 
		//将图片绘制到Picture控件表示的矩形区域
		image.Destroy();
		pWnd->ReleaseDC(pDc);
	}

}


void MyDialog::OnClickedCheck()
{
	// checkbox
	CButton *pCheck=(CButton*)GetDlgItem (IDC_CHECK);  
	if (pCheck->GetCheck())
	{
		m_showCheck = L"在校";
	}else
	{
		m_showCheck = L"未返校";
	}
	// 根据checkbox改变文本显示
	CWnd* pWnd = GetDlgItem(IDC_SHOW_CHECK); 
	pWnd->SetWindowTextW(m_showCheck);
}


void MyDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// 滑动条选择年级
	if(m_ctrlSlider.GetPos()==0)
	{
		m_static_grade = L"大一年级";
	}
	else if(m_ctrlSlider.GetPos()==1)
	{
		m_static_grade = L"大二年级";
	}
	else if(m_ctrlSlider.GetPos()==2)
	{
		m_static_grade = L"大三年级";
	}
	else if(m_ctrlSlider.GetPos()==3)
	{
		m_static_grade = L"大四年级";
	}
	// 根据slider改变文本显示
	CWnd* pWnd = GetDlgItem(IDC_STATIC_GRADE); 
	pWnd->SetWindowTextW(m_static_grade);
	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void MyDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint() 
	dc.SetBkMode(TRANSPARENT);  
	dc.SetTextColor(RGB(0,0,255));

	m_age_edit.GetWindowTextW(m_strAge);
	dc.TextOutW(rect.left+20,rect.top+20,m_strAge);

}


void MyDialog::OnChangeAgeEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// 重绘display
	InvalidateRect(&rect);
}


void MyDialog::OnSelchangeSexCombo()
{
	// 性别选项改变
	m_ctrlSex.GetLBText(m_ctrlSex.GetCurSel(),m_sex);
}


void MyDialog::OnChangeNationEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// 获取民族
	m_ctrlNation.GetWindowText(m_nation);
}


void MyDialog::OnChangeNameEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// 获取名字
	m_ctrlName.GetWindowText(m_name);
}


void MyDialog::OnChangeNumEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// 获取学号
	m_ctrlNum.GetWindowTextW(m_num);
}
