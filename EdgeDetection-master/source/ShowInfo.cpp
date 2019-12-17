// ShowFilterInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "edgeSearching.h"
#include "ShowInfo.h"
#include "afxdialogex.h"
#include"commonPara.h"
#include<fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// CShowFilterInfo �Ի���

IMPLEMENT_DYNAMIC(CShowFilterInfo, CDialogEx)

CShowFilterInfo::CShowFilterInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowFilterInfo::IDD, pParent)
	, m_ShowInfo(_T(""))
	, m_ShowInformation(_T(""))
{
}

CShowFilterInfo::~CShowFilterInfo()
{
}

void CShowFilterInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SHOW_INFO, m_ShowInformation);
}

BEGIN_MESSAGE_MAP(CShowFilterInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CONFIRM, &CShowFilterInfo::OnBnClickedButtonConfirm)
END_MESSAGE_MAP()


// CShowFilterInfo ��Ϣ�������

//��ʾ��ť
void CShowFilterInfo::OnBnClickedButtonConfirm()
{
	std::ifstream mStream; //�ļ�������
	mStream.open("E:/opencv/txt/Filter.txt",std::ifstream::in); //���ļ�

	std::string line;//����ֵ
	std::string mString="";//���ı�ֵ
	
	if (!mStream)//�ļ����򿪴����򷵻�
		return;

	while (getline(mStream, line))//��ȡ�ı�����ֱ������
		mString.append(line+"\r\n");//��ÿ������׷�ӵ�mString��

	mStream.close();//�ر��ļ�

	m_ShowInformation = mString.c_str();//�ı���ֵ
	
	UpdateData(FALSE);//��������

}
