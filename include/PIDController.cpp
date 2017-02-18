/** @file PIDController.cpp
* @brief a PID Controller class
* @author Daniel Gellman
* @copyright
* Class that implements a PID Controller object.
*/

#include "PIDController.h"
#include <cmath>
#include <iostream>


class PIDController{
public:
	PIDController( double dt, double max, double min, double Kp, double Kd, double Ki );
	~PIDController();
	double compute(double setpoint, double pv);
private:
	double Ki, Kp, Kd, max, min, dt, integral, pre_error;
};

PIDController::compute(double setpoint, double pv){

	return 0.0;
}

PIDController::PIDController(double dt, double max, double min, double Kp, double Kd, double Ki) :
		dt(dt),
		min(min),
		max(max),
		Ki(Ki),
		Kp(Kp),
		Kd(Kd),
		pre_error(0),
		integral(0)
{
}
PIDController::~PIDController(){

}
