#pragma once


// CAddBoxFilterKenelValue �Ի���

class CAddBoxFilterKenelValue : public CDialogEx
{
	DECLARE_DYNAMIC(CAddBoxFilterKenelValue)

public:
	CAddBoxFilterKenelValue(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddBoxFilterKenelValue();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHOOSE_BOXFILTER_KENELVALUE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_AddBoxFilterKenelValue;
};
