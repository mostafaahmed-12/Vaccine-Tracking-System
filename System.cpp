#include "System.h"
#include<queue>
using namespace std;
void System::Set_User_At_Wating_list(User user)
{
	
		this->Wating_list.push(user);
	
}

queue<User>System::Wating_list;

unordered_map<string,User>System::users;

unordered_map<string, Admin>System::Admins;


User System::Get_User_From_Wating_list()
{

	User user;
	user = this->Wating_list.front();
	if (user.get_gender() == "Famale") {
		user.count_famale--;
	}
	else if("Male")
	{
		user.count_male--;
	}
	this->Wating_list.pop();

	

	return user;
}

System::~System()
{
}

bool System::Check_id_is_Unique(User user)
{
	int flag = 0;

	if (this->users.find(user.get_id()) != users.end()) {
		cout <<"\t""You have account actually !" << endl;
		user.helper_for_counters(1);
		cout << endl;
			string ans;
	while (true)
	{
		cout << "\t""If you want to see your account press 1:-" << " "; cin >> ans;
		cout << endl;
		if (ans =="1") {
				this->users[user.get_id()].Display(0);

			break;
}
		
		else
		{
			cout << "\t""Please Enter 1 only " << endl;
			cout << endl;
			continue;
		}
	}
	flag = 0;
	}
	else
	{
		flag = 1;
	}
	
	return flag;

}

void System::check_vaccine(User& user)
{

	if (!this->Check_id_is_Unique(user)) {
		return;
	}
	else
	{
		if (user.vaccine.vac=="1")
		{
			cout << "\t""Which Doses You Had ?" << endl;
			cout << endl;
			string ans;

			while (true)
			{
				cout << "\t""Press 1 for one Dose Or 2 for both:-" << " "; cin >> ans;

				cout << endl;

				if (ans == "1") {

					user.vaccine.set_dose1(1);

					user.increase_counters();
			
					break;
				}

				else if (ans == "2")
				{
					user.vaccine.set_dose2(1);

					user.increase_counters();
					break;
				}
				else
				{
					cout << "\t""Please Enter 1 Or 2  only " << endl;
					cout << endl;
					continue;
				}
			}

			if (ans == "1") {

				cout << "\t" << "we will send the appointment of your next dose at message on your phone 011******94" << endl;
				cout << endl;
			}
			else if (ans == "2")
			{
				cout << "\t" <<"Thank you for helping us find out who got the vaccine" << endl;
				cout << endl;
			}

			this->users[user.get_id()] = user;
		}
		else if(user.vaccine.vac=="0")
		{

			this->Set_User_At_Wating_list(user);
			this->users[user.get_id()] = user;
			cout << "\t" << "You are added to waiting list" << endl;
			cout << endl;

		}
	}
	
}

void System::Add_User()
{
	User new_one;
	new_one.take_information();
	this->check_vaccine(new_one);
}

void System::Sign_in()
{
	string id, password;
	cout << "               *********************************************      " << endl;
	cout << "                   Enter The National Number and Password         " << endl;
	cout << "               *********************************************      " << endl;
	cout << endl;
	cout <<"\t\t\t\t\n                         THE NATIONAL NUMBER: "; cin >> id;
	cout <<"\t\t\t\t\n                         PASSWORD: "; cin >> password;
	int i = 2;





	while (i >= 1)
	{


		if (this->users[id].get_password() != password)
		{

			cout << "\n\     Wrong Password Or The National Number You Can try Only " << i << " times more" << endl;
			cout << "\t\t\t\t\n                         THE NATIONAL NUMBER: "; cin >> id;
			cout << "\t\t\t\t\n                         PASSWORD: "; cin >> password;

			i--;

		}


		if (this->users[id].get_password() == password) {
			cout << endl;
			this->users[id].users_operation();
			break;
		}
	
		


	}
	if (i == 0)
	{

		cout << "\n               YOU ARE BLOCKED FOR 10 SECONDS!!" << endl;;
		cout << endl;
		cout << "\t\t 1 for previous menu       \t\t\t2 for Exit \n\t\t\t\t\    Press any key to continue                  " << endl;
		cout << endl;
		string d;
		cout << "                       Your choice:-"; cin >> d;
		cout << endl;

		if (d == "2") {

			cout << "               ***********************************************           " << endl;
			cout << "                      THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
			cout << "                              HAVE A NICE DAY              " << endl;
			cout << "               ***********************************************           " << endl;

			exit(0);

		}

		else if (d == "1")
		{
			this->login_helper();
		}
		else
		{
			Sign_in();

		}
	}
}
void System::Sign_up()
{
	this->Add_User();
	this->The_interface();
}

