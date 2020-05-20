
// testOssmainDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "testOssmain.h"
#include "testOssmainDlg.h"
#include "afxdialogex.h"

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


// CtestOssmainDlg �Ի���




CtestOssmainDlg::CtestOssmainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestOssmainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestOssmainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestOssmainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtestOssmainDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtestOssmainDlg ��Ϣ�������

BOOL CtestOssmainDlg::OnInitDialog()
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

void CtestOssmainDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtestOssmainDlg::OnPaint()
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
HCURSOR CtestOssmainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "tinyxml2.h"
#include<stdio.h>
#include<Windows.h>

//#define _stat _stat64i32
using namespace std;
#include <userenv.h>
#pragma comment(lib,"userenv.lib") 


const char* dbeaver_tmpl = "<data-source id =\"%s\" provider=\"generic\" driver=\"vertica\" name=\"%s\" create-date=\"1426155106241\" update-date=\"1426755003074\" save-password=\"true\" show-system-objects=\"true\" read-only=\"false\" creator=\"ai4a\"> \
						   <connection host = \"%s\" port=\"%s\" server=\"\" database=\"%s\" url=\"%s\" user=\"%s\" password=\"%s\" type=\"dev\"> \
						   <network-handler type = \"PROXY\" id=\"socks_proxy\" enabled=\"false\" user=\"\" save-password=\"false\"> \
						   <property name = \"socks-host\" value=\"\"/> \
						   <property name = \"socks-port\" value=\"1080\"/> \
						   </network-handler> \
						   <network-handler type = \"TUNNEL\" id=\"ssh_tunnel\" enabled=\"false\" user=\"\" save-password=\"false\"> \
						   <property name = \"port\" value=\"22\"/> \
						   <property name = \"host\" value=\"\"/> \
						   <property name = \"keyPath\" value=\"\"/> \
						   <property name = \"authType\" value=\"PASSWORD\"/> \
						   </network-handler> \
						   </connection> \
						   <custom-property name = \"default.activeObject\" value=\"\"/> \
						   </data-source>";
const char* dbeaver_tmp_postgresql = "<data-source id =\"%s\" provider=\"generic\" driver=\"postgresql\" name=\"%s\" create-date=\"1426155106241\" update-date=\"1426755003074\" save-password=\"true\" show-system-objects=\"true\" read-only=\"false\" creator=\"ai4a\"> \
									 <connection host = \"%s\" port=\"%s\" server=\"\" database=\"%s\" url=\"%s\" user=\"%s\" password=\"%s\" type=\"dev\"> \
									 <network-handler type = \"PROXY\" id=\"socks_proxy\" enabled=\"false\" user=\"\" save-password=\"false\"> \
									 <property name = \"socks-host\" value=\"\"/> \
									 <property name = \"socks-port\" value=\"1080\"/> \
									 </network-handler> \
									 <network-handler type = \"TUNNEL\" id=\"ssh_tunnel\" enabled=\"false\" user=\"\" save-password=\"false\"> \
									 <property name = \"port\" value=\"22\"/> \
									 <property name = \"host\" value=\"\"/> \
									 <property name = \"keyPath\" value=\"\"/> \
									 <property name = \"authType\" value=\"PASSWORD\"/> \
									 </network-handler> \
									 </connection> \
									 <custom-property name = \"default.activeObject\" value=\"\"/> \
									 </data-source>";

const char ENCRYPTION_KEY[] = "sdf@!#$verf^wv%6Fwe%$$#FFGwfsdefwfe135s$^H)dg";
const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

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

