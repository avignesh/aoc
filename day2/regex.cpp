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

		//cout << "Processing: " << password;
		regex re("(.*)-(.*) (.*): (.*)");
	
		smatch match;
		int min,max;
		char c;
		string str;

		unordered_map<char, int> mymap;

		if(regex_search(password, match, re) == true)
		{
			min = atoi(match.str(1).c_str());
		       	max = atoi(match.str(2).c_str());
		       	c = match.str(3).c_str()[0];
			str = match.str(4);
	
			for(char i : str)
			{
				mymap[i]++;
			}
	
			if(mymap[c] >= min && mymap[c] <= max)
				num_valid++;
		}

	}
	cout << num_valid << endl;

	return 0;
}
