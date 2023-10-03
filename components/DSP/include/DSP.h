#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include <iostream>
#include <cstring>

#include "../../../config.h"
#include "JSON.h"

// : public Task
class DSP {
  char json_string[100];
  JSON json;
  struct json_bus* data_bus;
  int value;

  public:
    DSP(struct json_bus* data);
    // void run(void* data);
    static void dsb_task(void *parameter);
};