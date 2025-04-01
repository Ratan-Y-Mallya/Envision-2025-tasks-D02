**Explanation of code**
- First we import a libraries cv2(for object and face detection), mediapipe (for tracking hands) and pytoautogui(to move the mouse)
- We define a variable cap which captures the video and is later used in while loop to continuously take in video and display it, while loop runs till we click the letter ‘q’ then all the windows close
- Hand_detector and drawing_utils are some of the features provided by mediapipe, hand detector checks the postion of the hand while the drawing utils helps draw the hand landmarks 
- The screen width and screen height initializing will help us ensure that the the mouse movement is not only in the range of the frame but the whole screen similarly we also figure out the frame height and width
- The rgb_frame line of the code ensures that the video captured that is displayed is in proper rgb colours
- Then we use the line hands=output.multi_hand_landmarks that prints the landmarks on the hand
- The next if loop only runs if it detects a hand/hands on the frame
- We further initialize the x and y coordinates to ensure that the frame fits the entire screen and we initialize the index(id 8) and thumb(id 4),it moves the cursor to the fixed x and y position. it checks for the absolute difference of the y values of the thumb and index and then if its less(thumb and index are close) then it clicks
- The last few lines ensure that the while loop stops and all the windows close when you type ‘q’

**output**
![hand_landmarks](image.png)