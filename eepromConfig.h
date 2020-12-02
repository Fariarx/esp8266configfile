
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
