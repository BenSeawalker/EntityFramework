#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::pair;

#include "Components.h"

class System;

typedef unsigned int UINT;


class EntityManager
{
public:
	typedef UINT EID;
	typedef vector<Component *> ComponentList;
	typedef vector<System *> SystemList;

	EntityManager();
	~EntityManager();

	EID CreateEntity();
	EID CreateEntity(ComponentList _components);

	void DestroyEntity(EID &_entity);

	void AddComponent(EID _entity, Component * _component);
	void AddComponents(EID _entity, ComponentList _components);

	void DestroyComponent(EID _entity, CType _type);

	vector<EID> GetEntitiesWithComponent(CType _type);
	vector<EID> GetEntitiesWithComponents(vector<CType> _types);


	void AddSystem(System * _system);
	void AddSystems(SystemList _systems);


	template<typename T>
	T * GetComponent(EID _entity, CType _type);

private:
	map<EID, ComponentList> m_entities;
	SystemList m_systems;

	int GetComponentIndex(EID _entity, CType _type);
	EID GetValidID();

	
};

///////////////////////////////////////////////////
// TEMPLATE FUNCTIONS
//////
template<typename T>
T * EntityManager::GetComponent(EID _entity, CType _type)
{
	T * component = nullptr;
	int index = GetComponentIndex(_entity, _type);

	if (index >= 0)
		component = static_cast<T *>(m_entities.find(_entity)->second[index]);

	return component;
}

#endif //#ifndef ENTITYMANAGER_H