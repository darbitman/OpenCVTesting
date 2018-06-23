#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
  // open video file for reading
  VideoCapture vid("../PlayVideo/nature.mp4");

  // check if video file opened
  if (vid.isOpened() == false) {
    cout << "Cannot open the video file" << endl;
    // wait for keypress before continuing
    cin.get();
    return -1;
  }

  // get framerate
  double fps = vid.get(CAP_PROP_FPS);

  String windowName = "First Video";

  // create window for playing video
  namedWindow(windowName, WINDOW_NORMAL);

  while (true) {
    Mat frame;

    // get single frame from video
    bool success = vid.read(frame);

    if (success == false) {
      cout << "End of video" << endl;
      break;
    }

    // show single frame in window
    imshow(windowName, frame);

    // wait for 10ms until a key is pressed
    // if 'Esc' is pressed, stop the video
    // otherwise continue playback
    if (waitKey(10) == 27) {
      cout << "Esc key pressed. Stopping the video..." << endl;
      break;
    }
  }

  return 0;
}
