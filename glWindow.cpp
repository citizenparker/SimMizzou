#include "glWindow.h"
#include "Game.h"
#include "Utils.h"
#include <stdio.h>
#include <Gl/glaux.h>
#include <Gl/gl.h>

void idler(void *arg);

glWindow::glWindow(int x, int y, int w, int h, const char *l ) :
Fl_Gl_Window(x, y, w, h, l)
{
	// FLTK allows nothing in constructor -- see draw()
}

void glWindow::draw()
{
	if(!valid() )
	{

		init();
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_POLYGON_SMOOTH);
		glLineWidth(LINE_WIDTH_NORMAL);
		glShadeModel(GL_SMOOTH);
		glClearColor(COLOR_SKY_R, COLOR_SKY_G, COLOR_SKY_B, 0.5f);
		glDepthFunc(GL_LEQUAL);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		glViewport(0,0,w(),h());

		Fl::add_idle(idler, this);
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0,(GLfloat)w()/(GLfloat)h(),2.0f, 250.0f);
	gluLookAt(	cameraX, cameraY, cameraZ,
				cameraX, cameraY, 0.0,
				0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(COLOR_SKY_R, COLOR_SKY_G, COLOR_SKY_B, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(! game->gameRunning() )
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(cameraX - 50.0f, cameraY - 25.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(cameraX + 50.0f, cameraY - 25.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(cameraX + 50.0f, cameraY + 25.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(cameraX - 50.0f, cameraY + 25.0f);
		glEnd();


		return;
	}

	glBindTexture(GL_TEXTURE_2D, texture[game->getSeason()] );
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES);

	for(int a = 0; a < SIZE_BOARD; a++)
	{
		for(int b = 0; b < SIZE_BOARD; b++)
		{
			glTexCoord2f( GROUND_SCALE * (float)a / (float)SIZE_BOARD, GROUND_SCALE * (float)b / (float)SIZE_BOARD);
			glVertex3f( (float)a * SIZE_SQUARE, (float)b * SIZE_SQUARE, game->verticesZ[a][b] * ELEVATION );
			glTexCoord2f( GROUND_SCALE * (float)a / (float)SIZE_BOARD, GROUND_SCALE * (float)(b+1) / (float)SIZE_BOARD);
			glVertex3f( (float)a * SIZE_SQUARE, (float)(b+1) * SIZE_SQUARE, game->verticesZ[a][b+1] * ELEVATION );
			glTexCoord2f( GROUND_SCALE * (a + 0.5f) / (float)SIZE_BOARD, GROUND_SCALE * (b + 0.5f) / (float)SIZE_BOARD);
			glVertex3f( (a + 0.5f) * SIZE_SQUARE, (b + 0.5f) * SIZE_SQUARE, game->centersZ[a][b] * ELEVATION );

			glTexCoord2f( GROUND_SCALE * (float)a / (float)SIZE_BOARD, GROUND_SCALE * (float)(b+1) / (float)SIZE_BOARD);
			glVertex3f( (float)a * SIZE_SQUARE, (float)(b+1) * SIZE_SQUARE, game->verticesZ[a][b+1] * ELEVATION );
			glTexCoord2f( GROUND_SCALE * (float)(a+1) / (float)SIZE_BOARD, GROUND_SCALE * (float)(b+1) / (float)SIZE_BOARD);
			glVertex3f( (float)(a+1) * SIZE_SQUARE, (float)(b+1) * SIZE_SQUARE, game->verticesZ[a+1][b+1] * ELEVATION );
			glTexCoord2f( GROUND_SCALE * (a + 0.5f) / (float)SIZE_BOARD, GROUND_SCALE * (b + 0.5f) / (float)SIZE_BOARD);
			glVertex3f( (a + 0.5f) * SIZE_SQUARE, (b + 0.5f) * SIZE_SQUARE, game->centersZ[a][b] * ELEVATION );

			glTexCoord2f( GROUND_SCALE * (float)(a+1) / (float)SIZE_BOARD, GROUND_SCALE * (float)(b+1) / (float)SIZE_BOARD);
			glVertex3f( (float)(a+1) * SIZE_SQUARE, (float)(b+1) * SIZE_SQUARE, game->verticesZ[a+1][b+1] * ELEVATION );
			glTexCoord2f( GROUND_SCALE * (float)(a+1) / (float)SIZE_BOARD, GROUND_SCALE * (float)b / (float)SIZE_BOARD);
			glVertex3f( (float)(a+1) * SIZE_SQUARE, (float)b * SIZE_SQUARE, game->verticesZ[a+1][b] * ELEVATION );
			glTexCoord2f( GROUND_SCALE * (a + 0.5f) / (float)SIZE_BOARD, GROUND_SCALE * (b + 0.5f) / (float)SIZE_BOARD);
			glVertex3f( (a + 0.5f) * SIZE_SQUARE, (b + 0.5f) * SIZE_SQUARE, game->centersZ[a][b] * ELEVATION );

			glTexCoord2f( GROUND_SCALE * (float)(a+1) / (float)SIZE_BOARD, GROUND_SCALE * (float)b / (float)SIZE_BOARD);
			glVertex3f( (float)(a+1) * SIZE_SQUARE, (float)b * SIZE_SQUARE, game->verticesZ[a+1][b] * ELEVATION );
			glTexCoord2f( GROUND_SCALE * (float)a / (float)SIZE_BOARD, GROUND_SCALE * (float)b / (float)SIZE_BOARD);
			glVertex3f( (float)a * SIZE_SQUARE, (float)b * SIZE_SQUARE, game->verticesZ[a][b] * ELEVATION );
			glTexCoord2f( GROUND_SCALE * (a + 0.5f) / (float)SIZE_BOARD, GROUND_SCALE * (b + 0.5f) / (float)SIZE_BOARD);
			glVertex3f( (a + 0.5f) * SIZE_SQUARE, (b + 0.5f) * SIZE_SQUARE,  game->centersZ[a][b] * ELEVATION );

		}
	}

	glEnd();

	glBindTexture(GL_TEXTURE_2D, NULL);
	glColor3f(0.0, 0.0, 0.0);
	
	

	glBegin(GL_LINES);

	for(int i = 0; i < SIZE_BOARD; i++)
	{
		for( int j = 0; j < SIZE_BOARD; j++)
		{
			glVertex3f((float)i * SIZE_SQUARE, (float)j * SIZE_SQUARE, game->verticesZ[i][j] * ELEVATION );
			glVertex3f((float)i * SIZE_SQUARE, (float)(j+1) * SIZE_SQUARE, game->verticesZ[i][j+1] * ELEVATION );

			glVertex3f((float)i * SIZE_SQUARE, (float)(j+1) * SIZE_SQUARE, game->verticesZ[i][j+1] * ELEVATION );
			glVertex3f((float)(i+1) * SIZE_SQUARE, (float)(j+1) * SIZE_SQUARE, game->verticesZ[i+1][j+1] * ELEVATION );

			glVertex3f((float)(i+1) * SIZE_SQUARE, (float)(j+1) * SIZE_SQUARE, game->verticesZ[i+1][j+1] * ELEVATION );
			glVertex3f((float)(i+1) * SIZE_SQUARE, (float)j * SIZE_SQUARE, game->verticesZ[i+1][j] * ELEVATION );

			glVertex3f((float)(i+1) * SIZE_SQUARE, (float)j * SIZE_SQUARE, game->verticesZ[i+1][j] * ELEVATION );
			glVertex3f((float)i * SIZE_SQUARE, (float)j * SIZE_SQUARE, game->verticesZ[i][j] * ELEVATION );


		}
	}
	
	glEnd();

	Building *bldg;
	int typeRoof;
	int x;
	int y;
	float texLvl;
	int typeWall;
	float height;

	glColor3f(1.0f, 1.0f, 1.0f);
	while( (bldg = game->getNextBuilding()) != NULL )
	{
		typeRoof = bldg->getTypeInt();
		x = bldg->getX();
		y = bldg->getY();
		typeWall = bldg->getWallType();

		switch(bldg->getUpgradeLevel())
		{
		case 0:
			height = UPGRADE_ZERO_HEIGHT;
			texLvl = 0.5f;
			break;
		case 1:
			height = UPGRADE_ONE_HEIGHT;
			texLvl = .667f;
			break;
		case 2:
			height = UPGRADE_TWO_HEIGHT;
			texLvl = .834f;
			break;
		case 3:
			height = UPGRADE_THREE_HEIGHT;
			texLvl = 1.0f;
			break;
		}

		glBindTexture(GL_TEXTURE_2D, texture[typeWall]);
		glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION);
		glTexCoord2f(1.0f, 0.0f); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION  );
		glTexCoord2f(1.0f, texLvl); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION + height );
		glTexCoord2f(0.0f, texLvl); glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION + height );	

		glTexCoord2f(0.0f, 0.0f); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION  );
		glTexCoord2f(1.0f, texLvl); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION + height );
		glTexCoord2f(0.0f, texLvl); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION + height );

		glTexCoord2f(0.0f, 0.0f); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION  );
		glTexCoord2f(1.0f, texLvl); glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION + height );
		glTexCoord2f(0.0f, texLvl); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION + height );

		glTexCoord2f(0.0f, 0.0f); glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION  );
		glTexCoord2f(1.0f, texLvl); glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION + height );
		glTexCoord2f(0.0f, texLvl); glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION + height );

		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[typeRoof]);
		glBegin(GL_QUADS);

		glNormal3f( 0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION + height );
		glTexCoord2f(1.0f, 0.0f); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION + height );
		glTexCoord2f(1.0f, 1.0f); glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE,game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION + height );
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION + height );

		glEnd();
	}

	if(highlightingOn)
	{
		adjustHighlight();
		glBindTexture(GL_TEXTURE_2D, NULL);
		glColor3f(COLOR_HIGHLIGHT_R, highlightGreen, COLOR_HIGHLIGHT_B);
		
		glLineWidth(LINE_WIDTH_THICK);
		glBegin(GL_LINE_LOOP);

		for(int i = 0; i < BUILDING_SIZE; i++)
			glVertex3f( (highlightX + i) * SIZE_SQUARE, highlightY * SIZE_SQUARE, game->verticesZ[highlightX + i][highlightY] * ELEVATION);

		for(int j = 0; j < BUILDING_SIZE; j++)
			glVertex3f( (highlightX + BUILDING_SIZE) * SIZE_SQUARE,(highlightY +j) * SIZE_SQUARE, game->verticesZ[highlightX + BUILDING_SIZE][highlightY + j] * ELEVATION);
		
		for(int k = BUILDING_SIZE; k > 0; k--)
			glVertex3f( (highlightX + k) * SIZE_SQUARE, (highlightY + BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[highlightX + k][highlightY + BUILDING_SIZE] * ELEVATION);

		for(int m = BUILDING_SIZE; m > 0; m--)
			glVertex3f(highlightX * SIZE_SQUARE, (highlightY + m) * SIZE_SQUARE, game->verticesZ[highlightX][highlightY + m] * ELEVATION);

		glEnd();
		glLineWidth(LINE_WIDTH_NORMAL);
	}


}

