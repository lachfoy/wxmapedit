// handles all of the map loading and saving stuff

#ifndef MAP_H
#define MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAPS_DIR "maps/"

typedef struct Map
{
    uint8_t w;
    uint8_t h;
    uint8_t* wall_data;
    uint8_t* object_data;
} Map;

void generate_map(Map* map);
void save_map(Map* map, const char* map_name);
void load_map(Map* map, const char* map_name);

#ifdef __cplusplus
}
#endif

#endif