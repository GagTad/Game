#include "Game.h"
#include <random>

Game::Game() { 

	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;
	level = 1;
	scoreForNextLevel = 100;
	std::ifstream input("highscore.txt");
	if (input.is_open()) {
		input >> highScore;
		input.close();
	}
	else {
		highScore = 0;
	}
}
Block Game::GetRandomBlock() {
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	//es chgitem incha 
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks() {

	return { IBlock() , JBlock() , OBlock() ,ZBlock() , SBlock() ,LBlock() ,TBlock() ,BombBlock()};
}
void Game::Draw() {
	grid.Draw();
	currentBlock.Draw(11 ,11);
	switch (nextBlock.id)
	{
	case 3:
		nextBlock.Draw(255, 290);
		break;
	case 4:
		nextBlock.Draw(255, 280);
		break;
	case 8:
		nextBlock.Draw(240, 260);
		break;
	default:
		nextBlock.Draw(270, 270);
		break;
	}
	
}
void Game::HandleInput() { 
	
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		Reset();
	}

	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockleft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		
		MoveBlockDown();
		UpdateScore(0, 1);
		break;
	case KEY_SPACE:
		HardDrop();
	case KEY_UP:
		RoteteBlock();
		break;
	}

}
void Game::MoveBlockleft() {
	if (!gameOver) 
	{
		currentBlock.Move(0, -1);
		if (IsBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight() {
	if (!gameOver)
	{
		currentBlock.Move(0, 1);
		if (IsBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown() {
	if (!gameOver)
	{
		currentBlock.Move(1, 0);
		if (IsBlockOutside() || BlockFits() == false)
		{
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

void Game::HardDrop()
{
	
		if (gameOver) return;

		while (true) {
			currentBlock.Move(1, 0);
			if (IsBlockOutside() || !BlockFits()) {
				currentBlock.Move(-1, 0);
				LockBlock(); 
				break;
			}
			score += 1; 
		}
	

}

bool Game::IsBlockOutside() { 

	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item: tiles)
	{
		if (grid.IsCellOutside(item.row, item.column))
		{
			return true;
		}
		
	}
	return false;

}
void Game::RoteteBlock() { 
	if (!gameOver)
	{

		currentBlock.Rotate();
		if (IsBlockOutside() || BlockFits() == false)
		{
			currentBlock.UndoRotation();
		}
	}
	if (score > highScore) {
		highScore = score;
		std::ofstream output("highscore.txt");
		output << highScore;
		output.close();
	}

}
void Game::LockBlock() {
	std::vector<Position> tiles = currentBlock.GetCellPosition();

	if (currentBlock.id == 8) { // Bomb block
		for (Position pos : tiles) {
			for (int r = -1; r <= 1; r++) {
				for (int c = -1; c <= 1; c++) {
					int newRow = pos.row + r;
					int newCol = pos.column + c;
					if (!grid.IsCellOutside(newRow, newCol)) {
						grid.grid[newRow][newCol] = 0; // Clear cell
					}
				}
			}
		}
	}
	else {
		for (Position item : tiles) {
			grid.grid[item.row][item.column] = currentBlock.id;
		}
	}

	currentBlock = nextBlock;
	if (!BlockFits()) {
		gameOver = true;
	}
	nextBlock = GetRandomBlock();

	int rowsCleared = grid.ClearFullRows();
	UpdateScore(rowsCleared, 0);
}

bool Game::BlockFits() {
	
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (grid.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}


	}
	return true;

}

void Game::Reset()
{
	grid.initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
	level = 1;
	scoreForNextLevel = 100;
}

void Game::UpdateScore(int linesCleared , int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;

	}
	score += moveDownPoints;
	
	if (score >= scoreForNextLevel)
	{
		level++;
		scoreForNextLevel += 100; 

	}
	


}
