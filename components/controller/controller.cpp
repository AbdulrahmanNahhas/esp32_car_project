#include "controller.h"

void Controller::init() {
  gpio_set_direction(motor_pin1, GPIO_MODE_OUTPUT);
  gpio_set_direction(motor_pin2, GPIO_MODE_OUTPUT);
  gpio_set_direction(motor_pin3, GPIO_MODE_OUTPUT);
  gpio_set_direction(motor_pin4, GPIO_MODE_OUTPUT);
}

void Controller::control_motor(int direction) {
  switch (direction) {
  case MotorDirection::STOP:
    gpio_set_level(motor_pin1, 0);
    gpio_set_level(motor_pin2, 0);
    gpio_set_level(motor_pin3, 0);
    gpio_set_level(motor_pin4, 0);
    ESP_LOGI(TAG, "Car is stopping... \n");
    break;
  case MotorDirection::FORWARD:
    gpio_set_level(motor_pin1, 1);
    gpio_set_level(motor_pin2, 0);
    gpio_set_level(motor_pin3, 1);
    gpio_set_level(motor_pin4, 0);
    ESP_LOGI(TAG, "Car is moving forward \n");
    break;
  case MotorDirection::BACKWARD:
    gpio_set_level(motor_pin1, 0);
    gpio_set_level(motor_pin2, 1);
    gpio_set_level(motor_pin3, 0);
    gpio_set_level(motor_pin4, 1);
    ESP_LOGI(TAG, "Car is moving backward \n");
    break;
  case MotorDirection::RIGHT:
    gpio_set_level(motor_pin1, 0);
    gpio_set_level(motor_pin2, 0);
    gpio_set_level(motor_pin3, 1);
    gpio_set_level(motor_pin4, 0);
    ESP_LOGI(TAG, "Car is moving to right \n");
    break;
  case MotorDirection::LEFT:
    gpio_set_level(motor_pin1, 1);
    gpio_set_level(motor_pin2, 0);
    gpio_set_level(motor_pin3, 0);
    gpio_set_level(motor_pin4, 0);
    ESP_LOGI(TAG, "Car is moving to left \n");
    break;

  default:
    ESP_LOGI(TAG, "Error: Wrong direction!! \n");
    break;
  }
}