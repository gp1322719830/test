/*---------------------------------------Tips-----------------------------------------*/
//����EdgeCheck��
//���ܣ���ͼ����б�Ե���
//ʹ�ã�
/*----------------------------------------END---------------------------------------*/

#ifndef _CEDGECHECK
#define _CEDGECHECK

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 

using namespace cv;
using namespace std;

class EdgeCheck{
private:
	Mat strMat;

public:
	explicit EdgeCheck(Mat mat):strMat(mat){}
	bool Canny();//Canny����
	bool Roberts();// roberts����
	bool Sobel();//Sobel����
	bool Laplace();//Laplace����
	bool Susan();//Susan
	bool Krisch();
	bool Prewitt();

public:
	int LaplaceHole;//Laplace�˲����׾�ֵ
	int Sobelhole;//Sobel�׾���С
	int dxdy;//x,y����Ĳ�ֽ���
	int thresholdValue1;//�ͺ�����ֵ
	int thresholdValue2;
	Mat dstMat;
};

#endif