void glWindow::init()
{
	game = Game::getCurrentGameInstance();
	
	pickMode = PICK_NONE;
	pickResult = 0;

	cameraX = SIZE_BOARD * SIZE_SQUARE / 2.0f;
	cameraY = cameraX;
	cameraZ = INIT_CAMERA_Z;

	memset(selectBuffer, 0, sizeof(GLuint) * BUFSIZE);

	highlightingOn = false;
	highlightX = 0;
	highlightY = 0;
	highlightGreen = COLOR_HIGHLIGHT_G_MIN;

	scrollAmount = INIT_SCROLL_AMOUNT;

	sensitivity = INIT_SENSITIVITY;

	int count = loadTextures();
	if(count != TEX_NUM_TOTAL )
		game->popup(POPUP_IMAGE_LOAD_ERROR);

	lightAmbient[0] = lightAmbient[1] = lightAmbient[2] = 0.5f;
	lightAmbient[3] = 1.0f;

	lightDiffuse[0] = lightDiffuse[1] = lightDiffuse[2] = lightDiffuse[3] = 1.0f;

}

void glWindow::highlightOn(bool flag)
{
	highlightingOn = flag;
}

void glWindow::setHighlightAt(int x, int y)
{
	highlightX = x;
	highlightY = y;

	if(highlightX + BUILDING_SIZE > SIZE_BOARD)
		highlightX = SIZE_BOARD - BUILDING_SIZE;
	else if(highlightX < 0)
		highlightX = 0;

	if(highlightY + BUILDING_SIZE > SIZE_BOARD)
		highlightY = SIZE_BOARD - BUILDING_SIZE;
	else if(highlightY < 0)
		highlightY = 0;
}


