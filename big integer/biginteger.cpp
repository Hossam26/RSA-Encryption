#include "biginteger.h"
biginteger::biginteger()
{
}
string biginteger::addition(string s1, string s2)
{
	string result = {};
	char carry = 0;
	int l1 = s1.length();
	int l2 = s2.length();
	if (s1.length() <= s2.length())
	{
		for (int i = l1 - 1, j = l2 - 1; i >= 0; i--, j--) {
			int sum = (s1[i] - '0') + (s2[j] - '0') + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;
		}
		for (int i = l2 - l1 - 1; i >= 0; i--) {

			int sum = (s2[i] - '0') + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;
		}
		if (carry) {
			result.push_back(carry + '0');
		}
	}
	else {
		for (int i = l2 - 1, j = l1 - 1; i >= 0; i--, j--) {

			int sum = (s1[j] - '0') + (s2[i] - '0') + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;
		}
		for (int i = l1 - l2 - 1; i >= 0; i--) {

			int sum = (s1[i] - '0') + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;
		}
		if (carry) {
			result.push_back(carry + '0');
		}
	}
	reverse(result.begin(), result.end());
	return result;
}
string biginteger::subtraction(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	string s3 = "";
	int borrow = 0;
	int sub;
	int mark = 0;
	if (s1 == s2)
		return "0";
	if (l1 == l2) {
		for (int i = 0; i < l1; i++) {
			if (s2[i] > s1[i]) {
				mark = 1;
				break;
			}
			else if (s1[i] > s2[i]) {
				mark = 2;
				break;
			}
		}
	}
	if (l2 > l1 || mark == 1) {
		int j = l2 - 1;
		for (int i = l1 - 1; i >= 0; i--) {
			sub = ((s2[j] - '0') - (s1[i] - '0') - borrow);

			if (sub < 0) {
				sub += 10;
				borrow = 1;
			}
			else {
				borrow = 0;
			}
			j--;
			s3.push_back(sub + '0');
		}
		for (int i = l2 - l1 - 1; i >= 0; i--) {
			int sub = ((s2[i] - '0') - borrow);
			if (sub < 0)
			{
				sub = sub + 10;
				borrow = 1;
			}
			else
				borrow = 0;

			if (i > 0)
				s3.push_back(sub + '0');
			else if (sub != 0)
				s3.push_back(sub + '0');
		}
	}
	else {
		int j = l1 - 1;
		for (int i = l2 - 1; i >= 0; i--) {
			sub = ((s1[j] - '0') - (s2[i] - '0') - borrow);

			if (sub < 0) {
				sub += 10;
				borrow = 1;
			}
			else
				borrow = 0;
			j--;
			s3.push_back(sub + '0');
		}
		for (int i = l1 - l2 - 1; i >= 0; i--) {
			int sub = ((s1[i] - '0') - borrow);
			if (sub < 0)
			{
				sub = sub + 10;
				borrow = 1;
			}
			else
				borrow = 0;
			if (i > 0)
				s3.push_back(sub + '0');
			else if (sub != 0)
				s3.push_back(sub + '0');
		}
	}
	reverse(s3.begin(), s3.end());
	s3.erase(0, s3.find_first_not_of('0'));
	return s3;
}
string biginteger::multiplication(string s1, string s2)
{
	string result = {};
	int l1 = s1.length();
	int l2 = s2.length();
	int n = l1, mid;
	if (l2 >= l1)
	{
		n = l2;
		for (int i = l2 - l1; i > 0; i--)
		{
			s1 = '0' + s1;
		}
	}
	else
	{
		n = l1;
		for (int i = l1 - l2; i > 0; i--)
		{
			s2 = '0' + s2;
		}
	}
	mid = (n / 2) + (n % 2);
	if (n == 0)
	{
		return "0";
	}
	if (n == 1)
	{
		string resul = {};
		int mul = (s1[0] - '0') * (s2[0] - '0');
		if (mul == 0)
		{
			return "0";
		}
		resul = to_string(mul);
		return resul;
	}
	string a = s1.substr(0, mid);      /////str1=a--b
	string b = s1.substr(mid, n);
	string c = s2.substr(0, mid);    ////str2=c--d
	string d = s2.substr(mid, n);
	string eq1 = multiplication(b, d);
	string eq2 = multiplication(addition(a, b), addition(c, d));
	string eq3 = multiplication(a, c);
	string eq4 = subtraction(eq2, addition(eq1, eq3));
	for (int i = 0; i < n - n % 2; i++)
	{
		if (i < mid - n % 2)
		{

			eq4.push_back('0');
		}
		eq3.push_back('0');
	}
	result = addition(eq1, addition(eq4, eq3));
	result.erase(0, result.find_first_not_of('0'));
	return result;
}
bool biginteger::isgreater(string g, string s)
{
	int l1 = g.length();
	int l2 = s.length();
	if (l1 > l2)
	{
		return true;
	}
	else if (l2 > l1)
	{
		return false;
	}
	else
	{
		if (s == g)
		{
			return false;
		}
		for (int i = 0; i < l1; i++) 
		{
			if (g[i] > s[i]) {
				return true;
			}
			else if (s[i] > g[i]) {
				return false;
			}
		}
	}
}
dstract biginteger::div(string a, string b)
{
	dstract d;
	if (isgreater(b, a))
	{
		d.q = "0";
		d.r = a;
		return d;
	}
	d = div(a, addition(b, b));
	d.q = addition(d.q, d.q);
	if (isgreater(b, d.r))
	{
		return d;
	}
	else
	{
		d.q = addition(d.q, "1");
		d.r = subtraction(d.r, b);
		return d;
	}
}
string biginteger::divide(string a, string b)
{
	dstract d;
	d = div(a, b);
	return d.q;
}
string biginteger::mod(string a, string b)
{
	dstract d;
	d = div(a, b);
	return d.r;
}
string biginteger::mod_of_power(string B, string p, string m)
{
	return mod(mod_of_power_helper(B,p,m),m);
}
string biginteger::mod_of_power_helper(string B, string p, string m)
{
	string result = "0";
	string q1, q2;
	if (p == "0")
		return "1";
	else if (mod(p,"2") == "0")
	{
		q1 = mod_of_power_helper(B, divide(p, "2"), m);
		q2 = mod(q1, m);
		result = multiplication(q2,q2);
		
		return result;
	}
	else
	{
		q1 = mod_of_power_helper(B, divide(p, "2"), m);
		q2 = mod(q1, m);
		result = multiplication(B, multiplication(q2, q2));
		//q = q % m;
		return result;
	}
}
string biginteger::Encrypt(string M, string e, string n)
{
	return mod_of_power(M,e,n);
}
string biginteger::decrypt(string E, string d, string n)
{
	return mod_of_power(E, d, n);
}
biginteger::~biginteger()
{
}