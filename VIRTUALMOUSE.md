# ENVISION TASK 2 : VIRTUAL MOUSE
We create a virtual mouse using python,OpenCV,Mediapipe and pyautogui libraries. It can perform basic tasks like cursor movement and perform clicks.

## CODE
```python
import cv2
import mediapipe as mp
import pyautogui as pygui
mp_hands=mp.solutions.hands
mp_drw=mp.solutions.drawing_utils
hands=mp_hands.Hands(static_image_mode=False,min_detection_confidence=0.7,min_tracking_confidence=0.80)
screen_width,screen_height=pygui.size()
cap=cv2.VideoCapture(0)
index_y=0
while True:
    ret,frame=cap.read()
    if not ret:
        break
    frame=cv2.flip(frame,1)
    frame_height,frame_width,_=frame.shape
    rgb_frame=cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
    output=hands.process(rgb_frame)
    if output.multi_hand_landmarks:
        for hand_landmarks in output.multi_hand_landmarks:
            mp_drw.draw_landmarks(frame,hand_landmarks,mp_hands.HAND_CONNECTIONS)
            landmarks=hand_landmarks.landmark
            for id, landmark in enumerate(landmarks):
                x=int(landmark.x*frame_width)
                y=int(landmark.y*frame_height)
                if id==8:
                    cv2.circle(frame,(x,y),10,(0,255,0),2)
                    index_x=(screen_width/frame_width*x)
                    index_y=(screen_height/frame_height*y)
                    pygui.moveTo(index_x,index_y)
                if id==4:
                    cv2.circle(frame,(x,y),10,(0,255,0),2)
                    thumb_x=(screen_width/frame_width*x)
                    thumb_y=(screen_height/frame_height*y)
                    if abs(index_y-thumb_y)<45:
                        pygui.click()
                        pygui.sleep(0.5)
    cv2.imshow("hands",frame)
    if cv2.waitKey(1) & 0xFF==ord('n'): 
        break
cap.release()
cv2.destroyAllWindows()
```
## EXPLANATION:
### LIBRARIES USED:
1)OpenCV: to access webcam and to perform image processing.
2)Mediapipe: to implement hand detection,hand landmarks,landmark connections and to detect clicks.
3)pyautogui: to implement cursor movements and perform clcks.
### CODE EXPLANATION:
First we define the hand solutions of the mediapipe library. Using pyautogui we get the screen dimensions required later in the task.Using openCV we capture frames using videoCapture(0). we use read() to detect the frame(ret is a bool value showing whether frame is open or not).We flip the image and covert it to RGB format(openCV uses BGR format whereas Mediapipe requires RGB format) and then we process the rgb frame for hand detection(result here).If it detects multi_hand_landmarks in the frame then its draws all the necessary landmarks and connections on the palm.Since the values of landmarks are normalised in Mediapipe,we multiply the x,y cordinates of the landmarks with frame width and height respectively. We index all the fingetips[4,8,12,16,20]. we detect the index tip (id=8) and thumb tip (id=4), get their coordinates and draw circle around the tips.We again adjust the index landmarks by the formula (frame_dimension/screen_dimension)*(x or y) to match the screen and we then feed this into moveCursorto(x,y) function. We measure the distance between the thumb_tip and index_tip to detect clicks. If the distance<45 it dtects the click (using click() ) and we let the pyautogui reset for 0.5 s.We then display this using cv2.imshow().
### LOOP BREAKING MECHANISM:
using 0xFF==ord('n') (ord returns the ascii value and 0xFF detcts the click of a character on the keyboard) we break the loop,thus forsing the window to close.

## HAND COORDINATES :
![HAND_SCREENSHOT](images/)
