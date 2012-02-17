#include "Game.h"
#include "simmu_UI.h"
#include "glWindow.h"
#include "Building.h"
#include "Utils.h"
#include <FL/Fl_Ask.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

Game* Game::game;

Game::Game(smu_UI *UI)
{
	game = this;
	gameUI = UI;
	drawWindow = UI->drawWindow;
	curBuildingCount = 0;
	gameInProgress = false;
	mode = MODE_SELECT;
	srand(time(NULL));
}

int Game::getSeason()
{
	if(month == 12 || month < 3)
		return TYPE_WINTER;

	if(month < 6)
		return TYPE_SPRING;

	if(month < 9)
		return TYPE_SUMMER;

	return TYPE_FALL;
}

int Game::getMode()
{
	return mode;
}

void Game::setMode(int newMode)
{
	mode = newMode;
	if(mode == MODE_PLACE)
		drawWindow->highlightOn(true);
	else
		drawWindow->highlightOn(false);
}

void Game::newGame()
{
	month = INIT_MONTH;
	year = INIT_YEAR;
	strncpy(playerName, fl_input("Please enter your Chancellor's name:", "Richard L. Wallace"), NAME_MAX - 1 );
	playerApproval = INIT_APPROVAL;
	playerMoney	= INIT_MONEY;
	wallType = randInt(TYPE_BUILD1, TYPE_BUILD3);


	

	for(int i = 0; i < BUILDINGS_MAX; i++)
	{
		delete buildings[i];
		buildings[i] = NULL;
	}

	memset(verticesZ, 0, sizeof(int) * SIZE_VERTICES * SIZE_VERTICES);
	memset(centersZ, 0, sizeof(int) * SIZE_BOARD * SIZE_BOARD);
	memset(squareTaken, FALSE, sizeof(bool) * SIZE_BOARD * SIZE_BOARD);

	curBuildingCount = 0;

	gameInProgress = true;
	advanceDate();

}

void Game::loadGame(char* fileLoc)
{
	endGame();

	int length = strlen(fileLoc);
	if(	fileLoc[length - 4] != '.' &&
		fileLoc[length - 3] != 's' &&
		fileLoc[length - 2] != 'm' &&
		fileLoc[length - 1] != 'u')
	{
		strcat(fileLoc, ".smu");
	}

	FILE* loadFile = fopen(fileLoc, "r");
	if(loadFile == NULL)
	{
		popup(POPUP_INVALID_LOAD_FILE);
		return;
	}

	fscanf(loadFile, "%s %i %i %i %i %i",	playerName,
										&playerApproval,
										&playerMoney,
										&month,
										&year,
										&wallType);

	replaceInString(playerName, '_', ' ');

	char buildingName[NAME_MAX];
	int monthBuilt;
	int yearBuilt;
	int type;
	int upgradeLevel;
	int xLoc;
	int yLoc;
	int wallType;

	while(fscanf(loadFile,"%s %i %i %i %i %i %i %i\n",	buildingName,
														&monthBuilt,
														&yearBuilt,
														&type,
														&wallType,
														&upgradeLevel,
														&xLoc,
														&yLoc) != EOF)
	{

		replaceInString(buildingName, '_', ' ');
		loadBuilding(buildingName, monthBuilt, yearBuilt, type, xLoc, yLoc, wallType, upgradeLevel);
	}

	gameInProgress = true;
}

