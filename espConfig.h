#include <EEPROM.h>
#include <Arduino.h>
#include "FS.h"

template <class T>
bool WriteCfg(const T &value)
{
    SPIFFS.begin();

    File f = SPIFFS.open("/config.txt", "w");
    if (!f)
    {
        Serial.println("file open failed");
        SPIFFS.end();
        f.close();
        return 0;
    }

    delay(10);
 
    byte *p = (byte *)(void *)&value;
    char res[sizeof(value)];
    byte *r = (byte *)(void *)&res;  
    for (int i = 0; i < sizeof(value); i++)
    {
        *r++ = *p++;
    }

    f.write((uint8_t *)res, sizeof(value));
    f.close();

    SPIFFS.end();
    return 1;
}

template <class T>
bool ReadCfg(T &value)
{
    SPIFFS.begin();

    File f = SPIFFS.open("/config.txt", "r");
    if (!f)
    {
        Serial.println("file open failed");
        SPIFFS.end();
        f.close();
        return 0;
    }

    delay(10); 

    char *p = (char *)(void *)&value; 
    f.readBytes(p, sizeof(value));
    f.close();   
    
    SPIFFS.end(); 
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
};
