#include "sensor-validate.h"
#include <iostream>
#include <assert.h>


bool isRangeViolated(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return false;
  }
  return true;
}

bool iterateReadings(double* values, int numOfValues, float threshold)
{
	int lastButOneIndex = numOfValues - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!isRangeViolated(values[i], values[i + 1], threshold)) {
			return false;
		}
	}
	return true;
}

bool validate_parameter_readings(double* values, int numOfValues, float threshold)
{
	if ((values== NULL) || (numOfValues == 0))
		return false;
	else
	{
		return iterateReadings(values,  numOfValues, threshold);
	}
}


bool validateSOCreadings(double* values, int numOfValues)
{
	return validate_parameter_readings(values, numOfValues, SOC_THRESHOLD);
}

bool validateCurrentreadings(double* values, int numOfValues) 
{
	return validate_parameter_readings(values, numOfValues, CURRENT_THRESHOLD);
}
