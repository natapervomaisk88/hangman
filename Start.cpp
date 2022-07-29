#include <iostream>
#include "Word.h"
#include "Game.h"
using namespace std;

int main()
{
	Word* word = new Word();
	Game game(word);
	game.startGame();
	return 0;
}
