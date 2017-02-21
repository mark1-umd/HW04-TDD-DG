#include <iostream>
#include <lib.hpp>
#include "PIDController.h"

int main()
{
	PIDController controller = PIDController(1,2,.4,2,3,0);
    return 0;
}
