
// testmfcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "testmfc.h"
#include "testmfcDlg.h"
#include "afxdialogex.h"
#include<string>
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


// CtestmfcDlg �Ի���




CtestmfcDlg::CtestmfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestmfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestmfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtestmfcDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtestmfcDlg ��Ϣ�������

BOOL CtestmfcDlg::OnInitDialog()
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

void CtestmfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtestmfcDlg::OnPaint()
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
	HCURSOR CtestmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

	/*HWND getMyFindWindowEx(HWND hwndParent, HWND hc,LPCTSTR classname, int index)
	{
		HWND hwnd(0);
		if(hc!=0)
		{
			hwnd = hc;
		}
		do
		{
			hwnd = FindWindowEx(hwndParent, hwnd,"Edit" ,NULL );

			if(hwnd > 0)
			{
				index--;

			}else
			{
				AfxMessageBox("���ڲ�����");
				return hwnd;

			}

		} while(index>0);
		return hwnd;
	}
*/
#include <string>
using namespace std;
void CtestmfcDlg::OnBnClickedButton1()
{
	string s = "123";
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	/*CString strTime;
	CTime tTime = CTime::GetCurrentTime();
	strTime = tTime.Format("%Y%m%d%H%M%S");
	char szTempFile[MAX_PATH] = {0};
	GetTempPath(sizeof(szTempFile), szTempFile);
	strcat(szTempFile, "asia_");
	strcat(szTempFile, strTime);
	strcat(szTempFile, ".tcs");
	AfxMessageBox(szTempFile);*/

	//HWND h = (HWND)0x002614D8;
	//::SendMessage(h,WM_SETTEXT,3,(LPARAM)"123");
	//return;
	/*char *classname = "Edit";
	HWND hwnd = ::FindWindow("#32770","Quick Connect");
	if(hwnd ==NULL )
	{
	AfxMessageBox("���ڲ�����");
	return ;
	}
	HWND hWnd = ::FindWindowExA(hwnd, NULL, "#32770", NULL);
	if(hWnd ==NULL )
	{
	AfxMessageBox("���ڲ�����");
	return ;
	}
	HWND hc(0);
	HWND h = getMyFindWindowEx(hWnd,hc,classname,1);	
	if(h<=0)
	{
	return ;
	}
	hc = h;
	::SendMessage(h,WM_SETTEXT,11,(LPARAM)"10.1.198.67");
	HWND h1 = getMyFindWindowEx(hWnd,hc,classname,1);
	::SendMessage(h1,WM_SETTEXT,2,(LPARAM)"22");
	hc = h1;
	HWND h2 = getMyFindWindowEx(hWnd,hc,classname,1);
	if(h2<=0)
	{
	return ;
	}
	::SendMessage(h2,WM_SETTEXT,5,(LPARAM)"aiuap");
	HWND hb = ::FindWindowEx(hwnd,0,"Button","Connect");
	::SendMessage(hb,WM_LBUTTONDOWN,0,0);
	::SendMessage(hb,WM_LBUTTONUP,0,0);
	AfxMessageBox("�����ɹ�������");*/
	HWND hwnd = ::FindWindow("#32770","Quick Connect");
	hwnd = ::GetWindow(hwnd,GW_CHILD);
	HWND h = ::GetWindow(hwnd,GW_HWNDLAST);//Ѱ��hwnd���һ���ֵܴ���
	h = ::GetWindow(h,GW_HWNDPREV);//Ѱ��hǰһ���ֵܴ���
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_CHILD);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	::SendMessage(hwnd,WM_SETTEXT,11,(LPARAM)"10.1.198.67");
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	::SendMessage(hwnd,WM_SETTEXT,2,(LPARAM)"22");
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	hwnd = ::GetWindow(hwnd,GW_HWNDNEXT);
	::SendMessage(hwnd,WM_SETTEXT,5,(LPARAM)"aiuap");
	::SendMessage(h,WM_LBUTTONDOWN,0,0); 
	::SendMessage(h,WM_LBUTTONUP,0,0);	
	AfxMessageBox("�����ɹ�������");
}

