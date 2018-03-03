#include "Head.h"
void Main()
{
	const Font font(30);
	Player P;
	Enemy  E;
	while (System::Update())
	{

		P.move();

		Circle(P.GetX(), P.GetY(),20).draw(Color(0,255,255));
		Circle(E.GetX(), E.GetY(), 100).draw(Palette::Orange);
		font(L"Enemy?").drawCenter(E.GetX(), E.GetY(), Palette::White);
		for (int i = 1; i <= 16; i++) {
			Line(0, 40*i, 640, 40*i).draw(1);
			Line(40*i, 0, 40*i, 480).draw(1);
		}
		font(L"x:",P.GetX(),L" y:",P.GetY()).draw();
	}
}
