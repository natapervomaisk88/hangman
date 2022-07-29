#include <iostream>
#include "Word.h"
#include "Game.h"
using namespace std;

Game::Game(Word* word, int maxAttempts)
{
	this->maxAttempts = maxAttempts;
	this->countAttempts = this->maxAttempts;
	this->word = word;
}

Game::~Game()
{
	if (this->word != nullptr)
		delete this->word;
}

char Game::defaultChar = '_';

void Game::fillRealField(char letter)
{
	if (letter != defaultChar)
	{
		defaultChar = letter;
	}
	for (auto word : this->word->getWord())
	{
		realSituation.push_back(letter);
	}
}

bool Game::isWon(char ch)
{
	for (auto l : this->realSituation)
	{
		if (l == ch)
		{
			return false;
		}
	}
	return true;
}

void Game::showCurrentField()
{
	for (auto letter : realSituation)
	{
		cout << letter << " ";
	}
	cout << "\n\n\n";
}

void Game::fillLetter(char letter) //заполнение буквы
{
	vector<int> index;
	bool success = false;
	if (isLetter(letter))
	{
		for (size_t i = 0; i < this->word->getWord().length(); i++)
		{
			if (letter == this->word->getWord()[i])
			{
				this->realSituation.at(i) = letter;
				success = true;
			}
		}
	}
	if (!success)
	{
		this->countAttempts--;
	}
}

void Game::inputLetter()
{
	cout << "Enter letter: ";
	char ch;
	cin >> ch;
	this->fillLetter(ch);
}

bool Game::isRepeatErrorLetter(char ch)
{
	for (auto letter : this->errorLetter)
	{
		if (letter == ch)
		{
			return true;
		}
	}
	return false;
}

bool Game::isLetter(char ch)
{
	for (auto letter : this->word->getWord())
	{
		if (letter == ch)
		{
			this->messageSuccess();
			return true;
		}
	}
	if (!isRepeatErrorLetter(ch))
	{
		this->errorLetter.push_back(ch);
	}
	this->messageError();
	this->printLetterError();
	return false;
}

void Game::startGame()
{
	cout << "Game started...\n";
	cout << "your word has " << this->word->getWord().length() << " letters\n";
	this->fillRealField();
	this->showCurrentField();
	do
	{
		cout << "Guess the word... \n";
		this->inputLetter();
		this->showCurrentField();
		if (this->isWon())
		{
			this->messageWon();
			break;
		}
	} while (countAttempts != 0);
	if (!this->isWon())
	{
		this->messageLose();
	}
	cout << "Word: " << this->word->getWord() << endl;
	cout << "Attempts: " << this->maxAttempts - this->getCountAttempts() << endl;
}

int Game::getCountAttempts()
{
	return countAttempts;
}
void Game::messageAttempts()
{
	cout << this->getCountAttempts() << " attempts left\n";
}
void Game::messageError()
{
	cout << "Invalid letter\n";
	this->messageAttempts();
}
void Game::messageSuccess()
{
	cout << "You guessed right\n";
}

void Game::messageWon()
{
	cout << "Congratulations, you won!\n";
}

void Game::messageLose()
{
	cout << "You lose(:\n";
}

void Game::printLetterError()
{
	cout << "Letter error: ";
	for (auto l : this->errorLetter)
	{
		cout << l << " ";
	}
	cout << endl;
}