int glWindow::loadTextures()
{
	int numLoaded = 0;

	AUX_RGBImageRec* textureImage = NULL;

	if( textureImage = loadBMP(TEX_STARTUP_LOC) )
	{
		numLoaded++;
		glGenTextures(TEX_NUM_TOTAL, &texture[0]);//Unique
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_AGRI_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_AGRI]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_ART_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_ART]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_DORM_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_DORM]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_ENGR_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_ENGR]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_IATS_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_IATS]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_JOUR_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_JOUR]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_LAW_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_LAW]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_LIBR_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_LIBR]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_PHYS_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_PHYS]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_BRICK1_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_BRICK1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_BRICK2_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_BRICK2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_BRICK3_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_BRICK3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_BUILD1_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_BUILD1]);	
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);

	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_BUILD2_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_BUILD2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_BUILD3_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_BUILD3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_DORMWALL_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_DORMWALL]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_WINTER_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_WINTER]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_SPRING_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_SPRING]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_SUMMER_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_SUMMER]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	if( textureImage = loadBMP(TEX_FALL_LOC) )
	{
		numLoaded++;
		glBindTexture(GL_TEXTURE_2D, texture[TYPE_FALL]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textureImage->sizeX, textureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, textureImage->data);
	}

	if (textureImage)
	{
		if (textureImage->data)
		{
			free(textureImage->data);
		}

		free(textureImage);
	}

	return numLoaded;
}

