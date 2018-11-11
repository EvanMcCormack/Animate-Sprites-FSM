#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case 0:
		//std::cout << "Player Idling" << std::endl;
		m_state.idle();
		break;
	case 1:
		//std::cout << "Player Up" << std::endl;
		m_state.climbing();
		break;
	case 2:
		//std::cout << "Player Left" << std::endl;
		m_state.jumping();
		break;
	//case 3:
	//	//std::cout << "Player Idling" << std::endl;
	//	m_state.jumping();
	//	break;
	default:
		break;
	}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();
}