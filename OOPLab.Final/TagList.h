#pragma once
#ifndef _H_TagList_H_
#define _H_TagList_H_
#include"Tag.h"

class TagList
{
public:
	bool Check(Tag tag, int &index);
	vector<Tag> taglist();
	void LoadTagList();
	void SaveTagList();
	void AddNewTag(Tag tag);
	void RemoveTag(Tag tag);
	~TagList() {};

private:
	vector<Tag> _taglist;
};


#endif // !_H_TagList_H_
