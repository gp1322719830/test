/*--------------------Tips------------------------*/
//Enhance���ʵ�ֺ���
//
#include"stdafx.h"
#include"com.fanyu.Enhance.h"

/*ָ��ͼ����ǿ�㷨*/
//ָ��ͼ����ǿ�ı��Ϊ��S = cR^r��ͨ�������ѡ��c��r����ѹ���Ҷȷ�Χ��
//�㷨��c = 1.0 / 255.0, r = 2ʵ�֡�
bool Enhance::ExpEnhance(IplImage* img, IplImage* dst)
{
	// ����oldPixel:[1,256],������ȱ���һ�����ұ�
	uchar lut[256] = { 0 };

	double temp = 1.0 / 255.0;

	for (int i = 0; i<255; i++)
	{
		lut[i] = (uchar)(temp*i*i + 0.5);
	}

	for (int row = 0; row <img->height; row++)
	{
		uchar *data = (uchar*)img->imageData + row* img->widthStep;
		uchar *dstData = (uchar*)dst->imageData + row* dst->widthStep;

		for (int col = 0; col<img->width; col++)
		{
			for (int k = 0; k<img->nChannels; k++)
			{
				uchar t1 = data[col*img->nChannels + k];
				dstData[col*img->nChannels + k] = lut[t1];
			}
		}
	}
	return true;
}


/*����ͼ����ǿ�㷨*/
//����ͼ����ǿ��ͼ����ǿ��һ�ֳ����������乫ʽΪ�� S = c log(r + 1)��
//����c�ǳ����������㷨c = 255 / (log(256)������������ʵ�������������������
bool Enhance::LogEnhance(IplImage* img, IplImage* dst)
{
	// ����oldPixel:[1,256],������ȱ���һ�����ұ�
	uchar lut[256] = { 0 };

	double temp = 255 / log(256);

	for (int i = 0; i<255; i++)
	{
		lut[i] = (uchar)(temp* log(i + 1) + 0.5);
	}

	for (int row = 0; row <img->height; row++)
	{
		uchar *data = (uchar*)img->imageData + row* img->widthStep;
		uchar *dstData = (uchar*)dst->imageData + row* dst->widthStep;

		for (int col = 0; col<img->width; col++)
		{
			for (int k = 0; k<img->nChannels; k++)
			{
				uchar t1 = data[col*img->nChannels + k];
				dstData[col*img->nChannels + k] = lut[t1];
			}
		}
	}
	return true;
}

/*�ع�������⴦��*/
//�����ع�������⣬����ͨ�����㵱ǰͼ��ķ��ࣨ255 - image)��
//Ȼ��ȡ��ǰͼ��ͷ���ͼ��Ľ�С��Ϊ��ǰ����λ�õ�ֵ��
// �����ع�ԭ��ͼ��ת��Ȼ����ԭͼ�뷴ͼ����Сֵ
void Enhance::ExporeOver(IplImage* img, IplImage* dst)
{
	for (int row = 0; row <img->height; row++)
	{
		uchar *data = (uchar*)img->imageData + row* img->widthStep;
		uchar *dstData = (uchar*)dst->imageData + row* dst->widthStep;
		for (int col = 0; col<img->width; col++)
		{
			for (int k = 0; k<img->nChannels; k++)
			{
				uchar t1 = data[col*img->nChannels + k];
				uchar t2 = 255 - t1;
				dstData[col*img->nChannels + k] = min(t1, t2);
			}
		}
	}
}

/*�߷����*/
//�߷������Ҫ�ǽ�ͼ������ɫ����������ϴ������ֵĽ��紦����������
//����ͼ������һ���˺�һ��ʯͷ����ôʯͷ�������ߺ��˵��������Լ��沿��
//��װ�������������ĵط���䱻����������������������������仯�ĵط�
//�������л�ɫ��������ʽΪ��dst = r*(img - Blur(img))��
Mat Enhance::HighPass()
{
	Mat temp;
	GaussianBlur(strMat, temp, Size(7, 7), 1.6, 1.6);

	int r = 3;
	Mat diff = strMat + r*(strMat - temp); //�߷�����㷨
	return diff;
}