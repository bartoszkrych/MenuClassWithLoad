#pragma once
#include "MenuItem.h"
#include "MyCommand.h"

class CMenuCommand : public CMenuItem
{
public:
	void vRun() override;
	std::string toString() override;
	std::string getCommand() override;
	void vSetHelp(std::string sHelp);
	std::string sGetHelp() override;
	void vSetRoot(CMenuItem* cRoot) override;
	CMenuItem* cGetRoot() override;
	CMenuItem* cSearchObject(std::string sCommand, CMenuItem* cMenu) override;
	void vShowMenu() override;
	void vHelperShow(std::vector<int>* viLevel, std::vector<std::string>* vsCommand, int iLevel) override;

	CMenuCommand();
	CMenuCommand(std::string sName, std::string sCommand, CMyCommand * cCommand, std::string sHelp);
	CMenuCommand(std::string sName, std::string sCommand, std::string sHelp);
	CMenuCommand(std::string sName, std::string sCommand);
	CMenuCommand(CMyCommand *cCommand);
	~CMenuCommand();

private:
	CMyCommand * c_command;
	std::string s_name;
	std::string s_command;
	std::string s_path;
	std::string s_help;
};

