
// MFCHomework4.2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCHomework42App:
// �йش����ʵ�֣������ MFCHomework4.2.cpp
//

class CMFCHomework42App : public CWinApp
{
public:
	CMFCHomework42App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCHomework42App theApp;