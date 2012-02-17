#pragma once
#ifndef GLWINDOW_FINAL_H
#define GLWINDOW_FINAL_H

#include "Game.h"
#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>

/* Tough things we need out of our glWindow context
	(In order of importance)
	1. Texture Loading
	2. Texture Mapping
	3. 3D Picking
	4. 

  */

class glWindow : public Fl_Gl_Window
{
	void draw();

private:
	Game *game;
	GLuint texture[TEX_NUM_TOTAL];

	float cameraX;
	float cameraY;
	float cameraZ;

	float sensitivity;

	int scrollAmount;

	int pickX;
	int pickY;
	int pickMode;
	int pickResult;

	bool highlightingOn;
	int highlightX;
	int highlightY;
	float highlightGreen;

	GLuint selectBuffer[BUFSIZE];

	void squarePick();
	void vertexPick();
	void buildingPick();

	void processPick(int hits);

	float lightAmbient[4];
	float lightDiffuse[4];


public:
	glWindow(int x, int y, int w, int h, const char *l = 0 );

	void init();
	int loadTextures();
	int handle(int event);
	int getPickResult();
	void pick(int mode, int x, int y);
	void adjustHighlight();
	void highlightOn(bool flag);
	void setHighlightAt(int x, int y);


};

#endif //GLWINDOW_FINAL_H