#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
    virtual ~Component() {}
};

struct PositionComponent : public Component
{
    PositionComponent(float x, float y)
        : x(x)
        , y(y)
    {
    }

    float x, y;
};

struct VelocityComponent : public Component
{
    VelocityComponent(float vx, float vy)
        : vx(vx)
        , vy(vy)
    {
    }

    float vx, vy;
};

#endif