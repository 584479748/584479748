
// �ж�dbeaver�¾ɰ汾Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ж�dbeaver�¾ɰ汾.h"
#include "�ж�dbeaver�¾ɰ汾Dlg.h"
#include "afxdialogex.h"
#include<string>
#include<windows.h>
#include <userenv.h>
#pragma comment(lib, "Userenv.lib")
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�ж�dbeaver�¾ɰ汾Dlg �Ի���




C�ж�dbeaver�¾ɰ汾Dlg::C�ж�dbeaver�¾ɰ汾Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�ж�dbeaver�¾ɰ汾Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ж�dbeaver�¾ɰ汾Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�ж�dbeaver�¾ɰ汾Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C�ж�dbeaver�¾ɰ汾Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C�ж�dbeaver�¾ɰ汾Dlg ��Ϣ�������

BOOL C�ж�dbeaver�¾ɰ汾Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�ж�dbeaver�¾ɰ汾Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�ж�dbeaver�¾ɰ汾Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ж�dbeaver�¾ɰ汾Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

std::string WChar2Ansi(LPCWSTR pwszSrc)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
	if (nLen <= 0) return std::string("");
	char* pszDst = new char[nLen];
	if (NULL == pszDst) return std::string("");
	WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen - 1] = 0;
	std::string strTemp(pszDst);
	delete[] pszDst;
	return strTemp;
}

std::string ws2s(std::wstring& inputws)
{ 
	return WChar2Ansi(inputws.c_str()); 
}

void getXmlDirPath(wstring &filePath)
{
	DWORD dwSize = 256;
	wchar_t szHomeDir[256] = { 0 };
	memset(szHomeDir, 0, dwSize);
	HANDLE hToken = 0;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
	{
		if (GetUserProfileDirectoryW(hToken, szHomeDir, &dwSize))
		{
			//.dbeaver
			//filePath.append(szHomeDir).append(L"\\.dbeaver");Users\\�¼�ʢ\\AppData\\Roaming\\DBeaverData\\workspace6\\.metadata
			//filePath.append(szHomeDir).append(L"\\AppData\\Roaming\\DBeaverData\\workspace6");
			filePath.append(szHomeDir).append(L"\\.dbeaver");
		}
	}
}
void C�ж�dbeaver�¾ɰ汾Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	wstring xmlPath = L"";
	wstring driverXmlPath = L"";
	getXmlDirPath(xmlPath);
	if(::PathFileExists(ws2s(xmlPath).c_str()))
	{
		AfxMessageBox("DBeaver is �ɰ汾");
	}else
	{
		AfxMessageBox("DBeaver is �°汾");
	}
}
