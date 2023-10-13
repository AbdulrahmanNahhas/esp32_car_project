#include "DSP.h"

DSP::DSP(struct json_bus* data) {
  data_bus = data;

  printf("DSB Task Created!!");
  xTaskCreatePinnedToCore(&dsb_task, "DSP_Task", 4096, (void *)this, 1, NULL, 1);
}

void DSP::dsb_task(void *parameter) {
  DSP* dsp = (DSP*) (parameter);

  while(1) {
    // When recieve data from React-Native
    if(xQueueReceive(dsp->data_bus->queue_send, (void *)&dsp->json_string, 0) == pdPASS) {
      printf("===========================\n");
      printf("I received data from nimble\n");

      dsp->value = dsp->json.parse_json_objects(dsp->json_string);

      printf("Values Updated From User \n");
      printf("direction value: %d \n", dsp->value);

      if (dsp->value == directions::stop) {
        printf("Stopping...\n");
      }

      printf("===========================\n");
    }

    // Update the data
    dsp->json.update_values(50, 12204, -12103);
    strcpy(dsp->json_string, dsp->json.get_json_string());

    // // Send data to Nimble
    if (xQueueSend(dsp->data_bus->queue_recieve, (void *)&dsp->json_string, 10) != pdPASS) {
      printf("ERROR: Could not put item on delay queue.\n");
    }

    vTaskDelay(pdMS_TO_TICKS(200));
  }
}