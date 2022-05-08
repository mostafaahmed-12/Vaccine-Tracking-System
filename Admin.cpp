#include "Admin.h"
#include"System.h"
#include"User.h"
#include <cmath>
#include <iomanip> 


Admin::Admin() {

}

Admin::~Admin()
{
}

Admin::Admin(string name, string password)
{
	this->name = name;
	this->password = password;
}

void Admin::Statics()
{
	string number;
	cout << "               ***********************************************           " << endl;
	cout << "                             VACCINE STATISTICS                           " << endl;
	cout << "               ***********************************************           " << endl;
	cout << endl;
	cout << "             1.Basic statistics    2.Advanced Statistics     3.Back " << endl;
	cout << endl;
	cout << "                       Your choice:-"; cin >> number;
	cout << endl;
	if (number == "1") {
		this->basic_statistics();
		}

	else if(number=="2")
	{
		this->Addvanced_Statics();
	}

	
	

} 


void Admin::view()
{
	string id;
	System s;
	int i = 3;
	while (i>0){

		cout << "         ************************************************************\n";
		cout << "            viewing the records of user by his National Number"<<endl;
		cout << "         ************************************************************\n\n";
		cout << "\t\t\t\t\n                                    THE NATIONAL NUMBER: "; cin >> id;
		cout << endl;

		if (s.users.find(id) != s.users.end()) {
			s.users[id].Display(0);
			break;
		}
		else
		{
			cout << " \n                                   Sorry User is not found" << endl;
			i--;
		}
	}
	
	if (i == 0) {
		cout << "\n\t\t\tplease make sure this national number is true and try again\n\n";

	}


}

