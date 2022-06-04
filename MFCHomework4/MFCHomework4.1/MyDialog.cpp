// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCHomework4.1.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog �Ի���

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDialog::IDD, pParent)
	, picturePath(_T(""))
{

	m_name = _T("����������");
	//  m_age = 0;
	m_nation = _T("����������");
	m_num = _T("������ѧ��");
	m_sex = _T("");
	m_showCheck = _T("δ��У");
	m_static_grade = _T("��һ�꼶");
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


// MyDialog ��Ϣ�������



BOOL MyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_ctrlDisplay.GetWindowRect(&rect);  
	ScreenToClient(&rect);
	// �Ա�combobox��ʼ��
	m_ctrlSex.SetCurSel(0);  
	m_ctrlSex.GetLBText(0,m_sex);
	// �����ʼ��
	m_ctrlAgeSpin.SetRange(0,120);
	m_ctrlAgeSpin.SetPos(0);  
	//��������ʼ��
	m_ctrlSlider.SetRange(0,3);
	m_ctrlSlider.SetTicFreq(1);
	m_ctrlSlider.SetPos(0);
	
	



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MyDialog::OnClickedPicButton()
{
	// ���ļ��Ի���
	CFileDialog dlg(true,NULL,NULL,   
		OFN_HIDEREADONLY,L"Pictures|*.png;*.jpg;*.jpeg|�����ļ�|*.*||");
	if (IDOK == dlg.DoModal())
	{
		picturePath = dlg.GetPathName();
		// �õ� Picture Control ���
		CWnd* pWnd = GetDlgItem(IDC_PICTURE_FRAME); 
		CImage image;
		image.Load(picturePath);
		CRect rectControl; //�ؼ����ζ���
		CRect rectPicture; //ͼƬ���ζ���
		int x = image.GetWidth();
		int y = image.GetHeight();
		pWnd->GetClientRect(rectControl);
		CDC* pDc = pWnd->GetDC();
		SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);
		rectPicture = CRect(rectControl.TopLeft(), CSize((int)rectControl.Width(), (int)rectControl.Height()));
		((CStatic*)pWnd)->SetBitmap(NULL);
		//����ͼƬ
		image.Draw(pDc->m_hDC, rectPicture); 
		//��ͼƬ���Ƶ�Picture�ؼ���ʾ�ľ�������
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
		m_showCheck = L"��У";
	}else
	{
		m_showCheck = L"δ��У";
	}
	// ����checkbox�ı��ı���ʾ
	CWnd* pWnd = GetDlgItem(IDC_SHOW_CHECK); 
	pWnd->SetWindowTextW(m_showCheck);
}


void MyDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// ������ѡ���꼶
	if(m_ctrlSlider.GetPos()==0)
	{
		m_static_grade = L"��һ�꼶";
	}
	else if(m_ctrlSlider.GetPos()==1)
	{
		m_static_grade = L"����꼶";
	}
	else if(m_ctrlSlider.GetPos()==2)
	{
		m_static_grade = L"�����꼶";
	}
	else if(m_ctrlSlider.GetPos()==3)
	{
		m_static_grade = L"�����꼶";
	}
	// ����slider�ı��ı���ʾ
	CWnd* pWnd = GetDlgItem(IDC_STATIC_GRADE); 
	pWnd->SetWindowTextW(m_static_grade);
	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void MyDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint() 
	dc.SetBkMode(TRANSPARENT);  
	dc.SetTextColor(RGB(0,0,255));

	m_age_edit.GetWindowTextW(m_strAge);
	dc.TextOutW(rect.left+20,rect.top+20,m_strAge);

}


void MyDialog::OnChangeAgeEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// �ػ�display
	InvalidateRect(&rect);
}


void MyDialog::OnSelchangeSexCombo()
{
	// �Ա�ѡ��ı�
	m_ctrlSex.GetLBText(m_ctrlSex.GetCurSel(),m_sex);
}


void MyDialog::OnChangeNationEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// ��ȡ����
	m_ctrlNation.GetWindowText(m_nation);
}


void MyDialog::OnChangeNameEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// ��ȡ����
	m_ctrlName.GetWindowText(m_name);
}


void MyDialog::OnChangeNumEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// ��ȡѧ��
	m_ctrlNum.GetWindowTextW(m_num);
}
