#include "DSP.h"

DSP::DSP(struct json_bus* data) {
  data_bus = data;

  controller.init();

  printf("DSB Task Created!!");
  xTaskCreatePinnedToCore(&dsb_task, "DSP_Task", 4096, (void*)this, 1, NULL, 1);

  printf("HCSR04 Task Created!!");
  xTaskCreate(ultra_task, "Ultrasonic_Task", configMINIMAL_STACK_SIZE * 3, NULL, 5, NULL);
}

void DSP::ultra_task(void* parameter) {
  // DSP* dsp = (DSP*)(parameter);
  float distance;

  ultrasonic_sensor_t sensor = {
    .trigger_pin = TRIGGER_GPIO,
    .echo_pin = ECHO_GPIO
  };

  ultrasonic_init(&sensor);

  while (true) {
    esp_err_t res = ultrasonic_measure(&sensor, MAX_DISTANCE_CM, &distance);
    if (res != ESP_OK) {
      printf("Error %d: ", res);
      switch (res) {
      case ESP_ERR_ULTRASONIC_PING:
        printf("Cannot ping (device is in invalid state)\n");
        break;
      case ESP_ERR_ULTRASONIC_PING_TIMEOUT:
        printf("Ping timeout (no device found)\n");
        break;
      case ESP_ERR_ULTRASONIC_ECHO_TIMEOUT:
        printf("Echo timeout (i.e. distance too big)\n");
        break;
      default:
        printf("%s\n", esp_err_to_name(res));
      }
    }
    else
      // printf("Distance: %0.04f cm\n", distance * 100);

    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void DSP::dsb_task(void* parameter) {
  DSP* dsp = (DSP*)(parameter);

  while (1) {
    // When recieve data from React-Native
    if (xQueueReceive(dsp->data_bus->queue_send, (void*)&dsp->json_string, 0) == pdPASS) {
      printf("===========================\n");
      printf("I received data from nimble\n");

      // Convert data to objects
      dsp->value = dsp->json.parse_json_objects(dsp->json_string);

      // Printing
      printf("Values Updated From User \n");
      printf("direction value: %d \n", dsp->value);

      // Controlling Motor
      dsp->controller.control_motor(dsp->value);

      printf("===========================\n");
    }

    // Update the data
    dsp->json.update_values(50.5, 12204, -12103);
    strcpy(dsp->json_string, dsp->json.get_json_string());

    // // Send data to Nimble
    if (xQueueSend(dsp->data_bus->queue_recieve, (void*)&dsp->json_string, 10) != pdPASS) {
      printf("ERROR: Could not put item on delay queue.\n");
    }

    vTaskDelay(pdMS_TO_TICKS(200));
  }
}