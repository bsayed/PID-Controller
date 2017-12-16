#include <algorithm>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  this->K[0] = Kp;
  this->K[1] = Kd;
  this->K[2] = Ki;

  this->dK[0] = .5*Kp;
  this->dK[1] = .5*Kd;
  this->dK[2] = .5*Ki;

  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;

  this->last_updated_coeff = 0;
}

void PID::UpdateError(double cte) {

  if (!initialized) {
    p_error = cte;
    steps = 1;
    i_error = 0;
    initialized = true;
    best_err = std::numeric_limits<double>::max();
    err = 0;
  }

  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

  if (steps % (2*n) == 0) {
    err /= static_cast<double>(n);
    int coeff_idx = last_updated_coeff % 3;
    if (!twiddle_up[coeff_idx]) {
      K[coeff_idx] += dK[coeff_idx];
      twiddle_up[coeff_idx] = true;
      initialized = false;
    } else {
      if (err < best_err) {
        best_err = err;
        dK[coeff_idx] *= 1.1;
        last_updated_coeff++;
        twiddle_up[coeff_idx] = false;
        twiddle_down[coeff_idx] = false;
        initialized = false;
      } else if (!twiddle_down[coeff_idx]) {
        K[coeff_idx] -= 2 * dK[coeff_idx];
        twiddle_down[coeff_idx] = true;
        initialized = false;
      } else {
        K[coeff_idx] = dK[coeff_idx];
        dK[coeff_idx] *= 0.9;
        last_updated_coeff++;
        twiddle_up[coeff_idx] = false;
        twiddle_down[coeff_idx] = false;
        initialized = false;
      }
    }
  }
  steps++;
  if (steps >= (n)) {
    err += cte * cte;
  }
}

double PID::TotalError() {
  return 0.0;
}

