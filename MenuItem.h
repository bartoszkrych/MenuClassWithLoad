#pragma once
#include <string>
#include <vector>

class CMenuItem
{
public:
	virtual void vRun() = 0;
	virtual std::string toString()=0;
	virtual std::string getCommand() = 0;
	virtual std::string sGetHelp() = 0;
	virtual void vSetRoot(CMenuItem* cRoot) = 0;
	virtual CMenuItem* cGetRoot() = 0;
	virtual CMenuItem* cSearchObject(std::string sCommand, CMenuItem* cMenu) = 0;
	virtual void vHelperShow(std::vector <int>* viLevel, std::vector<std::string>* vsCommand, int iLevel)=0;
	virtual void vShowMenu()=0;
	virtual ~CMenuItem() = default;
protected:
	std::string s_command;
	std::string s_name;
	std::string s_help;
	CMenuItem* c_root = nullptr;
};

