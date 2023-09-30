#include "main.h"
#include "gpio_comp.h"
#include "Nimble.h"

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

  printf("hello");

  return status;
}

void Main::loop(void) {}