// ggh.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ggh.h"
//
//#define MAX_LOADSTRING 100
//
//// ȫ�ֱ���:
//HINSTANCE hInst;								// ��ǰʵ��
//TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
//TCHAR szWindowClass[MAX_LOADSTRING];			// ����������
//
//// �˴���ģ���а����ĺ�����ǰ������:
//ATOM				MyRegisterClass(HINSTANCE hInstance);
//BOOL				InitInstance(HINSTANCE, int);
//LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
//
//int APIENTRY _tWinMain(HINSTANCE hInstance,
//                     HINSTANCE hPrevInstance,
//                     LPTSTR    lpCmdLine,
//                     int       nCmdShow)
//{
//	UNREFERENCED_PARAMETER(hPrevInstance);
//	UNREFERENCED_PARAMETER(lpCmdLine);
//
// 	// TODO: �ڴ˷��ô��롣
//	MSG msg;
//	HACCEL hAccelTable;
//
//	// ��ʼ��ȫ���ַ���
//	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//	LoadString(hInstance, IDC_GGH, szWindowClass, MAX_LOADSTRING);
//	MyRegisterClass(hInstance);
//
//	// ִ��Ӧ�ó����ʼ��:
//	if (!InitInstance (hInstance, nCmdShow))
//	{
//		return FALSE;
//	}
//
//	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GGH));
//
//	// ����Ϣѭ��:
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//
//	return (int) msg.wParam;
//}
//
//
//
////
////  ����: MyRegisterClass()
////
////  Ŀ��: ע�ᴰ���ࡣ
////
////  ע��:
////
////    ����ϣ��
////    �˴�������ӵ� Windows 95 �еġ�RegisterClassEx��
////    ����֮ǰ�� Win32 ϵͳ����ʱ������Ҫ�˺��������÷������ô˺���ʮ����Ҫ��
////    ����Ӧ�ó���Ϳ��Ի�ù�����
////    ����ʽ��ȷ�ġ�Сͼ�ꡣ
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//	WNDCLASSEX wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);
//
//	wcex.style			= CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc	= WndProc;
//	wcex.cbClsExtra		= 0;
//	wcex.cbWndExtra		= 0;
//	wcex.hInstance		= hInstance;
//	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GGH));
//	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
//	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
//	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_GGH);
//	wcex.lpszClassName	= szWindowClass;
//	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//	return RegisterClassEx(&wcex);
//}
//
////
////   ����: InitInstance(HINSTANCE, int)
////
////   Ŀ��: ����ʵ�����������������
////
////   ע��:
////
////        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
////        ��������ʾ�����򴰿ڡ�
////
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//   HWND hWnd;
//
//   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����
//
//   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
//
//   if (!hWnd)
//   {
//      return FALSE;
//   }
//
//   ShowWindow(hWnd, nCmdShow);
//   UpdateWindow(hWnd);
//
//   return TRUE;
//}
//
////
////  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  Ŀ��: ���������ڵ���Ϣ��
////
////  WM_COMMAND	- ����Ӧ�ó���˵�
////  WM_PAINT	- ����������
////  WM_DESTROY	- �����˳���Ϣ������
////
////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	int wmId, wmEvent;
//	PAINTSTRUCT ps;
//	HDC hdc;
//
//	switch (message)
//	{
//	case WM_COMMAND:
//		wmId    = LOWORD(wParam);
//		wmEvent = HIWORD(wParam);
//		// �����˵�ѡ��:
//		switch (wmId)
//		{
//		case IDM_ABOUT:
//			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//			break;
//		case IDM_EXIT:
//			DestroyWindow(hWnd);
//			break;
//		default:
//			return DefWindowProc(hWnd, message, wParam, lParam);
//		}
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		// TODO: �ڴ���������ͼ����...
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
//
//// �����ڡ������Ϣ�������
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	UNREFERENCED_PARAMETER(lParam);
//	switch (message)
//	{
//	case WM_INITDIALOG:
//		return (INT_PTR)TRUE;
//
//	case WM_COMMAND:
//		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//		{
//			EndDialog(hDlg, LOWORD(wParam));
//			return (INT_PTR)TRUE;
//		}
//		break;
//	}
//	return (INT_PTR)FALSE;
//}


#include <windows.h>  
#include <tchar.h>  
#include "ShellAPI.h"  
//#include "resource1.h"  
#include <string.h>

#define WM_IAWENTRAY    WM_USER+5  //ϵͳ���̵��Զ�����Ϣ  

//����ȫ�ֱ���  
HINSTANCE g_hInst;
NOTIFYICONDATA e;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	g_hInst = hInstance; //��ȡ�ó���ʵ�����  

	static TCHAR szAppName[] = TEXT("TimeWork");
	HWND         hwnd;
	MSG          msg;
	WNDCLASS     wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	WNDCLASS wc;
	 wc.style = CS_HREDRAW | CS_VREDRAW;
	 wc.lpfnWndProc = WndProc;
	 wc.cbClsExtra = 0;
	 wc.cbWndExtra = 0;
	 wc.hInstance = hInstance;
	 wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	 wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	 wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	 wc.lpszMenuName = "MainMenu";
	 wc.lpszClassName = "MainWindowClass";
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName,                  // window class name  
		TEXT("���̳���"), // window caption  
		WS_OVERLAPPEDWINDOW,        // window style  
		CW_USEDEFAULT,              // initial x position  
		CW_USEDEFAULT,              // initial y position  
		CW_USEDEFAULT,              // initial x size  
		CW_USEDEFAULT,              // initial y size  
		NULL,                       // parent window handle  
		NULL,                       // window menu handle  
		hInstance,                  // program instance handle  
		NULL);                     // creation parameters  

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//��ʼ��NOTIFYICONDATA�ṹ  
	e.cbSize = sizeof(NOTIFYICONDATA);
	e.hWnd = hwnd;
	e.uID = 107;//IDI_GGH;
	e.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	e.uCallbackMessage = WM_IAWENTRAY;
	e.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_GGH));
	//e.hIcon = LoadIcon(g_hInst, (LPCTSTR)(32512));
	strcpy_s(e.szTip,20,"��̫���ˣ�"); //��ӵ�������ʾ���ַ��������������̴�����ʾ��ʾ����
	//	_tcscpy(e.szTip, TEXT("TimeWork���ڹ�����\r\n�����������")); //_tcscpy��windows�꣬�����ͷ�ļ�tchar.h  

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT        rect;

	switch (message)
	{
	case WM_CREATE:
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rect);

		DrawText(hdc, TEXT("Hello, my fridents��"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
		return 0;

	case WM_IAWENTRAY:
		if (wParam == IDI_GGH) {
			if (lParam == WM_LBUTTONDOWN) {
				//������������ط�����һ���˵�������Ҽ�����ʱ��ʾ  
				ShowWindow(hwnd, SW_SHOWNORMAL);
				return TRUE;
			}
		}
		return FALSE;
	case WM_SYSCOMMAND:
		switch (wParam)
		{
		case SC_CLOSE:
			DestroyWindow(hwnd);
			PostQuitMessage(0);
			break;
		case SC_MINIMIZE:
			ShowWindow(hwnd, SW_HIDE);
			Shell_NotifyIcon(NIM_ADD, &e); //��С��ʱ���ش��ڲ�����ϵͳ����  
			break;
		}
		return 0;

	case WM_DESTROY:
		Shell_NotifyIcon(NIM_DELETE, &e);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam); 

}
