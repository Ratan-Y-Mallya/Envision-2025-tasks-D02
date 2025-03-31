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
    frame=cv2.resize(frame,(640,480))
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