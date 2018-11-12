#include <Swording.h>
#include <Idle.h>

#include <string>

void Swording::idle(PlayerFSM * a)
{
	std::cout << "Swording -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}