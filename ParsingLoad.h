#pragma once
#include <string>
#include "MenuCommand.h"

class CMyMenu;
using namespace std;

void createChildren(std::string sString, int iCurIdx, CMyMenu* cMother);

CMyMenu* createMenu(string sString, int iCurrIdx);

CMenuCommand* createCommand(string sString, int iCurrIdx);

CMenuItem* start(string sString);