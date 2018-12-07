/*
  WiFiMQTTManager.h - Library for the ESP8266/ESP32 Arduino platform
  for configuration of WiFi and MQTT credentials using a AP mode and Captive Portal
*/
#ifndef WiFiMQTTManager_h
#define WiFiMQTTManager_h

//#define MQTT_MAX_PACKET_SIZE 512

#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ArduinoJson.h> // https://github.com/bblanchon/ArduinoJson
#include <PubSubClient.h>
#include "Arduino.h"
#include "FS.h"
#include "utility.h"

#ifdef ESP32
  #include <SPIFFS.h>
#endif

void _settingsAP();

class WiFiMQTTManager {
  public:
    WiFiMQTTManager(int resetPin, char* APpassword);
    //WiFiManager wm;
    void setup(String sketchName);
    void loop();
    void setDebugOutput(bool b);
    std::shared_ptr<PubSubClient> client;
    char clientId[40];
    char deviceId[40];
    char chipId[40];
    void (*subscribeTo)();
    void (*subscriptionCallback)(char* topicIn, byte* message, unsigned int length);
    bool formatFS;
    long lastMsg;
    char deviceType[40];
  private:
    void _setupSpiffs();
    void _checkButton();
    void _registerDevice();
    void _reconnect();
    void _subscribeToServices();
    //void _subscriptionCallback(char* topicIn, byte* message, unsigned int length);
    //void (*_subscriptionCallback)(char* topicIn, byte* message, unsigned int length);
    int _resetPin;
    char _friendly_name[40];
    char _mqtt_server[40];
    char _mqtt_port[6];
    String _sketchName;
    char* _APpassword;
    //char _mqtt_username[40] = "YOURMQTTUSERNAME";
    //char _mqtt_password[40] = "YOURMQTTPASSWORD";
    int _LED_BUILTIN;
    long _lastMsg;
    char _msg[50];
    int _value;
    bool _shouldSaveConfig;  
    WiFiClient _espClient;

};

#endif