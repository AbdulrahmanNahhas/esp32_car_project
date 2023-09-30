#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define pdSecond pdMS_TO_TICKS(1000) // Define a constant that represents one second in ticks.
#include "esp_log.h"

// The Main class is a simple class that contains two functions: setup() and loop().
class Main final {
public:
  esp_err_t setup(void);  // this function is called once when the application starts up.
  void loop(void);        // this function is called repeatedly until the application exits.
};