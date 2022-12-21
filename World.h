#ifndef WORLD_H
#define WORLD_H

#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <memory>

#include "Component.h"
#include "Entity.h"

class System;

/* Aliases */
template <typename Key, typename Value>
using HashMap = std::unordered_map<Key, Value>;

template <typename Value> 
using TypeMap = HashMap<std::type_index, Value>;

/*  Storage for the entities, the components and the systems, with all the
    related operations to their management */
class World 
{
public:
    template <typename T>
    void 
    addComponent(EntityID id, T* component)
    {
        m_components[id][typeid(T)] = component;
    }

    template <typename T>
    T*
    getComponent(EntityID id)
    {
        static_assert(std::is_base_of<Component, T>::value, 
            "T must derive from Component");
        return static_cast<T*>(m_components[id][typeid(T)]);
    }
    
    template <typename T>
    void 
    removeComponent(EntityID id, T* component)
    {
        m_components[id][typeid(T)] = component;
    }

    template <typename T>
    bool
    hasComponent(EntityID id) const
    {
        auto storage = m_components.at(id);
        return storage.find(typeid(T)) != storage.end();
    }

    template <typename T>
    std::vector<EntityID>
    getEntitiesWithComponent() const
    {
        std::vector<EntityID> entities;
        for (const auto& pair : m_components)
        {
            if (pair.second.find(typeid(T)) != pair.second.end()) {
                entities.push_back(pair.first);
            }
        }

        return entities;
    }

    /* Get all the entities with a specific set of components */
    template <typename... Ts>
    std::vector<EntityID>
    getEntitiesWithComponents() const
    {
        std::vector<EntityID> entities;
        std::unordered_set<EntityID> entitySet;
        for (const auto inner : { getEntitiesWithComponent<Ts>()... }) 
        {
            entitySet.insert(inner.begin(), inner.end());
        }
        entities.assign(entitySet.begin(), entitySet.end());
        return entities;
    }

    template <typename T>
    void 
    addSystem()
    {
        static_assert(std::is_base_of<System, T>::value, 
            "T must derive from System");
        m_systems.push_back(std::make_unique<T>(*this));
    }

    void 
    update(float deltaTime);
private:
    HashMap<EntityID, TypeMap<Component*>> m_components;
    std::vector<std::unique_ptr<System>> m_systems;
};

#endif