#include<string>
#include<iostream>
#include<stack>
using namespace std;
struct full_name {
	string frist_name;
	string second_name;
	string last_name;

};

#pragma once
class Vaccine
{
public:
	static int ones_count;
	static int both_count;

		static int one_dose_famale;
		static int one_dose_male;

       static int both_dose_famale; 
	   static int both_dose_male;


	 string vac;
	bool dose1 = 0;
	bool dose2 = 0;
	void set_dose1(bool value) {
		this->dose1 = value;
		ones_count++;

	
	}
	void set_dose2(bool value) {
		this->dose2 = value;
		both_count++;
		
	}
	
};
class User
{


private:
	string id;
	string gender;
	string age;
	string password;
	string country;
	full_name name;
	string Governorate;
	string deleted_vaccine;

public:
	Vaccine vaccine;
	static int count_male;
	static int count_famale;

	string get_id();
	string get_age();
	string get_password();
	string get_country();
	full_name get_name();
	string get_gender();
	Vaccine get_vaccine();
	void take_information();
	void set_vaccine(Vaccine&  vaccine);
	void set_id(string id);
	void set_age(string age);
	void set_password(string password);
	void set_country(string country);
	void set_name(full_name name);
	void set_gender(string gender);
	void set_vaccine_vac(bool vac);
	void helper_for_delete_function();
	void helper_for_counters(int for_gender=0,int for_vaccine=0 );
	void set_Governorate(string Governorate);
	void users_operation();
	void increase_counters();
	void undofun();
	void helper(string d);
	User();

	User(string id, string first_name, string second_name, string last_name, string password, string age, string gender, string Governorate, string country, string vac);
	

	void Edit();
	void Delete();

	void Display(int i);

	~User();
};