void Game::saveGame(char* fileLoc)
{
	if(!gameInProgress)
	{
		popup(POPUP_NO_GAME);
		return;
	}

	int length = strlen(fileLoc);
	if(	fileLoc[length - 4] != '.' &&
		fileLoc[length - 3] != 's' &&
		fileLoc[length - 2] != 'm' &&
		fileLoc[length - 1] != 'u')
	{
		strcat(fileLoc, ".smu");
	}
	FILE* saveFile = fopen(fileLoc, "r");
	if(saveFile != NULL && !fl_ask("%s\nalready exists. Overwrite?", fileLoc))
	{
		fclose(saveFile);
		return;
	}

	saveFile = fopen(fileLoc, "w");

	replaceInString(playerName, ' ', '_');
	fprintf(saveFile, "%s %i %i %i %i %i\n",	playerName,
												playerApproval,
												playerMoney,
												month,
												year,
												wallType);
	replaceInString(playerName, '_', ' ');

	for(int i = 0; i < BUILDINGS_MAX; i++)
	{
		if(buildings[i] == NULL)
			break;

		replaceInString(buildings[i]->getName(), ' ', '_');
		fprintf(saveFile,"%s %i %i %i %i %i %i %i\n",	buildings[i]->getName(),
														buildings[i]->getMonthInt(),
														buildings[i]->getYear(),
														buildings[i]->getTypeInt(),
														buildings[i]->getWallType(),
														buildings[i]->getUpgradeLevel(),
														buildings[i]->getX(),
														buildings[i]->getY() );

		replaceInString(buildings[i]->getName(), '_', ' ');

	}

	fclose(saveFile);

	fl_message("Game saved to %s", fileLoc);
}

bool Game::gameRunning()
{
	return gameInProgress;
}

void Game::quit()
{
	printf("IMPLEMENT QUIT in Game->quit() \n");
}

Game* Game::getCurrentGameInstance()
{
	if(game == NULL)
		printf("No Game Created Yet!!!!!\n!\n!\n");

	return game;
}

char* Game::getOpinion()
{
	return curOpinion;
}

int Game::getOpinionPercent()
{
	return curOpinionPer;
}

char* Game::getName()
{
	return playerName;
}

void Game::setName(const char *newName)
{
	strcpy(playerName, newName);
}

int Game::getApproval()
{
	return playerApproval;
}

void Game::setApproval(int approval)
{
	playerApproval = approval;
}

char* Game::getMoney()
{
	sprintf(moneyString, "%d", playerMoney);
	return moneyString;
}

void Game::setMoney(int money)
{
	playerMoney = money;
}

char* Game::getMonth()
{
	return months[month];
}

int Game::getYear()
{
	return year;
}

