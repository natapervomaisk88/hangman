#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Word
{
	string word;
	const string path = "words.txt";
	vector<string> words;
	string parse(string str);
public:
	Word();
	
	//������ ������ ���� � ���������� ��
	void createWords();

	//�������� ����� ��� ���������� � ����
	void inputWords();
	vector<vector<int>> crypto(); //������� �������� � ����, ��� ������� ����������
	bool saveToFile(vector<vector<int>> vec);
	void choiceWord();
	void showAllWords();
	string getWord();
};

