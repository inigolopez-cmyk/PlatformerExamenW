#pragma once
#include "Tile.h"
class Stair :
    public Tile
{
private:

public:
    Stair(float x, float y, float size);
    ~Stair();

    void Draw()const override;
};

