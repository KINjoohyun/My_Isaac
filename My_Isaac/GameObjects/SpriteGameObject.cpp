#include "stdafx.h"
#include "SpriteGameObject.h"
#include "ResourceMgr.h"

void SpriteGameObject::Reset()
{
	if (RESOURCE_MGR.GetTexture(textureId) != nullptr)
	{
		sprite.setTexture(*RESOURCE_MGR.GetTexture(textureId));
	}

	col.setSize({ sprite.getLocalBounds().width, sprite.getLocalBounds().height });
	col.setOutlineThickness(1);
	col.setFillColor(sf::Color::Transparent);
	col.setOutlineColor(sf::Color::Transparent);

	SetOrigin(origin);
}
void SpriteGameObject::Update(float dt)
{
	if (OnDebug != nullptr) OnDebug();
}
void SpriteGameObject::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(col);
}

void SpriteGameObject::SetPosition(const sf::Vector2f& position)
{
	GameObject::SetPosition(position);
	sprite.setPosition(position);
	col.setPosition(position);
}
void SpriteGameObject::SetPosition(float x, float y)
{
	GameObject::SetPosition(x, y);
	sprite.setPosition(this->position);
	col.setPosition(this->position);
}

void SpriteGameObject::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);

	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(sprite, origin);
		Utils::SetOrigin(col, origin);
	}
}
void SpriteGameObject::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	sprite.setOrigin(x, y);
	col.setOrigin(x, y);
}

void SpriteGameObject::SetFlipX(sf::Sprite& sprite, bool flip)
{
	flipX = flip;

	sf::Vector2f scale = sprite.getScale();
	scale.x = !flipX ? abs(scale.x) : -abs(scale.x);
	sprite.setScale(scale);
}