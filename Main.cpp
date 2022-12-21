#include <iostream>

#include "Ecs.h"

int
main(void)
{
    EntityIDGenerator generator;
    World world;
    world.addSystem<MovementSystem>();
    EntityID id1 = generator.generateId();
    EntityID id2 = generator.generateId();

    world.addComponent(id1, new PositionComponent(0.0f, 0.0f));
    world.addComponent(id1, new VelocityComponent(1.0f, 1.0f));
    world.addComponent(id2, new PositionComponent(0.0f, 0.0f));
    world.addComponent(id2, new VelocityComponent(2.0f, 2.0f));

    for (int i = 0; i < 1; i++)
    {
        float deltaTime = 1.0f;
        world.update(deltaTime);
    }

    auto finalPos = world.getComponent<PositionComponent>(id1);
    std::cout << finalPos->x << ", " << finalPos->y << std::endl;
    finalPos = world.getComponent<PositionComponent>(id2);
    std::cout << finalPos->x << ", " << finalPos->y << std::endl;
}