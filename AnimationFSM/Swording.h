#ifndef SWORDING_H
#define SWORDING_H

#include <State.h>

class Swording : public State
{
public:
	Swording() {};
	~Swording() {};
	void idle(PlayerFSM* a);
	void walking(PlayerFSM* a);
	void swording(PlayerFSM* a);
};

#endif // !SHOVELING_H
