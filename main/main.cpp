#include "main.h"

// Create a static instance of the Main class.
static Main main_app;
extern "C" void app_main(void) {
  ESP_ERROR_CHECK(main_app.setup()); // Initialize the Main object.
  while (true) {
    main_app.loop();
  }
}

esp_err_t Main::setup(void) {
  esp_err_t status{ ESP_OK };

  data_bus.queue_recieve = xQueueCreate(1, sizeof(char[100]));
  data_bus.queue_send = xQueueCreate(1, sizeof(char[100]));
  dsp = new DSP(&data_bus);

  startNVS();
  startBLE(&data_bus);

  // ? Start the FreeRTOS task to notify the client
  xTaskCreate(vTasksendNotification, "vTasksendNotification", 4096, NULL, 1, NULL);

  // controller.init();

  // vTaskDelay(2500 / portTICK_PERIOD_MS);

  return status;
}

void Main::loop(void) {
  // controller.control_motor(1);
  // vTaskDelay(2500 / portTICK_PERIOD_MS);
  // controller.control_motor(0);
  // vTaskDelay(2500 / portTICK_PERIOD_MS);
}