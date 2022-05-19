#include "serialota.h"

typedef void (*CallbackFunction)(String str);

ESPTelnet SerialOTA::telnet;
bool SerialOTA::_connected = false;

void SerialOTA::onConnect(String ip)
{
    Serial.println("CONNECTED");
    SerialOTA::_connected = true;
}

void SerialOTA::onDisconnect(String ip)
{
    Serial.println("DISCONNECTED");
    SerialOTA::_connected = false;
}

void SerialOTA::begin()
{
    SerialOTA::telnet.onConnect((CallbackFunction)&SerialOTA::onConnect);
    SerialOTA::telnet.onDisconnect((CallbackFunction)&SerialOTA::onDisconnect);
    SerialOTA::telnet.begin(23);
}

void SerialOTA::loop()
{
    SerialOTA::telnet.loop();
}

void SerialOTA::print(const String &str)
{
    if (SerialOTA::_connected)
    {
        SerialOTA::telnet.print(str);
    }
    Serial.print(str);
}

void SerialOTA::println(const String &str)
{
    Serial.println(SerialOTA::_connected);
    if (SerialOTA::_connected)
    {
        SerialOTA::telnet.println(str);
    }
    Serial.println(str);
}