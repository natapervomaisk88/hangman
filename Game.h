#pragma once
#include "Word.h"
#include "Timer.h"
class Game
{
	int maxAttempts; //максимальное число попыток
	vector<char> errorLetter;
	vector<char> realSituation;
	Word* word;
	Timer timer;
	int countAttempts;
	static char defaultChar;
	void fillRealField(char letter = defaultChar); //метод для визуализации изначального поля, заполняет нужное число _
	void showCurrentField(); //метод для показа текущего состояния поля
	bool isLetter(char ch);
	void fillLetter(char letter); //заполнение буквы
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

