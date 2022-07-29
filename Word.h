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
	string parse(string str)
	{
		vector<string> arr;
		string delim(" ");
		size_t prev = 0;
		size_t next;
		size_t delta = delim.length();

		while ((next = str.find(delim, prev)) != string::npos) {
			//Отладка-start
			string tmp = str.substr(prev, next - prev);
			cout << tmp << endl;
			//Отладка-end
			arr.push_back(str.substr(prev, next - prev));
			prev = next + delta;
		}
		string word;
		for (auto l : arr)
		{
			word.push_back(static_cast<char>(stoi(l)));
		}
		return word;
	}
public:
	Word();
	
	//возьмём массив слов и закодируем их
	void createWords();

	//запросим слова для сохранения в файл
	void inputWords()
	{

	}
	vector<vector<int>> crypto(); //перевод символов в коды, для некоего шифрования
	bool saveToFile(vector<vector<int>> vec);
	void choiceWord();
	void showAllWords();
	string getWord();
};

