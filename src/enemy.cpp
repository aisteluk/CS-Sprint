#include "actor.h"
#include "enemy.h"
#include <iostream>

Enemy::Enemy() {}

Enemy::Enemy(SDL_Texture* tileset, Graphics &graphics, Vector2 position, Vector2 tilesetPosition, float size )
  : Actor(tileset, graphics, position, tilesetPosition, Vector2(8*size,12*size))
{
  this->_size = size;
}

Enemy::~Enemy() {}

void Enemy::takeDamage()
{
  this->_size -= 0.25;
}


void Enemy::moveUp()
{
  _deltaPosition.y = -12;
}

void Enemy::moveDown()
{
  _deltaPosition.y = 12;
}

void Enemy::moveLeft()
{
  _deltaPosition.x = -8;
}

void Enemy::moveRight()
{
  _deltaPosition.x = 8;
}

void Enemy::stopMovingX()
{
  _deltaPosition.x = 0.0f;
}
void Enemy::stopMovingY()
{

  _deltaPosition.y = 0.0f;
}

void Enemy::pathfinding(Sprite other)
{
  if (this->_position.x < other.getPosition().x) {
    _deltaPosition.x = 8;
  } else {
    _deltaPosition.x = -8;
  }
  if (this->_position.y < other.getPosition().y) {
    _deltaPosition.y = 12;
  } else {
    _deltaPosition.y = -12;
  }
}


void Enemy::update(int elapsedTime)
{
  this->_totalElapsedTime += elapsedTime;
  if (this->_totalElapsedTime > 500)
  {
    _totalElapsedTime -= 500;
    _position.x += this->_deltaPosition.x*2;
    _position.y += this->_deltaPosition.y*2;
  }
}