void Game::advanceDate()
{

	resetOpinion();
	int prevMoney = playerMoney;
	int agLocs[BUILDINGS_MAX][2] = {0};
	int agCount = 0;
	int agLevels = 0;
	int artLocs[BUILDINGS_MAX][2] = {0};
	int artCount = 0;
	int artLevels = 0;
	int engrLocs[BUILDINGS_MAX][2] = {0};
	int engrCount = 0;
	int engrLevels = 0;
	int physLocs[BUILDINGS_MAX][2] = {0};
	int physCount = 0;
	int physLevels = 0;
	int lawLocs[BUILDINGS_MAX][2] = {0};
	int lawCount = 0;
	int lawLevels = 0;
	int librLocs[BUILDINGS_MAX][2] = {0};
	int librCount = 0;
	int librLevels = 0;
	int jourLocs[BUILDINGS_MAX][2] = {0};
	int jourCount = 0;
	int jourLevels = 0;
	int nonAgLocs[BUILDINGS_MAX][2] = {0};
	int nonAgCount = 0;
	int dormLocs[BUILDINGS_MAX][2] = {0};
	int dormCount = 0;
	int dormLevels = 0;

	int i = 0;
	int j = 0;

	for( i = 0; i < BUILDINGS_MAX; i++)
	{
		if(buildings[i] == NULL)
			break;

		switch(buildings[i]->getTypeInt())
		{
		case TYPE_AGRI:
			agLocs[agCount][0] = buildings[i]->getX();
			agLocs[agCount++][1] = buildings[i]->getY();
			agLevels += buildings[i]->getUpgradeLevel() + 1;
			break;
		case TYPE_ART:
			nonAgLocs[nonAgCount][0] = buildings[i]->getX();
			nonAgLocs[nonAgCount++][1] = buildings[i]->getY();
			artLocs[artCount][0] = buildings[i]->getX();
			artLocs[artCount++][1] = buildings[i]->getY();
			artLevels += buildings[i]->getUpgradeLevel() + 1;
			break;
		case TYPE_DORM:
			dormLocs[dormCount][0] = buildings[i]->getX();
			dormLocs[dormCount++][1] = buildings[i]->getY();
			dormLevels += buildings[i]->getUpgradeLevel() + 1;
			break;
		case TYPE_ENGR:
			nonAgLocs[nonAgCount][0] = buildings[i]->getX();
			nonAgLocs[nonAgCount++][1] = buildings[i]->getY();
			engrLocs[engrCount][0] = buildings[i]->getX();
			engrLocs[engrCount++][1] = buildings[i]->getY();
			engrLevels += buildings[i]->getUpgradeLevel() + 1;
			break;
		case TYPE_IATS:
			setOpinion("IATS ruins our campus!!!", 100);
			playerMoney -= 100000;
			break;
		case TYPE_JOUR:
			nonAgLocs[nonAgCount][0] = buildings[i]->getX();
			nonAgLocs[nonAgCount++][1] = buildings[i]->getY();
			jourLocs[jourCount][0] = buildings[i]->getX();
			jourLocs[jourCount++][1] = buildings[i]->getY();
			jourLevels += buildings[i]->getUpgradeLevel() + 1;
			break;
		case TYPE_LAW:
			nonAgLocs[nonAgCount][0] = buildings[i]->getX();
			nonAgLocs[nonAgCount++][1] = buildings[i]->getY();
			lawLocs[lawCount][0] = buildings[i]->getX();
			lawLocs[lawCount++][1] = buildings[i]->getY();
			lawLevels += buildings[i]->getUpgradeLevel() + 1;
			break;
		case TYPE_LIBR:
			nonAgLocs[nonAgCount][0] = buildings[i]->getX();
			nonAgLocs[nonAgCount++][1] = buildings[i]->getY();
			librLocs[librCount][0] = buildings[i]->getX();
			librLocs[librCount++][1] = buildings[i]->getY();
			librLevels += buildings[i]->getUpgradeLevel() + 1;
			break;
		case TYPE_PHYS:
			nonAgLocs[nonAgCount][0] = buildings[i]->getX();
			nonAgLocs[nonAgCount++][1] = buildings[i]->getY();
			physLocs[physCount][0] = buildings[i]->getX();
			physLocs[physCount++][1] = buildings[i]->getY();
			physLevels += buildings[i]->getUpgradeLevel() + 1;
			break;
		}
	}


		

	month++;
	if(month == 13)
	{
		month = 1;
		year++;
	}

	wallType = randInt(TYPE_BUILD1, TYPE_BUILD3);
	
	// GAME BEHAVIOR CODE BEGINS

	playerMoney -= MONEY_BASE_COST * (agCount + nonAgCount);
	playerMoney -= MONEY_DORM_COST * dormLevels;
		;
	for( i = 0; i < agLevels && i < dormLevels; i++)
		playerMoney += MONEY_AGRI_INCOME * agLevels;

	for( i = 0; i < artLevels && i < dormLevels; i++)
		playerMoney += MONEY_ART_INCOME * artLevels;

	for( i = 0; i < engrLevels && i < dormLevels; i++)
		playerMoney += MONEY_ENGR_INCOME * engrLevels;

	for( i = 0; i < jourLevels && i < dormLevels; i++)
		playerMoney += MONEY_JOUR_INCOME * jourLevels;

	for( i = 0; i < lawLevels && i < dormLevels; i++)
		playerMoney += MONEY_LAW_INCOME * lawLevels;

	for( i = 0; i < physLevels && i < dormLevels; i++)
		playerMoney += MONEY_PHYS_INCOME * physLevels;

	if(prevMoney < playerMoney)
		playerApproval += POS_APPROVAL;

	if(agLevels == 0)
		setOpinion("We need an Agriculture Program!!!", 65);
	else
	{
		for(i = 0; i < agCount; i++)
			for( j = 0; j < nonAgCount; j++)
				if(	abs(agLocs[i][0] - nonAgLocs[j][0]) <= DIST_CLOSE ||
					abs(agLocs[i][1] - nonAgLocs[j][1]) <= DIST_CLOSE)
					break;

		if(i != agCount || j != nonAgCount)
			setOpinion("Agriculture is too close to other buildings!", 41);

		if(dormLevels < agLevels)
			setOpinion("There's not enough living space for Aggies", 32);
	}

	if(artLevels == 0)
		setOpinion("We need an Art Program!!!", 73);
	else if(dormLevels < artLevels)
	{
		setOpinion("There's not enough living space for Artists", 32);
	}

	if(engrLevels == 0)
		setOpinion("We need an Engineering Program!!!", 87);
	else
	{
		for(i = 0; i < engrCount; i++)
			for(int j = 0; j < physCount; j++)
				if(	abs(engrLocs[i][0] - physLocs[j][0]) <= DIST_CLOSE ||
					abs(engrLocs[i][1] - physLocs[j][1]) <= DIST_CLOSE)
					break;

		if(i == engrCount || j == physCount)
			setOpinion("Engineering is too far from a Physics program!", 48);

		if(dormLevels < engrLevels)
			setOpinion("There's not enough living space for Engineers", 36);
	}

	if(jourLevels == 0)
		setOpinion("We need a Journalism Program!!!", 84);
	else
	{
		for(i = 0; i < jourCount; i++)
			for(int j = 0; j < librCount; j++)
				if(	abs(jourLocs[i][0] - librLocs[j][0]) <= DIST_CLOSE ||
					abs(jourLocs[i][1] - librLocs[j][1]) <= DIST_CLOSE)
					break;

		if(i == jourCount || j == librCount)
			setOpinion("Journalism is too far from a Library!", 46);

		if(dormLevels < jourLevels)
			setOpinion("There's not enough living space for Journalists", 39);
	}

	if(lawLevels == 0)
		setOpinion("We need a Law Program!!!", 74);
	else if(dormLevels < lawLevels)
		setOpinion("There's not enough living space for Lawyers", 29);

	if(physLevels == 0)
		setOpinion("We need a Physics Program!!!", 77);
	else if(dormLevels < physLevels)
		setOpinion("There's not enough living space for Physicists", 44);

	setOpinion("You're doing a great job!", 1);

	playerApproval -= (int)( curOpinionPer * STUDENT_OPINION_PERCENT);
	if(playerApproval > 100)
		playerApproval = 100;

	// GAME BEHAVIOR CODE ENDS

	gameUI->setGameApproval(playerApproval);
	gameUI->setGameMoney(getMoney());
	gameUI->setGameMonth(months[month]);
	gameUI->setGameYear(year);
	gameUI->setOpinion(getOpinion() );
	gameUI->setOpinionPercent(getOpinionPercent());
}


