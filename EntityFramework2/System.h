#ifndef SYSTEM_H
#define SYSTEM_H

class EntityManager;

class System
{
public:
	virtual void Update(EntityManager & _manager) {};
};

#endif
