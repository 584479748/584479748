
// AsiaLocalMainSso.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAsiaLocalMainSsoApp:
// �йش����ʵ�֣������ AsiaLocalMainSso.cpp
//

class CAsiaLocalMainSsoApp : public CWinApp
{
public:
	CAsiaLocalMainSsoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAsiaLocalMainSsoApp theApp;