// project1.cpp : ����Ӧ�ó������ڵ㡣
//
/*
#include "stdafx.h"
#include "project1.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���:
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
HINSTANCE hPrevInstance,
LPTSTR    lpCmdLine,
int       nCmdShow)
{
UNREFERENCED_PARAMETER(hPrevInstance);
UNREFERENCED_PARAMETER(lpCmdLine);

// TODO: �ڴ˷��ô��롣
MSG msg;
HACCEL hAccelTable;

// ��ʼ��ȫ���ַ���
LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
LoadString(hInstance, IDC_PROJECT1, szWindowClass, MAX_LOADSTRING);
MyRegisterClass(hInstance);

// ִ��Ӧ�ó����ʼ��:
if (!InitInstance (hInstance, nCmdShow))
{
return FALSE;
}

hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT1));

// ����Ϣѭ��:
while (GetMessage(&msg, NULL, 0, 0))
{
if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
{
TranslateMessage(&msg);
DispatchMessage(&msg);
}
}

return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
//  ע��:
//
//    ����ϣ��
//    �˴�������ӵ� Windows 95 �еġ�RegisterClassEx��
//    ����֮ǰ�� Win32 ϵͳ����ʱ������Ҫ�˺��������÷������ô˺���ʮ����Ҫ��
//    ����Ӧ�ó���Ϳ��Ի�ù�����
//    ����ʽ��ȷ�ġ�Сͼ�ꡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
WNDCLASSEX wcex;

wcex.cbSize = sizeof(WNDCLASSEX);

wcex.style			= CS_HREDRAW | CS_VREDRAW;
wcex.lpfnWndProc	= WndProc;
wcex.cbClsExtra		= 0;
wcex.cbWndExtra		= 0;
wcex.hInstance		= hInstance;
wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_PROJECT1);
wcex.lpszClassName	= szWindowClass;
wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

return RegisterClassEx(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
HWND hWnd;

hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

if (!hWnd)
{
return FALSE;
}

ShowWindow(hWnd, nCmdShow);
UpdateWindow(hWnd);

return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
int wmId, wmEvent;
PAINTSTRUCT ps;
HDC hdc;

switch (message)
{
case WM_COMMAND:
wmId    = LOWORD(wParam);
wmEvent = HIWORD(wParam);
// �����˵�ѡ��:
switch (wmId)
{
case IDM_ABOUT:
DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
break;
case IDM_EXIT:
DestroyWindow(hWnd);
break;
default:
return DefWindowProc(hWnd, message, wParam, lParam);
}
break;
case WM_PAINT:
hdc = BeginPaint(hWnd, &ps);
// TODO: �ڴ���������ͼ����...
EndPaint(hWnd, &ps);
break;
case WM_DESTROY:
PostQuitMessage(0);
break;
default:
return DefWindowProc(hWnd, message, wParam, lParam);
}
return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
UNREFERENCED_PARAMETER(lParam);
switch (message)
{
case WM_INITDIALOG:
return (INT_PTR)TRUE;

case WM_COMMAND:
if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
{
EndDialog(hDlg, LOWORD(wParam));
return (INT_PTR)TRUE;
}
break;
}
return (INT_PTR)FALSE;
}
*/

#include "stdafx.h"
#include<Windows.h>
#include <tchar.h>  
#include "ShellAPI.h"
#include "Resource.h"
#include<iostream>
#include<atltime.h>
#include<string.h>
int APIENTRY WinMain(HINSTANCE hInstance, // ��ģ���ʵ�����
HINSTANCE hPrevInstance, // Win16 ���µķ�������Ѿ�������
LPSTR lpCmdLine, // �����в���
int nCmdShow) // �����ڳ�ʼ��ʱ����ʾ��ʽ
{ // �������д���������ӵģ����ڵ���һ��С�Ի���
int nSel = MessageBox(NULL, TEXT("Hello, Win32 Application"), TEXT("04Win32AppDemo"), MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3); //MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3
if(nSel == IDYES) // �û�ѡ���ˡ��ǡ���ť
{
	ShellExecute(0,"open","calc.exe","","",SW_SHOWNORMAL);
	Sleep(5000);
	CString strTime;
	CTime tTime = CTime::GetCurrentTime();
	strTime = tTime.Format("%Y��%m��%d��%H��%M��%S��");
	HWND maindHwnd = FindWindow(NULL, "������");
	if(!maindHwnd)
	{
		MessageBox(NULL,_T("û���ҵ��ô���"),_T("��ʾ"),MB_OK);
	}
	SendMessage(maindHwnd,WM_CLOSE,0,0);
	MessageBox(NULL,_T("���������"),strTime,MB_YESNOCANCEL|MB_ICONQUESTION|MB_DEFBUTTON3);
}
else if(nSel == IDNO) // �û�ѡ���ˡ��񡱰�ť
{

} else if(nSel == IDCANCEL) // �û�ѡ���ˡ�ȡ������ť
{

}
return 0; 
}




////////////////////////////////////////////////////////////////////

