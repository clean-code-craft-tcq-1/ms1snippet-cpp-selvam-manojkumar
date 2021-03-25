#include "sensor-validate.h"
#include <iostream>
#include <assert.h>

/* check for surge of value */
bool isSurgeViolated(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return false;
  }
  return true;
}

/* check the surge for every elements in array */
bool iterateReadings(double* values, int numOfValues, float threshold)
{
	int lastButOneIndex = numOfValues - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!isSurgeViolated(values[i], values[i + 1], threshold)) {
			return false;
		}
	}
	return true;
}

/* check the validate the parametar data for invalid readings */
bool validate_parameter_readings(double* values, int numOfValues, float threshold)
{
	if ((values== NULL) || (numOfValues == 0))
		return true;
	else
	{
		return iterateReadings(values,  numOfValues, threshold);
	}
}

/* check the validate the SOC */
bool validateSOCreadings(double* values, int numOfValues)
{
	return validate_parameter_readings(values, numOfValues, SOC_THRESHOLD);
}

/* check the validate the current */
bool validateCurrentreadings(double* values, int numOfValues) 
{
	return validate_parameter_readings(values, numOfValues, CURRENT_THRESHOLD);
}
