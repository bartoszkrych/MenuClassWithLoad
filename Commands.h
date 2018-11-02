#pragma once
#include "MyCommand.h"
#include <string>

class COpenGoogle : public CMyCommand
{
public:
	void vRunCommand() override;
};


class CStatement : public CMyCommand
{
public:
	void vRunCommand() override;

	CStatement(std::string sStatment);
	CStatement();
private:
	std::string s_statement;
};


