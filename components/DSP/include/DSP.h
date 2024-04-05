#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <esp_err.h>
#include <iostream>
#include <cstring>

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include "../../../config.h"
#include "ultrasonic.h"
#include "controller.h"
#include "JSON.h"

// ======  For Ultrasonic ====== //
#define MAX_DISTANCE_CM 500      // 5m max
#define TRIGGER_GPIO GPIO_NUM_26 // Pin: 26
#define ECHO_GPIO    GPIO_NUM_27 // Pin: 27

class DSP {
private:
  struct json_bus* data_bus;
  int value;
  float distance;

  JSON json;
  char json_string[100];

  Controller controller;

public:
  DSP(struct json_bus* data);
  static void dsb_task(void *parameter);
  static void ultra_task(void *parameter);
};