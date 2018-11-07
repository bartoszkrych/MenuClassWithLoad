#include "MyMenu.h"
#include <filesystem>
#include <iostream>

const string DEFAULT_NAME = "DEFAULT";
const string DEFAULT_COMMAND = "defcom";

void CMyMenu::vAddItem(CMenuItem* newItem)
{
	newItem->vSetRoot(this);
	v_menu_items.push_back(newItem);
	i_size++;
}

bool CMyMenu::bDeleteItem(int iIndex)
{
	if (iIndex>=i_size)
	{
		return  false;
	} 
	else
	{
		delete v_menu_items[iIndex];
		v_menu_items.erase(v_menu_items.begin() + iIndex);
		i_size--;
		return true;
	}
}

void CMyMenu::vShowItems()
{
	for(int i = 0;i<i_size; i++)
	{
		cout << endl << "Index: " << i << ", " << v_menu_items[i]->toString();
	}
}

void CMyMenu::vRun()
{
	string enterComm;
	do 
	{
		system("cls");
		cout << endl << "Menu " << toString() << endl;
		for (int i = 0; i < i_size; i++)
		{
			cout << endl << i + 1 << ". "<<" " <<v_menu_items[i]->toString();
		}//		for (int i = 0; i < i_size; i++)

		bool b_test = false;
		string s_first_word;
		cout << endl << endl << "Enter command: ";
		do {
			getline(cin, enterComm);
			b_test = bTestCommand(enterComm);
			if(!b_test)
			{
				cout << "Wrong. Enter correct: ";
			}
		} while (!b_test);//do
		
		if (enterComm != "back")
		{
			int i_index_comm;
			vector <string> words(0);
			string s_analyze = enterComm;
			string s_curr_word;
			int i_index_words = 0;
			while (i_index_words != -1)
			{
				i_index_words = s_analyze.find(" ");
				s_curr_word = s_analyze.substr(0, i_index_words);
				words.push_back(s_curr_word);
				s_analyze = s_analyze.substr(i_index_words + 1);
			}//while (i_index != -1)

			if (words.size() == 1)
			{
				i_index_comm = iFindCommand(enterComm);
				v_menu_items[i_index_comm]->vRun();
			}
			else if (words[0]=="help")
			{
				i_index_comm = iFindCommand(words[1]);
				cout << v_menu_items[i_index_comm]->sGetHelp()<<endl;
				system("pause");
			}
			else if (words[0]=="search")
			{
				vSearchCommand(words[1]);
			}
		}//	if (enterComm != "back")
	} while (enterComm != "back");//do
}//void CMyMenu::vRun()

string CMyMenu::toString()
{
	return s_name + " (" + s_command + ")";
}

string CMyMenu::getCommand()
{
	return s_command;
}

std::string CMyMenu::sGetHelp()
{
	return "It's just a menu";
}

void CMyMenu::vSetRoot(CMenuItem* cRoot)
{
	c_root = cRoot;
}

CMenuItem* CMyMenu::cGetRoot()
{
	return c_root;
}

void CMyMenu::vSearchCommand(std::string sCommand)
{
	CMenuItem * root_ofTree = cGetRootOfTree();
	CMenuItem * c_item = root_ofTree->cSearchObject(sCommand, NULL);

	if(c_item !=NULL)
	{
		CMenuItem * mother = c_item->cGetRoot();
		if (mother != NULL)
		{

			CMenuItem * kid = this;
			string s_path = sCommand;
			while (mother != NULL)
			{
				s_path = mother->getCommand() + "/" + s_path;
				kid = mother;
				mother = mother->cGetRoot();
			}
			cout << s_path <<endl;
		}else
		{
			cout << sCommand << endl;
		}
	}
	else
	{
		cout << "No command."<<endl;
	}
	system("pause");
}

CMenuItem* CMyMenu::cSearchObject(string sCommand, CMenuItem* cMenu)
{
	for (int i = 0; i < v_menu_items.size(); i++)
	{
		if (sCommand == s_command) return this;
		if (cMenu != NULL) i = v_menu_items.size();
		else if (v_menu_items[i]->getCommand() != sCommand)
		{
			cMenu =v_menu_items[i]->cSearchObject(sCommand,cMenu);
		}
		else
		{
			cMenu=v_menu_items[i];
		}
	}
	return cMenu;
}

CMyMenu::CMyMenu()
{
	s_name = DEFAULT_NAME;
	s_command = DEFAULT_COMMAND;
	i_size = 0;
	c_root = NULL;
}

CMyMenu::CMyMenu(string sName, string sCommand)
{
	s_name = sName;
	s_command = sCommand;
	i_size = 0;
	c_root = NULL;
}

CMyMenu::~CMyMenu()
{
	cout << endl << "Deleting menu:" << s_command;
	for(int i = 0; i<v_menu_items.size();i++)
	{
		delete v_menu_items[i];
	}
}

bool CMyMenu::bTestCommand(string sTest)
{
	if (sTest == "back") return true;
	for(int i = 0; i < i_size; i++)
	{
		if (sTest == v_menu_items[i]->getCommand())
		{
				return true;
		}//	if (sTest == v_menu_items[i]->getCommand())
	}//	for(int i = 0; i < i_size; i++)

	vector <string> words(0);
	string s_analyze = sTest;
	string s_curr_word;
	int i_index = 0;	
	while (i_index != -1)
	{
		i_index = s_analyze.find(" ");
		s_curr_word = s_analyze.substr(0, i_index);
		words.push_back(s_curr_word);
		s_analyze = s_analyze.substr(i_index + 1);
	}//while (i_index != -1)

	if (words.size() != 2) return false;
	if (words[0] == "search") return true;
	if(words[0] == "help")
	{
		for (int i = 0; i < v_menu_items.size(); i++)
		{
			if (words[1] == v_menu_items[i]->getCommand())
			{
				return true;
			}//	if (sTest == v_menu_items[i]->getCommand())
		}//	for(int i = 0; i < i_size; i++)
	}
	return false;
}

int CMyMenu::iFindCommand(string sCommand)
{
	bool b_iter = false;
	int iter = 0;

	do {
		if (sCommand != v_menu_items[iter]->getCommand())
		{
			iter++;
		}//	if (enterComm != v_menu_items[iter]->getCommand())
		else
		{
			b_iter = true;
		}// ELSE 	if (enterComm != v_menu_items[iter]->getCommand())
	} while (!b_iter);//do

	return iter;
}

CMenuItem* CMyMenu::cGetRootOfTree()
{
	CMenuItem* mother = c_root;
	CMenuItem* kid = this;
	while (mother != NULL)
	{
		kid = mother;
		mother = mother->cGetRoot();
	}

	return kid;
}