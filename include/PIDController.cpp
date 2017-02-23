/** @file PIDController.cpp
* @brief a PID Controller class
* @author Daniel Gellman
 * @author Mark Jenkins
* @copyright
* Class that implements a PID Controller object.
*/

#include "PIDController.h"
#include <cmath>
#include <iostream>

/** @brief Constructor for PIDController.
   * @param [in] dt double - loop wait time.
   * @param [in] max double - max acceptable output.
   * @param [in] min double - min acceptable output.
   * @param [in] Kp double - proportional gain.
   * @param [in] Kd double - deriv gain.
   * @param [in] Ki double - integral gain.
   * @param pre_error double - default to zero.
   * @param integral double - default to zero.
   */
PIDController::PIDController(double dt, double max, double min, double Kp,
                             double Kd, double Ki)
    :
      dt(dt),
      max(max),
      min(min),
      Kp(Kp),
      Kd(Kd),
      Ki(Ki),
      pre_error(0),
      integral(0)
{
}
PIDController::~PIDController() {
}
/** @brief Compute the correction based on the set point and process variable
 * @param [in] setPoint a double for the current setpoint for the plant's output
 * @param [in] processVariable a double for the current measurement.
 */
double PIDController::compute(double setpoint, double pv) {
  // This implementation assumes that this method will be called
  // repeatedly at intervals equal to dt by a client of the
  // PIDController object
  // MJenkins 2017-02-22

  // calculate the amount of error
  double error = setpoint - pv;

  // add error to integral
  integral += (error * dt);

  // calculate the rate of change
  double derivative = (error - pre_error) / dt;

  // save the current error for next invocation
  pre_error = error;

  // apply the correction factor's maximum and minimum allowable
  // values specified in the private variables max and min
  // (this purpose for the min/max communicated in private e-mail
  //  with DGellman 2017-02-22)
  double correction = Kp * error + Ki * integral + Kd * derivative;
  if (correction > max)
    correction = max;
  else if (correction < min)
    correction = min;

  return correction;
}
double PIDController::getKi() {
  return Ki;
}
double PIDController::getKp() {
  return Kp;
}
double PIDController::getKd() {
  return Kd;
}
double PIDController::getMax() {
  return max;
}
double PIDController::getMin() {
  return min;
}
double PIDController::getDt() {
  return dt;
}
double PIDController::getIntegral() {
  return integral;
}
double PIDController::getPre_Error() {
  return pre_error;
}
