#define amount 15
#include <ESP8266WiFi.h>
const char *ssid = "ssid";
const char *password = "password";
const char *deviceid = "114514" const char *serveraddress = "http://127.0.0.1/bathserve/updateStatus?bathroomId=";

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".")
    }
    Serial.print("\nWiFi connected.\nYour IP address is: ");
    Serial.print(WiFi.localIP());
    for (int i = 0; i < amount; i++)
    {
        pinMode(i, INPUT);
    }
}
void loop()
{
    delay(30000);
    status = 0;
    for (int i = 0; i < amount; i++)
    {
        status += power(2, i);
        delay(200);
    }
    HttpClient http;
    char *url = strcat(serveraddress, itoa(status));
    http.begin(url.c_str());
    int httpResponseCode = http.GET();
    if (httpResponseCode)
    {
        Serial.print("GET ");
        Serial.print(url);
        Serial.println(" SUCCESS");
    }
}