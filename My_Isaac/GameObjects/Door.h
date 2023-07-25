#pragma once
#include "SpriteGameObject.h"

class Player;

class Door : public SpriteGameObject
{
public:
	enum class Look
	{
		Up,
		Right,
		Down,
		Left,
	};

protected:
	Look look;
	bool isOpen = true;

	Player* player;
	sf::Vector2f destination;
	sf::Vector2i currRoom;
	sf::Vector2i nextRoom;

	sf::FloatRect wall;
	float wallTop = 0.0f;
	float wallBottom = 0.0f;
	float wallLeft = 0.0f;
	float wallRight = 0.0f;

public:
	Door(const std::string& textureId, Look look, const sf::Vector2i& currRoom);
	virtual ~Door() override { Release(); }

	virtual void Init() override;
	virtual void Reset() override;
	virtual void Update(float dt) override;
	virtual void Release() override { }
	
	void SetPlayer(Player* player);
	void SetDestination(const sf::Vector2f& destination, const sf::Vector2i& nextRoom);
	void SetWall(const sf::FloatRect& wall);
	void Open();
	void Close();

	void Entrance();
};