void Game::setOpinion(char *newOpinion, int percent)
{

	if(curOpinionPer >= percent)
		return;

	strncpy(curOpinion, newOpinion, OPINION_MAX - 1);
	curOpinionPer = percent;

	if(curOpinionPer > 100)
		curOpinionPer = 100;
}

void Game::resetOpinion()
{
	curOpinionPer = 0;
	memset(curOpinion, 0, sizeof(char) * OPINION_MAX);
}


void Game::loadBuilding(char *title, int month, int year, int type, int x, int y, int wallType, int upgradeLvl)
{
	Building *newBuilding = new Building(title, month, year, type, x, y, wallType, upgradeLvl);

	for(int a = -1; a <= BUILDING_SIZE; a++)
		for(int b = -1; b <= BUILDING_SIZE; b++)
			if(x+a >= 0 && y+a >= 0 && x+a < SIZE_BOARD && y+b < SIZE_BOARD)
			{
				if(squareTaken[x+a][y+b])
				{
					popup(POPUP_BUILDING_ALREADY_THERE);
					return;
				}
			}

	for(int i = 0; i < BUILDINGS_MAX; i++)
	{
		if(buildings[i] == NULL)
		{
			buildings[i] = newBuilding;
			return;
		}
	}

	popup(POPUP_TOO_MANY_BUILDINGS);

}

