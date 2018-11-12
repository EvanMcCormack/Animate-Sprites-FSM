#ifndef SHOVELING_H
#define SHOVELING_H

#include <State.h>

class Shoveling : public State
{
public:
	Shoveling() {};
	~Shoveling() {};
	void idle(PlayerFSM* a);
	void shoveling(PlayerFSM* a);
};

#endif // !SHOVELING_H
