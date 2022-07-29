#include "Word.h"
Word::Word()
{
	this->choiceWord();
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

void Word::choiceWord()
{
	ifstream fin;
	int countWords = 0;
	fin.open(this->path);
	if (fin.is_open())
	{
		string str;
		while (getline(fin, str))
		{
			countWords++;
		}
		if (countWords == 0)
		{
			cout << "Word file not found\n";
			cout << "Let's start creating a file\n";
			this->createWords();
			this->saveToFile(this->crypto());
		}
		while (getline(fin, str))
		{
			countWords++;
		}
		//переместить указатель в начало файла
		fin.close();
		fin.open(path);
		//fin.seekg(0, fin.beg);
		srand(time(0));
		int indexWord = rand() % countWords;
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
