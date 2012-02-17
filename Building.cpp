#include <cstring>
#include "Building.h"
#include "Utils.h"

Building::Building(char *title, int month, int year, int buildType, int x, int y, int wall, int upgrade)
{
	name = new char[strlen(title) + 1];
	strcpy(name, title);
	monthBuilt = month;
	yearBuilt = year;
	type = buildType;
	wallType = wall;

	xLoc = x;
	yLoc = y;
	upgradeLevel = upgrade;
}

void Building::rename(const char *title)
{
	delete[] name;
	name = new char[strlen(title) + 1];
	strcpy(name, title);
}

bool Building::upgrade()
{
	if(upgradeLevel < UPGRADE_MAX )
	{
		upgradeLevel++;
		return true;
	}
	return false;	

}

int Building::getX()
{
	return xLoc;
}

int Building::getY()
{
	return yLoc;
}

char* Building::getName()
{
	return name;
}

char* Building::getMonth()
{
	return months[monthBuilt];
}

int Building::getMonthInt()
{
	return monthBuilt;
}

int Building::getTypeInt()
{
	return type;
}

int Building::getYear()
{
	return yearBuilt;
}

char* Building::getTypeShort()
{
	return typesTitlesShort[type];
}

char* Building::getTypeLong()
{
	return typesTitlesLong[type];
}

int Building::getUpgradeLevel()
{
	return upgradeLevel;
}

int Building::getUpgradePrice()
{
	return (int)(UPGRADE_PERCENT * typesPrices[type]);
}

bool Building::contains(int x, int y)
{
	if( (xLoc <= x && xLoc + BUILDING_SIZE - 1 >= x) &&
		(yLoc <= y && yLoc + BUILDING_SIZE - 1 >= y) )
	{
		return true;
	}

	return false;
}

int Building::getWallType()
{
	return wallType;
}



Building::~Building()
{
	delete[] name;
}