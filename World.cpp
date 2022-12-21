#include "World.h"
#include "System.h"

/* Get all the entities with a specific set of components */
void 
World::update(float deltaTime)
{
    for (const auto& system : m_systems)
    {
        system->update(deltaTime);
    }
}