int glWindow::handle(int event)
{
	static float lastX = 0.0f;
	static float lastY = 0.0f;

	switch(event)
	{
	case FL_PUSH:
		if( Fl::event_button() == 3 && game->gameRunning())
		{
			lastX = (float)Fl::event_x();
			lastY = (float)Fl::event_y();
		}
		else if( Fl::event_button() == 1 && game->gameRunning() && game->getMode() == MODE_SELECT)
		{
			pick(PICK_BUILDING, Fl::event_x(), Fl::event_y() );
			if(pickResult != PICK_FAILURE)
				game->loadBuildingInUI(pickResult);
		}
		else if( Fl::event_button() == 1 && game->gameRunning() && game->getMode() == MODE_PLACE)
		{
			pick(PICK_SQUARE, Fl::event_x(), Fl::event_y());
			if(pickResult != PICK_FAILURE)
			{
				int placeX = pickResult / SIZE_BOARD;
				int placeY = pickResult % SIZE_BOARD;	

				if(placeX + BUILDING_SIZE > SIZE_BOARD)	
					placeX = SIZE_BOARD - BUILDING_SIZE;
				if(placeY + BUILDING_SIZE > SIZE_BOARD)
					placeY = SIZE_BOARD - BUILDING_SIZE;
				game->placeBuilding(placeX, placeY);
			}
		}
		else if( Fl::event_button() == 1 && game->gameRunning() && game->getMode() == MODE_GROUND_UP)
		{
			pick(PICK_VERTEX, Fl::event_x(), Fl::event_y());
			if(pickResult != PICK_FAILURE)
			{
				game->raiseVertex(pickResult / SIZE_VERTICES, pickResult % SIZE_VERTICES);
				game->procCenters();
			}
		}
		else if( Fl::event_button() == 1 && game->gameRunning() && game->getMode() == MODE_GROUND_DOWN)
		{
			pick(PICK_VERTEX, Fl::event_x(), Fl::event_y());
			if(pickResult != PICK_FAILURE)
			{
				game->lowerVertex(pickResult / SIZE_VERTICES, pickResult % SIZE_VERTICES);
				game->procCenters();
			}
		}
		return 1;
	case FL_MOVE:
		if( game->gameRunning() && game->getMode() == MODE_PLACE)
		{
			pick(PICK_SQUARE, Fl::event_x(), Fl::event_y());
			if(pickResult != PICK_FAILURE)
			{
				highlightX = pickResult / SIZE_BOARD;
				highlightY = pickResult % SIZE_BOARD;

				if(highlightX + BUILDING_SIZE > SIZE_BOARD)
					highlightX = SIZE_BOARD - BUILDING_SIZE;
				if(highlightY + BUILDING_SIZE > SIZE_BOARD)
					highlightY = SIZE_BOARD - BUILDING_SIZE;
			}
		}
		return 1;
	case FL_ENTER:
		return 1;
	case FL_DRAG:
		if( Fl::event_state() & FL_BUTTON3 && game->gameRunning())
		{
			cameraX += (lastX - Fl::event_x()) * sensitivity;
			cameraY += (Fl::event_y() - lastY) * sensitivity;
			lastX = (float)Fl::event_x();
			lastY = (float)Fl::event_y();

			if(cameraX < CAMERA_XMIN)
				cameraX = CAMERA_XMIN;
			else if(cameraX > CAMERA_XMAX)
				cameraX = CAMERA_XMAX;

			if(cameraY < CAMERA_YMIN)
				cameraY = CAMERA_YMIN;
			else if(cameraY > CAMERA_YMAX)
				cameraY = CAMERA_YMAX;
		}
		return 1;
	case FL_RELEASE:
		return 1;
	case FL_MOUSEWHEEL:
		if(game->gameRunning() )
		{
			cameraZ += (float)(Fl::event_dy() * scrollAmount);

			if(cameraZ < CAMERA_ZMIN)
				cameraZ = CAMERA_ZMIN;
			else if(cameraZ > CAMERA_ZMAX)
				cameraZ = CAMERA_ZMAX;
		}
		return 1;
	default:
		return Fl_Gl_Window::handle(event);
		break;
	}
}

