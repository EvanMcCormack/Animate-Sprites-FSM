#include <Shoveling.h>
#include <Idle.h>

#include <string>

void Shoveling::idle(PlayerFSM * a)
{
	std::cout << "Shoveling -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Shoveling::shoveling(PlayerFSM* a)
{
	std::cout << "Still Shoveling" << std::endl;
	a->setCurrent(new Shoveling());
	delete this;
}
