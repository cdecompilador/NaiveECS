#ifndef ENTITY_H
#define ENTITY_H

#include <functional>

/* Wrapper around int, so later on when the id has more operations we
   don't have to redesign too much */
class EntityID
{
public:
    EntityID(int id)
        : m_id(id)
    {
    }

    operator int() const { return m_id; }

private:
    int m_id;
};

/* Impl hashable for EntityID */
namespace std
{
template <>
struct hash<EntityID>
{
    std::size_t operator()(const EntityID& id) const
    {
        return std::hash<int>()(id);
    }
};
}

/* Generator of new unique ids */
class EntityIDGenerator
{
public:
    EntityIDGenerator()
        : m_nextId(0)
    {
    }

    EntityID generateId() { return m_nextId++; }

private:
    int m_nextId;
};

#endif