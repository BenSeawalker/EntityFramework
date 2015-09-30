enum MType { POSITION };

struct Module
{
	MType type;

	Module(MType _type) : type(_type){};
};

struct Position : Module
{
	int x;
	int y;

	Position(int _x, int _y) : Module(POSITION), x(_x), y(_y) {};
};