#include "opencv2/objdetect/objdetect.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"

 #include <iostream>
 #include <stdio.h>

 using namespace std;
 using namespace cv;

 int main()
 {

 	CascadeClassifier face_cascade,eye_cascade;
 	face_cascade.load("haarcascade_mcs_eyepair_big.xml");
 	//eye_cascade.load("haarcascade__eye_tree_eyeglasses.xml");
 	char str[26];
    strcpy(str,"xdotool mousemove 0000 0000");
    char x18,x19,x20,x21,x23,x24,x25,x26,x22;

 	VideoCapture stream1(0);
 	Mat capture,gray,hist,croppedImage;
 	Mat testSample = Mat ( 100 , 100 , CV_8UC1 );
 	int a,b;

 	while(true)
 	{
 		stream1.read(capture);
 		cvtColor(capture,gray,CV_BGR2GRAY);
        equalizeHist(gray, gray);
        std::vector<Rect> faces;
        face_cascade.detectMultiScale(gray,faces,1.1,2,CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_SCALE_IMAGE,Size(30,30));

        for(size_t i=0;i<faces.size();i++)  
        {
            Point center(faces[i].x + faces[i].width*0.5,faces[i].y+faces[i].height*0.5);
            ellipse (capture,center,Size(faces[i].width*0.5,faces[i].height*0.5),0,0,360,Scalar(255,0,255),4,8,0);
            Rect facerect(faces[i].x ,faces[i].y,faces[i].width ,faces[i].height);
            croppedImage=capture(facerect);
           	resize ( croppedImage , testSample , testSample.size());
           	a=faces[i].x + faces[i].width*0.5;
           	b=faces[i].y+faces[i].height*0.5;


        }

        imshow("final",testSample);
        a=(double)(a-527)*5.45;

//cout<<posX;
		b=(double)(b-292)*4.864;


	if(a>1500)
    a=1500;
	if(b>800)
    b=800;

	a=1500-a;
        //cout<<"|"<<a<<"*"<<b<<"| ";
        x18=(a/1000)+48;
		x19=(a/100)%10+48;
		x20=(a/10)%10+48;
		x21=(a)%10+48;

		x23=(b/1000)+48;
		x24=(b/100)%10+48;
		x25=(b/10)%10+48;
		x26=(b)%10+48;

		str[18]=x18;
		str[19]=x19;
		str[20]=x20;
		str[21]=x21;
//y-coordiantes
		str[23]=x23;
		str[24]=x24;
		str[25]=x25;
		str[26]=x26;
		system(str);
        waitKey(10);
 	}
 	return 0;
 }