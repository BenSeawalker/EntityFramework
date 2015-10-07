#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "EntityManager.h"

typedef EntityManager::EID EID;

int main()
{
	EntityManager EM;

	EID eid = EM.CreateEntity({ new Position(10, 2), new Sprite('$') });

	Position * pos = EM.GetComponent<Position>(eid, POSITION);
	Sprite * spr = EM.GetComponent<Sprite>(eid, SPRITE);
	cout << eid << " " << pos->type << " " << pos->x << " " << pos->y << endl
		<< spr->type << " " << spr->image << endl;


	EM.DestroyComponent(eid, POSITION);
	cout << EM.GetComponent<Position>(eid, POSITION) << endl;
	

	EID e1 = EM.CreateEntity();
	EID e2 = EM.CreateEntity();
	EID e3 = EM.CreateEntity();

	EM.DestroyEntity(e2);
	e2 = EM.CreateEntity();

	EM.DestroyEntity(eid);
	EID e4 = EM.CreateEntity();

	EM.DestroyComponent(eid, POSITION);

	EM.DestroyEntity(eid);
	EM.GetComponent<Position>(eid, POSITION);

	cout << eid << " " << e1 << " " << e2 << " " << e3 << " " << e4 << endl;

	return 0;
}