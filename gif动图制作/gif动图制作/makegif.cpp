#include"UIlib.h"

using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")

class DuiWinWnd  : public WindowImplBase
{
protected:
	
	virtual CDuiString GetSkinFolder()
	{
		return _T("");
	}
	virtual CDuiString GetSkinFile()
	{
		return _T("makegif.xml");
	}
	virtual LPCTSTR GetWindowClassName(void)const
	{
		return _T("GIFMakeWnd");
	}

	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))//����Ϣ����
		{
			CDuiString strName = msg.pSender->GetName();
			if (strName == _T("btn_close"))
			{
				Close();
			}
			else if (strName == _T("btn_min"))
			{
				MessageBox(NULL, _T("��С��"), _T("����"), IDOK);
			}
			else if (strName == _T("btn_cmd"))
			{
				GenerateGifWithPic();
			}
		}
		else if (msg.sType == _T("itemselectchanged"))
		{
			CComboBoxUI* pComboselect = (CComboBoxUI*)m_PaintManager.FindControl(_T("combo_select"));
			int iSelect = pComboselect->GetCurSel();
			if (iSelect == 0)
			{
				MessageBox(NULL, _T("ѡ��ͼƬ"), _T("����"), IDOK);
			}
			else
			{
				MessageBox(NULL, _T("ѡ����Ƶ"), _T("����"), IDOK);
			}
		}
	}

	void SendMessage(CDuiString strCMD)//��cmd������
	{
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(strSEInfo));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:\\Windows\\System32");
		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_SHOW;
		//�������з���Ϣ
		ShellExecuteEx(&strSEInfo);
		//��������Ӧ���
		WaitForSingleObject(strSEInfo.hProcess, INFINITE);
		MessageBox(NULL, _T("�������"), _T("gif"), IDOK);
	}
	void GenerateGifWithPic()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmppeg\\");
		//��������
		CDuiString strCMD;
		
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -r 3 -i ");
		strCMD += strPath;
		strCMD += _T(".\\Pictrue\\%d.ipg ");
		strCMD += strPath;
		strCMD += _T("output.gif -y");
		//��cmd��������
		SendMessage(strCMD);
	}

};

	
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	DuiWinWnd wnd;
	wnd.Create(NULL, _T("makegif"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	wnd.CenterWindow();
	wnd.ShowModal();//������Ϣѭ��
	return 0;
}