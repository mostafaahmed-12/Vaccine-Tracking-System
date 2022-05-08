#pragma once
#include"User.h"
class Admin
{

private:
	string name;
	string password;
public:
	~Admin();
	Admin(string name,string password);
	void Statics();
    void view();
	void basic_statistics();
	void Delete_AT_Admin();
	void Addvanced_Statics();
	void helper_for_counters(User user);
	string get_Password();
	string get_Name();

	Admin();

};

