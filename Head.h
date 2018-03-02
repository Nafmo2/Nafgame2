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
	double x, y,px;
	double  a, g;
	bool alv;
	double dx;
	bool Lm, Rm;
public:

	std::list<std::pair<double, double>> D;
	void Init() {
		x = 100;
		y = 100;
		dx = 0;
		a = 0.75;
		g = 0.30;
		alv = true;
		Lm = Rm = false;
		D.clear();
	}
	Player() {
		Init();
	}
	bool Alive() {
		return alv;
	}
	double GetX() {
		return x;
	}
	double GetY() {
		return y;
	}
	void move() {
		if (Input::KeyRight.clicked) {
			if (!Rm && !Lm) {
				Rm = true;
				dx = 1, px = x;
			}
		}
		if (Input::KeyLeft.clicked) {
			if (!Rm && !Lm) {
				Lm = true;
				dx = 1, px = x;
			}
		}
		if (Rm || Lm) {
			if ((Rm ? x<px + 50 : x>px - 50)) {
				x += (Rm ? dx : -dx);
			}
			else {
				Rm = Lm = false;
			}
		}
	}
	void Gor() {
		alv = false;
	}
};
class Ball {
private:
	double x, y;
	double g, speed;
	double dx;
	bool flag;


public:
	double Col;
	void Init() {
		x = 100;
		y = 100;
		dx = 0;
		speed = 5;
		flag = false;
	}
	Ball() {
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