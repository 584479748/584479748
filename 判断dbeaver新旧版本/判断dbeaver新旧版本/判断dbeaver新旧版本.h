
// �ж�dbeaver�¾ɰ汾.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ж�dbeaver�¾ɰ汾App:
// �йش����ʵ�֣������ �ж�dbeaver�¾ɰ汾.cpp
//

class C�ж�dbeaver�¾ɰ汾App : public CWinApp
{
public:
	C�ж�dbeaver�¾ɰ汾App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ж�dbeaver�¾ɰ汾App theApp;