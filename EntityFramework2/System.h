#ifndef SYSTEM_H
#define SYSTEM_H

#include "EntityManager.h"

class System
{
public:
	virtual void Update(EntityManager & _manager) {};
};

#endif
