set(SOURCES "Nimble.c")

idf_component_register(
  SRCS ${SOURCES}
  INCLUDE_DIRS "include"
  REQUIRES bt nvs_flash driver
  PRIV_REQUIRES ${ESP_NIMBLE_PRIV_REQUIRES}
)