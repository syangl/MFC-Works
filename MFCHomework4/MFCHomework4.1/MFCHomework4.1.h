
// MFCHomework4.1.h : MFCHomework4.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCHomework41App:
// �йش����ʵ�֣������ MFCHomework4.1.cpp
//

class CMFCHomework41App : public CWinApp
{
public:
	CMFCHomework41App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCHomework41App theApp;
