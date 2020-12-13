#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("input.txt");

	vector<int> year;
	unordered_map<int,int>hashyear;

	int temp;
	int target = 2020;
	int hash;


	while(true)
	{
		infile >> temp;
		if(infile.eof())
			break;

		year.push_back(temp);
	}

	for(int i = 0; i < year.size(); i++)
	{
		target = 2020 - year[i];

		for(int j = i + 1; j < year.size(); j++)
		{
			hash = target - year[j];
			unordered_map<int,int>::const_iterator complement = hashyear.find(hash);
			if (complement == hashyear.end())
			{
				hashyear.insert(make_pair(year[j],hash));
			}
			else
			{
				cout << hash * year[j] * year[i] << endl;
				exit(0);
			}
		}		

		hashyear.clear();
	}

	return 0;
}
