#pragma once


// CSetSobelPara �Ի���

class CSetSobelPara : public CDialogEx
{
	DECLARE_DYNAMIC(CSetSobelPara)

public:
	CSetSobelPara(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetSobelPara();

// �Ի�������
	enum { IDD = IDD_DIALOG_SOBEL_PARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_Sobeldxdy;
	int m_Sobelhole;
};
