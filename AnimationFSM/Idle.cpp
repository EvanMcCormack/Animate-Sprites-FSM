#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Walking.h>
#include <Swording.h>
#include <Shoveling.h>

#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(PlayerFSM* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(PlayerFSM* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}
void Idle::walking(PlayerFSM* a)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setCurrent(new Walking());
	delete this;
}
void Idle::swording(PlayerFSM* a)
{
	std::cout << "Idle -> Swording" << std::endl;
	a->setCurrent(new Swording);
	delete this;
}
void Idle::shoveling(PlayerFSM* a)
{
	std::cout << "Idle -> Shoveling" << std::endl;
	a->setCurrent(new Shoveling());
	delete this;
}