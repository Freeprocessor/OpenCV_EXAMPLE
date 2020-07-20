#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp> // �̹������� ����, �ҷ�����
#include <opencv2/highgui.hpp> // Interface ���� ���
#include <opencv2/imgproc.hpp> // ĳ�� ���� ���� �Լ� ���
//#include <opencv2/opencv.hpp> // OpenCV ����� ��� �ҷ���

#include <iostream> // ������� ���� ���


// OpenCV�� C++ ǥ�� ���̺귯���� �浹���� �Լ��� ���� ������ 
// using namespace�� ����ص� ����� ����. ������ ���� ������Ʈ�� ��� �����ؾ���
using namespace cv;
using namespace std;


int main() // �����Լ� �ƱԸ�Ʈ ����
{
	Mat image; // Mat ��ü ����
	image = imread("unnamed.jpg", IMREAD_GRAYSCALE);	// �̹����� �о ���ϵǴ� Mat ��ü�� ����
														// �ι�° �ƱԸ�Ʈ�δ� IMREAD_UNCHANGED(����ä���� ���Խ�Ų �÷� �̹����� ������), 
														// IMREAD_COLOR(����ä���� ���� �÷� �̹����� ������), IMREAD_GRAYSCALE(�׷��̽����� �̹����� ��ȯ�Ͽ� ������)���� �����
	if (image.empty()) // �̹����� ����ִٸ� �����޼��� ��� �� ����
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}

	//namedWindow("Original", WINDOW_AUTOSIZE);	// â ���� ù��° �ƱԸ�Ʈ�� ������ Ÿ��Ʋ�� ������ �޼���, �ι�° �ƱԸ�Ʈ�� WINDOW_AUTOSIZE�� ��� �̹��� ũ�⿡ ������(â ũ�� ���� �Ұ�)
											// WINDOW_NORMAL�� ��� â ũ�� ���� ���� ���� ������ �ػ󵵿� ���� ������ ũ�Ⱑ ������ 
											// ���� �������� imshow���� ����Ͽ� ���� ������ ���� �����ϳ�, Ʈ���ٸ� ���̴� �� �۾��� �ϱ� ���ؼ� �ʿ���
	//setWindowProperty("Original", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
	imshow("Original", image);
	Canny(image, image, 50, 150);
	imshow("Canny", image);	// imshow �Լ��� ù��° �ƱԸ�Ʈ�� ������ â��, �ι�° �ƱԸ�Ʈ�� Mat ��ü�� ����� �̹����� ������

	waitKey(0); // Ű �Է��� �����ð� ���� ���. 0�� �ƱԸ�Ʈ�� ���� ������ ��� ��
}