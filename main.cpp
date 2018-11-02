
#include <iostream>
#include "MyMenu.h"
#include "ParsingLoad.h"
using namespace std;

int main()
{
	/*
	CMyMenu *main, *submenu1, *submenu11, *submenu2;
	CMenuCommand  *command_ala, *command_default, *command_empty, *command_browser;

	main = new  CMyMenu("Main", "main");
	submenu1 = new CMyMenu("Submenu1", "menu1");
	submenu11 = new CMyMenu("Submenu1", "menu11");
	submenu2 = new CMyMenu("Submenu2", "menu2");

	command_ala = new CMenuCommand("Write: \"Ala has a cat\"", "ala", new CStatement("Ala has a cat."),"This command can show you text.");
	command_default = new CMenuCommand(new CStatement());
	command_empty = new CMenuCommand("Test empty","empty");
	command_browser = new CMenuCommand("Open browser", "internet", new COpenGoogle(),"This command can show you text.");

	main->vAddItem(submenu1);
	main->vAddItem(submenu2);
	main->vAddItem(command_ala);
	submenu1->vAddItem(submenu11);
	submenu1->vAddItem(command_browser);
	submenu2->vAddItem(command_empty);
	submenu2->vAddItem(command_default);

	main->vRun();

	system("pause");
	*/

	string s_test_m_sm_com = "('mMenu','main';('Subm','sub';['MyCom','comm','helpComm']),('subm2','sub2';))";

	if(bLoadString(s_test_m_sm_com))
	{
		CMenuItem* main = cCreateFromString(s_test_m_sm_com);
		main->vRun();

		system("cls");

		delete main;

		cout << endl << endl << "Goodbye!" << endl << endl;
	}

	system("pause");
	
	return 0;
}//int main()