#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::pair;

#include "Components.h"
typedef unsigned int UINT;


class EntityManager
{
public:
	typedef UINT EID;
	typedef vector<Component *> ComponentList;

	EntityManager();
	~EntityManager();

	EID CreateEntity();
	EID CreateEntity(ComponentList &_components);

	void DestroyEntity(EID &_entity);

	Component * GetComponent(EID _entity, CType _type);
	int GetComponentIndex(EID _entity, CType _type);

	void DestroyComponent(EID _entity, CType _type);

	vector<EID> GetEntitiesWithComponent(CType _type);
	vector<EID> GetEntitiesWithComponents(vector<CType> _types);

private:
	map<EID, ComponentList> m_entities;

	EID GetValidID();

};

#endif //#ifndef ENTITYMANAGER_H