void Admin::basic_statistics()
{
	User u;
	System s;
	cout << endl;
	cout <<"          **********************************************************************************************************                 " << endl;
	cout << "                  Basic statistical analysis of Egyptian people who vaccinated in and outside Egypt                           " << endl;
	cout << "         **********************************************************************************************************                 " << endl;
	if (isnan(double(((double)u.vaccine.ones_count / ((double)s.users.size())) * 100.0))) 
	{
		cout << "                Percentage of people registered in the system that has received the first dose is = " << 0 << " %" << endl;
		cout << endl;
	}
	else
	{
		cout << "                Percentage of people registered in the system that has received the first dose is = " << setprecision(2)<<abs(double(((double)u.vaccine.ones_count / ((double)s.users.size())) * 100.0)) << " %" << endl;
		cout << endl;
	}
	if (isnan(double(((double)u.vaccine.both_count / ((double)s.users.size()))) * 100.0)) {
		cout << "                Percentage of people registered in the system that has received both doses is = " << 0 << " %" << endl;
		cout << endl;
	}

	else
	{
		cout << "                Percentage of people registered in the system that has received both doses is = " << setprecision(2)<< abs(double(((double)u.vaccine.both_count / ((double)s.users.size())) * 100.0)) << " %" << endl;

		cout << endl;
	}

cout << "                       Percentage of Females and Males registered in the system :-" << endl;
cout << endl; 
if (isnan(double(((double)u.count_famale / ((double)u.count_famale + (double)u.count_male)) * 100.0))) {
	cout <<"                       Famales = " <<0<<" %"<<endl;
}
else
{
	cout << "                      Famales = " << setprecision(2)<< abs(double(((double)u.count_famale / ((double)u.count_famale + (double)u.count_male)) * 100.0)) <<" %" << endl;
	cout << endl;


}

cout << endl;
if (isnan(double(((double)u.count_male / ((double)u.count_famale + (double)u.count_male)) * 100.0))) {
	cout << "                       Males = " << " 0 %" << endl;
	cout << endl;

}
else
{
	cout << "                       Males = " << setprecision(2)<< abs(double(((double)u.count_male / ((double)u.count_famale + (double)u.count_male)) * 100.0))<<" %" << endl;
	cout << endl;

}

cout << endl;
if (isnan(double(((double)u.vaccine.one_dose_famale / (((double)s.users.size()))) * 100.0))) {
	cout <<"              Percentage of Famales registered in the system that has received the first dose is = " << 0 << " %" << endl;
	cout << endl;


}
else
{
	cout << "              Percentage of Famales registered in the system that has received the first dose is =  "<< setprecision(2)<<(abs(double(((double)u.vaccine.one_dose_famale / ((double)s.users.size()))))*100.0) << " %" << endl;
	cout << endl;

}

cout<<endl;
if (isnan(double(((double)u.vaccine.one_dose_male / ((double)s.users.size())) * 100.0))) {
	cout << "              Percentage of Males registered in the system that has received the first dose is = " << 0 << " %" << endl;
	cout << endl;

}
else
{
	cout << "              Percentage of Males registered in the system that has received the first dose is = " << setprecision(2)<<abs((double(((double)u.vaccine.one_dose_male / ((double)s.users.size()))))*100.0 )<< " %" << endl;
	cout << endl;

}

cout << endl;
if (isnan(double(((double)u.vaccine.both_dose_famale / ((double)u.vaccine.both_dose_famale + (double)u.vaccine.both_dose_male)) * 100.0))) {
	cout << "              Percentage of Famales registered in the system that has received both doses is = " <<0<< "%" << endl;
	cout << endl;
}
else
{
	cout << "              Percentage of Famales registered in the system that has received both doses is = " <<setprecision(2)<< abs(double((((double)u.vaccine.both_dose_famale / ((double)s.users.size()))))*100.0) << " %" << endl;
	cout << endl;
}


if (isnan(double((((double)u.vaccine.both_dose_male / (((double)s.users.size())))) * 100.0))) {
	cout << "              Percentage of Male registered in the system that has received both doses is =  " << 0 << "%" << endl;
	cout << endl;

}
else
{
	cout << "               Percentage of Male registered in the system that has received both doses is = "<< setprecision(2) <<abs( double((((double)u.vaccine.both_dose_male / (((double)s.users.size())))) * 100.0)) << " %" << endl;
	cout << endl;
}


cout << endl;

string xx;
cout << "                            \t\t 1.Exit        2.Back to previous   " << endl;
cout << endl;
cout << "                                         Your choice:-"; cin >>xx;
cout << endl;
while (true)
{
	if (xx == "1") {
		cout << "                                     ***********************************************           " << endl;
		cout << "                                        THANK YOU FOR USING OUR APPLICATION!!                  " << endl;
		cout << "                                                   HAVE A NICE DAY                               " << endl;
		cout << "                                     ***********************************************           " << endl;

		exit(0);
		break;
	}
	else if (xx == "2")
	{
		this->Statics();
		break;
	}

}


}

void Admin:: helper_for_counters(User user)
{

	if (user.get_gender() == "Male") {

		user.count_male--;
	}

	else if (user.get_gender() == "Famale")
	{
		user.count_famale--;
	}

	if (user.vaccine.dose2) {

		user.vaccine.both_count--;

		if (user.get_gender() == "Male") {

			user.vaccine.both_dose_male--;

		}
		else if (user.get_gender() == "Famale")
		{

			user.vaccine.both_dose_famale--;
		}

	}

	if (user.vaccine.dose1) {
		user.vaccine.ones_count--;

		if (user.get_gender() == "Male") {

			user.vaccine.one_dose_male--;

		}
		else if (user.get_gender() == "Famale")
		{

			user.vaccine.one_dose_famale--;
		}
	}
}

string Admin::get_Password()
{
	return this->password;
}

string Admin::get_Name()
{
	return this->name;
}


