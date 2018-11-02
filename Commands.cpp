#include "Commands.h"
#include <Windows.h>
#include <iostream>

const std::string DEFAULT_STATEMENT = "Default command";

void COpenGoogle::vRunCommand()
{
	ShellExecute(NULL, L"open", L"http://google.com", NULL, NULL, SW_SHOWNORMAL);
}

void CStatement::vRunCommand()
{
	std::cout << std::endl << s_statement << std::endl << std::endl;
	system("pause");
}

CStatement::CStatement()
{
	s_statement = DEFAULT_STATEMENT;
}

CStatement::CStatement(std::string sStatment)
{
	s_statement = sStatment;
}
