// generated by Fast Light User Interface Designer (fluid) version 1.0103

#ifndef simmu_UI_h
#define simmu_UI_h
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "Game.h"
#include <stdlib.h>
#include "Building.h"
#include <FL/Fl_File_chooser.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include "glWindow.h"
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>

class smu_UI {
  Building *curBuilding;
  Game *game;
public:
  smu_UI();
  Fl_Window *mainWin;
  Fl_Menu_Bar *mainMenu;
  static Fl_Menu_Item menu_mainMenu[];
  static Fl_Menu_Item *fileSub;
  static Fl_Menu_Item *newItem;
private:
  inline void cb_newItem_i(Fl_Menu_*, void*);
  static void cb_newItem(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *loadItem;
private:
  inline void cb_loadItem_i(Fl_Menu_*, void*);
  static void cb_loadItem(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *saveItem;
private:
  inline void cb_saveItem_i(Fl_Menu_*, void*);
  static void cb_saveItem(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *quitItem;
private:
  inline void cb_quitItem_i(Fl_Menu_*, void*);
  static void cb_quitItem(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *budgetItem;
private:
  inline void cb_budgetItem_i(Fl_Menu_*, void*);
  static void cb_budgetItem(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *helpItem;
private:
  inline void cb_helpItem_i(Fl_Menu_*, void*);
  static void cb_helpItem(Fl_Menu_*, void*);
public:
  Fl_Box *toolBox;
  Fl_Box *schoolBox;
  glWindow *drawWindow;
  Fl_Box *logoBox;
  Fl_Input *G_NameInput;
private:
  inline void cb_G_NameInput_i(Fl_Input*, void*);
  static void cb_G_NameInput(Fl_Input*, void*);
public:
  Fl_Value_Output *G_ApprovalOutput;
  Fl_Output *G_MoneyOutput;
  Fl_Output *G_MonthOutput;
  Fl_Value_Output *G_YearOutput;
  Fl_Output *O_OpinionOutput;
  Fl_Value_Output *O_PercentOutput;
  Fl_Choice *T_BuildChoice;
private:
  inline void cb_T_BuildChoice_i(Fl_Choice*, void*);
  static void cb_T_BuildChoice(Fl_Choice*, void*);
public:
  Fl_Value_Output *T_PriceOutput;
  Fl_Group *modeGroup;
  Fl_Button *T_PlaceButton;
private:
  inline void cb_T_PlaceButton_i(Fl_Button*, void*);
  static void cb_T_PlaceButton(Fl_Button*, void*);
public:
  Fl_Button *T_SelectButton;
private:
  inline void cb_T_SelectButton_i(Fl_Button*, void*);
  static void cb_T_SelectButton(Fl_Button*, void*);
public:
  Fl_Button *T_DownButton;
private:
  inline void cb_T_DownButton_i(Fl_Button*, void*);
  static void cb_T_DownButton(Fl_Button*, void*);
public:
  Fl_Button *T_UpButton;
private:
  inline void cb_T_UpButton_i(Fl_Button*, void*);
  static void cb_T_UpButton(Fl_Button*, void*);
public:
  Fl_Box *buildingBox;
  Fl_Input *B_NameInput;
private:
  inline void cb_B_NameInput_i(Fl_Input*, void*);
  static void cb_B_NameInput(Fl_Input*, void*);
public:
  Fl_Output *B_MonthOutput;
  Fl_Value_Output *B_YearOutput;
  Fl_Output *B_TypeOutput;
  Fl_Value_Output *B_UpgradeLevelOutput;
  Fl_Value_Output *B_UpgradePriceOutput;
  Fl_Button *B_UpgradeButton;
private:
  inline void cb_B_UpgradeButton_i(Fl_Button*, void*);
  static void cb_B_UpgradeButton(Fl_Button*, void*);
public:
  Fl_Button *B_DemolishButton;
private:
  inline void cb_B_DemolishButton_i(Fl_Button*, void*);
  static void cb_B_DemolishButton(Fl_Button*, void*);
public:
  Fl_Box *infoBox;
  Fl_Box *modeBox;
  void budget();
  void evalBuildPrice();
  const char* getName();
  void help();
  void loadGame();
  void loadBuilding(Building *bldg);
  void newGame();
  void renameBuilding();
  void renamePlayer();
  void saveGame();
  void setGameApproval(int approval);
  void setGameMoney(char* money);
  void setGameMonth(char *month);
  void setGameName(char *name);
  void setGameOver();
  void setGameYear(int year);
  void setOpinion(char *opinion);
  void setOpinionPercent(int percent);
  void show();
  void hide();
  void modePlace();
  void modeSelect();
  void modeGroundDown();
  void modeGroundUp();
  void upgradeBldg();
  void demolishBldg();
};
#endif
