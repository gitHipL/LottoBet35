#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  fstream file("Test.txt", ios::in | ios::out);
  char data[500];
  file.seekp(0);
  file << "Hey";
  // file.getline(data, 500, ':');
  // cout << data;
  //  data = "olleh";
  //  file.seekp(0);
  //  file << data;
  file.close();
}

/*
Convert string to integer
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string str = "100"; // a variable of string data type

  int num; // a variable of int data type

  // using the stringstream class to insert a string and
  // extract an int
  stringstream ss;
  ss << str;
  ss >> num;

  cout << "The string value is " << str << endl;
  cout << "The integer representation of the string is " << num << endl;
}*/