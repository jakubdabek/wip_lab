//newagent.c
//Jakub Dąbek

#include "agents.h"

struct agent newagent(int x, int y)
{
	struct agent agent = { x, y };
	return agent;
}
