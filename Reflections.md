# Reflections
## PID controller for the steering angle
The PID controller for the steering angle used the Twiddle algorithm to adjust the coefficients of the controller. The initial values was chosen manually with a lot of trial and errors.  
To my surprise I found the following:
- The most important component was the Differential component.
- The second important component was the Proportional component, but was must less important than the D component.
- The Integral component had almost no effect on the algorithm which indicates that a PD controller would be sufficient.
The reason for that might be that the car in the simulator does not have an actual drift implemented.


## PD controller for the Throttle
I have implemented a PD controller for the Throttle. 
Initially I have used the same PID controller class for the steering angle however, the car kept popping up onto ledges.
It is also assumed that the throttle controller in the car itself has no error factor like
the drift in the steering angle. The values for the PD controller was tuned manually. 
The throttle value was capped at 0.8 as to avoid popping over the ledges at some turns.
The ideal solution would be applying break at certain situations.  