int Game::addBuilding(int month, int year, int type, int x, int y)
{
	Building *newBuilding;

	if(type != TYPE_DORM)
		newBuilding = new Building("Untitled Building", month, year, type, x, y, wallType);
	else
		newBuilding = new Building("Untitled Building", month, year, type, x, y, TYPE_DORMWALL);

	if(	verticesZ[x][y] != verticesZ[x+BUILDING_SIZE][y] || 
		verticesZ[x+BUILDING_SIZE][y] != verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] ||
		verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] != verticesZ[x][y+BUILDING_SIZE])
	{
		popup(POPUP_UNLEVEL_FOUNDATION);
		return ADD_FAILURE;
	}


	for(int a = -1; a <= BUILDING_SIZE; a++)
		for(int b = -1; b <= BUILDING_SIZE; b++)
			if(x+a >= 0 && y+a >= 0 && x+a < SIZE_BOARD && y+b < SIZE_BOARD)
			{
				if(squareTaken[x+a][y+b])
				{
					popup(POPUP_BUILDING_ALREADY_THERE);
					return ADD_FAILURE;
				}
			}

	for(int i = 0; i < BUILDINGS_MAX; i++)
	{
		if( buildings[i] == NULL)
		{
			buildings[i] = newBuilding;

			for(int j = 0; j < BUILDING_SIZE; j++)
				for(int k = 0; k < BUILDING_SIZE; k++)
					squareTaken[x+j][y+k] = true;
			
			return i;
		}
	}

	popup(POPUP_TOO_MANY_BUILDINGS);
	return ADD_FAILURE;

}

void Game::placeBuilding(int x, int y)
{
	int type = gameUI->T_BuildChoice->value();
	int pos = ADD_FAILURE;

	if(type == TYPE_NONE)
		return;
	
	if(playerMoney >= typesPrices[type] )
	{
		if( (pos = addBuilding(month, year, type, x, y)) != ADD_FAILURE )
		{
			playerMoney -= typesPrices[type];

			gameUI->setGameMoney(getMoney());
			gameUI->loadBuilding(buildings[pos]);
		}
	}
	else
		popup(POPUP_CANNOT_AFFORD);

}

void Game::upgradeBuilding(int x, int y)
{
	int upgradePos = -1;

	for(int i = 0; i < BUILDINGS_MAX; i++)
	{
		if(buildings[i] != NULL && buildings[i]->contains(x,y) )
		{
			upgradePos = i;
			break;
		}
		else if( buildings[i] == NULL)
			break;
	}

	if(upgradePos == -1)
	{
		printf("Invalid upgrade coords: (%i, %i)\n", x, y);
		return;
	}

	if(playerMoney >= buildings[upgradePos]->getUpgradePrice())
	{
		if(buildings[upgradePos]->upgrade() )
		{
			playerMoney -= buildings[upgradePos]->getUpgradePrice();
			gameUI->setGameMoney(getMoney());
			gameUI->loadBuilding(buildings[upgradePos]);
		}
		else
			popup(POPUP_UPGRADES_MAXED_OUT);
	}
	else
		popup(POPUP_CANNOT_AFFORD);
}
		
		


void Game::removeBuilding(int x, int y)
{
	int removedPos = -1;

	for(int i = 0; i < BUILDINGS_MAX; i++)
	{
		if(buildings[i] != NULL && buildings[i]->contains(x,y) )
		{
			removedPos = i;

			for(int a = 0; a < BUILDING_SIZE; a++)
				for(int b = 0; b < BUILDING_SIZE; b++)
					squareTaken[x+a][y+b] = false;

			delete buildings[i];
			buildings[i] = NULL;

			gameUI->loadBuilding(NULL);
		}
		else if( buildings[i] == NULL)
			break;
	}

	if(removedPos == -1)
	{
		printf("Invalid removal coords: (%i, %i)\n", x, y);
		return;
	}

	for(int j = removedPos + 1; j < BUILDINGS_MAX; j++)
	{
		buildings[j - 1] = buildings[j];

		if(buildings[j] == NULL)
			break;
	}
}


