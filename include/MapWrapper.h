#ifndef MAPWRAPPER_H
#define MAPWRAPPER_H

#include <string>

#include "map.h"

class MapWrapper
{
public:
    MapWrapper(Map* map = nullptr);

    static MapWrapper* loadMap();
    static MapWrapper generateMap();
    static void saveMap();

    inline int getWidth() { return m_map->w; }
    inline int getHeight() { return m_map->h; }
    inline bool isSolid(int x, int y) { return (m_map->wall_data[y * m_map->w + x] > 0); }

private:
    std::string m_mapName;
    Map* m_map;
};

#endif