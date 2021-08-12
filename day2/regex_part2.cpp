#include <iostream>
#include <fstream>
#include <regex>
#include <cstring>
#include <unordered_map>


using namespace std;

int main()
{
	ifstream infile;
	infile.open("input.txt");

	string password;
	int num_valid = 0;

	while(true)
	{
		getline(infile, password);
		if (infile.eof())
			break;

		cout << "Processing : " << password << " ... ";
		regex re("(.*)-(.*) (.*): (.*)");
	
		smatch match;
		int pos1,pos2;
		char c;
		string str;

		unordered_map<char, int> mymap;

		if(regex_search(password, match, re) == true)
		{
			pos1 = atoi(match.str(1).c_str());
		        pos2 = atoi(match.str(2).c_str());
		       	c = match.str(3).c_str()[0];
			str = match.str(4);
	
		
			if((str.c_str()[pos1-1]==c) ^ (str.c_str()[pos2-1]==c))
			{
				cout << "Valid " << str.c_str()[pos1-1] << " " << str.c_str()[pos2-1];
				num_valid++;
			}
			else
			{
				cout << "Invalid ";
			}
			cout << endl;
		}

	}
	cout << num_valid << endl;

	return 0;
}
