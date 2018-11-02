#include "ParsingLoad.h"
#include <iostream>
#include <vector>
#include <string>
#include "MyMenu.h"

using namespace std;


#define MENU_START '('
#define MENU_END ')'
#define COMM_START '['
#define COMM_END ']'
#define SEP_1 '\''
#define SEP_2 ','
#define SEP_3 ';'


CMyMenu* createMenu(string sString, int iCurrIdx)
{
	int i_end_name = sString.find(SEP_2, iCurrIdx);
	int i_end_command = sString.find(SEP_3, iCurrIdx);

	string s_name = sString.substr(iCurrIdx + 2, i_end_name - iCurrIdx - 3);
	string s_comm = sString.substr(i_end_name + 2, i_end_command - i_end_name - 3);

	CMyMenu* c_menu = new CMyMenu(s_name, s_comm);

	int iAfterSelcom = sString.find(SEP_3, iCurrIdx);
	iAfterSelcom++;
	if (sString[iAfterSelcom] != MENU_END)
	{
		createChildren(sString, iAfterSelcom, c_menu);
	}
	return c_menu;
}

CMenuCommand* createCommand(string sString, int iCurrIdx)
{
	int i_end_name = sString.find(SEP_2, iCurrIdx);
	int i_end_command = sString.find(SEP_2, i_end_name + 1);
	int i_end_help = sString.find(COMM_END, iCurrIdx);
	string s_name = sString.substr(iCurrIdx + 2, i_end_name - iCurrIdx - 3);
	string s_comm = sString.substr(i_end_name + 2, i_end_command - i_end_name - 3);
	string s_help = sString.substr(i_end_command + 2, i_end_help - i_end_command - 3);

	CMenuCommand* c_command = new CMenuCommand(s_name,s_comm,s_help);

	return c_command;
}

void createChildren(string sString, int iCurIdx, CMyMenu* cMother)
{
	iCurIdx--;
	while (sString[iCurIdx] != MENU_END) {
		iCurIdx++;
		if (sString[iCurIdx] == MENU_START)
		{
			CMyMenu* c_new_menu = createMenu(sString, iCurIdx);
			cMother->vAddItem(c_new_menu);
			iCurIdx = sString.find(MENU_END, iCurIdx);
			iCurIdx++;
		}
		else if (sString[iCurIdx] == COMM_START)
		{
			CMenuCommand* c_new_comm = createCommand(sString, iCurIdx);
			cMother->vAddItem(c_new_comm);
			iCurIdx = sString.find(COMM_END, iCurIdx);
			iCurIdx++;
		}
	}
}


CMenuItem* start(string sString)
{
	cout << endl << sString << endl;
	CMenuItem* newMenu = createMenu(sString, 0);

	return newMenu;
}