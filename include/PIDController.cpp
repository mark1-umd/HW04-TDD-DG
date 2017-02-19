/** @file PIDController.cpp
* @brief a PID Controller class
* @author Daniel Gellman
* @copyright
* Class that implements a PID Controller object.
*/

#include "PIDController.h"
#include <cmath>
#include <iostream>

PIDController::PIDController(double dt, double max, double min, double Kp, double Kd, double Ki) :
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
PIDController::PIDController(){

}
PIDController::~PIDController(){

}

void PIDController::Testing(){
	std::cout << "Successful build " << std::endl;
}

double PIDController::compute(double setpoint, double pv){

	return 0.0;
}
double PIDController::getKi(){
	return Ki;
}
double PIDController::getKp(){
	return Kp;
}
double PIDController::getKd(){
	return Kd;
}
double PIDController::getMax(){
	return max;
}
double PIDController::getMin(){
	return min;
}
double PIDController::getDt(){
	return dt;
}
double PIDController::getIntegral(){
	return integral;
}
double PIDController::getPre_Error(){
	return pre_error;
}
