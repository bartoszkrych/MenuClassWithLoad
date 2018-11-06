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
#define APOSTROPHE '\''
#define COMMA ','
#define SEMICOLON ';'

CMyMenu* createMenu(string sString, int& iCurrIdx)
{
	int i_end_name = sString.find(COMMA, iCurrIdx);
	int i_end_command = sString.find(SEMICOLON, iCurrIdx);

	string s_name = sString.substr(iCurrIdx + 2, i_end_name - iCurrIdx - 3);
	string s_comm = sString.substr(i_end_name + 2, i_end_command - i_end_name - 3);

	CMyMenu* c_menu = new CMyMenu(s_name, s_comm);

	iCurrIdx = sString.find(SEMICOLON, iCurrIdx);
	if (sString[iCurrIdx+1] != MENU_END)
	{
		iCurrIdx++;
		createChildren(sString, iCurrIdx, c_menu);
	}
	return c_menu;
}

CMenuCommand* createCommand(string sString, int& iCurrIdx)
{
	int i_end_name = sString.find(COMMA, iCurrIdx);
	int i_end_command = sString.find(COMMA, i_end_name + 1);
	int i_end_help = sString.find(COMM_END, iCurrIdx);
	string s_name = sString.substr(iCurrIdx + 2, i_end_name - iCurrIdx - 3);
	string s_comm = sString.substr(i_end_name + 2, i_end_command - i_end_name - 3);
	string s_help = sString.substr(i_end_command + 2, i_end_help - i_end_command - 3);

	CMenuCommand* c_command = new CMenuCommand(s_name,s_comm,s_help);

	return c_command;
}

void createChildren(string sString, int& iCurrIdx, CMyMenu* cMother)
{
	while (sString[iCurrIdx] != MENU_END) {
		if (sString[iCurrIdx] == COMMA) iCurrIdx++;
		if (sString[iCurrIdx] == MENU_START)
		{
			CMyMenu* c_new_menu = createMenu(sString, iCurrIdx);
			cMother->vAddItem(c_new_menu);
			iCurrIdx = sString.find(MENU_END, iCurrIdx);
			iCurrIdx++;
		}
		else if (sString[iCurrIdx] == COMM_START)
		{
			CMenuCommand* c_new_comm = createCommand(sString, iCurrIdx);
			cMother->vAddItem(c_new_comm);
			iCurrIdx = sString.find(COMM_END, iCurrIdx);
			iCurrIdx++;
		}
	}
}

CMenuItem* cCreateFromString(string sString)
{
	CMenuItem* c_new_Item;
	int p= 0;
	if(sString[0]==MENU_START)
	{
		c_new_Item = createMenu(sString, p);
	}else
	{
		c_new_Item = createCommand(sString, p);
	}

	return c_new_Item;
}

// @@@@@@@@ TESTING @@@@@@@@@@

bool bLoadString(string sString)
{

	int i_index = 0;

	if (sString.size() < 2)
	{
		cout << "Too short command!" << endl;

		return false;
	}// if (sString.size() == 0)
	if (bLoadHalf(sString, i_index))
	{
		if (i_index < sString.size())
		{
			cout << "Too much symbols(from idx= " << i_index << "):" << endl << "\"" << endl;
			for (int i = i_index; i < sString.size(); i++)
			{
				cout << sString[i];
			}//for (int i = i_index; i < sString.size(); i++)
			cout << "\"" << endl;
			return false;
		}
		return true;
	}//else if (bLoadHalf(sString))

	return false;
}//void vCreateFromString()

bool bLoadCommand(string &sString, int &iCurrIdx)
{
	int i_stage = 0;
	do
	{
		if (i_stage == 0)
		{
			if (!bLoadName(sString, iCurrIdx))
			{
				return false;
			}//if (!bLoadName(sInput))
			i_stage++;
		}// if (i_stage == 0)
		else if (i_stage == 1)
		{
			if (sString[iCurrIdx] == COMMA)
			{
				iCurrIdx++;
				if (!bLoadName(sString, iCurrIdx))
				{
					return false;
				}//if (!bLoadName(sInput))
				i_stage++;
			}// if (sInput[0] == COMMA)
			else
			{
				char pc_tab[1] = { COMMA };
				vShowFail(sString, iCurrIdx, pc_tab, 1);
				return false;
			}//else if (sInput[0] == COMMA)
		}// else if (i_stage == 1)
		else if (i_stage == 2)
		{
			if (sString[iCurrIdx] == COMMA)
			{
				iCurrIdx++;
				if (!bLoadName(sString, iCurrIdx))
				{
					return false;
				}//if (!bLoadName(sInput))
				i_stage++;
			}// if (sInput[0] == COMMA)
			else
			{
				char pc_tab[1] = { COMMA };
				vShowFail(sString, iCurrIdx, pc_tab, 1);
				return false;
			}//else if (sInput[0] == COMMA)
		}// else if (i_stage == 1)
	} while (sString[iCurrIdx] != COMM_END && i_stage != 3);
	iCurrIdx++;
	return true;
}//bool bLoadCommand(string &sString, int &iCurrIdx)

