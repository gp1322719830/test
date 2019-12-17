
// edgeSearchingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "edgeSearching.h"
#include "edgeSearchingDlg.h"
#include "afxdialogex.h"
#include"SetNoise.h" 
#include"commonPara.h"
#include"ShowInfo.h"
#include"AddBoxFilterKenelValue.h"
#include"com.fanyu.Filter.h"
#include"com.fanyu.Enhance.h"
#include"com.fanyu.EdgeCheck.h"
#include"SetCannyPara.h"
#include"com.fanyu.CreateNoise.h"
#include"SetSobelPara.h"
#include<atlimage.h>
#include"SetLaplaceHole.h"
#include"Paint.h"

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpenFile_Menu();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)


END_MESSAGE_MAP()


// CedgeSearchingDlg �Ի���


CedgeSearchingDlg::CedgeSearchingDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CedgeSearchingDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CedgeSearchingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOWORGIMAGE_STATIC, m_Show_ORG_Picture);
}

BEGIN_MESSAGE_MAP(CedgeSearchingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CedgeSearchingDlg::OnOpenFile)
	ON_COMMAND(ID_32782, &CedgeSearchingDlg::OnCreateGaNoise)
	ON_COMMAND(ID_32783, &CedgeSearchingDlg::OnAddPSNoise)
	ON_COMMAND(ID_32784, &CedgeSearchingDlg::OnBoxFilter)
	ON_COMMAND(ID_32819, &CedgeSearchingDlg::OnFilterIntroduction)
	ON_COMMAND(ID_32785, &CedgeSearchingDlg::OnAverageFilter)
	ON_COMMAND(ID_32776, &CedgeSearchingDlg::OnExpEnhance)
	ON_COMMAND(ID_32820, &CedgeSearchingDlg::OnLogEnhance)
	ON_COMMAND(ID_32792, &CedgeSearchingDlg::OnHighPass)
	ON_COMMAND(ID_32791, &CedgeSearchingDlg::OnExplorOver)
	ON_COMMAND(ID_32778, &CedgeSearchingDlg::OnCanny)
	ON_BN_CLICKED(IDC_BUTTON_GRAY, &CedgeSearchingDlg::OnBnClickedButtonGray)
	ON_BN_CLICKED(IDC_BUTTON_BINARY, &CedgeSearchingDlg::OnBnClickedButtonBinary)
	ON_COMMAND(ID_32786, &CedgeSearchingDlg::OnGaussianFilter)
	ON_COMMAND(ID_32773, &CedgeSearchingDlg::OnExit)
	ON_COMMAND(ID_32772, &CedgeSearchingDlg::OnSave)
	ON_COMMAND(ID_32797, &CedgeSearchingDlg::OnGaInfo)
	ON_COMMAND(ID_32798, &CedgeSearchingDlg::OnPSInfo)
	ON_COMMAND(ID_32788, &CedgeSearchingDlg::OnMediumFilter)
	ON_COMMAND(ID_32789, &CedgeSearchingDlg::OnDoubleEdgeFilter)
	ON_COMMAND(ID_32790, &CedgeSearchingDlg::OnWaveChange)
	ON_COMMAND(ID_32800, &CedgeSearchingDlg::OnBoxFilterInfo)
	ON_COMMAND(ID_32801, &CedgeSearchingDlg::OnAverageFilterInfo)
	ON_COMMAND(ID_32802, &CedgeSearchingDlg::OnGauFilterInfo)
	ON_COMMAND(ID_32803, &CedgeSearchingDlg::OnMediumFilterInfo)
	ON_COMMAND(ID_32804, &CedgeSearchingDlg::OnDouFilterInfo)
	ON_COMMAND(ID_32805, &CedgeSearchingDlg::OnWaveInfo)
	ON_COMMAND(ID_32807, &CedgeSearchingDlg::OnExpInfo)
	ON_COMMAND(ID_32808, &CedgeSearchingDlg::OnLogInfo)
	ON_COMMAND(ID_32809, &CedgeSearchingDlg::OnHPInfo)
	ON_COMMAND(ID_32810, &CedgeSearchingDlg::OnHConvInfo)
	ON_COMMAND(ID_32779, &CedgeSearchingDlg::OnRoberts)
	ON_COMMAND(ID_32780, &CedgeSearchingDlg::OnSobel)
	ON_COMMAND(ID_32781, &CedgeSearchingDlg::OnLaplace)
	ON_COMMAND(ID_32793, &CedgeSearchingDlg::OnSusan)
	ON_COMMAND(ID_32794, &CedgeSearchingDlg::OnKrisch)
	ON_COMMAND(ID_32795, &CedgeSearchingDlg::OnPrewitt)
	ON_COMMAND(ID_32812, &CedgeSearchingDlg::OnCannyInfo)
	ON_COMMAND(ID_32813, &CedgeSearchingDlg::OnRobertsInfo)
	ON_COMMAND(ID_32814, &CedgeSearchingDlg::OnSobelInfo)
	ON_COMMAND(ID_32815, &CedgeSearchingDlg::OnLaplaceInfo)
	ON_COMMAND(ID_32816, &CedgeSearchingDlg::OnSusanInfo)
	ON_COMMAND(ID_32817, &CedgeSearchingDlg::OnKrischInfo)
	ON_COMMAND(ID_32818, &CedgeSearchingDlg::OnPrewittInfo)
	ON_BN_CLICKED(IDC_BUTTON_AUTOCHECK, &CedgeSearchingDlg::OnBnClickedButtonAutocheck)
	ON_BN_CLICKED(IDC_SAVE_PICTURE_BUTTON, &CedgeSearchingDlg::OnBnClickedSavePictureButton)
	ON_BN_CLICKED(IDC__AMPLIFICATION_BUTTON, &CedgeSearchingDlg::OnBnClickedButtonAmpl)
	ON_BN_CLICKED(IDC_BUTTON_HAND_FIX, &CedgeSearchingDlg::OnBnClickedButtonHandFix)
	ON_BN_CLICKED(IDC_BUTTON_ANALISE, &CedgeSearchingDlg::OnBnClickedButtonAnalise)
END_MESSAGE_MAP()


// CedgeSearchingDlg ��Ϣ�������

BOOL CedgeSearchingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MAXIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_Menu.LoadMenu(IDR_MENU1);//���ز˵���
	SetMenu(&m_Menu);
	
	CONTINUE=true;//�Ҷ�ͼת��ִֻ��һ�α�־
	InitFlag = true;//��ʼ��һ�α�־


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CedgeSearchingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CedgeSearchingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		//// ��Ӵ���Ի��򱳾���ͼ
		//CPaintDC   dc(this);
		//CRect   rect;
		//GetClientRect(&rect);    //��ȡ�Ի��򳤿�      
		//
		//CDC   dcBmp;             //���岢����һ���ڴ��豸����
		//dcBmp.CreateCompatibleDC(&dc);             //����������DC
		//
		//CBitmap   bmpBackground;
		//bmpBackground.LoadBitmap(IDB_BITMAP2);    //������Դ��ͼƬ
		//
		//BITMAP   m_bitmap;                         //ͼƬ����               
		//bmpBackground.GetBitmap(&m_bitmap);       //��ͼƬ����λͼ��
		//
		////��λͼѡ����ʱ�ڴ��豸����
		//CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
		//
		////���ú�����ʾͼƬStretchBlt��ʾ��״�ɱ�
		//dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CedgeSearchingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/***********************************************
 *                     �˵��¼�����
 *
 *
 **
 ***********************************************/
/*--------------------���ж���----------------------*/
static CString FILEPATH;//ͼƬ�ļ���ַ

//���干��Mat����
static cv::Mat orgMat;//��ʼ����
static cv::Mat noiMat;//�������
static cv::Mat filMat;//�˲�����
static cv::Mat enhMat;//ǿ������
static cv::Mat edgMat;//��Ե����
static cv::Mat graMat;//�Ҷ�ͼ����
static cv::Mat binMat;//��ֵ������
extern cv::Mat cMat;//cpp�й������

//��ʼ��
void InitMat()
{
	if (InitFlag)
		InitFlag = false;
	
	binMat = edgMat = enhMat = filMat = noiMat = orgMat;
}
/*--------------------END----------------------*/

/*------------------------------��Ա����---------------------------------*/

//�ڶԻ�����ʾͼƬ����
void CedgeSearchingDlg::showImage(IplImage* image, UINT ID){

	//��Mat������ʾ��picture�ؼ�����Ҫ�Ķ���
	static CDC *pDC;
	static HDC hDC;
	static CRect rect;
	static CvvImage cimg;

	pDC = GetDlgItem(ID)->GetDC();
	hDC = pDC->GetSafeHdc();

	GetDlgItem(ID)->GetClientRect(&rect);

	cimg.CopyOf(image, image->nChannels);
	cimg.DrawToHDC(hDC, &rect);
	
	ReleaseDC(pDC);
}

//ͼƬ��ַ���ݺ���
void getFilePath(CString BmpName)
{
	FILEPATH = BmpName;
}


//�˵�->�ļ�->��
void CedgeSearchingDlg::OnOpenFile()
{
	//���ļ� �������ָ�ʽ���ļ�bmp gif jpg tiff
	CString filter;
	filter = "�����ļ�(*.bmp,*.jpg,*.gif,*tiff)|*.bmp;*.jpg;*.gif;*.tiff| BMP(*.bmp)|*.bmp| JPG(*.jpg)|*.jpg| GIF(*.gif)|*.gif| TIFF(*.tiff)|*.tiff||";

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter, NULL);

	//����ȷ����ť dlg.DoModal() ������ʾ�Ի���
	if (dlg.DoModal() == IDOK)
	{
		//�򿪶Ի����ȡͼ����Ϣ
		CString BmpName = dlg.GetPathName();     //��ȡ�ļ�·����   ��D:\pic\abc.bmp
		CString EntName = dlg.GetFileExt();      //��ȡ�ļ���չ��

		getFilePath(BmpName);//��ȡ�ļ���ַ���Ժ����

		EntName.MakeLower();                     //���ļ���չ��ת��Ϊһ��Сд�ַ�

		if (EntName.Compare(_T("bmp")) == 0)
		{
			//��������洢ͼƬ��Ϣ
			BITMAPINFO *pBmpInfo;       //��¼ͼ��ϸ��
			BYTE *pBmpData;             //ͼ������
			BITMAPFILEHEADER bmpHeader; //�ļ�ͷ
			BITMAPINFOHEADER bmpInfo;   //��Ϣͷ
			CFile bmpFile;              //��¼���ļ�

			//��ֻ���ķ�ʽ���ļ� ��ȡbmpͼƬ������ bmp�ļ�ͷ ��Ϣ ����
			if (!bmpFile.Open(BmpName, CFile::modeRead | CFile::typeBinary))
				return;
			if (bmpFile.Read(&bmpHeader, sizeof(BITMAPFILEHEADER)) != sizeof(BITMAPFILEHEADER))
				return;
			if (bmpFile.Read(&bmpInfo, sizeof(BITMAPINFOHEADER)) != sizeof(BITMAPINFOHEADER))
				return;
			pBmpInfo = (BITMAPINFO *)new char[sizeof(BITMAPINFOHEADER)];

			//Ϊͼ����������ռ�
			memcpy(pBmpInfo, &bmpInfo, sizeof(BITMAPINFOHEADER));
			DWORD dataBytes = bmpHeader.bfSize - bmpHeader.bfOffBits;
			pBmpData = (BYTE*)new char[dataBytes];
			bmpFile.Read(pBmpData, dataBytes);
			bmpFile.Close();

			/*Ϊ��Mat����Ĺ���ʹ��*/
			//��CSring����ת��ΪString����
			USES_CONVERSION;
			String str(W2A(FILEPATH));
			orgMat = imread(str, 3);//�Ѷ����Mat�浽cMat��

			//��ʾͼ��
			CRect rect;
			static CDC *pDC;
			CWnd *pWnd = GetDlgItem(IDC_SHOWORGIMAGE_STATIC); //���pictrue�ؼ����ڵľ��
			pWnd->GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������
			pDC = pWnd->GetDC(); //���pictrue�ؼ���DC
			pDC->SetStretchBltMode(COLORONCOLOR);
			StretchDIBits(pDC->GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0,
				bmpInfo.biWidth, bmpInfo.biHeight, pBmpData, pBmpInfo, DIB_RGB_COLORS, SRCCOPY);
		}
	}
	CONTINUE = true;//�Ҷ�ͼ��ť����
	InitMat();//��ʼ������ʹ�õ���Mat����
}

//�˵�->�ļ�->�˳�
void CedgeSearchingDlg::OnExit()
{
	EndDialog(IDD_EDGESEARCHING_DIALOG);
}

//�˵�->�ļ�->����
void CedgeSearchingDlg::OnSave()
{
	CString saveFilePath;
	CClientDC dc(this);
    CRect rect;
	BOOL  showMsgTag = FALSE;                  //�Ƿ�Ҫ������ͼ�񱣴�ɹ��Ի���" 

	GetClientRect(&rect);                  //��ȡ������С

	HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);
	
	//��������λͼ

	HDC hdc = CreateCompatibleDC(dc);      //��������DC���Ա㽫ͼ�񱣴�Ϊ��ͬ�ĸ�ʽ

	HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);

	//��λͼѡ��DC�������淵��ֵ 

	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0, SRCCOPY);

	//����ĻDC��ͼ���Ƶ��ڴ�DC��
	ATL::CImage image;

	image.Attach(hbitmap);

	BOOL saveTag = FALSE;

	if (!saveTag)                          //���ͼ���ǵ�һ�α�д��,��򿪶Ի���
	{
		saveTag = TRUE;

		showMsgTag = TRUE;

		CString  strFilter = _T("λͼ�ļ�(*.bmp)|*.bmp|JPEG ͼ���ļ�|*.jpg|GIFͼ���ļ� | *.gif | PNGͼ���ļ� | *.png |������ʽ(*.*) | *.* || ");
		CFileDialog dlg(FALSE, _T("bmp"), _T("iPaint1.bmp"), NULL, strFilter);

		if (dlg.DoModal() != IDOK)
			return;

		CString strFileName;          //����û�û��ָ���ļ���չ������Ϊ�����һ��
		CString strExtension;
		strFileName = dlg.m_ofn.lpstrFile;

		if (dlg.m_ofn.nFileExtension = 0)               //��չ����ĿΪ0
		{
			switch (dlg.m_ofn.nFilterIndex)
			{
			case 1:
				strExtension = "bmp"; break;
			case 2:
				strExtension = "jpg"; break;
			case 3:
				strExtension = "gif"; break;
			case 4:
				strExtension = "png"; break;
			default:
				break;
			}

			strFileName = strFileName + "." + strExtension;

		}

		saveFilePath = strFileName;     //saveFilePathΪ�����е�ȫ�ֱ���,����ΪCString
	}

	else
		showMsgTag = FALSE;

	//AfxMessageBox(saveFilePath);               //��ʾͼ�񱣴��ȫ·��(�����ļ���)

	HRESULT hResult = image.Save(saveFilePath);     //����ͼ��

	if (FAILED(hResult))

	{

		MessageBox(_T("����ͼ���ļ�ʧ�ܣ�"));

	}

	else

	{

		if (showMsgTag)

			MessageBox(_T("�ļ�����ɹ���"));

	}

	image.Detach();

	SelectObject(hdc, hOldMap);

}



