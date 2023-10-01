#include "JSON.h"

JSON::JSON(void) {
  *root = cJSON_CreateObject();
  *gps = cJSON_CreateObject();
}

/* When user Write
  this function gets json string and the output will be objects

  ? Example:  
  {
    move: true | false
    direction: “forward” | “backward” | “right” | “left”
  }

*/
void JSON::save_objects(char *json_string) {

}

/* When user Read
  
  ? Example:
  {
    distance: int
    latitude: double
    longitude: double
  }

*/
void JSON::update_values(int Distance, double Latitude, double Longitude) {
  latitude = Latitude;
  longitude = Longitude;
  distance = Distance;

  cJSON_AddNumberToObject(gps, "latitude", latitude);
  cJSON_AddNumberToObject(gps, "longitude", longitude);
  cJSON_AddItemToObject(root, "GPS", gps);
  cJSON_AddNumberToObject(root, "distance", distance);
}
char JSON::print() {
  char *json_string = cJSON_Print(root);
  printf(json_string);
  return json_string;
}

JSON::~JSON(void) {
  cJSON_Delete(gps);
  cJSON_Delete(root);
}