void System::Sign_in_as_admin(){
		string name, password;
		cout << "               ***********************************************           " << endl;
		cout << "                          Enter The Name And Password                  " << endl;
		cout << "               ***********************************************           " << endl;
		cout << endl;
		cout << "\t\t\t\t\n                  	NAME: "; cin >> name;
		cout << "\t\t\t\t\n                        PASSWORD: "; cin >> password;

		int i = 2;
		while (i >=1)
		{
			  


			if (Admins[name].get_Password() != password)
			{

				cout << "\n\n\t     Wrong Password Or name  You Can try Only " << i << " times more" << endl;
				cout << "\t\t\t\t\n                  	NAME: "; cin >> name;
				cout << "\t\t\t\t\n                        PASSWORD: "; cin >> password;

			}


			 if (Admins[name].get_Password() == password)
			 {

				cout <<"\n                      YOU ARE LOGIN SUCCESSFULLY       " << endl;
				cout << endl;
				cout << "               ***********************************************           " << endl;
				cout << "                           Welcome to admin page                   " << endl;
				cout << "               ***********************************************           " << endl;
				cout << endl;
				X:
				cout << "\t1.VIEW STATISTICS       \t\t2.SEARCHING ON USER \n\t\t              3.DELETE" << endl;
				cout << endl;
				string ans;
				cout << "                       Your choice:-"; cin >> ans;

				cout <<endl;

				if (ans == "1") {
					Admins[name].Statics();
					break;
				}
				else if (ans == "2")
				{
					Admins[name].view();
					break;

				}
				else if (ans == "3")
				{
					Admins[name].Delete_AT_Admin();
					break;


				}

			}

		
			i--;
		}

											
		if (i == 0) {
			cout << endl;
			cout << "                    YOU ARE BLOCKED FOR 10 SECONDS!!"<<endl;
			cout << endl;

			cout << "\t\t 1 for previous menu       \t\t\t2 for Exit \n\t\t\t\t\    Press any key to continue                  " << endl;
			cout << endl;


			string d;
			cout << "                       Your choice:-"; cin >>d;
			cout << endl;
			if (d == "1") {
				this->login_helper();
			}
			else if(d=="2")
			{
				cout << "               ***********************************************           " << endl;
				cout << "                      THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
				cout << "                              HAVE A NICE DAY              " << endl;
				cout << "               ***********************************************           " << endl;
			
				exit(0);
			}
			else
			{
				Sign_in_as_admin();

			}
		}
		cout << endl;
		cout << endl;
		string xx;
		cout << "\t\t 1.Back to login page            2.Another Operation \n\t\t\t\              3.Exit" << endl;
		cout << endl;
		cout << "                       Your choice:-"; cin >>xx;
		cout << endl;
		if (xx == "1") {
			this->login_helper();
		}

		else if(xx=="3")
		{
			cout << "               ***********************************************           " << endl;
			cout << "                      THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
			cout << "                              HAVE A NICE DAY              " << endl;
			cout << "               ***********************************************           " << endl;

			exit(0);
		}
		else if(xx=="2")
		{
			goto X;
		}

}

void System::login_helper()
{

	string x;
	cout << "               ***********************************************           " << endl;
	cout << "                          Welcome  at login page                              " << endl;
	cout << "               ***********************************************           " << endl; cout << endl;

	cout <<"\t\t 1. Admin             \t\t\t2.User \n\t\t\t\     3. Back To main menu" << endl;

	cout << endl;
	cout << "                       Your choice:-"; cin >>x;

	cout << endl;
	if (x == "3") {
		this->The_interface();
	}

	else if (x == "1")
	{
		this->Sign_in_as_admin();

	}


	else if (x == "2")
	{
		this->Sign_in();
	}

}


