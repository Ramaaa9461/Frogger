#include "Entity.h"

Entity::~Entity()
{
}

Rectangle Entity::getBoxCollider()
{
    return boxCollider;
}
