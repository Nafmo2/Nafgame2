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
	double x, y;
	double  a, g;
	bool alv;
	double dx;
public:

	std::list<std::pair<double, double>> D;
	void Init() {
		x = 100;
		y = 240;
		dx = 0;
		a = 0.75;
		g = 0.30;
		alv = true;
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
	//�����̏d�͂����������ړ��֐�
	//T�͏�����ɍs���L�[�������ꂽ��
	//dx�͑��x g�͏d�� a�͉����x�ł��B
	void Phy(bool T) {
		y += dx;
		dx += g;
		if (T) {
			dx -= a;
		}
	}
	void Gor() {
		alv = false;
	}
	//�O�Ղ̕`��֐�
	void UpK() {
		//�O�ɂ͂ݏo����
		int pot = 0;
		for (auto &s : D) {
			//�͂ݏo�Ă��Ȃ���΍��W�����炵�Ēe��`��B�͂ݏo�Ă�����A�J�E���g�𑝂₷�B
			if (0 < s.first) {
				s.first -= 4;
				Circle(s.first, s.second, 4).draw(Palette::Aqua);
			}
			else pot++;

		}
		//�͂ݏo��������pop����B
		//(��ɓ��ꂽ�v�f����ɉ�ʊO�ɏo��͂��Ȃ̂�)
		for (int i = 0; i < pot; i++)D.pop_front();
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
	//���ł��邩�ǂ����̃t���O��Ԃ�
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
	//����͉��ɂ�����΂��Ȃ��̂�speed����x���W�������B
	//�͂ݏo������ł��邩�ǂ����̃t���O��false��
	void Phy() {
		x -= speed;
		if (x < 0)flag = false;

	}


};
//�X�R�A���L�^���邽�߂Ƀt�@�C�����o�͂���Ƃ���
long long int RW(int x) {
	if (Ad)return HighScore;//Admin�@�\���g������e��
	std::fstream fs, fe;
	long long int S[10];
	fs.open("ranking.txt", std::ios::in);
	//�J���Ȃ������ꍇ 100�`60�܂ł��������񂾃t�@�C�������B
	if (!fs.is_open()) {
		fs.close();
		std::fstream fw; fw.open("ranking.txt", std::ios::out | std::ios::trunc);
		for (int i = 0; i < 5; i++)fw << 100 - i * 10 << std::endl;
		fw.close();
		fs.open("ranking.txt", std::ios::in);
	}

	for (int i = 0; i < 5; i++)fs >> S[i];
	S[5] = x;
	//���_���Ƀ\�[�g
	std::sort(S, S + 6);
	fs.close();
	fe.open("ranking.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i<5; i++)fe << S[5 - i] << std::endl;
	fe << std::endl;
	fe.close();
	HighScore = S[5];
	return HighScore;
}/*
 long long int RW(int x) {
	String Name =L"";
	if (Ad)return HighScore;
	std::fstream fs,fe;
	
	std::pair<String,String> S[10];
	fs.open("ranking.txt", std::ios::in);
	TextReader reader(L"ranking.txt");
	for (int i = 0; i < 5; i++)reader.readLine(S[i].first);
	for (int i = 0; i < 5; i++)reader.readLine(S[i].second);
	S[5].first = Format(x);
	std::sort(S, S + 6);
	fs.close();
	reader.close();
	fe.open("ranking.txt", std::ios::out | std::ios::trunc);
	TextWriter write(L"ranking.txt");
	for (int i = 0; i < 5; i++)write.writeln(S[i].first);
	for (int i = 0; i < 5; i++)write.writeln(S[i].second);
	write.close();
	 HighScore = Parse<int>(S[5].first);
	 return HighScore;
}

 */