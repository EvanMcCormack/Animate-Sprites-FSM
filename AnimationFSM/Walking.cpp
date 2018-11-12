#include "Walking.h"
#include <Jumping.h>
#include <Idle.h>

#include <string>

void Walking::idle(PlayerFSM * a)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Walking::jumping(PlayerFSM * a)
{
	std::cout << "Walking -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
