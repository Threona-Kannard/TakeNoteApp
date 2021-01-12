#pragma once
#ifndef _H_Note_H_
#define _H_Note_H_
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
class Note
{
private:
	vector<string> _tag;
	string _content;
	string _name;
public:
	friend class Tag;
	string content();
	vector<string> tag();
	string name();
	Note(string name, vector<string> tag);
	Note(string name, vector<string> tag,string content);
	void setNoTag();
	void RemoveTag(string removetagname);
	void LoadNote();
	void SaveNote();
	~Note() {};

};


#endif // !_H_Note_H_
