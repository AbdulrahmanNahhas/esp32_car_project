#pragma once

#include "cJSON.h"
#include <cstdio>

/*
  READ:
  - Distance (ultrasonics)
  - GPS:
    - Latitude
    - Longitude

  Write:
  - Move: boolean
  - Direction: char[] (“forward” or “backward” or “right” or “left”)

  * when user click on left arrow (example) the Move will be true, and Direction = Left
  * and when user hand go off the button the Move will be false
*/

class JSON {
  cJSON *root;
  cJSON *gps;

  // From Sensors
  float distance=50.5;
  double latitude=36, longitude=36;

  // From User (Application)
  int direction;

  public:
    JSON();
    int parse_json_objects(char *json_string);                              // convert json data to objects and save it in the variables (here in the class)
    void update_values(float Distance, double Latitude, double Longitude);  // update the data
    void print();                                                           // print JSON data
    char* get_json_string();                                                // print JSON data
    ~JSON();
};