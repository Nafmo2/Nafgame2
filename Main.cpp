
#include "Head.h"
void Main()
{
	const Font font(30);
	double x=100, y=100,dx=0,px=0;
	bool M=false,N=false;
	while (System::Update())
	{
		Circle(x, y,20).draw(Color(0,255,255));
		Circle(100, 140, 20).draw(Color(0, 255, 0));
		Circle(150, 140, 20).draw(Color(0, 255, 0));
		Line(0, 80, 640, 80).draw(1);
		Line(0, 120, 640, 120).draw(1);

		if (Input::KeyRight.clicked) {
			if (!M&&!N) {
				M = true;
				dx = 1,px=x;
			}
		}
		if (Input::KeyLeft.clicked) {
			if (!M && !N) {
				N = true;
				dx = 1, px = x;
			}
		}
		if (M||N) {
			if ((M?x<px+50:x>px-50)) {
				x += (M ? dx : -dx);
			}else {
				M = N = false;
			}
		}
		font(L"x:",x,L" dx:",dx,L" M:",M).draw();
	}
}
