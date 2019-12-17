#pragma once
#include "afxwin.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// CPaint �Ի���

class CPaint : public CDialogEx
{
	DECLARE_DYNAMIC(CPaint)

public:
	CPaint(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPaint();
// �Ի�������
	enum { IDD = IDD_DIALOG_ANALISE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStart();
	CStatic m_Picture;
	cv::Mat orgMat;
	afx_msg void OnStnClickedStaticPicture();
	};
