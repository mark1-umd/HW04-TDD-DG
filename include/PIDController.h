/** @file PIDController.cpp
* @brief a PID Controller class
* @author Daniel Gellman
* @copyright
* Class that implements a PID Controller object.
*/

#ifndef _PIDController_H_
#define _PIDController_H_

class PIDController{
public:
	PIDController( double dt, double max, double min, double Kp, double Kd, double Ki );
	~PIDController();
	double compute(double setpoint, double pv);
private:
	double Ki, Kp, Kd, max, min, dt, integral, pre_error;
};

#endif
