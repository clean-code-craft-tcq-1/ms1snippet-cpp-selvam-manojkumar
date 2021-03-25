
#define SOC_THRESHOLD         0.05
#define CURRENT_THRESHOLD     0.1

bool iterateReadings(double* values, int numOfValues, float threshold);

bool isRangeViolated(double value, double nextValue, double maxDelta);

bool validateSOCreadings(double* values, int numOfValues);

bool validateCurrentreadings(double* values, int numOfValues);
