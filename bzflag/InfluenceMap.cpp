#include "InfluenceMap.h"

InfluenceMap::InfluenceMap()
{

}

int InfluenceMap::getInfluence(int x, int y)
{
    float floatX, floatY, influence = 0;

    floatX = x * SCALE;
    floatY = y * SCALE;
    const float nodePos[2] = { floatX, floatY };

    for (int i = 0; i <= World::getWorld()->getCurMaxPlayers(); i++)
    {
        Player * p = NULL;
        const float * pos;   // p's position
        double distance = 0; // distance between robot and node

        p   = World::getWorld()->getPlayer(i);
        pos = p->getPosition();

        if (p->getTeam() != TeamColor::GreenTeam)
        {
            distance   = getDistance(pos, nodePos);
            influence += ((INF / distance) + 1);
        }
    }

    return (int)influence;
}

float InfluenceMap::getDistance(const float pos1[2], const float pos2[2])
{
    float pos[2];
    float distance = 0;

    pos[0] = (pos1[0] - pos2[0]);
    pos[1] = (pos1[1] - pos2[1]);

    distance = hypotf(pos[0], pos[1]);

    return distance;
}