bool bLoadMenu(string &sString, int &iCurrIdx)
{
	int i_stage = 0;
	do
	{
		if (i_stage == 0)
		{
			if (!bLoadName(sString, iCurrIdx))
			{
				return false;
			}//if (!bLoadName(sInput))
			i_stage++;
		}// if (i_stage == 0)
		else if (i_stage == 1)
		{
			if (sString[iCurrIdx] == COMMA)
			{
				iCurrIdx++;
				if (!bLoadName(sString, iCurrIdx))
				{
					return false;
				}//if (!bLoadName(sInput))
				i_stage++;
			}// if (sInput[0] == COMMA)
			else
			{
				char pc_tab[1] = { COMMA };
				vShowFail(sString, iCurrIdx, pc_tab, 1);
				return false;
			}//else if (sInput[0] == COMMA)
		}// else if (i_stage == 1)
		else if (i_stage == 2)
		{
			if (sString[iCurrIdx] == SEMICOLON)
			{
				iCurrIdx++;
				i_stage++;
			}// if (sInput[0] == COMMA)
			else
			{
				char pc_tab[1] = { SEMICOLON };
				vShowFail(sString, iCurrIdx, pc_tab, 1);
				return false;
			}//else if (sInput[0] == COMMA)
		}//else if (i_stage == 2)
		else if (i_stage == 3)
		{
			if (!bLoadHalf(sString, iCurrIdx))
			{
				return false;
			}//if (!bLoadHalf(sInput, sString, false))
			if (sString[iCurrIdx] == COMMA)
			{
				iCurrIdx++;
			}//if (sInput[0] == COMMA)
			else if (sString[iCurrIdx] == MENU_END)
			{
				iCurrIdx++;
				return true;
			}//else if (sInput[0] == MENU_END)
			else
			{
				char pc_tab[2] = { MENU_END,COMMA };
				vShowFail(sString, iCurrIdx, pc_tab, 2);
				return false;
			}//else if (!bLoadHalf(sInput, sString, false))
		}//else if (i_stage == 3)
		if (sString.size() == iCurrIdx)
		{
			cout << " WPROWADZONO NIEPELNA KOMENDE!" << endl;
			return false;
		}// if (sInput.size() == 0)
	} while (sString[iCurrIdx] != MENU_END || i_stage != 3);
	iCurrIdx++;
	return true;
}//bool bLoadMenu(string &sInput)

bool bLoadName(string &sString, int &iCurrIdx)
{
	if (sString[iCurrIdx] != APOSTROPHE)
	{
		char pc_tab[1] = { APOSTROPHE };
		vShowFail(sString, iCurrIdx, pc_tab, 1);
		return false;
	}// if (sInput[0] != APOSTROPHE)
	do
	{
		iCurrIdx++;
		if (sString.size() == iCurrIdx)
		{
			cout << "Not found -> ' <-";
			cout << "\tToo short command!" << endl;
			return false;
		}// if (sInput.size() == 0)
	} while (sString[iCurrIdx] != APOSTROPHE);//   while (sInput[0] != APOSTROPHE)
	iCurrIdx++;
	return true;
}//bool bLoadName(string &sInput)

bool bLoadHalf(string &sString, int &iCurrIdx)
{
	while (sString.size() != iCurrIdx)
	{
		if (sString[iCurrIdx] == MENU_START)
		{
			iCurrIdx++;
			return bLoadMenu(sString, iCurrIdx);
		}// if (sInput[0] == MENU_END)
		else if (sString[iCurrIdx] == COMM_START)
		{
			iCurrIdx++;
			return bLoadCommand(sString, iCurrIdx);
		}// else if (sInput[0] == COMM_START)
		else
		{
			char pc_tab[2] = { MENU_START,COMM_START };
			vShowFail(sString, iCurrIdx, pc_tab, 2);
			return false;
		}//else if (sInput[0] == MENU_END)
	}// while (sInput.size() != 0)
	return true;
}//bool bLoadHalf(string &sInput)

void vShowFail(string &sString, int &iCurrIdx, char pcSuggest[], int iSize)
{
	cout << "Wrong symbol(find arrows) :" << endl;
	for (int i = 0; i < sString.size(); i++)
	{
		if (i == iCurrIdx)
		{
			cout << " -> " << sString[i] << " <- ";
		}//if (i == i_fail)
		else
		{
			cout << sString[i];
		}//else if (i == i_fail)
	}//for (int i = 0; i < sString.size(); i++)
	if (iCurrIdx == sString.size())
	{
		cout << "{}";
		cout << endl << "Incomplete command!";
	}// if (iCurrIdx == sString.size())

	cout << endl << "Should be:";
	for (int i = 0; i < iSize; i++)
	{
		if (i != 0)
		{
			cout << "or";
		}// if (i != 0)
		cout << " ->  " << pcSuggest[i] << "  <- ";
	}//for (int i = 0; i < iSize; i++)
	cout << endl;
}//void vShowFail(string sString, int iFailDistance, char pcSuggest[], int iSize)

void vShowFail(string &sString, int &iCurrIdx)
{
	cout << "Error:" << endl;
	for (int i = 0; i < sString.size(); i++)
	{
		if (i == iCurrIdx)
		{
			cout << "-> " << sString[i] << " <-";
		}//if (i == iCurrIdx)
		else
		{
			cout << sString[i];
		}//else if (i == iCurrIdx)
	}//for (int i = 0; i < sString.size(); i++)
	if (iCurrIdx == sString.size())
	{
		cout << "{}";
		cout << endl << "Incomplete command" << endl;
	}// if (iCurrIdx == sString.size())

}//void vShowFail(string sString, int iFailDistance)
