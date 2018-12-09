/*
  utility.h - Library for the ESP8266/ESP32 Arduino platform
  for configuration of WiFi and MQTT credentials using a AP mode and Captive Portal

  credit: https://blog.galowicz.de/2016/02/20/short_file_macro/

  Written by David Reed hashmark47@gmail.com
  GNU license  
*/

using cstr = const char * const;

static constexpr cstr past_last_slash(cstr str, cstr last_slash)
{
    return
        *str == '\0' ? last_slash :
        *str == '/'  ? past_last_slash(str + 1, str + 1) :
                       past_last_slash(str + 1, last_slash);
}

static constexpr cstr past_last_slash(cstr str) 
{ 
    return past_last_slash(str, str);
}
#define __SHORT_FILE__ ({constexpr cstr sf__ {past_last_slash(__FILE__)}; sf__;})
#define __SKETCH_NAME__ ({constexpr cstr sf__ {past_last_slash(__FILE__)}; sf__;})