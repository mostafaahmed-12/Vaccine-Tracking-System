#include<queue>
#include<unordered_map>
#include"User.h"
#include"Admin.h"
#include<stack>
#pragma once
class System
{


public:

	System();
	static queue<User>Wating_list;
   static unordered_map<string, User>users;
   static unordered_map<string,Admin>Admins;
   ~System();
   bool Check_id_is_Unique(User user);
	void Set_User_At_Wating_list(User user);
	User Get_User_From_Wating_list();
	void check_vaccine(User &user);
	void Add_User();
	void Sign_in();
	void Sign_up();
	void test_display_map();
	void The_interface();
	void Sign_in_as_admin();
	void login_helper();
	void intial_users_store_at_system();
};