void log2file(char *fmt, ...)
{
	FILE *fp = NULL;
	va_list args = NULL;
	char sprint_buf[1024] = {0};


	char timebuf[50] = {0};
	struct tm *stm ;
	time_t tt = time(NULL);
	stm= localtime(&tt);
	sprintf(timebuf, "%d[%04d-%02d-%02d %02d:%02d:%02d]:", GetCurrentProcessId(),stm->tm_year+1900,
		stm->tm_mon+1, stm->tm_mday, stm->tm_hour, stm->tm_min, stm->tm_sec);

	char filename[250] = {0};
	sprintf(filename, "C:\\asia_log\\testOssMain_%04d-%02d-%02d.log", stm->tm_year+1900,
		stm->tm_mon+1, stm->tm_mday);
	fp = fopen(filename, "a+");
	if(fp)
	{
		va_start(args, fmt);


		//fprintf(fp, "[%s]:",timebuf);
		fprintf(fp, timebuf);
		vfprintf(fp, fmt, args);
		fprintf(fp, "\n");
		va_end(args);
		fclose(fp);
	}

	return;

}


void getXmlDirPath(std::wstring &filePath){
	DWORD dwSize = 256;
	wchar_t szHomeDir[256] = { 0 };
	memset(szHomeDir, 0, dwSize);
	HANDLE hToken = 0;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
	{
		if (GetUserProfileDirectoryW(hToken, szHomeDir, &dwSize))
		{
			//filePath.append(szHomeDir).append(L"\\.dbeaver");Users\\�¼�ʢ\\AppData\\Roaming\\DBeaverData\\workspace6\\.metadata
			filePath.append(szHomeDir).append(L"\\AppData\\Roaming\\DBeaverData\\workspace6");
		}
	}
}
//�жϵ�ǰdbeaver�Ƿ��Ѿ�������postgresql��jdbc����
BOOL isInstallPostgreDiver(std::wstring &driverXmlPath,std::wstring &xmlPath)
{
	HANDLE pFile;
	DWORD fileSize;
	char *buffer,*tmpBuf;C:
	DWORD dwBytesRead,dwBytesToRead,tmpLen;
	pFile = CreateFileW(driverXmlPath.c_str(),GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
		//���Ѵ��ڵ��ļ� 
		FILE_ATTRIBUTE_NORMAL, NULL); 
	if ( pFile == INVALID_HANDLE_VALUE) 
	{ 
		//printf("open file error!\n"); 
		CloseHandle(pFile); 
		driverXmlPath= L"";
		driverXmlPath.append(L"C:\\Users\\�¼�ʢ\\AppData\\Roaming\\DBeaverData\\workspace6\\.metadata\\.plugins\\org.jkiss.dbeaver.core\\drivers.xml");

		pFile = CreateFileW(driverXmlPath.c_str(),GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL, NULL); 
		if ( pFile == INVALID_HANDLE_VALUE) 
		{
			return FALSE; 
		}
	} 
	fileSize = GetFileSize(pFile,NULL); 
	//�õ��ļ��Ĵ�С 
	buffer = (char *) malloc(fileSize+2); 
	ZeroMemory(buffer,fileSize); 
	dwBytesToRead = fileSize; 
	dwBytesRead = 0; 
	tmpBuf = buffer; 
	do{ //ѭ�����ļ���ȷ�������������ļ�    
		ReadFile(pFile,tmpBuf,dwBytesToRead,&dwBytesRead,NULL);
		if (dwBytesRead == 0) 
			break; 
		dwBytesToRead -= dwBytesRead; 
		tmpBuf += dwBytesRead;
	} while (dwBytesToRead > 0); 
	CloseHandle(pFile); 
	//�����Ƿ�װ������
	//log2file("\npostgres diver xml:%s\n",buffer);
	if(strstr(buffer,"postgresql")!=NULL)
	{
		free(buffer); 
		return TRUE;
	}

	free(buffer); 
	return FALSE;

}

