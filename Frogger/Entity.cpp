#include "Entity.h"


Entity::Entity(Texture _texture, int raw, int direction, float speed)
{
	texture = _texture;
	position.y = ((GetScreenHeight() / 15) * raw);
	this->direction = direction;
	this->speed = speed;

	position.y += texture.height * 1.5f;

	boxCollider.width = texture.width;
	boxCollider.height = texture.height;
	boxCollider.x = position.x;
	boxCollider.y = position.y;

}

Entity::~Entity()
{
}

Rectangle Entity::getBoxCollider()
{
    return boxCollider;
}
