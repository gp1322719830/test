//���幫��ȫ�ֲ���
#ifndef _COMMON
#define _COMMON

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 

using namespace cv;

static bool CONTINUE = false;//����ִ�б�־
static bool InitFlag = false;//��ʼ����־

//����ȫ�ֺ�����
class CommonPara{

public:
	void MatToCImage(Mat &mat, ATL::CImage &cImage);
};


#endif