#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include <cstring>
#include "../../../config.h"
#include "JSON.h"

class DSP {
  char json_string[100];
  JSON json;
  static struct json_bus* data_bus;
  int value;

  public:
    DSP(struct json_bus* data);
    static void dsb_task(void *parameter);
};