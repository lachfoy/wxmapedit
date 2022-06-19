#ifndef MAPWRAPPER_H
#define MAPWRAPPER_H

#include <string>
#include <cstdint>

extern "C" {
#include "map.h"
}

class MapWrapper
{
public:
    MapWrapper(Map* map = nullptr);

    inline int getWidth() const { return m_map->w; }
    inline int getHeight() const { return m_map->h; }
    inline bool isSolid(int x, int y) const { return (m_map->wall_data[y * m_map->w + x] > 0); }
    inline void setTile(int x, int y, int value) { m_map->wall_data[y * m_map->w + x] = uint8_t(value); }
    inline int getTile(int x, int y) const { return m_map->wall_data[y * m_map->w + x]; }

    static MapWrapper* loadMap();
    static MapWrapper generateMap();
    static void saveMap();

private:
    std::string m_mapName;
    Map* m_map;
};

#endif