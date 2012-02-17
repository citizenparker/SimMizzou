#include "simmu_UI.h"
#include "Game.h"
#include "Utils.h"
#include <FL/Fl.H>
#include <stdio.h>

int main(int argc, char **argv)
{
	smu_UI *ui = new smu_UI();
	ui->show();
	return Fl::run();
}