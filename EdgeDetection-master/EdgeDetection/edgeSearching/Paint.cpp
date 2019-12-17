// Paint.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "edgeSearching.h"
#include "Paint.h"
#include "afxdialogex.h"


// CPaint �Ի���

IMPLEMENT_DYNAMIC(CPaint, CDialogEx)

CPaint::CPaint(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPaint::IDD, pParent)
{
}

CPaint::~CPaint()
{
}

void CPaint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PICTURE, m_Picture);
}


BEGIN_MESSAGE_MAP(CPaint, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_START, &CPaint::OnBnClickedButtonStart)
	ON_STN_CLICKED(IDC_STATIC_PICTURE, &CPaint::OnStnClickedStaticPicture)
END_MESSAGE_MAP()


// CPaint ��Ϣ�������



void CPaint::OnBnClickedButtonStart()
{
	CPen myPen,pen2,pen3;
	CDC *pDC = m_Picture.GetDC();
	CRect Rect;

	m_Picture.GetClientRect(&Rect);
	myPen.CreatePen(PS_SOLID,3,RGB(0,255,0)); //����ʵ�Ļ��ʣ��ֶ�Ϊ3����ɫ��ɫ
	pen2.CreatePen(PS_DOT,1,RGB(100,100,100));
	pen3.CreatePen(PS_SOLID,5,(RGB(0,0,255)));


	////��������ϵ
	pDC->SelectObject(&myPen);//ѡ�񻭱�
	pDC->MoveTo(Rect.left,Rect.bottom);
	pDC->LineTo(Rect.right,Rect.bottom);
	pDC->MoveTo(Rect.left, Rect.bottom);
	pDC->LineTo(Rect.left, Rect.top);

	const int WIDTH = Rect.right - Rect.left;//���ο�
	const int HEIGHT =Rect.bottom-Rect.top;//����1��
	
	int len = WIDTH / 100 * 40;//����߳�
	
	////��������
	int Ax = 0;
	int Ay = HEIGHT;
	int Bx = len;
	int By = Ay;
	int Cx = len + len*sqrt(2)/2;
	int Cy = HEIGHT - len*sqrt(2)/2;
	int Dx = len*sqrt(2)/2;
	int Dy = Cy;
	int aX = Ax;
	int aY =Ay - len;
	int bX = Bx;
	int bY = By-len;
	int cX = Cx;
	int cY = Cy - len;
	int dX = Dx;
	int dY = Dy - len;

	////����������
	pDC->MoveTo(Ax,Ay);
	pDC->LineTo(Bx,By);
	pDC->LineTo(Cx, Cy);
	pDC->LineTo(Dx, Dy);
	pDC->LineTo(Ax, Ay);
	pDC->LineTo(aX, aY);
	pDC->LineTo(bX, bY);
	pDC->LineTo(cX, cY);
	pDC->LineTo(dX, dY);
	pDC->LineTo(aX, aY);
	pDC->MoveTo(Bx,By);
	pDC->LineTo(bX,bY);
	pDC->MoveTo(Cx,Cy);
	pDC->LineTo(cX,cY);
	pDC->MoveTo(Dx,Dy);
	pDC->LineTo(dX,dY);
	

	////������������
	pDC->SelectObject(&pen2);//ѡ�񻭱�

	int span = len / 20;//�������߿��
	
	for (int i = 0; i < span+4; ++i)//����������
	{
		pDC->MoveTo(Dx, Dy - span*i);
		pDC->LineTo(Cx, Cy - span*i);
	}

	for (int i = 0; i < span + 4; ++i)//����������
	{
		pDC->MoveTo(Ax, Ay - span*i);
		pDC->LineTo(Dx, Dy - span*i);
	}


	////����浽��������
	pDC->SelectObject(&pen3);//ѡ�񻭱�

	//double plLen = (double)len / orgMat.rows;//ӳ��ͼƬ�ĵ�λ����
	//double pwLen = (double)len / (orgMat.cols*orgMat.channels());//ӳ��ͼƬ�ĵ�λ���
	//double phLen = (double)len / 255;//ӳ��ͼƬ�ĵ�λ�߶�
	//double nX, nY;
	//
	//for (int i = 0; i < orgMat.rows;i++){
	//	for (int j = 0; j < orgMat.cols*orgMat.channels();j++){
	//		nX = pwLen*j / sqrt(2) + plLen*i;
	//		nY = HEIGHT-(pwLen*j / sqrt(2) + phLen*orgMat.at<uchar>(i, j));
	//		
	//		pDC->MoveTo(nX,nY);
	//		pDC->SetPixel(nX, nY, RGB(100, 0, 0));
	//	}
	//}

	double nX,nY;//������
	const double pxDensity = orgMat.rows;//ͼƬ����
	const double pyDensity = orgMat.cols*orgMat.channels();//ͼƬ��������

	for (double j = 0; j < pyDensity; j++){
		for (double i = 0; i < pxDensity; i++){
			nX = len*(1 + sqrt(2) / 2) / (pxDensity+pyDensity / sqrt(2))* (i + j / (sqrt(2)));
			nY = HEIGHT - len*(1 + sqrt(2) / 2) /(pyDensity/sqrt(2)+255)* (j / sqrt(2) + orgMat.at<uchar>(i, j));
			
			pDC->MoveTo(nX,nY);
			pDC->SetPixel(nX,nY,RGB(0,0,255));

		}
	}

	ReleaseDC(pDC);

	UpdateData(TRUE);
}


void CPaint::OnStnClickedStaticPicture()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
