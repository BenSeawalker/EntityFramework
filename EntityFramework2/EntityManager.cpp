#include "EntityManager.h"

typedef EntityManager::EID EID;

EntityManager::EntityManager()
{}


EntityManager::~EntityManager()
{
	
}



EID EntityManager::CreateEntity()
{
	EID eid;
	eid = GetValidID();

	m_entities.insert(m_entities.begin(), pair<EID, vector<Component *>>(eid, {}));

	return eid;
}

EID EntityManager::CreateEntity(vector<Component *> _components)
{
	EID eid;
	eid = GetValidID();

	m_entities.insert(m_entities.begin(), pair<EID, vector<Component *>>(eid, _components));

	return eid;
}

void EntityManager::DestroyEntity(EID &_entity)
{
	int index = GetEntityIndex(_entity);

	if (index >= 0)
	{
		m_entities.erase(m_entities.find(_entity));
		_entity = 0;
	}
	
}

void EntityManager::DestroyComponent(EID _entity, CType _type)
{
	int entity_index = GetEntityIndex(_entity);
	if (entity_index >= 0)
	{
		int component_index = GetComponentIndex(_entity, _type);

		if (component_index >= 0)
		{
			entity * e = &m_entities[entity_index];
			delete e->components[component_index];
			e->components.erase(e->components.begin() + component_index);
		}
	}
}


Component * EntityManager::GetComponent(EID _entity, CType _type)
{
	bool found = false;
	Component * component = nullptr;
	int index = GetComponentIndex(_entity, _type);

	if (index >= 0)
		component = m_entities[index].components[index];

	return component;
}

int EntityManager::GetComponentIndex(EID _entity, CType _type)
{
	bool found = false;
	int entity_index = GetEntityIndex(_entity);
	int component_index = -1;

	if (entity_index >= 0)
	{
		for (UINT c = 0; c < m_entities[entity_index].components.size() && !found; ++c)
		{
			if (m_entities[entity_index].components[c]->type == _type)
			{
				found = true;
				component_index = c;
			}
		}
	}

	return component_index;
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