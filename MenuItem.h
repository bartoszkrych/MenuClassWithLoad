#pragma once
#include <string>

class CMenuItem
{
public:
	virtual void vRun() = 0;
	virtual void vSetPath(std::string SPath) = 0;
	virtual std::string sGetPath() = 0;
	virtual std::string toString()=0;
	virtual std::string getCommand() = 0;
	virtual std::string sGetHelp() = 0;
	virtual void vSetRoot(CMenuItem* cRoot) = 0;
	virtual CMenuItem* cGetRoot() = 0;
	virtual void vSearchCommand(std::string sCommand) = 0;
	virtual std::string sGetPathSearch(std::string sCommand, std::string s_s) = 0;

	virtual ~CMenuItem() = default;
protected:
	std::string s_command;
	std::string s_name;
	std::string s_path;
	std::string s_help;
	CMenuItem* c_root = nullptr;
};

