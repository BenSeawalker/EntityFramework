#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
using std::vector;


#include "Components.h"
typedef unsigned int UINT;


class EntityManager
{
public:
	typedef UINT EID;

	EntityManager();
	~EntityManager();

	EID CreateEntity();
	EID CreateEntity(vector<Component *> _components);

	void DestroyEntity(EID &_entity);

	Component * GetComponent(EID _entity, CType _type);


private:
	struct entity
	{
		EID id;
		vector<Component *> components;
	};

	vector<entity> m_entities;

	EID GetValidID();
	int GetEntityIndex(EID _entity);

};

#endif //#ifndef ENTITYMANAGER_H