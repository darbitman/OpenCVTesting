#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
  // Read the image file
  Mat image = imread("../DisplayImage/guitar.png");

  // Check for failure
  if (image.empty()) {
    cout << "Could not open or find the image" << endl;
    cin.get(); //wait for any key press
    return -1;
  }

  // name the window
  String windowName = "The Guitar";

  // create window instance
  namedWindow(windowName);

  // show the image inside the window
  imshow(windowName, image);

  // Wait for any keystroke in the window
  waitKey(0);

  // destroy the window
  destroyWindow(windowName);
  return 0;
}
