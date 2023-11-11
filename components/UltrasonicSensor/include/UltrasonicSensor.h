#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "driver/rtc_io.h"
#include "driver/gpio.h"

class Ultrasonic {
private:
  gpio_num_t TRIGGER_GPIO;
  gpio_num_t ECHO_GPIO;
  TimerHandle_t timer;

public:
  Ultrasonic(gpio_num_t triggerPin, gpio_num_t echoPin);
  int GetDistance(void);
};