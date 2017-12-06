//agents.h
//Jakub Dąbek

#pragma once

struct agent
{
	int x, y;
};

struct agent newagent(int, int);
void north(struct agent*);
void south(struct agent*);
void east(struct agent*);
void west(struct agent*);
double distance(struct agent, struct agent);
