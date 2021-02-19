#include<iostream>
#include"biginteger.h"
#include<string>
#include<fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;
void main()
{
biginteger k;
int choice;
cout << "1-sample test cases."<<endl;
cout << "2-complete test cases." << endl;
cin >> choice;
	auto start = high_resolution_clock::now();
fstream input;
fstream output;
if (choice == 1)
{
output.open("output_sample.text", ios::app);
input.open("SampleRSA.txt");
}
else
{
output.open("output_complete.text", ios::app);
input.open("TestRSA.txt");
}
string n;
getline(input,n);
int num = stoi(n);
string B, p, m,s_eord,result="0";
int eord;
for (int i = 0; i <num; i++)
{
getline(input, n);
getline(input, p);
getline(input, m);
getline(input, s_eord);
eord = stoi(s_eord);
if (eord== 0)
{
auto start = high_resolution_clock::now();
result = k.Encrypt(m, p, n);
output << result<<"\n";
auto stop = high_resolution_clock::now();
double duration_m = double(duration_cast<milliseconds>(stop - start).count());
duration_m = duration_m / 1000;
output << "time :"<<duration_m << " sec \n";
}
else
{
auto start = high_resolution_clock::now();
result = k.decrypt(m, p, n);
output << result<<"\n";
auto stop = high_resolution_clock::now();
double duration_m = double(duration_cast<milliseconds>(stop - start).count());
duration_m = duration_m / 1000;
output << "time :"<<duration_m << " sec \n";
}
}
input.close();
output.close();
auto stop = high_resolution_clock::now();
double duration_m = double(duration_cast<milliseconds>(stop - start).count());
duration_m = duration_m / 1000;
cout << duration_m <<" S "<<endl;
system("pause");
}
