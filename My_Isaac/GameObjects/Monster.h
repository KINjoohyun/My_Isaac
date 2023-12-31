#pragma once
#include "RoomObject.h"
#include "AnimationController.h"

class Monster : public RoomObject
{
protected:
	ObjType objtype;
	AnimationController animation;
	int r = 0;
	int c = 0;

	int damage = 0;
	float speed = 0.0f;
	float recognize = 0.0f;
	bool isChase = false;
	sf::Vector2f direction;

	float hitedTimer = 0.0f;
	float hitedDuration = 0.5f;

	float attackTimer = 0.0f;
	float attackDuration = 1.0f;

	sf::Sound monstersound;
	std::string soundPath = "";

public:
	Monster(ObjType objtype, int r, int c, const std::string& textureId = "", const std::string& name = "");
	virtual ~Monster() override { Release(); }

	virtual void Init() override;
	virtual void Reset() override;
	virtual void Update(float dt) override;

	virtual void OnDamage(int damage) override;
	void SetMonster(int damage = 0, float speed = 0.0f, int maxHp = 0, float recognize = 0.0f, bool isChase = true);
	const sf::Vector2f& GetDirection();
	const int& GetDamage();
	void SetSound(const std::string& path);

	std::function<void()>BloodShoot;
};