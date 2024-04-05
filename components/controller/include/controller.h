#pragma once

#include "esp_log.h"
#include "driver/gpio.h"
#include "../../../config.h"

#define motor_pin1 GPIO_NUM_18
#define motor_pin2 GPIO_NUM_19
#define motor_pin3 GPIO_NUM_27
#define motor_pin4 GPIO_NUM_26

class Controller {
private:
  const char* TAG = "CONTROLLER";

public:
  void init();
  void control_motor(int direction);
};