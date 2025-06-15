#pragma once
#include "Grid.h"
#include "ChildBlocks.cpp"
#include <fstream>

class Game 
{
private:
	bool IsBlockOutside();
	void RoteteBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;


public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockleft();
	void MoveBlockRight();
	void MoveBlockDown();
	Grid grid;
	bool gameOver;
	int score;
	int level;
	int scoreForNextLevel;
	int highScore;
	//
	int GetScore() const { return score; }
	int GetLevel() const { return level; }
	void HardDrop();

    //


};