int glWindow::getPickResult()
{
	return pickResult;
}

void glWindow::pick(int mode, int x, int y)
{
	pickMode = mode;
	pickX = x;
	pickY = y;

	switch(mode)
	{
	case PICK_BUILDING:
		buildingPick();
		break;
	case PICK_SQUARE:
		squarePick();
		break;
	case PICK_VERTEX:
		vertexPick();
		break;
	}
}

void glWindow::buildingPick()
{
	make_current();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	gluPickMatrix((double)pickX, (double)(viewport[3]-pickY), 5, 5, viewport);
	
	gluPerspective(90.0,(GLfloat)w()/(GLfloat)h(),2.0f, 250.0f);
	
	gluLookAt(	cameraX, cameraY, cameraZ,
				cameraX, cameraY, 0.0,
				0.0, 1.0, 0.0);
	
	glSelectBuffer(BUFSIZE,selectBuffer);

	glRenderMode(GL_SELECT);

	glInitNames();

	Building *bldg;
	int x;
	int y;
	int bldgCount = 0;
	float height;

	glColor3f(1.0f, 1.0f, 1.0f);
	while( (bldg = game->getNextBuilding()) != NULL )
	{
		x = bldg->getX();
		y = bldg->getY();

		switch(bldg->getUpgradeLevel())
		{
		case 0:
			height = UPGRADE_ZERO_HEIGHT;
			break;
		case 1:
			height = UPGRADE_ONE_HEIGHT;
			break;
		case 2:
			height = UPGRADE_TWO_HEIGHT;
			break;
		case 3:
			height = UPGRADE_THREE_HEIGHT;
			break;
		}

		glPushName(bldgCount++);
		glBegin(GL_QUADS);

		glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION);
		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION  );
		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION + height );
		glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION + height );	

		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION);	
		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION  );
		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION + height );
		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION + height );

		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION);	
		glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION  );
		glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION + height );
		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION + height );

		glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION);	
		glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION  );
		glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION + height );
		glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION + height );

		glVertex3f(x * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x][y] * ELEVATION + height );
		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, y * SIZE_SQUARE, game->verticesZ[x+BUILDING_SIZE][y] * ELEVATION + height );
		glVertex3f((x+BUILDING_SIZE) * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE,game->verticesZ[x+BUILDING_SIZE][y+BUILDING_SIZE] * ELEVATION + height );
		glVertex3f(x * SIZE_SQUARE, (y+BUILDING_SIZE) * SIZE_SQUARE, game->verticesZ[x][y+BUILDING_SIZE] * ELEVATION + height );

		glEnd();
		glPopName();
	}
	
	int hits = glRenderMode(GL_RENDER);

	if(hits == 0)
	{
		pickResult = PICK_FAILURE;
		pickMode = PICK_NONE;
		return;
	}

	int closest = selectBuffer[3];
	unsigned int lowestDepth = selectBuffer[1];

	for(int i = 1; i < hits; i++)
	{
		if(selectBuffer[(i * 4) + 1] < lowestDepth)
		{
			lowestDepth = selectBuffer[(i * 4) + 1];
			closest = selectBuffer[(i * 4) + 3];
		}
	}
	pickResult = closest;
	pickMode = PICK_NONE;
}

