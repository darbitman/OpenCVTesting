#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
  // Read the image file
  Mat image = imread("../HomogeneousBlur/guitar.png");

  // Check for failure
  if (image.empty()) {
    cout << "Could not open or find the image" << endl;
    cin.get(); //wait for any key press
    return -1;
  }

  // Blur image with 3x3 kernel
  Mat image_blurred_with_3x3_kernel;
  blur(image, image_blurred_with_3x3_kernel, Size(3, 3));

  // Blur image with 5x5 kernel
  Mat image_blurred_with_5x5_kernel;
  blur(image, image_blurred_with_5x5_kernel, Size(5, 5));

  // Define names of windows
  String window_name_original = "Original picture";
  String window_name_3x3_kernel = "Picture blurred with 3x3 kernel";
  String window_name_5x5_kernel = "Picture blurred with 5x5 kernel";

  // create windows
  namedWindow(window_name_original);
  namedWindow(window_name_3x3_kernel);
  namedWindow(window_name_5x5_kernel);

  imshow(window_name_original, image);
  imshow(window_name_3x3_kernel, image_blurred_with_3x3_kernel);
  imshow(window_name_5x5_kernel, image_blurred_with_5x5_kernel);


  // Wait for any keystroke in the window
  waitKey(0);

  // destroy the windows
  destroyAllWindows();
  return 0;
}
