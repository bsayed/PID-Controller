#ifndef PID_H
#define PID_H

class PID {

public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double best_err;
  double err;

  /*
  * Coefficients
  */ 
  double K[3];
  double dK[3];
//  double Kd;
//
//
//  double dKp;
//  double dKi;
//  double dKd;

  bool twiddle_up[3] = {false,false,false};
  bool twiddle_down[3]= {false,false,false};
  unsigned long n;
  unsigned int last_updated_coeff;

  /*
   * Initialization flag
   */
  bool initialized;

  /*
   * Number of steps
   */
  unsigned long steps;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
