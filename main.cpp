#include <iostream>
#include <fstream>
#include <streambuf>
#include "ParsingLoad.h"
using namespace std;

int main()
{
	ifstream load("save.txt");
		//string s_test_m_sm_com = "('mMenu','main';('Subm','sub';['MyCom','comm','helpComm']),('subm2','sub2';))";
		//string s_test_m_sm_com = "('menu glowne','main';('podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('podmenu2','podmenu2';)),('podmenu3','menu3';['test','test','pomoc'],['Def','defcom','def']),['ala ma kota','ala','alaa'])";
		string s_test_m_sm_com((std::istreambuf_iterator<char>(load)), std::istreambuf_iterator<char>());


	if(bLoadString(s_test_m_sm_com))
	{
		CMenuItem* main = cCreateFromString(s_test_m_sm_com);
		main->vRun();

		system("cls");

		delete main;

		cout << endl << endl << "Goodbye!" << endl << endl;
	}

	/*
	ofstream out("save.txt");
	out << s_string;
	out.close();
	system("pause");
	 */

	system("pause");
	
	return 0;
}//int main()