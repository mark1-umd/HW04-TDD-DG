/** @file PIDController.cpp
* @brief a PID Controller class
* @author Daniel Gellman
* @copyright
* Class that implements a PID Controller object.
*/

#ifndef GUARD_PIDController_H
#define GUARD_PIDController_H

class PIDController{
private:
	double dt,max,min, Kp, Kd, Ki, pre_error, integral;
public:
	PIDController( double dt, double max, double min, double Kp, double Kd, double Ki);
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

#endif
