
// �ж�dbeaver�¾ɰ汾Dlg.h : ͷ�ļ�
//

#pragma once


// C�ж�dbeaver�¾ɰ汾Dlg �Ի���
class C�ж�dbeaver�¾ɰ汾Dlg : public CDialogEx
{
// ����
public:
	C�ж�dbeaver�¾ɰ汾Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DBEAVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
