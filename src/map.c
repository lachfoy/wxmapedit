#include "map.h"

void generate_map(Map* map) // generates a filled map for testing
{
    // dummy w and h
    map->w = 18;
    map->h = 10;

    // dummy wall data
    uint8_t wall_data[] = { 
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };

    // dummy object data
    uint8_t object_data[] = { 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    // allocate memory blocks for data
    map->wall_data = (uint8_t*)malloc(sizeof(uint8_t) * map->w * map->h);
    map->object_data = (uint8_t*)malloc(sizeof(uint8_t) * map->w * map->h);

    // assign dummy data
    for (uint16_t i = 0; i < map->w * map->h; i++)
    {
        map->wall_data[i] = wall_data[i];
        map->object_data[i] = object_data[i];
    }
}

void save_map(Map* map, const char* map_path)
{
    // map buffer size is 2 ints for w and h then w * h ints for the wall data and another w * h ints for the object data.
    size_t map_buffer_size = (sizeof(uint8_t) * 2) + (sizeof(uint8_t) * map->w * map->h) + (sizeof(uint8_t) * map->w * map->h);
    uint8_t* map_buffer = (uint8_t*)malloc(map_buffer_size);

    // write into the map_buffer
    map_buffer[0] = map->w;
    map_buffer[1] = map->h;

    for (uint16_t i = 0; i < map->w * map->h; i++)
        map_buffer[i + 2] = map->wall_data[i];

    for (uint16_t i = 0; i < map->w * map->h; i++)
        map_buffer[i + 2 + map->w * map->h] = map->object_data[i]; 
    
    // save the map buffer as a binary file
    FILE* fptr;
    fptr = fopen(map_path, "wb");
    
    if (fptr == NULL)
    {
        printf("Failed to open %s\n", map_path);
        exit(1);
    }

    fwrite(map_buffer, map_buffer_size, 1, fptr);

    fclose(fptr);
}