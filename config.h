#ifndef CONFIG_H
#define CONFIG_H

#include "freertos/queue.h"

struct json_bus {
  QueueHandle_t queue_send;
  QueueHandle_t queue_recieve;
};

static struct json_bus data_bus;

#endif