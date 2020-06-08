
// AsiaLocalMainSso.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "AsiaLocalMainSso.h"
#include "AsiaLocalMainSsoDlg.h"
#include<string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAsiaLocalMainSsoApp

BEGIN_MESSAGE_MAP(CAsiaLocalMainSsoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CAsiaLocalMainSsoApp ����

CAsiaLocalMainSsoApp::CAsiaLocalMainSsoApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAsiaLocalMainSsoApp ����

CAsiaLocalMainSsoApp theApp;


// CAsiaLocalMainSsoApp ��ʼ��


BOOL CAsiaLocalMainSsoApp::InitInstance()
{
	std::string str = ::AfxGetApp()->m_lpCmdLine;
	if(str.find("-install")!=str.npos)
	{
		CString strExePath;
		CString strPath;
		GetModuleFileName(NULL,strPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
		int nPos = strPath.ReverseFind(_T('\\'));
		strExePath = strPath.Left(nPos+1);
		strExePath.Append("AsiaLocalMainSso.reg");
		FILE * f = fopen(strExePath,"w+");
		if(f==NULL)
		{
			assert(0);
			return false;
		}
		CString path;
		path.Format("Windows Registry Editor Version 5.00\n\
					\n\
					[HKEY_CLASSES_ROOT\AsiaLocalMainSso]\
					@=\"AsiaLocalMainSso Protocol\"\
					\"URL Protocol\"=\"\"\
					\n\
					[HKEY_CLASSES_ROOT\AsiaLocalMainSso\DefaultIcon]\
					@=\"%%s\",1\"\
					\n\
					[HKEY_CLASSES_ROOT\AsiaLocalMainSso\shell]\
					\n\
					[HKEY_CLASSES_ROOT\AsiaLocalMainSso\shell\open]\
					\n\
					[HKEY_CLASSES_ROOT\AsiaLocalMainSso\shell\open\command]\
					@=\"\"%%s\" \"%1\"\"",strPath,strPath);
		int size = fwrite(path.GetString(),sizeof(char),path.GetLength(),f);

		if(size<1)
		{
			return false;		
		}
		fclose(f);
		return true;

	}
	AfxMessageBox(str.c_str());
	return FALSE;
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CAsiaLocalMainSsoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

