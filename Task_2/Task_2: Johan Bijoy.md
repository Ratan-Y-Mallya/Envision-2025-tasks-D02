<h1>VIRTUAL MOUSE 🖱️</h1>

<h3>Explanation</h3>

+ First we import all the modules we want to use in this project.

We then initalize each variables: 

  The cap variable acts as a object to that allows you to read frames from a video file or directly from a camera.
    The variable hand_detector is used for real time hand tracking. It detects or tracks hand landmarks in images and video streams.
    The next variable drawing_utils is used to viusally draw the hand landmarks by directly drawing on the input images.
    The screen_width and screen_heigh variable holds the exact screen's width and height from the pyautogui module.
    We then initialize a variable to hold the y coordinate of the index finger.

+ The cap.read() read from the data stored in the cap object.
+ Flip function in opencv flips the video in horizontally, vertically or mirror and vertical.
+ Frame_width and frame_height holds the frame dimensions according to the frame defined within the flip function.
+ rgb_frame is used to change the color of one variable to another.
+ The output variable analyzes a image and marks the hand landmarks.
+ The multi_hand_landmarks() function provides detailed information about the detected hand landmarks for each hand in the input image or frame.
+ The programs then checks a condition stating if hands are found while processing the image. If hands are detected it loops through each detected hand and draws landmarks on each hand after which the landmarks
  are stored in a list. It then loops through each landmarks using its index.
+ If the program finds the 8th landmark i.e, the tip of the index finger it draws a yellow circle around the finger tip, After which it maps the index finger position from the camera coordinates to screen coordinates.
+ Next it searches for the tip of the thumb finger and then draws a yellow circle around it. Then it maps the camera coordinates with the screen coordinates. It then prints the difference of the vertical distance
  between the tip of index finger and thumb finger.
+ If the vertical distance is less than 20 it performs a click and then waits for the 1 second to prevent multiple clicks. If the vertical distance is moderately small, it moves the mouse cursor to the mapped finger position.
+ The program then displays the processed frame in a window titled Virtual Mouse and waits 1 milliseconds between the frames.
+ Then checks if J or j is pressed, if yes it releases the webcame and closes all opencv windows and exits the program after adding a small delay, otherwise continues the loops if no exit was pressed.



<h3>Screenshot</h3>

![hand_landmarks](https://github.com/user-attachments/assets/b2df698d-7b86-4d4f-ab44-92488406fc72)
