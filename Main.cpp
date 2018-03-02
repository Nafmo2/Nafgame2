
#include "Head.h"
void Main()
{
	const Font font(30);
	Player P;
	while (System::Update())
	{
		Circle(P.GetX(), P.GetY(),20).draw(Color(0,255,255));
		Circle(100, 140, 20).draw(Color(0, 255, 0));
		Circle(150, 140, 20).draw(Color(0, 255, 0));
		Line(0, 80, 640, 80).draw(1);
		Line(0, 120, 640, 120).draw(1);
		P.move();
		font(L"x:",P.GetX(),L" dx:Disable").draw();
	}
}
