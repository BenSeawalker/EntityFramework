#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "EntityManager.h"

typedef EntityManager::EID EID;

int main()
{
	EntityManager EM;

	EID eid = EM.CreateEntity({ new Position(5, 3) });

	Position * pos = static_cast<Position *>(EM.GetComponent(eid, POSITION));
	cout << eid << " " << pos->type << " " << pos->x << " " << pos->y << endl;

	EID e1 = EM.CreateEntity();
	EID e2 = EM.CreateEntity();
	EID e3 = EM.CreateEntity();

	EM.DestroyEntity(e2);
	e2 = EM.CreateEntity();

	EM.DestroyEntity(eid);
	EID e4 = EM.CreateEntity();

	EM.DestroyEntity(eid);
	EM.GetComponent(eid, POSITION);

	cout << eid << " " << e1 << " " << e2 << " " << e3 << " " << e4 << endl;

	return 0;
}