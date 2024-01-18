#include <stdint.h>
#include <stdio.h>

#include "driver/driver.h"

int main (){
	GPIO_INITIALIZATION();

	int pVal, threshold = 20;

	while (1)
	{
		pVal = getPressureVal();

		if (pVal <= threshold) {
			Set_Alarm_actuator(AlarmOff);
		} else {
			Set_Alarm_actuator(AlarmOn);
		}

		Delay(1000);
	}

}
