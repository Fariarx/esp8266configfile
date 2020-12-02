
#include <Arduino.h>
#include <EEPROM.h>

template <class T>
bool WriteCfg(const T &value)
{
    EEPROM.begin(4096);

    byte *p = (byte *)(void *)&value;
    for (int i = 0; i < sizeof(value); i++)
    {
        EEPROM.write(i, *p++);
    }

    EEPROM.commit();
    return 1;
}

template <class T>
bool ReadCfg(T &value)
{
    EEPROM.begin(4000);

    byte *p = (byte *)(void *)&value;
    for (int i = 0; i < sizeof(value); i++)
    {
        *p++ = EEPROM.read(i);
    }  

    return 1;
}

struct config_t
{
    int ini = 0;
    char struct_passwoed[32];
    signed int struct_timeOffset;
    bool temperatureListSet = false;
    char temperatureList[400];
    bool temperatureListDaySleepSet = false;
    char temperatureListDaySleep[400];
    int offHeatingTimer = 0;
    int daySleepTimer = 0;
    bool heatingState = true;
    int rebootCount = 0;
    unsigned long currentTime = 0;
    float default_temperature = -5;
    float forced_temperature = NULL;
    bool relayAlwaysOn = false;
    int rebootEvery = 10;
    float temperatureTolerance = 1;
    bool wasSetSettings = false;
    bool wasAutoReboot = false;
};
