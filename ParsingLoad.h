#pragma once
#include <string>
#include "MenuCommand.h"

class CMyMenu;
using namespace std;

void createChildren(std::string sString, int& iCurrIdx, CMyMenu* cMother);

CMyMenu* createMenu(string sString, int& iCurrIdx);

CMenuCommand* createCommand(string sString, int& iCurrIdx);

CMenuItem* cCreateFromString(string sString);

// @@@@@@@@ TESTING @@@@@@@@@@

bool bLoadString(string sString);

bool bLoadMenu(string &sString, int &iCurrIdx);

bool bLoadCommand(string &sString, int &iCurrIdx);

bool bLoadName(string &sString, int &iCurrIdx);

bool bLoadHalf(string &sString, int &iCurrIdx);

void vShowFail(string &sString, int &iCurrIdx, char pcSuggest[], int iSize);

void vShowFail(string &sString, int &iCurrIdx);