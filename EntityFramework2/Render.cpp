//#include "Render.h"
//
//
//
//Render::Render()
//{
//}
//
//
//Render::~Render()
//{
//}
//
//void Render::Update(EntityManager & _manager)
//{
//	auto entities = _manager.GetEntitiesWithComponents({ SPRITE, POSITION });
//
//	for each (auto entity in entities)
//	{
//		Position * pos = _manager.GetComponent<Position>(entity, POSITION);
//		Sprite * spr = _manager.GetComponent<Sprite>(entity, POSITION);
//
//		cout << pos->x << " " << pos->y << " " << spr->image << endl;
//	}
//
//	if (entities.size() > 0)
//		cout << endl;
//}