#pragma once
#ifndef GAME_FINAL_H
#define GAME_FINAL_H

#include "Utils.h"
#include "Building.h"

class smu_UI;
class glWindow;

class Game
{
private:
	smu_UI*		gameUI;
	glWindow*	drawWindow;

	Building*	buildings[BUILDINGS_MAX];
	int			curBuildingCount;

	int			mode;

	char		playerName[NAME_MAX];
	char		moneyString[MONEY_MAX_LENGTH];
	int			playerApproval;
	int			playerMoney;
	int			month;
	int			year;
	int			wallType;

	bool		gameInProgress;

	char		curOpinion[OPINION_MAX];
	int			curOpinionPer;

	void loadBuilding(char *title, int month, int year, int type, int x, int y, int wallType, int upgradeLvl);

public:
	static Game *game;
	static Game* getCurrentGameInstance();

	int verticesZ[SIZE_VERTICES][SIZE_VERTICES];
	float centersZ[SIZE_BOARD][SIZE_BOARD];
	bool squareTaken[SIZE_BOARD][SIZE_BOARD];

	Game(smu_UI *UI);

	void newGame();
	void loadGame(char *fileLoc);
	void saveGame(char *fileLoc);
	void quit();

	char* getName();
	void setName(const char* newName);
	
	int getApproval();
	void setApproval(int approval);

	int getMode();
	void setMode(int newMode);

	char* getMoney();
	void setMoney(int money);

	char* getMonth();
	int getYear();

	int getSeason();

	char* getOpinion();
	void setOpinion(char* newOpinion, int percent);
	void resetOpinion();
	int getOpinionPercent();

	void advanceDate();

	void informUI();
	void loadBuildingInUI(int count);

	int addBuilding(int month, int year, int type, int x, int y);
	void placeBuilding(int x, int y);

	void popup(int message);
	void printAll();

	void removeBuilding(int x, int y);
	void upgradeBuilding(int x, int y);

	bool raiseVertex(int x, int y);
	bool lowerVertex(int x, int y);
	void procCenters();

	bool gameRunning();

	void endGame();

	Building* getNextBuilding();
};

#endif //GAME_FINAL_H