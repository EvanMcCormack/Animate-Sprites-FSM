#include <Hammering.h>
#include <Idle.h>

#include <string>

void Hammering::idle(PlayerFSM * a)
{
	std::cout << "Hammering -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Hammering::hammering(PlayerFSM* a)
{
	std::cout << "Still Hammering" << std::endl;
	a->setCurrent(new Hammering());
	delete this;
}