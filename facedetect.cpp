#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <vector>
#include <string>
 
  using namespace std;
  using namespace cv;
 
 string xmlName = "/home/jun/softinstall/opencv-3.2.0/data/haarcascades/haarcascade_frontalface_alt.xml";
 CascadeClassifier face_cascade;
 void detectFaces(Mat image);
 
 int main()
 {
     Mat image = imread("/home/jun/图片/test2.jpeg");
     if (!image.data)
     {
         cout << "read image failed……" << endl;
         return -1;
     }
     face_cascade.load(xmlName);
     detectFaces(image);
     waitKey(0);
 }
 
 void detectFaces(Mat image)
 {
     vector<Rect> faces;
     Mat face_gray;
     cvtColor(image, face_gray, CV_BGR2GRAY);
     face_cascade.detectMultiScale(face_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(1, 1));
     cout << faces.size() << endl;
     for (int i = 0; i < faces.size(); i++)
     {
         Rect r(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
         rectangle(image, r, Scalar(0, 0, 255), 3);
     }
     namedWindow("face", CV_WINDOW_NORMAL);
     imshow("face", image);
 }
