#pragma once
#ifndef _H_Tag_H_
#define _H_Tag_H_

#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include"Note.h"
using namespace std;

class Tag
{
private:
	string _nameTag;
	vector<Note> _noteList;
public:
	Tag(string nameTag);
	void addnewNote(Note newNote);
	void removeNote(Note removeNote);
	void removeATag(string removeNameTag,string nameNote);
	string nameTag();
	vector<Note> noteList();
	void LoadTag();
	void SaveTag();
	~Tag() {};
};
#endif // !_H_Tag_H_

