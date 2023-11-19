#include "JSON.h"

JSON::JSON() {
  root = cJSON_CreateObject();
  gps = cJSON_CreateObject();
  cJSON_AddNumberToObject(gps, "latitude", latitude);
  cJSON_AddNumberToObject(gps, "longitude", longitude);
  cJSON_AddItemToObject(root, "GPS", gps);
  cJSON_AddNumberToObject(root, "distance", distance);
}

/* When user Write
  this function gets json string and the output will be objects

  ? Example:  
  {
    move: 0 | 1
    direction: “forward” | “backward” | “right” | “left”
  }
*/
int JSON::parse_json_objects(char *json_string) {
  // Create a cJSON object to represent the JSON object
  cJSON *root = cJSON_Parse(json_string);

  // Check if the JSON object was parsed successfully
  if (root == NULL) {
    printf("Error parsing JSON object.\n");
    return 0;
  }

  direction = cJSON_GetObjectItem(root, "direction")->valueint;

  return direction;
}

/* When user Read
  
  ? Example:
  {
    "distance": int
    "gps": {
      "latitude": double
      "longitude": double
    }
  }

*/
void JSON::update_values(float Distance, double Latitude, double Longitude) {
  distance = Distance;
  latitude = Latitude;
  longitude = Longitude;

  cJSON_SetNumberValue(cJSON_GetObjectItem(gps, "latitude"), latitude);
  cJSON_SetNumberValue(cJSON_GetObjectItem(gps, "longitude"), longitude);
  cJSON_SetNumberValue(cJSON_GetObjectItem(root, "distance"), distance);
}

void JSON::print() {
  char* json_string = cJSON_Print(root);
  printf("\n");
  printf(json_string);
  printf("\n");
}

char* JSON::get_json_string() {
  char* json_string = cJSON_Print(root);
  return json_string;
}

JSON::~JSON() {
  cJSON_Delete(gps);
  cJSON_Delete(root);
}