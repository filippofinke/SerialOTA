#include "serialota.h"
#include "secrets.h"

SerialOTA sota;

void setup()
{
    Serial.begin(9600);
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println();
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);

    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    sota.begin();
}

int cnt;
void loop()
{
    sota.loop();
    sota.println(String(cnt++));
    delay(500);
}