//
void DisplayErrorText(
	DWORD dwError
	)
{
	//_asm {int 3};
	HLOCAL hlocal = NULL;   // Buffer that gets the error message string

	// Use the default system locale since we look for Windows messages.
	// Note: this MAKELANGID combination has 0 as value
	DWORD systemLocale = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);

	// Get the error code's textual description
	BOOL fOk = FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS |
		FORMAT_MESSAGE_ALLOCATE_BUFFER, 
		NULL, dwError, systemLocale, 
		(PTSTR) &hlocal, 0, NULL);

	if (!fOk) {
		// Is it a network-related error?
		HMODULE hDll = LoadLibraryEx(TEXT("netmsg.dll"), NULL, 
			DONT_RESOLVE_DLL_REFERENCES);

		if (hDll != NULL) {
			fOk = FormatMessage(
				FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS |
				FORMAT_MESSAGE_ALLOCATE_BUFFER,
				hDll, dwError, systemLocale,
				(PTSTR) &hlocal, 0, NULL);
			FreeLibrary(hDll);
		}
	}

	if (fOk && (hlocal != NULL)) {
		//SetDlgItemText(hwnd, IDC_ERRORTEXT, (PCTSTR) LocalLock(hlocal));
		MessageBox(0,(PCTSTR) LocalLock(hlocal),TEXT("error"),MB_ICONERROR);
		LocalFree(hlocal);
	} else {
		MessageBox(0,TEXT("No text found for this error number."),TEXT("error"),MB_ICONERROR);
	}
}
#define _ENCODE32
CString  ax_asia_decryption(const char* lpSrc)
{
	CString strResult = "";
#ifdef _ENCODE32
	HINSTANCE hLib = LoadLibrary("encode2.dll");
#else
	HINSTANCE hLib = LoadLibrary("encode2_x64.dll");
#endif
	//ָ��Ҫע���ocx�ļ���·�����ļ�����
	if (hLib == NULL)
	{
		//MessageBox("��������OCX�ļ�!");
		log2file("����encodeģ��ʧ��");
		DisplayErrorText(GetLastError());
		//strlog.Format(_T("�ؼ�%s����ʧ��"),ocxpath);
		//AppendLog(strlog);

		return strResult;
	}
	//strlog.Format(_T("�ؼ�%s����ɹ�"),ocxpath);
	//AppendLog(strlog);


	//��ȡע�ắ��DllRegisterServer��ַ
	typedef char* (__cdecl *_asia_decryption)(const char *src);
	_asia_decryption asia_decryption = (_asia_decryption)GetProcAddress(hLib,"asia_decryption");



	//����ע�ắ��DllRegisterServer
	if(asia_decryption!=NULL)
	{
		strResult = (*asia_decryption)(lpSrc);

		return strResult;
	}
	else
	{
		log2file("����encode�ں���ʧ��");
		DisplayErrorText(GetLastError());
		//strlog.Format(_T("���ҿؼ�%sע�ắ��ʧ��"),ocxpath);
		//AppendLog(strlog);
	}
	FreeLibrary(hLib);
	return strResult;
	//return NULL;
}
//const char ENCRYPTION_KEY[] = "sdf@!#$verf^wv%6Fwe%$$#FFGwfsdefwfe135s$^H)dg";
//const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
char *base64_encodefordbeaver(const char* data, int data_len)
{
	int prepare = 0, ret_len = 0, temp = 0, tmp = 0, i = 0;
	char *ret = NULL;
	char *f = NULL;
	char changed[4];
	ret_len = data_len / 3;
	temp = data_len % 3;
	if (temp > 0)
	{
		ret_len += 1;
	}
	ret_len = ret_len * 4 + 1;
	ret = (char *) malloc(ret_len);
	if (ret == NULL)
	{
		exit(0);
	}
	memset(ret, 0, ret_len);
	f = ret;
	while (tmp < data_len)
	{
		temp = 0;
		prepare = 0;
		memset(changed, '\0', 4);
		while (temp < 3)
		{
			if (tmp >= data_len)
			{
				break;
			}
			prepare = ((prepare << 8) | (data[tmp] & 0xFF));
			tmp++;
			temp++;
		}
		prepare = (prepare << ((3 - temp) * 8));
		for (i = 0; i < 4; i++)
		{
			if (temp < i)
			{
				changed[i] = 0x40;
			}
			else
			{
				changed[i] = (prepare >> ((3 - i) * 6)) & 0x3F;
			}
			*f = base[changed[i]];
			f++;
		}
	}
	*f = '\0';
	return ret;
}
char* dbeaver_pwd_encode(const char* str, int len){
	char* szBuf = new char[len + 2];
	memcpy(szBuf, str, len);
	szBuf[len] = 0;
	szBuf[len + 1] = -127;
	int keyOffset = 0, keyLen = strlen(ENCRYPTION_KEY);
	for (int i = 0; i < len + 2; i++) {
		byte keyChar = ENCRYPTION_KEY[keyOffset];
		keyOffset++;
		if (keyOffset >= keyLen) {
			keyOffset = 0;
		}
		szBuf[i] ^= keyChar;
	}
	char* result = base64_encodefordbeaver(szBuf, len + 2);
	delete szBuf;
	return result;
}

