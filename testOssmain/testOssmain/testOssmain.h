
// testOssmain.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CtestOssmainApp:
// �йش����ʵ�֣������ testOssmain.cpp
//

class CtestOssmainApp : public CWinApp
{
public:
	CtestOssmainApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CtestOssmainApp theApp;