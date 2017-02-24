/** @file PIDController.h
* @brief a PID Controller class
* @author Daniel Gellman
* @copyright Daniel Gellman
* Class that implements a PID Controller object.
*/

#ifndef INCLUDE_PIDCONTROLLER_H_
#define INCLUDE_PIDCONTROLLER_H_

class PIDController{
 private:
  double dt, max, min, Kp, Kd, Ki, pre_error, integral;
 public:
  PIDController(double dt, double max, double min, double Kp, double Kd,
                double Ki);
  ~PIDController();
  double compute(double setpoint, double pv);
  double getKi();
  double getKp();
  double getKd();
  double getMax();
  double getMin();
  double getDt();
  double getIntegral();
  double getPre_Error();
  void Testing();
};

#endif  // INCLUDE_PIDCONTROLLER_H_
