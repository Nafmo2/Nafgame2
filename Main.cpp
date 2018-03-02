
#include "Main.h"
void Main()
{
	const Font font(30);
	double x=100, y=100,dx=0,g=0.01,a=0,px;
	bool M=false;
	while (System::Update())
	{
		Circle(x, y,20).draw(Color(0,255,255));
		Circle(100, 140, 20).draw(Color(0, 255, 255));
		Circle(150, 140, 20).draw(Color(0, 255, 255));
		Line(0, 80, 640, 80).draw(1);
		Line(0, 120, 640, 120).draw(1);

		if (Input::KeyRight.clicked) {
			if (!M) {
				M = true;
				a = 0,g=0.8, dx = 1,px=x;
			}
		}
		if (M) {
			if (x < px+50) {
				x += dx;
			}else {
				M = false;
			}
		}

		if (Input::KeyLeft.clicked)x -= 50;
		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
		font(L"x:",x,L" dx:",dx,L" M:",M).draw();
	}
}
