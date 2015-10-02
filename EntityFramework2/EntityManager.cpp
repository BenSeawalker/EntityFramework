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

EID EntityManager::CreateEntity(vector<Component *> _components)
{
	entity e;
	e.id = GetValidID();
	e.components = _components;

	m_entities.push_back(e);

	return e.id;
}

void EntityManager::DestroyEntity(EID &_entity)
{
	int index = GetEntityIndex(_entity);

	if (index >= 0)
	{
		m_entities.erase(m_entities.begin() + index);
		_entity = 0;
	}
	
}


Component * EntityManager::GetComponent(EID _entity, CType _type)
{
	bool found = false;
	Component * component = nullptr;
	int index = GetEntityIndex(_entity);

	if (index >= 0)
	{
		for (UINT c = 0; c < m_entities[index].components.size() && !found; ++c)
		{
			if (m_entities[index].components[c]->type == _type)
			{
				found = true;
				component = m_entities[index].components[c];
			}
		}
	}

	return component;
}

EID EntityManager::GetValidID()
{
	EID eid = 1;
	for (EID i = 0; i < m_entities.size(); ++i)
	{
		if (m_entities[i].id == eid)
			++eid;
	}

	return eid;
}

int EntityManager::GetEntityIndex(EID _entity)
{
	bool found = false;
	UINT e;

	for (e = 0; e < m_entities.size() && !found; ++e)
	{
		if (m_entities[e].id == _entity)
			found = true;
	}

	e = ((e > 0) ? (e - 1) : e);

	return (found ? e : -1);
}