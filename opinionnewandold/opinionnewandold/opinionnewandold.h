
// opinionnewandold.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CopinionnewandoldApp:
// �йش����ʵ�֣������ opinionnewandold.cpp
//

class CopinionnewandoldApp : public CWinApp
{
public:
	CopinionnewandoldApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CopinionnewandoldApp theApp;