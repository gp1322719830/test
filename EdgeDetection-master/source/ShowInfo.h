#pragma once

// CShowFilterInfo �Ի���
//��ʾ�鿴��Ϣ����

class CShowFilterInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CShowFilterInfo)

public:
	CShowFilterInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShowFilterInfo();

// �Ի�������
	enum { IDD = IDD_DIALOG_SHOW_FILTER_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonConfirm();
	CString m_ShowInfo;
	CString m_ShowInformation;
};