void System::intial_users_store_at_system()
{
	User u1("1", "mostafa", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u1.vaccine.set_dose1(1);
	u1.vaccine.one_dose_male++;
	this->users[u1.get_id()] = u1;
	User u2("2", "hanfy", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u2.vaccine.set_dose1(1);
	u2.vaccine.one_dose_male++;
	this->users[u2.get_id()] = u2;
	User u3("3", "nahass", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u3.vaccine.set_dose1(1);
	u3.vaccine.one_dose_male++;
	this->users[u3.get_id()] = u3;
	User u4("4", "hassan", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u4.vaccine.set_dose1(1);
	this->users[u4.get_id()] = u4;
	u4.vaccine.one_dose_male++;
	User u5("5", "seif", "ahmed", "hinawi", "123", "20", "Male", "cairo", "Egypt", "1");
	u5.vaccine.set_dose1(1);
	u5.vaccine.one_dose_male++;
	this->users[u5.get_id()] = u5;


	User u6("6", "reem", "ahmed", "hinawi", "123", "20", "Famale", "cairo", "Egypt", "1");
	u6.vaccine.set_dose2(1);
	u6.vaccine.both_dose_famale++;
	this->users[u6.get_id()] = u6;
	User u7("7", "mona", "ahmed", "hinawi", "123", "20", "Famale", "cairo", "Egypt", "1");
	u7.vaccine.set_dose2(1);
	u7.vaccine.both_dose_famale++;
	this->users[u7.get_id()] = u7;
	User u8("8", "heba", "ahmed", "hinawi", "123", "20", "Famale", "cairo", "Egypt", "1");
	u8.vaccine.set_dose2(1);
	u8.vaccine.both_dose_famale++;
	this->users[u8.get_id()] = u8;
	User u9("9", "abeer", "ahmed", "hinawi", "123", "20", "Famale", "cairo", "Egypt", "1");
	u9.vaccine.set_dose2(1);
	u9.vaccine.both_dose_famale++;
	this->users[u9.get_id()] = u9;
	User u10("10", "nada", "ahmed", "hinawi", "123", "20", "Famale", "cairo", "Egypt", "1");
	u10.vaccine.set_dose2(1);
	u10.vaccine.both_dose_famale++;
	this->users[u10.get_id()] = u10;


	Admin a1("Hinawi", "123");
	Admin a2("Hassan", "123");
	Admin a3("Hanfy", "123");
	Admin a4("Nahass", "123");
	Admin a5("Seif", "123");

	Admins["Hinawi"] = a1;
	Admins["Hassan"] = a2;
	Admins["Hanfy"] = a3;
	Admins["Nahass"] = a4;
	Admins["Seif"] = a5;



}


void System::test_display_map()
{
	
	for (auto it = users.begin(); it != users.end(); it++) {
		 it->second.Display(0);
	}
}

void System::The_interface()
{
	string choice;
	cout << endl;
	cout << "               ***********************************************           " << endl;
	cout << "                    WELCOME TO VACCINE TRACKING SYSTEM                    " << endl;
	cout << "               ***********************************************           " << endl; cout << endl;
	cout <<"\t\t 1. Sign In        \t\t\t2.Sign Up \n\t\t\t\t\     3. Exit" << endl;
	cout << endl;
	cout << "                       Your choice:-"; cin >> choice;
	cout << endl;

	if (choice == "3") {
		cout << "               ***********************************************           " << endl;
		cout << "                      THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
		cout << "                              HAVE A NICE DAY              " << endl;
		cout << "               ***********************************************           " << endl;
		exit(0);
	}

	else if(choice=="2")
	{
		this->Sign_up();

	}

	else if(choice=="1")
	{
		this->login_helper();

	}


}

System::System()
{ 
	
	User non_real("", "", "", "", "", "", "", "", "", "0");
	Wating_list.push(non_real);
	this->Wating_list.pop();
	users[non_real.get_id()] = non_real;
	users.erase(non_real.get_id());
	


}