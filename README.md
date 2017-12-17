# CarND-Controls-PID
This project implements a PID controller in C++ to maneuver a vehicle around a track in a simulator.
The simulator provides the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle and the throttle control.
A PID controller was implemented to control the steering angle and a PD controller was implemented to control the throttle.
---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distributions
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Code Style

[Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).


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