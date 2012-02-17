
#pragma once
#ifndef BUILDING_FINAL_H
#define BUILDING_FINAL_H
#include "Utils.h"

class Building
{
private:
	char *name;
	int monthBuilt;
	int yearBuilt;
	int type;
	int upgradeLevel;
	int xLoc;
	int yLoc;
	int wallType;

public:

	Building(char *title, int month, int year, int type, int x, int y, int wall, int upgrade = 0);
	void rename(const char *title);
	bool upgrade();

	int getX();
	int getY();

	bool contains(int x, int y);

	char* getName();
	char* getMonth();
	int getMonthInt();
	int getYear();
	char* getTypeShort();
	char* getTypeLong();
	int getTypeInt();
	int getUpgradeLevel();
	int getUpgradePrice();
	int getWallType();

	~Building();
};

#endif //BUILDING_FINAL_H
