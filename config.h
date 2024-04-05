#ifndef CONFIG_H
#define CONFIG_H

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

struct json_bus {
  QueueHandle_t queue_send;     // move - direction
  QueueHandle_t queue_recieve;  // distance - gps ...
};

enum MotorDirection {
  STOP,     // 0
  FORWARD,  // 1
  BACKWARD, // 2
  RIGHT,    // 3
  LEFT      // 4
};

#endif