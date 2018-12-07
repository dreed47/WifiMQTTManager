# WiFiMQTTManager

## Requirements

* [WiFiManager Library](https://github.com/tzapu/WiFiManager/tree/development)
* [Arduino Json Library](https://github.com/bblanchon/ArduinoJson)
* [PubSub Client](https://github.com/knolleary/pubsubclient)
    + NOTE: Change MQTT_MAX_PACKET_SIZE in PubSubClient.h to 512 (at least)