void Admin::Delete_AT_Admin()
{
	
	System s;

	string id;

	while (true)
	{

		cout << "         ************************************************************"<<endl;
		cout << "              Delete the records of user by his National Number      "<<endl;
		cout << "         *************************************************************"<<endl;
		cout << endl;
		cout << "                           THE NATIONAL NUMBER: "; cin >> id;
		

		if (s.users.find(id) != s.users.end()) {

			string delete_option;
			cout << endl;
			cout << endl;
			cout << "\t\t 1. Remove This User              2.Remove Record" << endl;
			cout << endl;
			cout << "                               Your choice:-"; cin >> delete_option;
			s.users[id].Display(0);
			cout << endl;
			cout << endl;
			X:
			if (delete_option == "1"|| delete_option=="7")
			{
				if (s.users[id].vaccine.vac=="0")
				{
					queue<User>deletee;

					while (!s.Wating_list.empty()) {

						if (s.Wating_list.front().get_id() != id) {

							deletee.push(s.Wating_list.front());

							s.Wating_list.pop();
						}
						else if (s.Wating_list.front().get_id() ==id)
						{
							s.Wating_list.pop();


						}
					}

					while (deletee.size() > 1)
					{


						s.Wating_list.push(deletee.front());

						deletee.pop();

					}


				}

				s.users[id].helper_for_counters(1,1);
				s.users.erase(id);
				cout << "               *********************************************      " << endl;
				cout << "                               USER IS DELETED                                 " << endl;
				cout << "               *********************************************      " << endl;
		

			}

			else if (delete_option == "2") {
				cout << endl;
				string number;
				cout << "                              The Number Of Record You want To Delete : "; cin >> number;
				cout << endl;
			
					if(number=="1"){ 
						s.users[id].set_name({ "Deleted ","by" ,"Admin" }); 
						cout << endl;
						cout << "                                process is done successfully                " << endl;
					}
					else if(number=="2")
					{
						s.users[id].helper_for_counters(1,1);
						s.users[id].set_gender("Deleted by Admin");
						cout << endl;
						cout << "                                process is done successfully               " << endl;

					}
					else if(number=="3")
					{
						s.users[id].set_age("Deleted by Admin");
						cout << endl;
						cout << "                                 process is done successfully               " << endl;

					}
					else if (number == "4")
					{
						s.users[id].set_country("Deleted by Admin");
						cout << endl;
						cout << "                                  process is done successfully               " << endl;

					}
					else if (number == "5")
					{
						string pass;
						cout << "                            !!!!!Password is deleted!!!!!!           " << endl;
						cout << endl;
						cout << "                             You must enter new password for this user" << endl;
						cout << endl;
						cout << "                                           New password : "; cin >> pass;
						s.users[id].set_password(pass);

					}
					else if (number == "6")
					{
						s.users[id].set_Governorate("Deleted by Admin");
						cout << endl;
						cout << "                                        process is done successfully        " << endl;

					}
					else if(number=="7")
					{
						int x;
						delete_option = "7";
						cout << "!!!!!!!WARNING IF YOU DELETE THE NATIONAL  NUMBER MEANS YOU WANT TO DELETE  ACCOUNT OF THIS USER!!!!!!!!!" << endl;
						cout << endl;
						cout << "                         Press 1 if you want to stop deleting Or Any key  to continue:"; cin >> x; cout << endl;
						if (x == 1) {
							return;
						}
						else
						{
							goto X;

						}
					}
					else if (number == "8")
					{
						if (s.users[id].vaccine.vac=="1") {
							s.users[id].helper_for_counters(0,1);
							Vaccine vacine;
							vacine.vac = "Deleted by admin";
							vacine.dose1 = 0;
							vacine.dose2 = 0;
							s.users[id].set_vaccine(vacine);
						

						}
						
						cout << "                               Vaccine information is deleted" << endl;
					}

				

				

			}
			break;
		}
		else
		{
			cout << "                                        invalid national number please Try Again" << endl;
		}

	}






}

void Admin::Addvanced_Statics()
{
	cout << "bouns after eid thanks ";
}
