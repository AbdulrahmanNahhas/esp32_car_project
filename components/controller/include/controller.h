#pragma once

#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_attr.h"

// mcpwm = Motor Control Pulse Width Modulator
#include "driver/mcpwm.h"
#include "soc/mcpwm_periph.h"
#include "../../../config.h"

#define GPIO_PWM0A_OUT 15
#define GPIO_PWM0B_OUT 16

class Controller {
  // int direction = 0;

public:
  Controller();

  void initialize();
  void control_motor(int direction);
};