//#define WM_IAWENTRAY    WM_USER+5  //ϵͳ���̵��Զ�����Ϣ  
//
//NOTIFYICONDATA e;
//
//
//LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); 
//int APIENTRY WinMain(HINSTANCE hInstance,    //Win32������
//	HINSTANCE hPrevInstance, 
//	LPSTR lpCmdLine, 
//	int nCmdShow) 
//{ 
//	char szClassName[] = "MainWClass"; 
//	WNDCLASSEX wndclass; 
//	// �����������ڵĲ������WNDCLASSEX �ṹ
//	wndclass.cbSize = sizeof(wndclass); // �ṹ�Ĵ�С
//	wndclass.style = CS_HREDRAW|CS_VREDRAW; // ָ�������С�ı���ػ�
//	wndclass.lpfnWndProc = MainWndProc; // ���ں���ָ��
//	wndclass.cbClsExtra = 0; // û�ж�������ڴ�
//	wndclass.cbWndExtra = 0; // û�ж���Ĵ����ڴ�
//	wndclass.hInstance = hInstance; // ʵ����� 
//	wndclass.hIcon = ::LoadIcon(NULL, MAKEINTRESOURCE(IDI_PROJECT1)); // ʹ��Ԥ����ͼ�� MAKEINTRESOURCE(IDI_PROJECT1)
//	wndclass.hCursor = ::LoadCursor(NULL, IDC_ARROW); // ʹ��Ԥ����Ĺ��
//	wndclass.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH); // ʹ�ð�ɫ������ˢ
//	wndclass.lpszMenuName = NULL; // ��ָ���˵�
//	wndclass.lpszClassName = szClassName ; // ����������� 
//	wndclass.hIconSm = NULL; // û�����Сͼ��
//	// ע�����������
//	::RegisterClassEx(&wndclass); 
//	// ����������
//	HWND hwnd = ::CreateWindowEx( 
//		0, // dwExStyle����չ��ʽ 
//		szClassName, // lpClassName������ 
//		TEXT("�������չʾ!"), // lpWindowName������ 
//		WS_OVERLAPPEDWINDOW, // dwStyle�����ڷ�� 
//		CW_USEDEFAULT, // X����ʼ X ���� 
//		CW_USEDEFAULT, // Y����ʼ Y ���� 
//		CW_USEDEFAULT, // nWidth����� 
//		CW_USEDEFAULT, // nHeight���߶� 
//		NULL, // hWndParent�������ھ�� 
//		NULL, // hMenu���˵���� 
//		hInstance, // hlnstance������ʵ����� 
//		NULL) ; // lpParam���û����� 
//	if(hwnd == NULL) 
//	{ ::MessageBox(NULL, TEXT("�������ڳ���"), TEXT("error"), MB_OK); 
//	return -1; 
//	} 
//	// ��ʾ���ڣ�ˢ�´��ڿͻ���
//	::ShowWindow(hwnd, nCmdShow); 
//	::UpdateWindow(hwnd); 
//	// ����Ϣ������ȡ����Ϣ���������ں�������ֱ��GetMessage ����FALSE��������Ϣѭ��
//	MSG msg; 
//
//
//	//��ʼ��NOTIFYICONDATA�ṹ  
//	e.cbSize = sizeof(NOTIFYICONDATA);
//	e.hWnd = hwnd;
//	e.uID = 107;//IDI_GGH;
//	e.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
//	e.uCallbackMessage = WM_IAWENTRAY;
//	e.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT1));
//	//e.hIcon = LoadIcon(g_hInst, (LPCTSTR)(32512));
//	strcpy_s(e.szTip,20,"��̫���ˣ�"); //��ӵ�������ʾ���ַ��������������̴�����ʾ��ʾ����
//	//	_tcscpy(e.szTip, TEXT("TimeWork���ڹ�����\r\n�����������")); //_tcscpy��windows�꣬�����ͷ�ļ�tchar.h 
//
//	while(::GetMessage(&msg, NULL, 0, 0)) 
//	{ // ת��������Ϣ
//		::TranslateMessage(&msg); 
//		// ����Ϣ���͵���Ӧ�Ĵ��ں���
//		::DispatchMessage(&msg); 
//	} 
//	// �� GetMessage ����FALSE ʱ�������
//	return msg.wParam; 
//} 
//LRESULT CALLBACK MainWndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) //�ص�����
//{
//	char szText[] = "Hello world��";
//	//int cxChar = LOWORD (GetDialogBaseUnits ());    //��ô������ڶ�������Ԫ��ȣ������飩
//	//int cyChar = HIWORD (GetDialogBaseUnits ());    //��ô������ڶ�������Ԫ�߶ȣ������飩
//	switch (message) 
//	{ 
//	case WM_PAINT: // ���ڿͻ�����Ҫ�ػ�
//		{ HDC hdc; 
//		PAINTSTRUCT ps; 
//		// ʹ��Ч�Ŀͻ��������Ч����ȡ���豸�������
//		hdc = ::BeginPaint (hwnd, &ps) ; 
//		// ��ʾ����
//		TextOut(hdc, 500, 250, szText, strlen(szText)); 
//		/*TextOut (   hdc, 
//		rect.right / 2 - cxChar * lstrlen ( szText ) / 2,       //ʹ�ַ����ڴ�����ˮƽ����
//		( rect.bottom - cyChar ) / 2,                           //ʹ�ַ����ڴ����д�ֱ����
//		szText,                     //�ַ���������
//		lstrlen ( szText )          //lstrlen������ȡ�ַ����ĳ���
//		) ;*/
//		::EndPaint(hwnd, &ps); 
//		return 0; 
//		} 
//		//case WM_DESTROY: // �������ٴ���
//		//	// ����Ϣ����Ͷ��һ��WM_QUIT ��Ϣ����ʹGetMessage ��������0��������Ϣѭ��
//		//	::PostQuitMessage(0) ; 
//		//		return 0 ; 
//	case WM_DESTROY:
//		Shell_NotifyIcon(NIM_DELETE, &e);
//		PostQuitMessage(0);
//		return 0;
//	case WM_SYSCOMMAND:
//		switch (wParam)
//		{
//		case SC_CLOSE:
//			DestroyWindow(hwnd);
//			PostQuitMessage(0);
//			break;
//		case SC_MINIMIZE:
//			ShowWindow(hwnd, SW_HIDE);
//			Shell_NotifyIcon(NIM_ADD, &e); //��С��ʱ���ش��ڲ�����ϵͳ����  
//			break;		
//		}
//		return 0;
//
//	} 
//	// �����ǲ��������Ϣ����ϵͳ��Ĭ�ϴ���
//	return ::DefWindowProc(hwnd, message, wParam, lParam); 
//}