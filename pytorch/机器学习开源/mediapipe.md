##### 官方文档

https://google.github.io/mediapipe/solutions/hands.html

##### github

https://github.com/google/mediapipe



#### hands

```python
import mediapipe as mp
mp_hands = mp.solutions.hands

with mp_hands.Hands(
            min_detection_confidence=0.5,
            min_tracking_confidence=0.5) as hands:
  results_hand = hands.process(image)

if results_hand.multi_hand_landmarks:
    # print(results_hand.multi_hand_landmarks)
    for hand_landmarks in results_hand.multi_hand_landmarks:
print(hand_landmarks)
'''
landmark{
    x: 
    y:
    z:
}
landmark...
'''
a = hand_landmarks.lanmark
print(a)
'''
[x:y:z:
 ,x:y:z:]
'''
for point in a: # 21 points
   print(point.x, point.y, point.z)
```

