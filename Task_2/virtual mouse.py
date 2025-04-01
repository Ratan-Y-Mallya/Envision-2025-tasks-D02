import cv2
import mediapipe as mp
import pyautogui
index_y=0
cap= cv2.VideoCapture(0)
hand_detector= mp.solutions.hands.Hands()
drawing_utils= mp.solutions.drawing_utils
screen_width,screen_height=pyautogui.size()
while True:
    _,frame =cap.read()
    frame=cv2.flip(frame,1)
    frame_height , frame_width , _ =frame.shape
    rgb_frame=cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    output=hand_detector.process(rgb_frame)
    hands=output.multi_hand_landmarks
    if hands:
        for hand in hands:
            drawing_utils.draw_landmarks(frame ,hand)
            landmarks=hand.landmark
            for id, landmark in enumerate(landmarks):
                
                x=int(landmark.x*frame_width)
                y=int(landmark.y*frame_height)
                #print(f"{x}, {y}") 
                if id==8:
                    cv2.circle(img=frame, center=(x,y) , radius=10, color=(0,255,255))
                    index_x=1.5*screen_width*x/frame_width
                    index_y=1.5*screen_height*y/frame_height
                    pyautogui.moveTo(index_x,index_y)
                if id==4:
                    cv2.circle(img=frame, center=(x,y) , radius=10, color=(0,255,255))
                    thumb_x=screen_width*x/frame_width
                    thumb_y=screen_height*y/frame_height  
                    print(abs(index_y-thumb_y))
                    if abs(index_y-thumb_y)<30:
                        print("click")
                        pyautogui.click()
                        pyautogui.sleep(1)
  
    cv2.imshow("hand_tracking", frame)
    key = cv2.waitKey(1) & 0xFF  
    if key == ord('q'):
        print("Closing all windows")
        break

cap.release()
cv2.destroyAllWindows()
   
       