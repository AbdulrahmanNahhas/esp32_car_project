# include($ENV{IDF_PATH}/tools/cmake/project.cmake)

idf_component_register(
  SRCS "gpio_comp.c"
  INCLUDE_DIRS "include"
  REQUIRES driver
)
