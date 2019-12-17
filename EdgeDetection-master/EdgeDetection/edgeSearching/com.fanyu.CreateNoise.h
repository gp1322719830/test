/*---------------------------------------Tips-----------------------------------------*/
//����CreateNoise��
//���ܣ�����ͼ������
//ʹ�ã����ó�Ա����void AddGaussianNoise(Mat&)��Ӹ�˹����
//            ���ó�Ա����void AddPepperNoise(Mat&int n)��ӽ�����
//            ���ó�Ա����void AddSaitNoise(Mat&,int n)���������
/*----------------------------------------END---------------------------------------*/

#ifndef _CCREATENOISE
#define _CCREATENOISE

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define TWO_PI 6.2831853071795864769252866 //2*PI����

using namespace cv;
using namespace std;


//����CreateNoise��
class CreateNoise{
private:
	double generateGaussianNoise();//������˹��������

public:
	void AddPepperNoise(Mat &image, int n);//��ӽ�����
	void AddSaltNoise(Mat &image, int n);//���������
	void AddGaussianNoise(Mat&);//��Ӹ�˹����
};

#endif
