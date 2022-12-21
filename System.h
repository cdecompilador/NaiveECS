#include "Entity.h"
#include "Component.h"

#include <vector>

class World;

class System 
{
public:
    System(World& world) 
        : m_pWorld(world)
    {
    }

    virtual ~System() {}

    /* This function is called every frame to update the system */
    virtual void
    update(float deltaTime) = 0;
protected:
    World& m_pWorld;
};

class MovementSystem : public System 
{
public:
    MovementSystem(World& world) 
        : System(world)
    {
    }

    void 
    update(float deltaTime) override;
};