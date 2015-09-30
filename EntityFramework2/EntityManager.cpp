#include "EntityManager.h"

typedef EntityManager::EID EID;

EntityManager::EntityManager()
{}


EntityManager::~EntityManager()
{}



EID EntityManager::CreateEntity()
{
	entity e;
	e.id = GetValidID();

	m_entities.push_back(e);

	return e.id;
}

EID EntityManager::CreateEntity(vector<Module *> _modules)
{
	entity e;
	e.id = GetValidID();
	e.modules = _modules;

	m_entities.push_back(e);

	return e.id;
}


Module * EntityManager::GetModule(EID _entity, MType _type)
{
	bool found = false;
	Module * module = nullptr;

	for (UINT m = 0; m < m_entities.size() && !found; ++m)
	{
		if (m_entities[_entity].modules[m]->type == _type)
		{
			found = true;
			module = m_entities[_entity].modules[m];
		}
	}

	return module;
}

EID EntityManager::GetValidID()
{
	EID eid = 0;
	for (EID i = 0; i < m_entities.size(); ++i)
	{
		if (m_entities[i].id == eid)
			++eid;
	}

	return eid;
}