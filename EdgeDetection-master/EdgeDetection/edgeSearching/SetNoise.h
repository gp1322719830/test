#pragma once


// CSetNoise �Ի���

class CSetNoise : public CDialogEx
{
	DECLARE_DYNAMIC(CSetNoise)

public:
	CSetNoise(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetNoise();

// �Ի�������
	enum { IDD = IDD_NOISE_PS_SPOT_N_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_SetNoise;
};
