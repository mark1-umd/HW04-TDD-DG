/** @file PIDController.cpp
* @brief a PID Controller class
* @author Daniel Gellman
 * @author Mark Jenkins
 * @copyright 2017 Daniel Gellman and Mark Jenkins
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
 * @param [in] setpoint a double for the current setpoint for the plant's output
 * @param [in] pv a double for the current measurement of the process variable
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
/** @brief Return current setting for coefficient Ki
 *
 */
double PIDController::getKi() {
  return Ki;
}
/** @brief Return current setting for coefficient Kp
 *
 */
double PIDController::getKp() {
  return Kp;
}
/** @brief Return current setting for coefficient Kd
 *
 */
double PIDController::getKd() {
  return Kd;
}
/** @brief Return current setting for correction maximum value
 *
 */
double PIDController::getMax() {
  return max;
}
/** @brief Return current setting for correction minimum value
 *
 */
double PIDController::getMin() {
  return min;
}
/** @brief Return current setting for duration of time between compute calls
 *
 */
double PIDController::getDt() {
  return dt;
}
/** @brief Return current value of the internal error integral
 *
 */
double PIDController::getIntegral() {
  return integral;
}
/** @brief Return current value for the internal "previous error" store
 *
 */
double PIDController::getPre_Error() {
  return pre_error;
}