void glWindow::squarePick()
{
	make_current();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	gluPickMatrix((double)pickX, (double)(viewport[3]-pickY), 5, 5, viewport);
	
	gluPerspective(90.0,(GLfloat)w()/(GLfloat)h(),2.0f, 250.0f);
	
	gluLookAt(	cameraX, cameraY, cameraZ,
				cameraX, cameraY, 0.0,
				0.0, 1.0, 0.0);
	
	glSelectBuffer(BUFSIZE,selectBuffer);

	glRenderMode(GL_SELECT);

	glInitNames();

	glColor3f(1.0f, 1.0f, 1.0f);


	int quadCount = 0;

	for(int i = 0; i < SIZE_BOARD; i++)
	{
		for( int j = 0; j < SIZE_BOARD; j++)
		{
			glPushName(quadCount++);

			glBegin(GL_QUADS);
			
			glVertex3f((float)i * SIZE_SQUARE, (float)j * SIZE_SQUARE, game->verticesZ[i][j] * ELEVATION );
			glVertex3f((float)(i+1) * SIZE_SQUARE, (float)j * SIZE_SQUARE, game->verticesZ[i+1][j] * ELEVATION );
			glVertex3f((float)(i+1) * SIZE_SQUARE, (float)(j+1) * SIZE_SQUARE, game->verticesZ[i+1][j+1] * ELEVATION );
			glVertex3f((float)i * SIZE_SQUARE, (float)(j+1) * SIZE_SQUARE, game->verticesZ[i][j+1] * ELEVATION );

			glEnd();
			glPopName();

		}
	}
	
	
	int hits = glRenderMode(GL_RENDER);

	if(hits == 0)
	{
		pickResult = PICK_FAILURE;
		pickMode = PICK_NONE;
		return;
	}
		
	int closest = selectBuffer[3];
	unsigned int lowestDepth = selectBuffer[1];

	for(int k = 1; k < hits; k++)
	{
		if(selectBuffer[(k * 4) + 1] < lowestDepth)
		{
			lowestDepth = selectBuffer[(k * 4) + 1];
			closest = selectBuffer[(k * 4) + 3];
		}
	}

	pickResult = closest;
	pickMode = PICK_NONE;

}

