#include "Head.h"
void Main()
{
	const Font font(20);
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
		Rect(380,90,200,20).drawFrame(1,1,Palette::Orange);
		Rect(380,90,200*E.GetHpR(),20).draw(Palette::Orange);


		
		Rect(80, 140, 40, 200).drawFrame(0, 5, Palette::White);
		Rect(160,180, 40, 40).drawFrame(0, 3, Palette::White);
		Rect(160,260,40,40).drawFrame(0,3,Palette::White);
		for (int i = 0; i < 4; i++) {
			Line(80,180 + i * 40,120,180 + i * 40).draw(2.5);
			//Line(160,180 + i * 40,200,180 + i * 40).draw(2.5);
		}
		Circle(pos, 5).draw(Palette::Yellow);
		//font(pos).draw(0,400);
		font(L"x:",P.GetX(),L" y:",P.GetY(),L" EnemyHp:",int(E.GetHpR()*100),L"% Pos:",P.GetPos()).draw();
		font(L"Up:",Input::KeyUp.pressed,L" Down:",Input::KeyDown.pressed).draw(0,400);
		font(L"Right:",Input::KeyRight.pressed,L" Left:",Input::KeyLeft.pressed).draw(0,440);
	}
}