void OutputDebugPrintf(const char * strOutputString,...)
{
	char strBuffer[4096]={0};
	va_list vlArgs;
	va_start(vlArgs,strOutputString);
	_vsnprintf(strBuffer,sizeof(strBuffer)-1,strOutputString,vlArgs);
	//vsprintf(strBuffer,strOutputString,vlArgs);
	va_end(vlArgs);
	OutputDebugString(strBuffer);
}
//const char* dbeaver_tmp_postgresql = "<data-source id =\"%s\" provider=\"generic\" driver=\"postgresql\" name=\"%s\" create-date=\"1426155106241\" update-date=\"1426755003074\" save-password=\"true\" show-system-objects=\"true\" read-only=\"false\" creator=\"ai4a\"> \
//									 <connection host = \"%s\" port=\"%s\" server=\"\" database=\"%s\" url=\"%s\" user=\"%s\" password=\"%s\" type=\"dev\"> \
//									 <network-handler type = \"PROXY\" id=\"socks_proxy\" enabled=\"false\" user=\"\" save-password=\"false\"> \
//									 <property name = \"socks-host\" value=\"\"/> \
//									 <property name = \"socks-port\" value=\"1080\"/> \
//									 </network-handler> \
//									 <network-handler type = \"TUNNEL\" id=\"ssh_tunnel\" enabled=\"false\" user=\"\" save-password=\"false\"> \
//									 <property name = \"port\" value=\"22\"/> \
//									 <property name = \"host\" value=\"\"/> \
//									 <property name = \"keyPath\" value=\"\"/> \
//									 <property name = \"authType\" value=\"PASSWORD\"/> \
//									 </network-handler> \
//									 </connection> \
//									 <custom-property name = \"default.activeObject\" value=\"\"/> \
//									 </data-source>";

BOOL DeleteDirectory(LPCWSTR strDes)
{
	//ɾ��Ŀ��Ŀ¼�µ������ļ�     
	WIN32_FIND_DATAW       FileData;
	HANDLE                hSearch;
	BOOL                  bFinished = FALSE;
	std::wstring               strTemp;

	strTemp = strDes;
	strTemp += L"//*.*";

	hSearch = FindFirstFileW(strTemp.c_str(), &FileData);
	if (hSearch == INVALID_HANDLE_VALUE)
	{
		bFinished = TRUE;           //��Ŀ¼��û���ļ�
	}
	while (!bFinished)
	{
		strTemp = strDes;
		strTemp += L"//";
		strTemp += FileData.cFileName;
		//strTemp = strTemp + L"//" +FileData.cFileName;
		if ((wcscmp(FileData.cFileName, L".") != 0) && (wcscmp(FileData.cFileName, L"..") != 0))
		{
			//��Ŀ¼�ͽ���ݹ����     
			if (FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				DeleteDirectory(strTemp.c_str());
			}
			else
			{//���ļ���ɾ��     
				DeleteFileW(strTemp.c_str());
			}
		}
		bFinished = FindNextFileW(hSearch, &FileData) ? FALSE : TRUE;
	}
	FindClose(hSearch);
	//ɾ����Ŀ¼     
	RemoveDirectoryW(strDes);
	return TRUE;
}

std::string ws2s(std::wstring& inputws)
{ 
	return WChar2Ansi(inputws.c_str()); 
}
#include <sys/stat.h>

