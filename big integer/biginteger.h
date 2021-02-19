#pragma once
#include<iostream>
#include"biginteger.h"
#include<string>
using namespace std;
	struct dstract
{
	string q="0";
	string r="0";
};
class biginteger
{
public:	
	biginteger();
	string addition(string, string);
	string multiplication(string, string);
	string subtraction(string, string);
	dstract div(string, string);
	bool isgreater(string g, string s);
	string	mod(string,string);
	string mod_of_power_helper(string, string, string);
	string mod_of_power(string, string, string);
	string Encrypt(string, string, string);
	string decrypt(string, string, string);
	string divide(string, string);
	~biginteger();
};