void Game::popup(int message)
{
	switch(message)
	{
	case POPUP_TOO_MANY_BUILDINGS:
		fl_message("The building limit of %i buildings has been reached", BUILDINGS_MAX);
		break;
	case POPUP_BUILDING_ALREADY_THERE:
		fl_message("The location you chose is too close to another building");
		break;
	case POPUP_NO_GAME:
		fl_message("Please start a game before saving");
		break;
	case POPUP_INVALID_LOAD_FILE:
		fl_message("That file is invalid. Please select another");
		break;
	case POPUP_IMAGE_LOAD_ERROR:
		fl_message("There has been an image file loading error.\nPlease ensure that all image files exist in their proper locations");
		break;
	case POPUP_UPGRADES_MAXED_OUT:
		fl_message("This building has reached the maximum level of upgrades, Level %i", UPGRADE_MAX);
		break;
	case POPUP_CANNOT_AFFORD:
		fl_message("You cannot afford that");
		break;
	case POPUP_UNLEVEL_FOUNDATION:
		fl_message("Buildings must be placed on level terrain");
		break;
	default:
		fl_message("I don't know how to handle this message: %i", message);
		break;

	}
}

void Game::printAll()
{
	printf("All Building Info:\n\n");
	for( int i = 0; i < BUILDINGS_MAX; i++)
	{
		if( buildings[i] != NULL)
		{
			printf("Info for %s building %s:\n", buildings[i]->getTypeLong(), buildings[i]->getName() );
			printf("Built in %s, %i at (%i, %i)\n", buildings[i]->getMonth(), buildings[i]->getYear(), buildings[i]->getX(), buildings[i]->getY() );

		}
		else
			break;
	}
}

void Game::informUI()
{
	gameUI->G_NameInput->value( playerName );
	gameUI->G_ApprovalOutput->value( playerApproval );
	gameUI->G_MoneyOutput->value( getMoney() );
	gameUI->G_MonthOutput->value( getMonth() );
	gameUI->G_YearOutput->value( year );
	gameUI->O_OpinionOutput->value( getOpinion() );
	gameUI->O_PercentOutput->value( getOpinionPercent() );
}

void Game::loadBuildingInUI(int count)
{
	if(count < 0 || count > BUILDINGS_MAX || buildings[count] == NULL)
	{
		printf("Invalid building pos %i for loadBuildingInUI()\n", count);
		return;
	}

	gameUI->loadBuilding(buildings[count]);

}

Building* Game::getNextBuilding()
{
	
	if( buildings[curBuildingCount] == NULL || curBuildingCount >= BUILDINGS_MAX)
	{
		curBuildingCount = 0;
		return NULL;
	}
	
	return buildings[curBuildingCount++];
	
}

void Game::endGame()
{

	for(int i = 0; i < BUILDINGS_MAX; i++)
	{
		delete buildings[i];
		buildings[i] = NULL;
	}

	memset(verticesZ, 0, sizeof(int) * SIZE_VERTICES * SIZE_VERTICES);
	memset(centersZ, 0, sizeof(int) * SIZE_BOARD * SIZE_BOARD);
	memset(squareTaken, FALSE, sizeof(bool) * SIZE_BOARD * SIZE_BOARD);

	curBuildingCount = 0;

	gameInProgress = false;
}

