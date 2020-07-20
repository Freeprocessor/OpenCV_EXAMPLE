#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp> // for cvtColor

#include <iostream>


using namespace cv;
using namespace std;


int main()
{

	Mat frame;

	VideoCapture cap(0);
	if (!cap.isOpened()) // ī�޶� �̻� ���� Ȯ��
	{
		cerr << "ī�޶� �� �� �����ϴ�." << endl;
		return -1;
	}

	while (1) // �������� ���� ����
	{
		cap.read(frame);
		if (frame.empty()) // ��κ��� ī�޶󿡼��� ������ ������ �Ϻ� ī�޶󿡼� ó�� �̹����� �����ö� ������ ���� �� �ִ�. �ش� ������ �Ÿ��� ���� ����
		{
			cerr << "ĸ�� ����" << endl;
			break;
		}

		//cvtColor(frame, frame, COLOR_BGR2GRAY);

		imshow("Live", frame);

		if (waitKey(1) >= 0) // Ű �Է½� Break
			break;
	}


	return 0;
}