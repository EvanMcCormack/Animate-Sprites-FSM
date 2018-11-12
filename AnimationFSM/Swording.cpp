#include <Swording.h>
#include <Idle.h>
#include <Walking.h>

#include <string>

void Swording::idle(PlayerFSM * a)
{
	std::cout << "Swording -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Swording::walking(PlayerFSM* a)
{
	std::cout << "Swording -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}

void Swording::swording(PlayerFSM* a)
{
	std::cout << "Still Swording" << std::endl;
	a->setCurrent(new Swording());
	delete this;
}