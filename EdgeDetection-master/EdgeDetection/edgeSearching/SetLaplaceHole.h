#pragma once


// CSetLaplaceHole �Ի���

class CSetLaplaceHole : public CDialogEx
{
	DECLARE_DYNAMIC(CSetLaplaceHole)

public:
	CSetLaplaceHole(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetLaplaceHole();

// �Ի�������
	enum { IDD = IDD_DIALOG_LAPLACE_HOLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_setLaplaceHole;
};
