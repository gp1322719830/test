// SetLaplaceHole.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "edgeSearching.h"
#include "SetLaplaceHole.h"
#include "afxdialogex.h"


// CSetLaplaceHole �Ի���

IMPLEMENT_DYNAMIC(CSetLaplaceHole, CDialogEx)

CSetLaplaceHole::CSetLaplaceHole(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetLaplaceHole::IDD, pParent)
	, m_setLaplaceHole(0)
{

}

CSetLaplaceHole::~CSetLaplaceHole()
{
}

void CSetLaplaceHole::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_setLaplaceHole);
	DDV_MinMaxInt(pDX, m_setLaplaceHole, 0, 10);
}


BEGIN_MESSAGE_MAP(CSetLaplaceHole, CDialogEx)
END_MESSAGE_MAP()


// CSetLaplaceHole ��Ϣ�������
