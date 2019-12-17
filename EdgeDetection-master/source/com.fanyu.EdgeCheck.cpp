/*--------------------Tips------------------------*/
//EdgeCheck���ʵ�ֺ���
//
#include"stdafx.h"
#include"com.fanyu.EdgeCheck.h"

//Canny����
bool EdgeCheck::Canny(){	
	cv::Canny(strMat, dstMat, thresholdValue1, thresholdValue2 , 3,false);//3����Sobel�׾�ֵ
	return true;
}

//Roborts����
bool EdgeCheck::Roberts()
{
	Mat srcImage = strMat;
	cv::Mat dstImage = srcImage.clone();

	int nRows = dstImage.rows;
	int nCols = dstImage.cols;
	for (int i = 0; i < nRows - 1; i++)
	{
		for (int j = 0; j < nCols - 1; j++)
		{
			// ���ݹ�ʽ����
			int t1 = (srcImage.at<uchar>(i, j) -
				srcImage.at<uchar>(i + 1, j + 1)) *
				(srcImage.at<uchar>(i, j) -
				srcImage.at<uchar>(i + 1, j + 1));
			int t2 = (srcImage.at<uchar>(i + 1, j) -
				srcImage.at<uchar>(i, j + 1)) *
				(srcImage.at<uchar>(i + 1, j) -
				srcImage.at<uchar>(i, j + 1));
			// ����Խ������ز�
			dstImage.at<uchar>(i, j) = (uchar)sqrt(t1 + t2);
		}
	}

	dstMat=dstImage;
	
	return true;
}

//Sobel����
//��(x,y)�����ݶ�
bool EdgeCheck::Sobel(){
	Mat grad_Image;
	cv::Sobel(strMat, grad_Image, CV_16S, dxdy, dxdy, Sobelhole, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_Image, dstMat);
	return true;
}

//Laplace����
bool EdgeCheck::Laplace()
{
	Mat abs_dstImage;
	//ʹ��Laplace����
	cv::Laplacian(strMat,abs_dstImage, CV_16S, LaplaceHole, 1, 0, BORDER_DEFAULT);

	//�������ֵ���������ת����8λ  
	convertScaleAbs(abs_dstImage, dstMat);
	return true;
}

bool EdgeCheck::Susan()
{
	int height, width, step, channels;
	int i, j, k, same, max, min, thresh, sum;
	uchar*data0, *data1;
	
	IplImage* Img, *nimg; //����IplImageָ��
	//����ͼ��
	Img = &(IplImage)strMat;

	if (!Img)
		return false;
	nimg = cvCreateImage(cvGetSize(Img), 8, 1);
	height = Img->height;
	width = Img->width;
	step = Img->widthStep / sizeof(uchar);
	channels = Img->nChannels;
	data0 = (uchar*)Img->imageData;
	data1 = (uchar*)nimg->imageData;

	int OffSetX[37] = { -1, 0, 1,
		-2, -1, 0, 1, 2,
		-3, -2, -1, 0, 1, 2, 3,
		-3, -2, -1, 0, 1, 2, 3,
		-3, -2, -1, 0, 1, 2, 3,
		-2, -1, 0, 1, 2,
		-1, 0, 1 };
	int OffSetY[37] = { -3, -3, -3,
		-2, -2, -2, -2, -2,
		-1, -1, -1, -1, -1, -1, -1,
		0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 1, 1, 1,
		2, 2, 2, 2, 2,
		3, 3, 3 };

	max = min = data0[0];
	
	for (i = 3; i<height - 3; i++)
	for (j = 3; j<width - 3; j++)
	{
		same = 0; sum = 0;
		for (k = 0; k<37; k++)
		{
			sum += data0[(i + OffSetY[k])*step + (j + OffSetX[k])];
			thresh = sum / 37;
			if (abs(data0[(i + OffSetY[k])*step + (j + OffSetX[k])] - data0[i*step + j]) <= thresh)
				same++;
			if (same<18)
				data1[i*step + j] = 255;
			else
				data1[i*step + j] = 0;
		}
	}

	dstMat= cvarrToMat(nimg);
	cvReleaseImage(&nimg);

	return true;
}

bool EdgeCheck::Krisch()
{
	IplImage *src;
	src = &(IplImage)strMat;

	if (!src)
		return false;
	IplImage *dst = cvCloneImage(src);
	int x, y;
	float a, b, c, d;
	float p1, p2, p3, p4, p5, p6, p7, p8, p9;
	uchar* ps = (uchar*)src->imageData; //psΪָ������ͼƬ���ݵ�ָ��
	uchar* pd = (uchar*)dst->imageData; //pdΪָ�����ͼƬ���ݵ�ָ��
	int w = dst->width;
	int h = dst->height;
	int step = dst->widthStep;

	for (x = 0; x<w - 2; x++)      //ȡ�ԣ�x+1��y+1)Ϊ���ĵ�9����������  1 4 7
	{                                                            // 2 5 8
		for (y = 0; y<h - 2; y++)                                     // 3 6 9
		{
			p1 = ps[y*step + x];
			p2 = ps[y*step + (x + 1)];
			p3 = ps[y*step + (x + 2)];
			p4 = ps[(y + 1)*step + x];
			p5 = ps[(y + 1)*step + (x + 1)];
			p6 = ps[(y + 1)*step + (x + 2)];
			p7 = ps[(y + 2)*step + x];
			p8 = ps[(y + 2)*step + (x + 1)];
			p9 = ps[(y + 2)*step + (x + 2)];//�õ�(i+1,j+1)��Χ�Ÿ���ĻҶ�ֵ
			a = fabs(float(-5 * p1 - 5 * p2 - 5 * p3 + 3 * p4 + 3 * p6 + 3 * p7 + 3 * p8 + 3 * p9));    //����4��������ݶ�ֵ
			b = fabs(float(3 * p1 - 5 * p2 - 5 * p3 + 3 * p4 - 5 * p6 + 3 * p7 + 3 * p8 + 3 * p9));
			c = fabs(float(3 * p1 + 3 * p2 - 5 * p3 + 3 * p4 - 5 * p6 + 3 * p7 + 3 * p8 - 5 * p9));
			d = fabs(float(3 * p1 + 3 * p2 + 3 * p3 + 3 * p4 - 5 * p6 + 3 * p7 - 5 * p8 - 5 * p9));
			a = (a>b) ? a : b;                                         //ȡ���������ϵ����ֵ��Ϊ��Եǿ��
			a = (a>c) ? a : c;
			a = (a>d) ? a : d;
			pd[(y + 1)*step + (x + 1)] = a;
		}
	}
	cvNormalize(dst, dst, 0, 255, CV_MINMAX); //��һ������

	dstMat= cvarrToMat(dst);

	cvReleaseImage(&dst);
	
	return true;
}

bool EdgeCheck::Prewitt()
{
	//-------prewitt���� ���ûҶ�ͼ ----
	IplImage *src = &(IplImage)strMat;

	if (!src)
		return false;
	IplImage *gray = cvCreateImage(cvGetSize(src), 8, 1);
	if (src->nChannels == 1)
	{
		//����
		cvCopy(src, gray);
	}
	else
	{
		//ɫ�ʿռ�ת����ת������ΪCV_BGR2GRAY
		cvtColor(cvarrToMat(src), cvarrToMat(gray), CV_BGR2GRAY);
	}

	IplImage *dst = NULL;
	dst = cvCreateImage(cvGetSize(gray), 8, 1);
	//����prewitt���ӵ�ģ��
	float prewittx[9] =
	{
		-1, 0, 1,
		-1, 0, 1,
		-1, 0, 1
	};
	float prewitty[9] =
	{
		1, 1, 1,
		0, 0, 0,
		-1, -1, -1
	};
	CvMat px;
	px = cvMat(3, 3, CV_32F, prewittx);
	CvMat py;
	py = cvMat(3, 3, CV_32F, prewitty);

	//Ϊ���ͼ������ռ�
	IplImage *dstx = cvCreateImage(cvGetSize(gray), 8, 1);
	IplImage *dsty = cvCreateImage(cvGetSize(gray), 8, 1);
	
	//��ͼ��ʹ��ģ�壬�Զ����߽� cvCvtColor(src,gray,CV_RGB2GRAY);
	filter2D(cvarrToMat(gray), cvarrToMat(dstx), -1,cvarrToMat(&px), cvPoint(-1, -1));
	filter2D(cvarrToMat(gray), cvarrToMat(dsty), -1,cvarrToMat(&py), cvPoint(-1, -1));

	//�����ݶȣ�����Ϊ2��ע��ѧϰָ���ʹ�÷���
	int i, j, temp;
	float tempx, tempy;  //����Ϊ��������Ϊ�˱���sqrt������������
	uchar* ptrx = (uchar*)dstx->imageData;
	uchar* ptry = (uchar*)dsty->imageData;
	for (i = 0; i<src->width; i++)
	{
		for (j = 0; j<src->height; j++)
		{
			tempx = ptrx[i + j*dstx->widthStep];   //tempx,tempy��ʾ����ָ����ָ�������
			tempy = ptry[i + j*dsty->widthStep];
			temp = (int)sqrt(tempx*tempx + tempy*tempy);
			dst->imageData[i + j*dstx->widthStep] = temp;
		}
	}
	cvReleaseImage(&dstx);
	cvReleaseImage(&dsty);
	
	dstMat= cvarrToMat(dst);

	cvReleaseImage(&dst);
	cvReleaseImage(&src);
	cvReleaseImage(&gray);

	return true;
}
