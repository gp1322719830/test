/*---------------------------------------Tips-----------------------------------------*/
//����Enhance��
//���ܣ���ͼ�������ǿ
//ʹ�ã�
/*----------------------------------------END---------------------------------------*/

#ifndef _CENHANCE
#define _CENHANCE

#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 

using namespace std;
using namespace cv;

class Enhance{
private:
	Mat strMat;

public:
	Mat dstMat;
public:
	explicit Enhance(Mat& mat):strMat(mat){}
	bool ExpEnhance(IplImage*,IplImage*);
	bool LogEnhance(IplImage*, IplImage*);
	void ExporeOver(IplImage* img, IplImage* dst);
	Mat HighPass();
};

#endif