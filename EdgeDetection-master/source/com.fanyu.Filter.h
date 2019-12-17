/*---------------------------------------Tips-----------------------------------------*/
//����Filter��
//���ܣ���ͼ������˲�
//ʹ�ã�
/*----------------------------------------END---------------------------------------*/

#ifndef _CFILTER
#define _CFILTER

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 

using namespace cv;
using namespace std;

//�����˲���
class Filter{
private:


public:
	int kenelValue;//�ں˴�С
	int dDepth = -1;//ͼ�����
	Mat srcMat;//ԭͼ
	Mat dstMat;//����Ŀ��ͼ

public:
	explicit Filter(Mat& mat) :srcMat(mat){}
	bool boxFilter();//�����˲�����
	bool averageFilter();//��ֵ�˲�
	bool GaussianFilter();//��˹�˲�
	bool medianFilter();//��ֵ�˲�
	bool bilateralFilter();//˫���˲�
	bool waveConvert();//С���任
};
#endif