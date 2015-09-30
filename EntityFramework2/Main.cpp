#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "EntityManager.h"

int main()
{
	EntityManager EM;

	EntityManager::EID eid = EM.CreateEntity({ new Position(5, 3) });

	Position * pos = static_cast<Position *>(EM.GetModule(eid, POSITION));
	cout << pos->type << " " << pos->x << " " << pos->y << endl;

	return 0;
}