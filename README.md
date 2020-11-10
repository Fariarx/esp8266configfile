# esp8266configfile
Simple byte write/read the file into flash. 
Limited only by the memory of your controller.

# Example
Write/read struct:

```C
#include <espConfig.h>

struct config_t
{ 
    char data[60];
    int state = 0;
};

config_t configuration;

void setup()
{
  if (ReadCfg(configuration))
  {
    Serial.println("Restored config!");
    Serial.println(configuration.state);
  }
  
  configuration.state++;
  WriteCfg(configuration);
  
  delay(5000);
  ESP.reset();
}
```
