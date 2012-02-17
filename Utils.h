#pragma once
#ifndef UTILS_FINAL_H
#define UTILS_FINAL_H
#include <string.h>
#include <GL/glaux.h>
#include <stdio.h>

#define ADD_FAILURE		-1

#define BUFSIZE		512

#define BUILDINGS_MAX	20
#define BUILDING_SIZE  2

#define CAMERA_ZMIN		80.0f
#define CAMERA_ZMAX		180.0f
#define CAMERA_XMIN		0.0f
#define CAMERA_XMAX		400.0f  // SIZE_BOARD * SIZE_SQUARE
#define CAMERA_YMIN		0.0f
#define CAMERA_YMAX		400.0f  // SIZE_BOARD * SIZE_SQUARE

#define COLOR_HIGHLIGHT_R		1.0f
#define COLOR_HIGHLIGHT_G_MIN	0.0f
#define COLOR_HIGHLIGHT_G_MAX	1.0f
#define COLOR_HIGHLIGHT_G_STEP	.04f
#define COLOR_HIGHLIGHT_B		1.0f

#define COLOR_SKY_R		0.38f
#define COLOR_SKY_G		0.69f
#define COLOR_SKY_B		0.87f

#define DIST_CLOSE		5

#define ELEVATION		5.0f

#define GAME_SPEED_MEDIUM	1000

#define GROUND_SCALE			3.0f
#define GROUND_MAX_ELEVATION	5
#define GROUND_MIN_ELEVATION	-5

#define INIT_APPROVAL	75
#define INIT_MONEY		2250000
#define INIT_MONTH		7
#define INIT_YEAR		2005

#define INIT_CAMERA_Z		130.0f
#define INIT_SCROLL_AMOUNT	5
#define INIT_SENSITIVITY	.3f

#define LINE_WIDTH_NORMAL	2.0f
#define LINE_WIDTH_THICK	8.0f

#define MODE_PLACE			0
#define MODE_SELECT			1
#define MODE_GROUND_UP		2
#define MODE_GROUND_DOWN	3

#define MONEY_MAX_LENGTH	10
#define MONEY_MAX_AMOUNT	1000000000

#define MONEY_BASE_COST		5000
#define MONEY_DORM_COST		7500

#define MONEY_AGRI_INCOME	12000
#define MONEY_ART_INCOME	11000
#define MONEY_ENGR_INCOME	16000
#define MONEY_JOUR_INCOME	14500
#define MONEY_LAW_INCOME	13000
#define MONEY_PHYS_INCOME	12200

#define	NAME_MAX	40

#define OPINION_MAX	80

#define PICK_FAILURE	-1

#define PICK_NONE		0
#define PICK_SQUARE		1
#define PICK_BUILDING	2
#define PICK_VERTEX		3

#define POPUP_TOO_MANY_BUILDINGS			0
#define POPUP_BUILDING_ALREADY_THERE		1
#define POPUP_NO_GAME						2
#define POPUP_INVALID_LOAD_FILE				3
#define POPUP_IMAGE_LOAD_ERROR				4
#define POPUP_UPGRADES_MAXED_OUT			5
#define POPUP_CANNOT_AFFORD					6
#define POPUP_UNLEVEL_FOUNDATION			7

#define POS_APPROVAL	15;

#define STUDENT_OPINION_PERCENT		.10

#define SIZE_BOARD		20
#define SIZE_VERTICES	21 // SIZE_BOARD + !
#define SIZE_SQUARE		20.0f

#define TEX_NUM_GROUNDS	4
#define TEX_NUM_TOTAL	21  // TEX_NUM_ROOFS + TEX_NUM_WALLS + TEX_NUM_GROUNDS + 1 (Startup)
#define TEX_NUM_ROOFS	9
#define TEX_NUM_WALLS	7

// Startup Screen = 1
#define TEX_STARTUP_LOC		"images/startgame.bmp"
// Rooftops = 9
#define TEX_AGRI_LOC		"images/agri.bmp"
#define TEX_ART_LOC			"images/art.bmp"
#define TEX_DORM_LOC		"images/dormroof.bmp"
#define TEX_ENGR_LOC		"images/engr.bmp"
#define TEX_IATS_LOC		"images/iats.bmp"
#define TEX_JOUR_LOC		"images/jour.bmp"
#define TEX_LAW_LOC			"images/law.bmp"
#define TEX_LIBR_LOC		"images/libr.bmp"
#define TEX_PHYS_LOC		"images/phys.bmp"
// Walls = 7
#define TEX_BRICK1_LOC		"images/brick1.bmp"
#define TEX_BRICK2_LOC		"images/brick2.bmp"
#define TEX_BRICK3_LOC		"images/brick3.bmp"
#define TEX_BUILD1_LOC		"images/build1.bmp"
#define TEX_BUILD2_LOC		"images/build2.bmp"
#define TEX_BUILD3_LOC		"images/build3.bmp"
#define TEX_DORMWALL_LOC	"images/dormwall.bmp"
// Grounds = 4
#define TEX_WINTER_LOC		"images/winter.bmp"
#define TEX_SPRING_LOC		"images/spring.bmp"
#define TEX_SUMMER_LOC		"images/summer.bmp"
#define TEX_FALL_LOC		"images/fall.bmp"

#define TYPE_NONE		0
#define TYPE_AGRI		1
#define TYPE_ART		2
#define TYPE_DORM		3
#define TYPE_ENGR		4
#define TYPE_IATS		5
#define TYPE_JOUR		6
#define TYPE_LAW		7
#define TYPE_LIBR		8
#define TYPE_PHYS		9

// Used for Texturing compatibility purposes. Invalid building types
#define TYPE_BRICK1		10
#define TYPE_BRICK2		11
#define TYPE_BRICK3		12
#define TYPE_BUILD1		13
#define TYPE_BUILD2		14
#define TYPE_BUILD3		15
#define TYPE_DORMWALL	16
#define TYPE_WINTER		17
#define TYPE_SPRING		18
#define TYPE_SUMMER		19
#define TYPE_FALL		20

#define UPGRADE_PERCENT			.75

#define UPGRADE_MAX				3
#define UPGRADE_ZERO_HEIGHT		30.0f
#define UPGRADE_ONE_HEIGHT		40.0f
#define UPGRADE_TWO_HEIGHT		50.0f
#define UPGRADE_THREE_HEIGHT	60.0f

static char* typesTitlesShort[10] = { "NONE", "AGRI", "ART", "DORM", "ENGR", "IATS", "JOUR", "LAW", "LIBR", "PHYS" };

static char* typesTitlesLong[10] = {	"None", "Agriculture", "Art", "Dormitory", "Engineering",
									"IATS", "Journalism", "Law", "Library",
									"Physics" };

static int typesPrices[10] = { 0, 400000, 210000, 150000, 450000, 370000, 320000, 590000, 500000, 280000 };


static char* months[13] = {	"None", "January", "February", "March",
							"April", "May", "June", "July",
							"August", "September", "October", "November",
							"December" };

static void replaceInString(char* string, char target, char replacedWith)
{
	int length = strlen(string);
	for(int i = 0; i < length; i++)
		if(string[i] == target)
			string[i] = replacedWith;
}

static AUX_RGBImageRec* loadBMP(char *fileLoc)
{
	FILE *file = NULL;
	if(!fileLoc)
		return NULL;

	file = fopen(fileLoc, "r");
	if(file)
	{
		fclose(file);
		return auxDIBImageLoad(fileLoc);
	}
	return NULL;
}

inline static int randInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

#endif //UTILS_FINAL_H