#pragma once


// CSetCannyPara �Ի���

class CSetCannyPara : public CDialogEx
{
	DECLARE_DYNAMIC(CSetCannyPara)

public:
	CSetCannyPara(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetCannyPara();

// �Ի�������
	enum { IDD = IDD_DIALOG_CANNY_THRESHOLDVALUE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_CannyValue1;
	int m_CannyValue2;
	int m_setCannyValue1;
	int m_setCannyValue2;
	int m_setCannyV1;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int m_setCannyV2;
};
