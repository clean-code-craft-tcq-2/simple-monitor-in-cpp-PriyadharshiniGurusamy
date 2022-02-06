#include <assert.h>
#include <iostream>
using namespace std;

std::string TempWarning = "Temperature out of range!";
std::string SocWarning = "State of Charge out of range!";
std::string RateofChargeWarning = "Charge Rate out of range!";

void PrintWarning(std::string warning)
{
    cout << warning << "\n";
}

bool TempCheck(float temperature)
{
    bool retVal = (temperature < 0 || temperature > 45)? false: true;
    return retVal;
}

bool SocCheck(float soc)
{
    bool retVal = (soc < 20 || soc > 80)? false: true;
    return retVal;
}

bool ChargeRateCheck(float chargeRate)
{
    bool retVal = (chargeRate > 0.8)? false: true;
    return retVal;
}

bool BatteryValuesisOK(float value, bool (*Validation)(float), std::string Warning)
{
    bool retVal = Validation(value);
    if(!retVal) {
    PrintWarning(Warning);
  }
  return retVal;
  
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool retVal =  BatteryValuesisOK(temperature, TempCheck, TempWarning);
    retVal =  retVal && BatteryValuesisOK(soc, SocCheck, SocWarning);
    retVal =  retVal && BatteryValuesisOK(chargeRate, ChargeRateCheck, RateofChargeWarning);
  return retVal;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
