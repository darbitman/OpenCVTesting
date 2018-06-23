#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;
int lowThreshold;
int max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
// name the window
String windowName = "The Guitar";

void CannyThreshold(int, void*)
{
  /// Reduce noise with a kernel 3x3
  blur(src_gray, detected_edges, Size(3, 3));

  /// Canny detector
  Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

  /// Using Canny's output as a mask, we display our result
  dst = Scalar::all(0);

  src.copyTo(dst, detected_edges);
  imshow(windowName, dst);
}

int main() {
  // Read the image file
  src = imread("../../EdgeDetection/guitar.png");

  // Check for failure
  if (src.empty()) {
    cout << "Could not open or find the image" << endl;
    cin.get(); //wait for any key press
    return -1;
  }

  Mat dst;
  dst.create(src.size(), src.type());
  cvtColor(src, src_gray, CV_BGR2GRAY);


  // create window instance
  namedWindow(windowName);

  createTrackbar("Min Threshold:", windowName, &lowThreshold, max_lowThreshold, CannyThreshold);

  // show the image inside the window
  imshow(windowName, dst);

  // Wait for any keystroke in the window
  waitKey(0);

  // destroy the window
  destroyWindow(windowName);
  return 0;
}
