// AddBoxFilterKenelValue.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "edgeSearching.h"
#include "AddBoxFilterKenelValue.h"
#include "afxdialogex.h"


// CAddBoxFilterKenelValue �Ի���

IMPLEMENT_DYNAMIC(CAddBoxFilterKenelValue, CDialogEx)

CAddBoxFilterKenelValue::CAddBoxFilterKenelValue(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddBoxFilterKenelValue::IDD, pParent)
	, m_AddBoxFilterKenelValue(0)
{

}

CAddBoxFilterKenelValue::~CAddBoxFilterKenelValue()
{
}

void CAddBoxFilterKenelValue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BOXFILTER_KENELVALUE, m_AddBoxFilterKenelValue);
	DDV_MinMaxInt(pDX, m_AddBoxFilterKenelValue, 1, 50);
}


BEGIN_MESSAGE_MAP(CAddBoxFilterKenelValue, CDialogEx)
END_MESSAGE_MAP()


// CAddBoxFilterKenelValue ��Ϣ�������
