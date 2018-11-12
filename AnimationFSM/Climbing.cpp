#include <Climbing.h>
#include <Jumping.h>
#include <Idle.h>

#include <string>

void Climbing::idle(PlayerFSM* a)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Climbing::climbing(PlayerFSM* a)
{
	std::cout << "Still Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}
void Climbing::jumping(PlayerFSM* a)
{
	std::cout << "Climbing -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}