//�˵�->�������->��˹����
void CedgeSearchingDlg::OnCreateGaNoise()
{
	noiMat = orgMat;//����ͼ�����

	CreateNoise *m_CreateGaNoise = NULL;  //����һ���������������
	m_CreateGaNoise->AddGaussianNoise(noiMat);  //���ø�˹��������

	delete m_CreateGaNoise; //�ͷ�

	showImage(&(IplImage)noiMat, IDC_SHOW_NOISE_PICTURE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->�������->��������
void CedgeSearchingDlg::OnAddPSNoise()
{
	INT_PTR nRes;//���ڱ���Domodal�����ķ���ֵ

	CSetNoise m_SetNoiseN;//����SetNoiseN���ʵ��
	
    m_SetNoiseN.m_SetNoise=1000;//Ĭ��ֵ
	UpdateData(FALSE);

	nRes = m_SetNoiseN.DoModal();//��������

	if (nRes == IDCANCEL)//�ж϶Ի��򷵻�ֵ�Ƿ�ΪCANCEL��ʵ�򷵻�
		return;

	else if (nRes == IDOK)
		UpdateData(TRUE);//�ѿؼ���ֵ���µ�����

		int NoiseN = m_SetNoiseN.m_SetNoise;//��ȡ�ؼ�����ֵ��NoiseN��ʾ�����

		noiMat = orgMat;//��ȡMat����

		CreateNoise *m_CreatePSNoise = NULL;  //����һ���������������
		m_CreatePSNoise->AddPepperNoise(noiMat, NoiseN);  //���ý�����������
		m_CreatePSNoise->AddSaltNoise(noiMat, NoiseN);

		delete m_CreatePSNoise; //�ͷ����������

		showImage(&(IplImage)noiMat, IDC_SHOW_NOISE_PICTURE_STATIC);//��ʾͼƬ��ָ���ؼ�

}


//�˵�->�������->��˹��������
void CedgeSearchingDlg::OnGaInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->�������->������������
void CedgeSearchingDlg::OnPSInfo()
{
}
 


//�˵�->�˲�->�����˲�
void CedgeSearchingDlg::OnBoxFilter()
{
	CAddBoxFilterKenelValue m_BoxFilter;//��������

	INT_PTR nResB;
	
	m_BoxFilter.m_AddBoxFilterKenelValue=5;//Ĭ��ֵ
	UpdateData(FALSE);

	nResB = m_BoxFilter.DoModal();//��������

	Filter mFilter(noiMat); //��ʼ���˲�����

	if (nResB==IDCANCEL)
		return;

	if (nResB == IDOK)//���ȷ��
		UpdateData(TRUE);

	mFilter.kenelValue = m_BoxFilter.m_AddBoxFilterKenelValue;//��ȡ�ؼ�ֵ
	mFilter.dDepth = -1;//ͼ�����Ϊԭͼ���

	mFilter.boxFilter();//���÷����˲�������������������dstMat��

	filMat = mFilter.dstMat;//Ŀ��ͼ���浽cMat��

	showImage(&(IplImage)filMat, IDC_SHOW_FILTER_PICTURE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->�˲�->��ֵ�˲�
void CedgeSearchingDlg::OnAverageFilter()
{
	CAddBoxFilterKenelValue m_BlurFilter;//��������
	m_BlurFilter.m_AddBoxFilterKenelValue=7;//Ĭ��ֵ
	UpdateData(FALSE);

	INT_PTR nResB;
	nResB = m_BlurFilter.DoModal();//��������

	Filter mFilter(noiMat); //��ʼ���˲�����
	
	if (nResB == IDCANCEL)
		return;

	if (nResB == IDOK)//���ȷ��
		UpdateData(TRUE);

	mFilter.kenelValue = m_BlurFilter.m_AddBoxFilterKenelValue;//��ȡ�ؼ�ֵ
	mFilter.dDepth = -1;//ͼ�����Ϊԭͼ���

	mFilter.averageFilter();//�����˲�������������������dstMat��

	filMat = mFilter.dstMat;//Ŀ��ͼ���浽cMat��

	showImage(&(IplImage)filMat, IDC_SHOW_FILTER_PICTURE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->�˲�->��˹�˲�
void CedgeSearchingDlg::OnGaussianFilter()
{
	CAddBoxFilterKenelValue m_GauFilter;//��������
	m_GauFilter.m_AddBoxFilterKenelValue = 3;//Ĭ��ֵ
	UpdateData(FALSE);

	INT_PTR nResB;
	nResB = m_GauFilter.DoModal();//��������

	Filter mFilter(noiMat); //��ʼ���˲�����

	if (nResB == IDCANCEL)
		return;

	if (nResB == IDOK)//���ȷ��
		UpdateData(TRUE);

	mFilter.kenelValue = m_GauFilter.m_AddBoxFilterKenelValue;//��ȡ�ؼ�ֵ
	mFilter.dDepth = -1;//ͼ�����Ϊԭͼ���

	mFilter.GaussianFilter();//�����˲�������������������dstMat��

	filMat = mFilter.dstMat;//Ŀ��ͼ���浽cMat��

	showImage(&(IplImage)filMat, IDC_SHOW_FILTER_PICTURE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->�˲�->��ֵ�˲�
void CedgeSearchingDlg::OnMediumFilter()
{
	CAddBoxFilterKenelValue m_MedFilter;//��������

	INT_PTR nResB;
	
	m_MedFilter.m_AddBoxFilterKenelValue = 7;//Ĭ��ֵ
	UpdateData(FALSE);

	nResB = m_MedFilter.DoModal();//��������

	Filter mFilter(noiMat); //��ʼ���˲�����

	if (nResB == IDCANCEL)
		return;

	if (nResB == IDOK)//���ȷ��
		UpdateData(TRUE);

	mFilter.kenelValue = m_MedFilter.m_AddBoxFilterKenelValue;//��ȡ�ؼ�ֵ
	mFilter.dDepth = -1;//ͼ�����Ϊԭͼ���

	mFilter.medianFilter();//�����˲�������������������dstMat��

	filMat = mFilter.dstMat;//Ŀ��ͼ���浽cMat��

	showImage(&(IplImage)filMat, IDC_SHOW_FILTER_PICTURE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->�˲�->˫���˲�
void CedgeSearchingDlg::OnDoubleEdgeFilter()
{
	CAddBoxFilterKenelValue m_DouFilter;//��������
	m_DouFilter.m_AddBoxFilterKenelValue = 25;//Ĭ��ֵ
	UpdateData(FALSE);

	INT_PTR nResB;
	nResB = m_DouFilter.DoModal();//��������

	Filter mFilter(noiMat); //��ʼ���˲�����

	if (nResB == IDCANCEL)
		return;

	if (nResB == IDOK)//���ȷ��
		UpdateData(TRUE);

	mFilter.kenelValue = m_DouFilter.m_AddBoxFilterKenelValue;//��ȡ�ؼ�ֵ
	mFilter.dDepth = -1;//ͼ�����Ϊԭͼ���

	mFilter.bilateralFilter();//�����˲�������������������dstMat��

    filMat = mFilter.dstMat;//Ŀ��ͼ���浽cMat��

	showImage(&(IplImage)filMat, IDC_SHOW_FILTER_PICTURE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->�˲�->С���任
void CedgeSearchingDlg::OnWaveChange()
{
	CAddBoxFilterKenelValue m_waveConvert;//��������
	
	m_waveConvert.m_AddBoxFilterKenelValue=2;//Ĭ��ֵ
	
	INT_PTR nResB;
	nResB = m_waveConvert.DoModal();//��������

	Filter mFilter(noiMat); //��ʼ���˲�����

	if (nResB == IDCANCEL)
		return;

	if (nResB == IDOK)//���ȷ��
		UpdateData(TRUE);

	mFilter.kenelValue = m_waveConvert.m_AddBoxFilterKenelValue;//��ȡ�ؼ�ֵ
	mFilter.dDepth = -1;//ͼ�����Ϊԭͼ���

	mFilter.waveConvert();//�����˲�������������������dstMat��

	filMat = mFilter.dstMat;//Ŀ��ͼ���浽cMat��

	showImage(&(IplImage)filMat, IDC_SHOW_FILTER_PICTURE_STATIC);//��ʾͼƬ��ָ���ؼ�
}


//�˵�->�˲�->�鿴˵��->ͼ���˲�����
void CedgeSearchingDlg::OnFilterIntroduction()
{
	CShowFilterInfo m_ShowInfo;//ʵ�����鿴��Ϣ���ڶ���
	m_ShowInfo.DoModal();//��������
}

//�˵�->�˲�->�鿴˵��->�����˲�����
void CedgeSearchingDlg::OnBoxFilterInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->�˲�->�鿴˵��->��ֵ�˲�����
void CedgeSearchingDlg::OnAverageFilterInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->�˲�->�鿴˵��->��˹�˲�����
void CedgeSearchingDlg::OnGauFilterInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->�˲�->�鿴˵��->��ֵ�˲�����
void CedgeSearchingDlg::OnMediumFilterInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->�˲�->�鿴˵��->˫���˲�����
void CedgeSearchingDlg::OnDouFilterInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->�˲�->�鿴˵��->С���任����
void CedgeSearchingDlg::OnWaveInfo()
{
	// TODO:  �ڴ���������������
}



//�˵�->��ǿ->ָ����ǿ
void CedgeSearchingDlg::OnExpEnhance()
{

	Enhance mEnhance(filMat);//��ʼ����ǿ�����
	Mat dst;
	mEnhance.ExpEnhance(&(IplImage)filMat, &(IplImage)dst);//ָ����ǿ

	enhMat = dst;//����enhMat

	showImage(&(IplImage)enhMat, IDC_SHOWENHANCEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�

}

//�˵�->��ǿ->������ǿ
void CedgeSearchingDlg::OnLogEnhance()
{
	Enhance mLogEnhance(filMat);//��ʼ����ǿ�����
	Mat dst;
	mLogEnhance.LogEnhance(&(IplImage)filMat, &(IplImage)dst);//ָ����ǿ

	enhMat = dst;//����enhMat

	showImage(&(IplImage)enhMat, IDC_SHOWENHANCEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->��ǿ->�߷���
void CedgeSearchingDlg::OnHighPass()
{
	Enhance mHPEnhance(filMat);//��ʼ����ǿ����

	enhMat = mHPEnhance.dstMat = mHPEnhance.HighPass();//���ø߷����

	showImage(&(IplImage)enhMat, IDC_SHOWENHANCEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�

}

//�˵�->��ǿ->���ع�
void CedgeSearchingDlg::OnExplorOver()
{
	Enhance mEOEnhance(filMat);
	mEOEnhance.ExporeOver(&(IplImage)filMat, &(IplImage)(mEOEnhance.dstMat));

	enhMat = mEOEnhance.dstMat;//���洦����

	showImage(&(IplImage)enhMat, IDC_SHOWENHANCEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�

}


//�˵�->��ǿ->�鿴˵��-->ָ��
void CedgeSearchingDlg::OnExpInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->��ǿ->�鿴˵��-->����
void CedgeSearchingDlg::OnLogInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->��ǿ->�鿴˵��-->���ع�
void CedgeSearchingDlg::OnHPInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->��ǿ->�鿴˵��-->�߷���
void CedgeSearchingDlg::OnHConvInfo()
{
	// TODO:  �ڴ���������������
}





//�˵�->���->Canny����
void CedgeSearchingDlg::OnCanny()
{
	CSetCannyPara m_SetCannyPara;  //��ʼ����������
	
	m_SetCannyPara.m_setCannyValue1=270;//Ĭ��ֵ
	m_SetCannyPara.m_setCannyValue2=270*2/3;
	UpdateData(FALSE);

	INT_PTR nResC;//���浯������ֵ

	nResC = m_SetCannyPara.DoModal();//�������ڲ���ȡ����ֵ

	if (nResC == IDCANCEL)
		return;

	else if (nResC == IDOK)//������ȷ����ť
		UpdateData(TRUE);//�ӿؼ�����ֵ������

	EdgeCheck mEdgeCheckCanny(enhMat);//��ʼ����Ե��������
	//�ؼ�������ֵ����Ե���������Ա
	mEdgeCheckCanny.thresholdValue1 = m_SetCannyPara.m_setCannyValue1;
	mEdgeCheckCanny.thresholdValue2 = m_SetCannyPara.m_setCannyValue2;

	mEdgeCheckCanny.Canny();//����Canny����

	edgMat = mEdgeCheckCanny.dstMat;//����������


	showImage(&(IplImage)edgMat, IDC_SHOWEDGEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�

}

//�˵�->���->Roberts����
void CedgeSearchingDlg::OnRoberts()
{
	EdgeCheck m_Roberts(enhMat);//��ʼ����������

	m_Roberts.Roberts();//Roberts����

	edgMat=m_Roberts.dstMat;//����
	
	showImage(&(IplImage)edgMat, IDC_SHOWEDGEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�

}

//�˵�->���->Soberl����
void CedgeSearchingDlg::OnSobel()
{
	//�������ò���
	CSetSobelPara m_setSobelPara;//��������

	m_setSobelPara.m_Sobeldxdy=2;//Ĭ��ֵ
	m_setSobelPara.m_Sobelhole=3;
	UpdateData(FALSE);

	INT_PTR nResS;

	nResS=m_setSobelPara.DoModal();//����

	if (nResS == IDCANCEL)
		return;

	if (nResS == IDOK)//������ȷ����ť������¿ؼ�ֵ������
		UpdateData(TRUE);

	////���ü������
	EdgeCheck m_SobelCheck(enhMat);//��ʼ�������
	
	//��ֵ
	m_SobelCheck.dxdy = m_setSobelPara.m_Sobeldxdy;
	m_SobelCheck.Sobelhole = m_setSobelPara.m_Sobelhole;

	m_SobelCheck.Sobel();//���

	edgMat = m_SobelCheck.dstMat;//�洢���

	showImage(&(IplImage)edgMat, IDC_SHOWEDGEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->���->Laplace����
void CedgeSearchingDlg::OnLaplace()
{
	////����
	CSetLaplaceHole m_setLaplaceHole;

	m_setLaplaceHole.m_setLaplaceHole=3;//Ĭ��ֵ
	UpdateData(FALSE);

	INT_PTR nResL=m_setLaplaceHole.DoModal();
	
	if (nResL == IDCANCEL)
		return;

	if (nResL == IDOK)//�����ȷ�����������
		UpdateData(TRUE);

	////���
	EdgeCheck m_Laplace(enhMat);

	m_Laplace.LaplaceHole = m_setLaplaceHole.m_setLaplaceHole;//��ȡ����
	m_Laplace.Laplace();//���

	edgMat = m_Laplace.dstMat;//����
	
	showImage(&(IplImage)edgMat, IDC_SHOWEDGEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->���->Susan����
void CedgeSearchingDlg::OnSusan()
{
	EdgeCheck m_Susan(enhMat);
	m_Susan.Susan();

	edgMat = m_Susan.dstMat;//����
	
	showImage(&(IplImage)edgMat, IDC_SHOWEDGEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->���->Krisch����
void CedgeSearchingDlg::OnKrisch()
{
	EdgeCheck m_Krisch(enhMat);
	m_Krisch.Krisch();

    edgMat = m_Krisch.dstMat;//����
	
	showImage(&(IplImage)edgMat, IDC_SHOWEDGEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�˵�->���->Prewitt����
void CedgeSearchingDlg::OnPrewitt()
{
	EdgeCheck m_Prewitt(enhMat);
	m_Prewitt.Krisch();

	edgMat = m_Prewitt.dstMat;//����

	showImage(&(IplImage)edgMat, IDC_SHOWEDGEIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�
}


//�˵�->���->�鿴˵��-->Canny���ӽ���
void CedgeSearchingDlg::OnCannyInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->���->�鿴˵��-->Roberts���ӽ���
void CedgeSearchingDlg::OnRobertsInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->���->�鿴˵��-->Sobel���ӽ���
void CedgeSearchingDlg::OnSobelInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->���->�鿴˵��-->Laplace���ӽ���
void CedgeSearchingDlg::OnLaplaceInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->���->�鿴˵��-->Susan���ӽ���
void CedgeSearchingDlg::OnSusanInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->���->�鿴˵��-->Krisch���ӽ���
void CedgeSearchingDlg::OnKrischInfo()
{
	// TODO:  �ڴ���������������
}

//�˵�->���->�鿴˵��-->Prewitt���ӽ���
void CedgeSearchingDlg::OnPrewittInfo()
{
	// TODO:  �ڴ���������������
}



/***********************************************
*                     ��ť�¼�����
*
*
**
***********************************************/

//��ť���Ҷ�ͼת��
void CedgeSearchingDlg::OnBnClickedButtonGray()
{
	if (CONTINUE)
	{
		CONTINUE = false;

		cvtColor(orgMat, graMat, CV_BGR2GRAY);//תΪ�Ҷ�ͼ

		orgMat = graMat;

		showImage(&(IplImage)graMat, IDC_SHOWORGIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�
	}
}

//��ť����ֵ��ͼ��
void CedgeSearchingDlg::OnBnClickedButtonBinary()
{
	binMat = orgMat;

	CV_Assert(binMat.depth() != sizeof(uchar));  //����ֻ�����8bit��ͼ�����

	int channels = binMat.channels();            //��ȡͼ��channel
	int nrows = binMat.rows;                     //���������
	int ncols = binMat.cols*channels;             //�����������=����*channel������

	if (binMat.isContinuous())               //�жϾ����Ƿ��������������������൱��ֻ��Ҫ����һ��һά����
	{
		ncols *= nrows;
		nrows = 1;                 //һά����
	}

	//�������ص�Ҷ�ֵ
	for (int i = 0; i < nrows; i++)
	{
		uchar *p = binMat.ptr<uchar>(i);    //��ȡ�е�ַ

		for (int j = 0; j < ncols; j++)
		{
			if (p[j] < 100)
				p[j] = 0;
			else
				p[j] = 255;
		}
	}

	orgMat= binMat;//����

	showImage(&(IplImage)binMat, IDC_SHOWORGIMAGE_STATIC);//��ʾͼƬ��ָ���ؼ�
}

//�Զ���ⰴť
void CedgeSearchingDlg::OnBnClickedButtonAutocheck()
{
}

//����ͼ��
void CedgeSearchingDlg::OnBnClickedSavePictureButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

//�Ŵ���ʾ
void CedgeSearchingDlg::OnBnClickedButtonAmpl()
{
}


/*--------------------�ֹ��Ż�---------------------*/
//Mat��ʼ��
Mat m_org = edgMat, m_dst, m_img, m_tmp;
void on_mouse(int event, int x, int y, int flags, void*ustc)//event����¼����ţ�x,y������꣬flags��ק�ͼ��̲����Ĵ���
{
	/*event����¼�����:
	#define CV_EVENT_MOUSEMOVE 0                 ����
	#define CV_EVENT_LBUTTONDOWN 1           ������
	#define CV_EVENT_RBUTTONDOWN 2           �Ҽ����
	#define CV_EVENT_MBUTTONDOWN 3          �м���
	#define CV_EVENT_LBUTTONUP 4                   ����ͷ�
	#define CV_EVENT_RBUTTONUP 5                   �Ҽ��ͷ�
	#define CV_EVENT_MBUTTONUP 6                  �м��ͷ�
	#define CV_EVENT_LBUTTONDBLCLK 7         ���˫��
	#define CV_EVENT_RBUTTONDBLCLK 8         �Ҽ�˫��
	#define CV_EVENT_MBUTTONDBLCLK 9         �м��ͷ�
	*/

	static Point pre_pt = (-1, -1);//��ʼ����  
	static Point cur_pt = (-1, -1);//ʵʱ����  
	char temp[16];
	if (event == CV_EVENT_LBUTTONDOWN)//������£���ȡ��ʼ���꣬����ͼ���ϸõ㴦��Բ  
	{
		m_org.copyTo(m_img);//��ԭʼͼƬ���Ƶ�img��  

		pre_pt = Point(x, y);
		putText(m_img, temp, pre_pt, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0, 255), 1, 8);//�ڴ�������ʾ����  
		circle(m_img, pre_pt, 2, Scalar(255, 255, 0, 0), CV_FILLED, CV_AA, 0);//��Բ  
		imshow("�ֶ��Ż�", m_img);
	}
	else if (event == CV_EVENT_MOUSEMOVE && !(flags & CV_EVENT_FLAG_LBUTTON))//���û�а��µ����������ƶ��Ĵ�����  
	{
		m_img.copyTo(m_tmp);//��img���Ƶ���ʱͼ��tmp�ϣ�������ʾʵʱ����  

		cur_pt = Point(x, y);
		putText(m_tmp, temp, cur_pt, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0, 255));//ֻ��ʵʱ��ʾ����ƶ�������  
		imshow("�ֶ��Ż�", m_tmp);
	}
	else if (event == CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_LBUTTON))//�������ʱ������ƶ�������ͼ���ϻ�����  
	{
		m_img.copyTo(m_tmp);

		cur_pt = Point(x, y);
		putText(m_tmp, temp, cur_pt, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0, 255));
		rectangle(m_tmp, pre_pt, cur_pt, Scalar(0, 255, 0, 0), 1, 8, 0);//����ʱͼ����ʵʱ��ʾ����϶�ʱ�γɵľ���  
		imshow("�ֶ��Ż�", m_tmp);
	}
	else if (event == CV_EVENT_LBUTTONUP)//����ɿ�������ͼ���ϻ�����  
	{
		m_org.copyTo(m_img);

		cur_pt = Point(x, y);
		putText(m_img, temp, cur_pt, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0, 255));
		circle(m_img, pre_pt, 2, Scalar(255, 0, 0, 0), CV_FILLED, CV_AA, 0);
		rectangle(m_img, pre_pt, cur_pt, Scalar(0, 255, 0, 0), 1, 8, 0);//���ݳ�ʼ��ͽ����㣬�����λ���img��  
		imshow("�ֶ��Ż�", m_img);
		m_img.copyTo(m_tmp);
		//��ȡ���ΰ�Χ��ͼ�񣬲����浽dst��  
		int width = abs(pre_pt.x - cur_pt.x);
		int height = abs(pre_pt.y - cur_pt.y);
		if (width == 0 || height == 0)
			return;

		m_dst = m_org(Rect(min(cur_pt.x, pre_pt.x), min(cur_pt.y, pre_pt.y), width, height));
		//ɾ��ѡ�о��ο��е�����ֵ
		for (int i = 0; i <m_dst.rows; i++){
			for (int j = 0; j < m_dst.cols; j++){
				for (int k = 0; k < m_dst.channels(); k++)
					m_dst.at<cv::Vec3b>(i, j)[k] = 0;
			}
		}
		imshow("�ֶ��Ż�", m_img);
		waitKey(0);
	}
}

void CedgeSearchingDlg::OnBnClickedButtonHandFix()
{
	/*������*/
	edgMat.copyTo(m_img);
	edgMat.copyTo(m_tmp);

	namedWindow("�ֶ��Ż�",WINDOW_AUTOSIZE);//����һ��img����
	setMouseCallback("�ֶ��Ż�", on_mouse, 0);//���ûص�����  
	imshow("�ֶ��Ż�", m_img);
	waitKey(0);
}


//ͳ�Ʒ���
void CedgeSearchingDlg::OnBnClickedButtonAnalise()
{
	CPaint *myPaint;

	myPaint = new CPaint();

	myPaint->orgMat = orgMat;//����ͼƬ����

	INT_PTR nRes;

	nRes=myPaint->DoModal();
}
