#include "Word.h"
Word::Word()
{
	this->choiceWord();
}

string Word::parse(string str)
{
	vector<string> arr;
	string delim(" ");
	size_t prev = 0;
	size_t next;
	size_t delta = delim.length();

	while ((next = str.find(delim, prev)) != string::npos) {
		//Отладка-start
		string tmp = str.substr(prev, next - prev);
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

//возьмём массив слов и закодируем их
void Word::createWords()
{
	this->words = {
		"Hello",
		"World",
		"Read",
		"Green"
	};
}

vector<vector<int>> Word::crypto() //перевод символов в коды, для некоего шифрования
{
	vector<vector<int>> vec;
	int k = 0;
	for (auto w : this->words)
	{
		cout << "Word: " << w << endl;
		vector<int> v;
		for (int i = 0; i < w.length(); i++)
		{
			cout << static_cast<int>(w.at(i)) << " ";
			v.push_back(static_cast<int>(w.at(i)));
		}
		vec.push_back(v);
		cout << endl;
	}
	return vec;
}

bool Word::saveToFile(vector<vector<int>> vec)
{
	ofstream fout;
	fout.open(this->path, ofstream::app);
	if (fout.is_open())
	{
		for (auto v : vec)
		{
			for (auto code : v)
			{
				fout << code << " ";
			}
			fout << "\n";
		}
		fout.close();
		return true;
	}
	return false;
}

void Word::inputWords()
{
	int count;
	cout << "Enter count word:";
	cin >> count;
	cin.ignore();
	while (count)
	{
		string str;
		cout << "Enter word:";
		getline(cin, str);
		this->words.push_back(str);
		count--;
	}
}

void Word::choiceWord()
{
	ifstream fin;
	int countWords = 0;
	fin.open(this->path);
	if (fin.fail())
	{
		cout << "Word file not found\n";
		int choice;
		cout << "Generate word file - 0\nUse words from array - 1\n";
		cin >> choice;
		cout << "Let's start creating a file\n";
		if (choice)
		{
			this->createWords();
		}
		else
		{
			this->inputWords();
		}
		this->saveToFile(this->crypto());
		fin.open(this->path);
	}
	if (fin.is_open())
	{
		string str;
		while (getline(fin, str))
		{
			countWords++;
		}
		//переместить указатель в начало файла
		fin.close();
		fin.open(path);
		//fin.seekg(0, fin.beg);
		int indexWord = 0;
		do
		{
			srand(time(0));
			indexWord = rand() % countWords;
		} while (indexWord == 0);
		bool findWord = false;
		int count = 1;
		vector<int> vec;
		while (getline(fin, str))
		{
			if (count == indexWord)
			{
				break;
			}
			count++;
		}
		this->word = this->parse(str);
		fin.close();
	}
}

void Word::showAllWords()
{
	for (auto w : this->words)
	{
		cout << w << endl;
	}
}
string Word::getWord()
{
	return this->word;
}
