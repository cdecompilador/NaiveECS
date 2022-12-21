#include "System.h"
#include "World.h"

#include <iostream>

void 
MovementSystem::update(float deltaTime)
{

    /* Get all entities with a Position and Velocity */
    std::vector<EntityID> entities = m_pWorld
        .getEntitiesWithComponents<PositionComponent, VelocityComponent>();

    printf("AQUI\n");
    /* Update the position of the entities based on their velocities */
    for (const auto entity : entities) 
    {
        printf("Entity %d\n", (int)entity);
        auto position = m_pWorld.getComponent<PositionComponent>(entity);
        auto velocity = m_pWorld.getComponent<VelocityComponent>(entity);

        position->x += (velocity->vx * deltaTime);
        position->y += (velocity->vy * deltaTime);
    }
}