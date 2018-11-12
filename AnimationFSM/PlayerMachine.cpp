#include <PlayerFSM.h>
#include <Idle.h>

PlayerFSM::PlayerFSM()
{
	m_current = new Idle();
}

PlayerFSM::~PlayerFSM() {}

void PlayerFSM::setCurrent(State* s)
{
	m_current = s;
}

State* PlayerFSM::getCurrent()
{
	return m_current;
}

void PlayerFSM::setPrevious(State* s)
{
	m_previous = s;
}

State* PlayerFSM::getPrevious()
{
	return m_previous;
}

void PlayerFSM::idle()
{
	m_current->idle(this);
}

void PlayerFSM::jumping()
{
	m_current->jumping(this);
}

void PlayerFSM::climbing()
{
	m_current->climbing(this);
}

void PlayerFSM::walking()
{
	m_current->walking(this);
}

void PlayerFSM::swording()
{
	m_current->swording(this);
}

void PlayerFSM::shoveling()
{
	m_current->shoveling(this);
}

void PlayerFSM::hammering()
{
	m_current->hammering(this);
}