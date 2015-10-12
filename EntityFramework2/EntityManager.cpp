#include "EntityManager.h"

#include "System.h"
#include "Components.h"

#include <time.h>
#include <thread>
using std::thread;


typedef EntityManager::EID EID;

//void UpdateSystems(EntityManager * _this);

EntityManager::EntityManager()
	: m_running(true)
{
	thread system_loop(&EntityManager::UpdateSystems, *this, this);
	system_loop.detach();
}




EntityManager::~EntityManager()
{
	for each (auto iter_entity in m_entities)
	{
		auto components = iter_entity.second;
		for (UINT i = 0; i < components.size(); ++i)
			delete components[i];
	}

	for each (System * system in m_systems)
	{
		delete system;
	}
}



EID EntityManager::CreateEntity()
{
	EID eid = GetValidID();

	m_entities[eid] = {};

	return eid;
}

EID EntityManager::CreateEntity(ComponentList _components)
{
	EID eid = GetValidID();

	m_entities[eid] = _components;

	return eid;
}

void EntityManager::DestroyEntity(EID &_entity)
{
	auto iter_entity = m_entities.find(_entity);

	if (iter_entity != m_entities.end())
	{
		m_entities.erase(m_entities.find(_entity));
		_entity = 0;
	}
	
}



void EntityManager::AddComponent(EID _entity, Component * _component)
{
	auto iter_entity = m_entities.find(_entity);
	if (iter_entity != m_entities.end())
	{
		DestroyComponent(_entity, _component->type); // replace existing component...

		iter_entity->second.push_back(_component);
	}
}


void EntityManager::AddComponents(EID _entity, ComponentList _components)
{
	for each (auto component in _components)
		AddComponent(_entity, component);
}


void EntityManager::DestroyComponent(EID _entity, CType _type)
{
	auto iter_entity = m_entities.find(_entity);
	if (iter_entity != m_entities.end())
	{
		int component_index = GetComponentIndex(_entity, _type);

		if (component_index >= 0)
		{
			auto components = iter_entity->second;
			delete components[component_index];
			components.erase(components.begin() + component_index);
		}
	}
}


int EntityManager::GetComponentIndex(EID _entity, CType _type)
{
	int component_index = -1;
	auto iter_entity = m_entities.find(_entity);
	
	
	if (iter_entity != m_entities.end())
	{
		auto components = iter_entity->second;

		bool found = false;
		for (UINT c = 0; c < components.size() && !found; ++c)
		{
			if (components[c]->type == _type)
			{
				found = true;
				component_index = c;
			}
		}
	}

	return component_index;
}



vector<EID> EntityManager::GetEntitiesWithComponent(CType _type)
{
	vector<EID> entities;

	for each (auto iter_entity in m_entities)
	{
		EID entity = iter_entity.first;
		if (GetComponentIndex(entity, _type) >= 0)
			entities.push_back(entity);
	}

	return entities;
}


vector<EID> EntityManager::GetEntitiesWithComponents(vector<CType> _types)
{
	vector<EID> entities;

	for each (auto iter_entity in m_entities)
	{
		EID entity = iter_entity.first;

		bool has_components = true;
		for (UINT i = 0; i < _types.size() && has_components; ++i)
			has_components = (GetComponentIndex(entity, _types[i]) >= 0);

		if (has_components)
			entities.push_back(entity);
	}

	return entities;
}

void EntityManager::AddSystem(System * _system)
{
	m_systems.push_back(_system);
	//_system->Update(*this);
}

void EntityManager::AddSystems(SystemList _systems)
{
	for each (auto system in _systems)
		AddSystem(system);
}



EID EntityManager::GetValidID()
{
	EID eid = 1;

	while (m_entities.find(eid) != m_entities.end())
		++eid;

	return eid;
}


bool EntityManager::Running()
{
	return m_running;
}

void EntityManager::Running(bool _running)
{
	m_running = _running;
}


void EntityManager::UpdateSystems(EntityManager * _this)
{
	time_t last_time;
	time_t current_time;

	time(&last_time);
	time(&current_time);

	while (_this->m_running)
	{
		time(&current_time);

		if (difftime(current_time, last_time) >= (1.0f / 1.0f))
		{
			time(&last_time);

			for each (auto system in _this->m_systems)
				system->Update(*_this);
		}
	}
}
