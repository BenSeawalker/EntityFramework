enum CType { POSITION };

struct Component
{
	CType type;

	Component(CType _type) : type(_type){};
};

struct Position : Component
{
	int x;
	int y;

	Position(int _x, int _y) : Component(POSITION), x(_x), y(_y) {};
};