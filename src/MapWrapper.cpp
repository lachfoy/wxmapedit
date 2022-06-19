#include "MapWrapper.h"

MapWrapper::MapWrapper(Map* map)
{
    m_map = map;
}

MapWrapper MapWrapper::generateMap()
{
    Map* map = (Map*)malloc(sizeof(Map));
    generate_map(map);
    return MapWrapper(map);
}