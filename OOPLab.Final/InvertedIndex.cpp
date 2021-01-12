#include"InvertedIndex.h"

void InvertedIndex::addfile(string filename)
{
	ifstream fin;
	fin.open(filename+".txt", ios::in);

	if (!fin)
	{
		cout << "File Not Found\n";
		return;
	}

	string line, word;
	int line_number = 0, word_number = 0;
	while (getline(fin, line))
	{
		line_number++;
		word_number = 0;
		stringstream s(line);
		while (s >> word)
		{
			word_number++;
			word_position obj;
			string name = filename.substr(4, 1);
			obj.file_name = name;
			obj.line = line_number;
			obj.index = word_number;
			Dictionary[word].push_back(obj);
		}
	}
	fin.close();
}


vector<int> InvertedIndex::search(string word)
{
	vector<int> f;

	if (Dictionary.find(word) == Dictionary.end())
	{
		cout << "No instance exist\n";
		return f;
	}
	int time = 1;
	bool visited = false;
	int size = (int)Dictionary[word].size();
	for (int counter = 0; counter < size; counter++)
	{
		int origin = stoi(Dictionary[word][counter].file_name);
		if (!visited)
		{
			f.push_back(origin);
			visited = true;
		}
		int origin2;
		if (counter < size - 1)
			origin2 = stoi(Dictionary[word][counter + 1].file_name);
		else
			origin2 = -1;
		if (origin2 != -1 && origin == origin2)
		{
			time++;
		}
		else
		{
			f.push_back(time);
			visited = false;
			time = 1;
		}
	}
	return f;
}