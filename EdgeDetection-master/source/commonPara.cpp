/*--------------------Tips------------------------*/
//EdgeCheck���ʵ�ֺ���
//
#include"stdafx.h"
#include"commonPara.h"

//��Mat����תΪCImage����
void CommonPara::MatToCImage(Mat &mat, ATL::CImage &cImage)
{
	//create new CImage  
	int width = mat.cols;
	int height = mat.rows;
	int channels = mat.channels();

	cImage.Destroy(); //clear  
	cImage.Create(width, height, 8 * channels); //Ĭ��ͼ�����ص�ͨ��ռ��1���ֽ�  

	//copy values  
	uchar* ps;
	uchar* pimg = (uchar*)cImage.GetBits(); //A pointer to the bitmap buffer  
	int step = cImage.GetPitch();

	for (int i = 0; i < height; ++i)
	{
		ps = (mat.ptr<uchar>(i));
		for (int j = 0; j < width; ++j)
		{
			if (channels == 1) //gray  
			{
				*(pimg + i*step + j) = ps[j];
			}
			else if (channels == 3) //color  
			{
				for (int k = 0; k < 3; ++k)
				{
					*(pimg + i*step + j * 3 + k) = ps[j * 3 + k];
				}
			}
		}
	}
}

