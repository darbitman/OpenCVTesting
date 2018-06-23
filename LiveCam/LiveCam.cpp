#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main() {
  VideoCapture cap;

  // get public feed
  cap.open("http://webcam01.bigskyresort.com/mjpg/video.mjpg");

  if (!cap.isOpened()) {
    cout << "Cannot open feed" << endl;
    return -1;
  }
  // create window to display feed
  namedWindow("Live Feed");

  while (true) {
    Mat frame;
    bool success = cap.read(frame);
    if (!success) {
      cout << "Cannot read frame from feed" << endl;
      break;
    }
    imshow("Live Feed", frame);
    if (waitKey(30) == 27) {
      cout << "Esc key pressed" << endl;
      break;
    }
  }
  return 0;
}
