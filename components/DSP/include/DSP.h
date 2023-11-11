#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include <iostream>
#include <cstring>

#include "UltrasonicSensor.h"
#include "../../../config.h"
#include "JSON.h"

class DSP {
  struct json_bus* data_bus;
  char json_string[100];
  int value;
  JSON json;
  int distance=0;

  public:
    DSP(struct json_bus* data);
    static void dsb_task(void *parameter);
};