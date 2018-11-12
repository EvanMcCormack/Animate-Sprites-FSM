#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) //: m_animated_sprite(s)
{
	m_state.setCurrent(new Idle());
	m_state.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite[m_currentIndex].getCurrentFrame();
	m_animated_sprite[m_currentIndex].setTextureRect(m_animated_sprite[m_currentIndex].getFrame(frame));
	return m_animated_sprite[m_currentIndex];
}

void Player::setNewTexture(AnimatedSprite a)
{

	m_animated_sprite[index] = a;
	index++;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case 0:
		//std::cout << "Player Idling" << std::endl;
		m_state.idle();
		m_previousIndex = m_currentIndex;
		m_currentIndex = 0;
		break;
	case 1:
		//std::cout << "Player Up" << std::endl;
		m_state.climbing();
		if (m_currentIndex != 4 & m_currentIndex != 5 & m_currentIndex != 6)
		{
			m_previousIndex = m_currentIndex;
			m_currentIndex = 1;
		}
		break;
	case 2:
		//std::cout << "Player Left" << std::endl;
		m_state.jumping();
		if (m_currentIndex != 4 & m_currentIndex != 5 & m_currentIndex != 6)
		{
			m_previousIndex = m_currentIndex;
			m_currentIndex = 2;
		}
		break;
	case 3:
		//std::cout << "Player Idling" << std::endl;
		m_state.walking();
		if (m_currentIndex != 1 & m_currentIndex != 2 & m_currentIndex != 5 & m_currentIndex != 6)
		{
			m_previousIndex = m_currentIndex;
			m_currentIndex = 3;
		}
		break;
	case 4: 
		m_state.swording();
		if (m_currentIndex != 1 & m_currentIndex != 5 & m_currentIndex != 6)
		{
			m_previousIndex = m_currentIndex;
			m_currentIndex = 4;
		}
		break;
	case 5:
		m_state.shoveling();
		if (m_currentIndex != 1 & m_currentIndex != 2 & m_currentIndex != 3 & m_currentIndex != 4 & m_currentIndex != 6)
		{
			m_previousIndex = m_currentIndex;
			m_currentIndex = 5;
		}
		break;
	case 6:
		m_state.hammering();
		if (m_currentIndex != 1 & m_currentIndex != 2 & m_currentIndex != 3 & m_currentIndex != 4 & m_currentIndex != 5)
		{
			m_previousIndex = m_currentIndex;
			m_currentIndex = 6;
		}
	default:
		break;
	}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite[m_currentIndex].update();
}