
#ifndef SerialOTA_H
#define SerialOTA_H
#include "Arduino.h"
#include "ESPTelnet.h"

class SerialOTA
{
private:
    static ESPTelnet telnet;
    static bool _connected;
    static void onConnect(String ip);
    static void onDisconnect(String ip);

public:
    static void begin(void);
    static void loop(void);
    static void print(const String &str);
    static void println(const String &str);
};

#endif