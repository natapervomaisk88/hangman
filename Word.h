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
	
	//возьмём массив слов и закодируем их
	void createWords();

	//запросим слова для сохранения в файл
	void inputWords();
	vector<vector<int>> crypto(); //перевод символов в коды, для некоего шифрования
	bool saveToFile(vector<vector<int>> vec);
	void choiceWord();
	void showAllWords();
	string getWord();
};

