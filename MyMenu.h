#pragma once
#include <vector>
#include "MenuItem.h"
#include <string>
using namespace std;


class CMyMenu : public CMenuItem
{
public:
	void vAddItem(CMenuItem * newItem);
	bool bDeleteItem(int iIndex);
	void vShowItems();


	void vRun() override;
	string toString() override;
	string getCommand() override;
	void vSetPath(std::string SPath) override;
	string sGetPath() override;
	std::string sGetHelp() override;
	void vSetRoot(CMenuItem* cRoot) override;
	CMenuItem* cGetRoot() override;
	void vSearchCommand(std::string sCommand) override;
	string sGetPathSearch(string sCommand, string s_s) override;

	CMyMenu();
	CMyMenu(string sName, string sCommand);
	~CMyMenu();
private:
	std::vector<CMenuItem*>  v_menu_items;
	int i_size;
	string s_path;
	std::string s_help;
	CMenuItem*  c_root;

	bool bTestCommand(string test);
	int iFindCommand(string sCommand);
	CMenuItem * cGetRootOfTree();
};