short LocalDbeaver4PostgresqlLogin(LPCTSTR sExecName, LPCTSTR cUserName, LPCTSTR cPassWord, LPCTSTR cHost, LPCTSTR cPort, LPCTSTR cDbName, LPCTSTR cCharSet)
{
	//_asm{int 3};
	log2file("%s: %s %s %s %s %s %s %s",__FUNCTION__,sExecName,cUserName,cPassWord,cHost,cPort,cDbName,cCharSet);
	std::wstring xmlPath= L"";
	std::wstring driverXmlPath= L"";
	getXmlDirPath(xmlPath);
	std::wstring metadataPath = xmlPath;
	driverXmlPath = xmlPath;
	driverXmlPath.append(L"\\.metadata\\.plugins\\org.jkiss.dbeaver.core\\drivers.xml");
	log2file("xml:%s",ws2s(driverXmlPath).c_str());
	if(!isInstallPostgreDiver(driverXmlPath,xmlPath))
	{
		::MessageBox(NULL, "û�и�Dbeaver��������Postgresql������", "��ʾ", 0);
		return 0;
	}
	xmlPath.append(L"\\General");
	
	SHCreateDirectory(NULL, xmlPath.c_str());

	string str_tmp = cPassWord;
	CString strpassword = ax_asia_decryption(str_tmp.c_str());
	if(strpassword.GetLength() < 1)
	{
		log2file("Dbeaver4Postgresql����ʹ����δ���ܵ�����");
		strpassword = str_tmp.c_str();
	}
	char* encodedPwd = dbeaver_pwd_encode(strpassword.GetString(), strpassword.GetLength());
	tinyxml2::XMLDocument doc(false);
	xmlPath.append(L"\\.dbeaver-data-sources.xml");
	struct _stat buf;
	int result = _stat(ws2s(xmlPath).c_str(), &buf);
	OutputDebugPrintf("LocalDbeaver4PostgresqlLogin:xml·��:%s",ws2s(xmlPath).c_str());
	log2file("LocalDbeaver4PostgresqlLogin:xml·��:%s",ws2s(xmlPath).c_str());
	//log2file();
	if (result != 0)
	{
		metadataPath.append(L"\\.metadata\\.plugins\\org.eclipse.core.resources");
		//RemoveDirectoryW(metadataPath.c_str());
		//SHFILEOPSTRUCTW FileOp = { 0 };
		//FileOp.fFlags = FOF_ALLOWUNDO |   //����Żػ���վ
		//	FOF_NOCONFIRMATION | FOF_SILENT; //������ȷ�϶Ի���
		//FileOp.pFrom = metadataPath.c_str();//L"C:\\Users\\zhangtx\\.dbeaver\\.metadata\\.plugins\\org.eclipse.core.resources";
		//FileOp.pTo = NULL;      //һ��Ҫ��NULL
		//FileOp.wFunc = FO_DELETE;    //ɾ������
		//result = SHFileOperationW(&FileOp);
		DeleteDirectory(metadataPath.c_str());
		//DeleteDirs(metadataPath.c_str());
		//::MessageBoxA(NULL, ws2s(metadataPath).c_str(),"Tips",MB_OK);
		//Sleep(500);
	}
	doc.LoadFile(ws2s(xmlPath).c_str());
	tinyxml2::XMLNode* root = doc.RootElement();
	if (!root)
	{
		doc.NewDeclaration();
		root = doc.InsertEndChild(doc.NewElement("data-sources"));
	}
	tinyxml2::XMLElement* curElement = root->FirstChildElement("data-source");
	tinyxml2::XMLElement* nextElement = NULL;
	while (curElement)
	{
		nextElement = curElement->NextSiblingElement();
		if (strstr(curElement->Attribute("id"), "creator_ai4a")){
			const char* txt = curElement->Value();
			doc.DeleteNode(curElement);
		}
		curElement = nextElement;
	}
	char* szBuf = (char*) malloc(2000);
	::memset(szBuf, 0, 2000);
	char szDbTitle[200] = { 0 };
	sprintf(szDbTitle, "PostgreSQL_%s_%s_%s", cHost, cPort, cDbName);
	char szDbUrl[200] = {0};
	sprintf(szDbUrl, "jdbc:postgresql://%s:%s/%s", cHost, cPort, cDbName);
	sprintf(szBuf, dbeaver_tmp_postgresql, "postgresql-1426154947249-creator_ai4a",
		szDbTitle, //dbname
		cHost, //host
		cPort, //port
		cDbName, //database
		szDbUrl, //url
		cUserName, //username
		encodedPwd //password
		);
	tinyxml2::XMLDocument docNode;
	docNode.Parse(szBuf);
	tinyxml2::XMLPrinter printer;
	docNode.Print(&printer);
	tinyxml2::XMLText* textNode = doc.NewText(printer.CStr());
	root->InsertFirstChild(textNode);
	doc.SaveFile(ws2s(xmlPath).c_str());
	free(szBuf);
	free(encodedPwd);

	////����Ϊ����vertica���ݿ�jar���Ĵ���
	//tinyxml2::XMLDocument doc1(false);
	//doc1.LoadFile(ws2s(driverXmlPath).c_str());
	//tinyxml2::XMLNode* root1 = doc1.RootElement();
	//if(root1)
	//{
	//	tinyxml2::XMLElement* providerNode=root1->FirstChildElement("provider");
	//	while(providerNode!=NULL)
	//	{
	//		const char *p = providerNode->Attribute("id");
	//		if(strcmp(providerNode->Attribute("id"),"generic")==0)
	//			break;
	//		providerNode=providerNode->NextSiblingElement();//��һ���ֵܽڵ�
	//	}
	//	if(providerNode)
	//	{
	//		tinyxml2::XMLElement* driverNode=providerNode->FirstChildElement("driver");
	//		while(driverNode!=NULL)
	//		{
	//			const char *p = providerNode->Attribute("id");
	//			if(strcmp(driverNode->Attribute("id"),"postgresql")==0)
	//				break;
	//			driverNode=driverNode->NextSiblingElement();//��һ���ֵܽڵ�
	//		}
	//		if(driverNode)
	//		{
	//			doc1.DeleteNode(driverNode);
	//		}
	//		tinyxml2::XMLElement* verticaNode = doc1.NewElement("driver");
	//		verticaNode->SetAttribute("id","postgresql");
	//		verticaNode->SetAttribute("custom ","false");
	//		verticaNode->SetAttribute("name ","PostgreSQL");
	//		verticaNode->SetAttribute("class ","org.postgresql.Driver");
	//		verticaNode->SetAttribute("url ","jdbc:vertica://{host}:{port}/{database}");
	//		verticaNode->SetAttribute("port ","5433");
	//		verticaNode->SetAttribute("description ","PostgreSQL standard driver");
	//		tinyxml2::XMLElement* verticaDriverNode = doc1.NewElement("library");
	//		verticaDriverNode->SetAttribute("path","C:\\Windows\\postgresql-9.1-901.jdbc4.jar");
	//		verticaNode->InsertEndChild(verticaDriverNode);
	//		providerNode->InsertEndChild(verticaNode);

	//	}
	//}
	//doc1.SaveFile(ws2s(driverXmlPath).c_str());

	//����dbeaver.exe���
	HINSTANCE hInstance = ShellExecute(NULL, "open", sExecName, "", "", SW_SHOW);
	if ((int) hInstance < 32)
	{
		char cTmp[255];
		sprintf(cTmp, "û�а�װ%s�����Ҳ���%s(���������û�������)", sExecName, sExecName);
		::MessageBox(NULL, cTmp, "��ʾ", 0);
		return -1;
	}
	return 0;
}
void CtestOssmainDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LocalDbeaver4PostgresqlLogin("C:\\Users\\�¼�ʢ\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\DBeaver Community\\DBeaver","postgres","postgres","10.1.198.67 ","5432","postgres",NULL);
}
