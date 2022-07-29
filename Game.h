#pragma once
#include "Word.h"
#include "Timer.h"
class Game
{
	int maxAttempts; //������������ ����� �������
	vector<char> errorLetter;
	vector<char> realSituation;
	Word* word;
	Timer timer;
	int countAttempts;
	static char defaultChar;
	void fillRealField(char letter = defaultChar); //����� ��� ������������ ������������ ����, ��������� ������ ����� _
	void showCurrentField(); //����� ��� ������ �������� ��������� ����
	bool isLetter(char ch);
	void fillLetter(char letter); //���������� �����
	void inputLetter();
	int getCountAttempts();
	void messageAttempts();
	void messageError();
	void messageSuccess();
	void messageWon();
	void messageLose();
	void printLetterError();
	
public:
	Game(Word* word, int maxAttempts = 6);
	void startGame();
	bool isWon(char ch = defaultChar);
	~Game();
};

