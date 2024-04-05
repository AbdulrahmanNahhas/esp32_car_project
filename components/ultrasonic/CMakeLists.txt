# https://github.com/ESP32Tutorials/HC-SR04-Ultrasonic-Sensor-with-ESP32-ESP-IDF/blob/main/Ultrasonic_sensor_esp-idf/components/ultrasonic/CMakeLists.txt

if(${IDF_TARGET} STREQUAL esp8266)
    set(req esp8266 freertos esp_timer)
elseif(${IDF_VERSION_MAJOR} STREQUAL 4 AND ${IDF_VERSION_MINOR} STREQUAL 1 AND ${IDF_VERSION_PATCH} STREQUAL 3)
    set(req driver freertos)
else()
    set(req driver freertos esp_timer)
endif()

idf_component_register(
    SRCS ultrasonic.cpp
    INCLUDE_DIRS "include"
    REQUIRES ${req}
)