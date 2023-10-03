#ifndef CONFIG_H
#define CONFIG_H

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

struct json_bus {
  QueueHandle_t queue_send; // move - direction
  QueueHandle_t queue_recieve; // distance - gps ...
};

enum directions {
  stop,     // 0
  forward,  // 1
  backward, // 2
  right,    // 3
  left      // 4
};

#endif