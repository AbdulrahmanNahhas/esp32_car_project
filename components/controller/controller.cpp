#include "controller.h"

// ! Error - Nothing Working!!

Controller::Controller() {
  // 1. mcpwm gpio initialization
  printf("initializing mcpwm gpio...\n");
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, GPIO_PWM0A_OUT);
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, GPIO_PWM0B_OUT);

  // 2. initial mcpwm configuration
  printf("Configuring Initial Parameters of mcpwm...\n");
  mcpwm_config_t pwm_config;
  pwm_config.frequency = 1000;    //frequency = 500Hz,
  pwm_config.cmpr_a = 0;        // duty cycle of PWMxA = 0
  pwm_config.cmpr_b = 0;    //duty cycle of PWMxb = 0
  pwm_config.counter_mode = MCPWM_UP_COUNTER;
  pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
  mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);    //Configure PWM0A & PWM0B with above settings
}

void Controller::control_motor(int direction) {
  switch (direction) {
  case directions::stop:
    printf("Car is stopping... \n");
    break;
  case directions::forward:
    printf("Car is moving forward \n");
    break;
  case directions::backward:
    printf("Car is moving backward \n");
    break;
  case directions::right:
    printf("Car is moving to right \n");
    break;
  case directions::left:
    printf("Car is moving to left \n");
    break;
  
  default:
    printf("Error: Wrong direction!! \n");
    break;
  }
}