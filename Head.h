#pragma once
#include <list>
#include <Siv3D.hpp>
#include <queue>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstdlib>
__int64 HighScore;
bool Ad = false;
class Player {
private:
	double x, y, px, py;
	double  a, g;
	bool alv;
	double dx, dy, speed,power;
	double movew;
	bool mf[5];
public:

	std::list<std::pair<double, double>> D;
	void Init() {
		x = 100,y = 140;
		speed = 4,power=1;
		dx = dy = 0;
		a = 0.75;
		g = 0.30;
		alv = true;
		mf[0]= mf[1]= mf[2]= mf[3] =false;
		movew = 40;
		D.clear();
	}
	Player() {
		Init();
	}
	bool Alive() {
		return alv;
	}
	bool Attack() {
		return x > 160;
	}
	double GetX() {
		return x;
	}
	double GetY() {
		return y;
	}
	double GetPow() {
		return power;
	}
	void move() {
		if(!mf[0] && !mf[1]){
			if (Input::KeyLeft.pressed) {
					mf[0] = true;
					dx = speed*2, px = x - movew * 2;
			}
			if (Input::KeyRight.pressed) {
					mf[1] = true;
					dx = speed*2, px = x + movew * 2;
			}
		}
		if (!mf[2] && !mf[3]) {
			if (Input::KeyUp.pressed) {
				mf[2] = true;
				dy = speed, py = y - movew;
			}
			if (Input::KeyDown.pressed) {
				mf[3] = true;
				dy = speed, py = y + movew;
			}
		}
		if (mf[0] || mf[1]) {
			if ((mf[1] ? x<px : x>px)) {
				if(px<100||px>180)
					mf[1] = mf[0] = false;
				else
					x += (mf[1] ? dx : -dx);
			}
			else {
				mf[1] = mf[0] = false;
			}
		}
		if (mf[2] || mf[3]) {
			if ((mf[3] ? y<py : y>py)) {
				if (py<140||py>340)
					mf[2] = mf[3] = false;
				else
					y += (mf[3] ? dy : -dy);
			}
			else {
				mf[2] = mf[3] = false;
			}
		}
	}
	void Gor() {
		alv = false;
	}
};
class Enemy {
private:
	double x, y;
	double hp,mhp;
	double dx,speed;
	bool flag;


public:
	double Col;
	void Init() {
		x = 300;
		y = 240;
		dx = 0;
		hp = mhp = 600;
		flag = false;
	}
	Enemy() {
		Init();
	}
	//飛んでいるかどうかのフラグを返す
	bool NF() {
		return flag;
	}
	void set(int a, int b, double c) {
		x = a;
		y = b;
		Col = c;
		flag = true;
	}
	double GetX() {
		return x;
	}
	double GetY() {
		return y;
	}
	double GetHpR() {
		return hp / mhp;
	}
	void Attacked(bool f,double power) {
		if (f)hp -= power;
		if (hp < 0)hp = 0;
	}
	//今回は横にしか飛ばさないのでspeedだけx座標を引く。
	//はみ出たら飛んでいるかどうかのフラグをfalseに
	void Phy() {
		x -= speed;
		if (x < 0)flag = false;

	}


};
//スコアを記録するためにファイル入出力するところ
long long int RW(int x) {
	if (Ad)return HighScore;//Admin機能を使ったら弾く
	std::fstream fs, fe;
	long long int S[10];
	fs.open("ranking.txt", std::ios::in);
	//開けなかった場合 100～60までを書き込んだファイルを作る。
	if (!fs.is_open()) {
		fs.close();
		std::fstream fw; fw.open("ranking.txt", std::ios::out | std::ios::trunc);
		for (int i = 0; i < 5; i++)fw << 100 - i * 10 << std::endl;
		fw.close();
		fs.open("ranking.txt", std::ios::in);
	}

	for (int i = 0; i < 5; i++)fs >> S[i];
	S[5] = x;
	//得点順にソート
	std::sort(S, S + 6);
	fs.close();
	fe.open("ranking.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i<5; i++)fe << S[5 - i] << std::endl;
	fe << std::endl;
	fe.close();
	HighScore = S[5];
	return HighScore;
}