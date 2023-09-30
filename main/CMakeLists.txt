set(SOURCES "main.cpp" "nimble.cpp")

idf_component_register(
  SRCS ${SOURCES}
  INCLUDE_DIRS .
)