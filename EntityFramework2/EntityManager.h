#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
using std::vector;


#include "Modules.h"
typedef unsigned int UINT;


class EntityManager
{
public:
	typedef UINT EID;

	struct entity
	{
		EID id;
		vector<Module *> modules;
	};


public:
	EntityManager();
	~EntityManager();

	EID CreateEntity();
	EID CreateEntity(vector<Module *> _modules);

	Module * GetModule(EID _entity, MType _type);


private:
	vector<entity> m_entities;

	EID GetValidID();
};

#endif //#ifndef ENTITYMANAGER_H