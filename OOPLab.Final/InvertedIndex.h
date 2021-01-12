#pragma once
#ifndef _H_InvertedIndex_H_
#define _H_InvertedIndex_H_
#include<map>
#include"Note.h"

struct word_position
{
	string file_name;
	int line;
	int index;

};
class InvertedIndex
{
	map<string, vector<word_position> > Dictionary;
public:

	void addfile(string filename);
	vector<int> search(string word);
};
#endif // !_H_InvertedIndex_H_