void glWindow::vertexPick()
{
	make_current();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	gluPickMatrix((double)pickX, (double)(viewport[3]-pickY), 5, 5, viewport);
	
	gluPerspective(90.0,(GLfloat)w()/(GLfloat)h(),2.0f, 250.0f);
	
	gluLookAt(	cameraX, cameraY, cameraZ,
				cameraX, cameraY, 0.0,
				0.0, 1.0, 0.0);
	
	glSelectBuffer(BUFSIZE,selectBuffer);

	glRenderMode(GL_SELECT);

	glInitNames();

	glColor3f(1.0f, 1.0f, 1.0f);


	int vertCount = 0;
	float pos = 0.0f;

	for(int i = 0; i < SIZE_VERTICES; i++)
	{
		for( int j = 0; j < SIZE_VERTICES; j++)
		{
			glPushName(vertCount++);

			glBegin(GL_QUADS);
			
			glVertex3f((float)(i - 0.5f) * SIZE_SQUARE, (float)(j - 0.5f) * SIZE_SQUARE, game->verticesZ[i][j] * ELEVATION );
			glVertex3f((float)(i + 0.5f) * SIZE_SQUARE, (float)(j - 0.5f) * SIZE_SQUARE, game->verticesZ[i][j] * ELEVATION );
			glVertex3f((float)(i + 0.5f) * SIZE_SQUARE, (float)(j + 0.5f) * SIZE_SQUARE, game->verticesZ[i][j] * ELEVATION );
			glVertex3f((float)(i - 0.5f) * SIZE_SQUARE, (float)(j + 0.5f) * SIZE_SQUARE, game->verticesZ[i][j] * ELEVATION );

			glEnd();
			glPopName();

		}
	}
	
	
	int hits = glRenderMode(GL_RENDER);

	if(hits == 0)
		pickResult = PICK_FAILURE;
	else
	{
		
		int closest = selectBuffer[3];
		unsigned int lowestDepth = selectBuffer[1];		

		for(int k = 1; k < hits; k++)
		{
			if(selectBuffer[(k * 4) + 1] < lowestDepth)
			{
				lowestDepth = selectBuffer[(k * 4) + 1];
				closest = selectBuffer[(k * 4) + 3];
			}
		}

		pickResult = closest;
	}

	pickMode = PICK_NONE;

}

void glWindow::adjustHighlight()
{
	static float amount = COLOR_HIGHLIGHT_G_STEP;
	highlightGreen += amount;
	if(highlightGreen > COLOR_HIGHLIGHT_G_MAX)
	{
		amount = -amount;
		highlightGreen = COLOR_HIGHLIGHT_G_MAX;
	}
	else if(highlightGreen < COLOR_HIGHLIGHT_G_MIN)
	{
		amount = -amount;
		highlightGreen = COLOR_HIGHLIGHT_G_MIN;
	}

}


void idler(void *arg)
{
	static int count = 0;
	static Game* game = Game::getCurrentGameInstance();
	if(game == NULL)
		printf("Game is null");
	
	if(++count % GAME_SPEED_MEDIUM == 0)
	{
		count = 0;
		game->advanceDate();
	}

	glWindow *gW = (glWindow*)arg;
	gW->redraw();
}