bool Game::raiseVertex(int x, int y)
{
	bool changedS		= false;
	bool changedE		= false;
	bool changedW		= false;

	if(x < 0 || x >= SIZE_VERTICES || y < 0 || y >= SIZE_VERTICES)
		return true;

	if(verticesZ[x][y] >= GROUND_MAX_ELEVATION)
		return true;

	for(int a = 0; a < BUILDING_SIZE; a++)
		for(int b = 0; b < BUILDING_SIZE; b++)
			if(x-a >= 0 && x-a < SIZE_BOARD && y-b >= 0 && y-b < SIZE_BOARD && squareTaken[x-a][y-b] == true)
				return false;


	verticesZ[x][y]++;
	if(x-1 >= 0 && verticesZ[x][y] - verticesZ[x-1][y] > 1)
	{
		if(!raiseVertex(x-1,y) )
		{	//WEST
			verticesZ[x][y]--;
			return false;
		}
		changedW = true;
	}

	if(y-1 >= 0 && verticesZ[x][y] - verticesZ[x][y-1] > 1)
	{
		if(!raiseVertex(x,y-1) )
		{	//SOUTH
			verticesZ[x][y]--;

			if(changedW)
				lowerVertex(x-1, y);

			return false;
		}
		changedS = true;
	}

	if(x+1 < SIZE_VERTICES && verticesZ[x][y] - verticesZ[x+1][y] > 1)
	{
		if(!raiseVertex(x+1,y) )
		{	//EAST
			verticesZ[x][y]--;

			if(changedW)
				lowerVertex(x-1, y);

			if(changedS)
				lowerVertex(x, y-1);

			return false;
		}
		changedE = true;
	}

	if(y+1 < SIZE_VERTICES && verticesZ[x][y] - verticesZ[x][y+1] > 1)
	{
		if(!raiseVertex(x,y+1) )
		{	//NORTH
			verticesZ[x][y]--;

			if(changedW)
				lowerVertex(x-1, y);

			if(changedS)
				lowerVertex(x, y-1);

			if(changedE)
				lowerVertex(x+1, y);

			return false;
		}
	}
	
	return true;

}

bool Game::lowerVertex(int x, int y)
{
	bool changedS		= false;
	bool changedE		= false;
	bool changedW		= false;

	if(x < 0 || x >= SIZE_VERTICES || y < 0 || y >= SIZE_VERTICES)
		return true;

	if(verticesZ[x][y] <= GROUND_MIN_ELEVATION)
		return true;

	for(int a = 0; a < BUILDING_SIZE; a++)
		for(int b = 0; b < BUILDING_SIZE; b++)
			if(x-a >= 0 && x-a < SIZE_BOARD && y-b >= 0 && y-b < SIZE_BOARD && squareTaken[x-a][y-b] == true)
				return false;


	verticesZ[x][y]--;
	if(x-1 >= 0 && verticesZ[x][y] - verticesZ[x-1][y] < -1)
	{
		if(!lowerVertex(x-1,y) )
		{	//WEST
			verticesZ[x][y]++;
			return false;
		}
		changedW = true;
	}

	if(y-1 >= 0 && verticesZ[x][y] - verticesZ[x][y-1] < -1)
	{
		if(!lowerVertex(x,y-1) )
		{	//SOUTH
			verticesZ[x][y]++;

			if(changedW)
				raiseVertex(x-1, y);

			return false;
		}
		changedS = true;
	}

	if(x+1 < SIZE_VERTICES && verticesZ[x][y] - verticesZ[x+1][y] < -1)
	{
		if(!lowerVertex(x+1,y) )
		{	//EAST
			verticesZ[x][y]++;

			if(changedW)
				raiseVertex(x-1, y);

			if(changedS)
				raiseVertex(x, y-1);

			return false;
		}
		changedE = true;
	}

	if(y+1 < SIZE_VERTICES && verticesZ[x][y] - verticesZ[x][y+1] < -1)
	{
		if(!lowerVertex(x,y+1) )
		{	//NORTH
			verticesZ[x][y]++;

			if(changedW)
				raiseVertex(x-1, y);

			if(changedS)
				raiseVertex(x, y-1);

			if(changedE)
				raiseVertex(x+1, y);

			return false;
		}
	}
	
	return true;
}

void Game::procCenters()
{
	for(int x = 0; x < SIZE_BOARD; x++)
		for(int y = 0; y < SIZE_BOARD; y++)
			if(verticesZ[x][y] < verticesZ[x+1][y])
			{
				if(verticesZ[x][y] == verticesZ[x+1][y+1])
					centersZ[x][y] = (float)verticesZ[x][y];
				else
					centersZ[x][y] = (verticesZ[x][y] + verticesZ[x+1][y+1]) / 2.0f;
			}
			else
			{
				if(verticesZ[x+1][y] == verticesZ[x][y+1])
					centersZ[x][y] = (float)verticesZ[x+1][y];
				else
					centersZ[x][y] = (verticesZ[x+1][y] + verticesZ[x][y+1]) / 2.0f;
			}

}