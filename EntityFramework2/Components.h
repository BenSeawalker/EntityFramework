enum CType { POSITION, SPRITE };

/////////////////////////////////////////////
// COMPONENT
/////
struct Component
{
	CType type;

	Component(CType _type) : type(_type){};
};

/////////////////////////////////////////////
// POSITION
/////
struct Position : Component
{
	int x;
	int y;

	Position() : Component(POSITION), x(0), y(0) {};
	Position(int _x, int _y) : Component(POSITION), x(_x), y(_y) {};
};


/////////////////////////////////////////////
// SPRITE
/////
struct Sprite : Component
{
	char image;

	Sprite() : Component(SPRITE), image('\0') {};
	Sprite(char _image) : Component(SPRITE), image(_image) {};
};