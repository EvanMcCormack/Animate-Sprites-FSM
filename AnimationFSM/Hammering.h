#ifndef HAMMERING_H
#define HAMMERING_H

#include <State.h>

class Hammering : public State
{
public:
	Hammering() {};
	~Hammering() {};
	void idle(PlayerFSM* a);
	void hammering(PlayerFSM* a);
};

#endif // !HAMMERING_H
