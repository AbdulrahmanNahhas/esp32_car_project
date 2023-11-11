#include "UltrasonicSensor.h"

Ultrasonic::Ultrasonic(gpio_num_t triggerPin, gpio_num_t echoPin) {
  this->TRIGGER_GPIO = triggerPin;
  this->ECHO_GPIO = echoPin;
  gpio_set_direction(echoPin, GPIO_MODE_INPUT);
  gpio_set_direction(triggerPin, GPIO_MODE_OUTPUT);
}

// This function measures the distance to an object using an ultrasonic sensor.
int Ultrasonic::GetDistance(void) {
  int distance;

  // Deinitialize the trigger GPIO pin and set it to low.
  rtc_gpio_deinit(TRIGGER_GPIO);
  rtc_gpio_set_level(TRIGGER_GPIO, 0);

  // Delay for 1 millisecond and then set the trigger GPIO pin to high.
  vTaskDelay(1 / portTICK_PERIOD_MS);
  rtc_gpio_set_level(TRIGGER_GPIO, 1);  

  // Delay for 5 milliseconds and then set the trigger GPIO pin to low.
  vTaskDelay(5 / portTICK_PERIOD_MS);
  rtc_gpio_set_level(TRIGGER_GPIO, 0);

  // Wait until the echo GPIO pin goes high.
  while(rtc_gpio_get_level(ECHO_GPIO) == 0);

  // Reset and start a timer with a period of 100 milliseconds.
  xTimerReset(timer, 100);
  xTimerStart(timer, 100);

  // Wait until the echo GPIO pin goes low.
  while(rtc_gpio_get_level(ECHO_GPIO) == 1);

  // Stop the timer.
  xTimerStop(timer, 0);

  // Calculate the distance from the time it took for the echo to return. The 0.01716 factor is used to convert the time in milliseconds to centimeters.
  distance = xTimerGetPeriod(timer) / portTICK_PERIOD_MS;
  distance = distance * 0.01716;

  // Return the distance.
  return distance;
}


