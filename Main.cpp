#include "Head.h"
void Main()
{
	const Font font(30);
	Player P;
	while (System::Update())
	{
		Circle(P.GetX(), P.GetY(),20).draw(Color(0,255,255));
		for (int i = 1; i <= 16; i++) {
			Line(0, 40*i, 640, 40*i).draw(1);
			Line(40*i, 0, 40*i, 480).draw(1);
		}

		P.move();
		font(L"x:",P.GetX(),L" y:",P.GetY()).draw();
	}
}
