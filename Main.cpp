#include "Head.h"
void Main()
{
	const Font font(15),Ene(20);
	Player P;
	Enemy  E;
	int count = 0,EA=60;
	while (System::Update())
	{
		const Point pos = Mouse::Pos();
		P.move();
		E.Attacked(P.Attack(),P.GetPow());
		if(count%EA==0){
			if(P.GetPos()>4)P.Attacked(E.GetPow());
			EA = Random(100,120);
			count = 0;
		}
		if(count % EA > EA-40){
			for(int i = 0; i < 5;i++)
				Line(240,160 + i * 40,200,160+i * 40).drawArrow(10,{ 15.0,15.0 },Palette::Yellowgreen);
		}
		Circle(P.GetX(), P.GetY(),20).draw(Color(0,255,255));
		Circle(E.GetX(), E.GetY(), 100).draw(Palette::Orange);
		Ene(L"Enemy?").drawCenter(E.GetX(), E.GetY(), Palette::White);
		Rect(380,90,200,20).drawFrame(1,1,Palette::Orange);
		Rect(380,90,200*E.GetHpR(),20).draw(Palette::Orange);
		Rect(80,90,200,20).drawFrame(1,1,Palette::Cyan);
		Rect(80,90,200 * P.GetHpR(),20).draw(Palette::Cyan);
		Rect(380,120,200,20).drawFrame(1,1,Palette::Orange);
		Rect(380,120,200*(1.0-double(count)/double(EA)),20).draw(Palette::Orange);
		
		Rect(80, 140, 40, 200).drawFrame(0, 5, Palette::White);
		Rect(160, 140, 40, 200).drawFrame(0, 5, Palette::White);
		for (int i = 0; i < 4; i++) {
			Line(80,180 + i * 40,120,180 + i * 40).draw(2.5);
			Line(160,180 + i * 40,200,180 + i * 40).draw(2.5);

		}
		Circle(pos, 5).draw(Palette::Yellow);
		font(pos).draw(0,400);
		font(L"x:",P.GetX(),L" y:",P.GetY(),L" EHp:",int(E.GetHpR()*100),L"% PHp",int(P.GetHpR()*100),L"% Pos:",P.GetPos()).draw();
		font(L"EA:",EA,L" count:",count,L" C/E:",double(count) / double(EA)).draw(0,50);
		count++;
		count %= 60 * 10000000;
	}
}
