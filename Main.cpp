#include "Head.h"
void Main()
{
	const Font font(25);
	Player P;
	Enemy  E;
	while (System::Update())
	{
		const Point pos = Mouse::Pos();
		P.move();
		E.Attacked(P.Attack(),P.GetPow());
		Circle(P.GetX(), P.GetY(),20).draw(Color(0,255,255));
		Circle(E.GetX(), E.GetY(), 100).draw(Palette::Orange);
		font(L"Enemy?").drawCenter(E.GetX(), E.GetY(), Palette::White);
		Rect(120,80,400,40).drawFrame(1,1,Palette::Orange);
		Rect(120,80,400*E.GetHpR(),40).draw(Palette::Orange);


		for (int i = 1; i <= 16; i++) {
			Line(0, 40*i, 640, 40*i).draw(1);
			Line(40*i, 0, 40*i, 480).draw(1);
		}
		Circle(pos, 5).draw(Palette::Yellow);
		font(pos).draw(0,400);
		font(L"x:",P.GetX(),L" y:",P.GetY(),L" EnemyHp:",int(E.GetHpR()*100),L"%").draw();
	}
}
