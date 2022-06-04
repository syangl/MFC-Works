
// MFCHomework4.1View.cpp : CMFCHomework41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCHomework4.1.h"
#endif

#include "MFCHomework4.1Doc.h"
#include "MFCHomework4.1View.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHomework41View

IMPLEMENT_DYNCREATE(CMFCHomework41View, CView)

BEGIN_MESSAGE_MAP(CMFCHomework41View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTON_DIALOG, &CMFCHomework41View::OnButtonDialog)
END_MESSAGE_MAP()

// CMFCHomework41View ����/����

CMFCHomework41View::CMFCHomework41View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCHomework41View::~CMFCHomework41View()
{
}

BOOL CMFCHomework41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCHomework41View ����

void CMFCHomework41View::OnDraw(CDC* pDC)
{
	CMFCHomework41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// ���ĵ�
	pDC->TextOutW(20,20,GetDocument()->m_inStr);
}


// CMFCHomework41View ��ӡ

BOOL CMFCHomework41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCHomework41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCHomework41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCHomework41View ���

#ifdef _DEBUG
void CMFCHomework41View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCHomework41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCHomework41Doc* CMFCHomework41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCHomework41Doc)));
	return (CMFCHomework41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCHomework41View ��Ϣ�������

void CMFCHomework41View::OnButtonDialog()
{
	// ��������ť���򿪱�׼�Ի���
	MyDialog dlg;
	CString str;
	if (IDOK == dlg.DoModal())
	{
		str.Format(L"������%s; �Ա�%s; ѧ�ţ�%s;  ���䣺%s; ���壺%s; ״̬��%s; �꼶��%s",
			dlg.m_name, dlg.m_sex, dlg.m_num, dlg.m_strAge, dlg.m_nation, dlg.m_showCheck, dlg.m_static_grade);
		//д���ĵ�
		GetDocument()->m_outStr = str;

		//��ͼ������
		CDC *pDC = GetDC();
		pDC->TextOutW(20,20,str);

		CImage image;
		image.Load(dlg.picturePath);
		CRect rectControl; //���ζ���
		CRect rectPicture; //ͼƬ���ζ���
		GetClientRect(rectControl);
		SetStretchBltMode(pDC->m_hDC, STRETCH_HALFTONE);
		CPoint point = rectControl.TopLeft();
		point.y += (int)rectControl.Height()/8;
		rectPicture = CRect(point, CSize((int)rectControl.Width()/9, (int)rectControl.Height()/4));
		//����ͼƬ
		image.Draw(pDC->m_hDC, rectPicture); 
		image.Destroy();
		ReleaseDC(pDC);
	}
}
