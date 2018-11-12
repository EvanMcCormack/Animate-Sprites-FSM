#ifndef PLAYER_H
#define PLAYER_H

#include <Input.h>
#include <PlayerFSM.h>
#include <AnimatedSprite.h>

class Player
{
private:
	PlayerFSM m_state;
	AnimatedSprite m_animated_sprite[7];
	Player();
	int index = 0;
	int m_currentIndex = 0;
	int m_previousIndex = 0;

public:
	Player(const AnimatedSprite&);
	~Player();
	AnimatedSprite& getAnimatedSprite();
	void setNewTexture(AnimatedSprite a);
	void handleInput(Input);
	void update();
};

#endif // !PLAYER_H
