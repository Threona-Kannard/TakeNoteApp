#include"TagList.h"

bool TagList::Check(Tag tag,int &index)
{
	bool check = true;
	index = -1;
	for (int i = 0; i < _taglist.size(); i++)
	{
		if (_taglist[i].nameTag() == tag.nameTag()) 
		{
			check = false;
			index = i;
		}
	}
	return check;
}
vector<Tag> TagList::taglist()
{
	return _taglist;
}
void TagList::AddNewTag(Tag tag)
{
	int index;
	bool check = Check(tag,index);
	if (check)
	{
		_taglist.push_back(tag);
	}
	else
	{
		Note cur = tag.noteList().back();
		_taglist[index].addnewNote(cur);
	}
}
void TagList::RemoveTag(Tag tag)
{
	int index;
	int l = _taglist.size();
	for (int i = 0; i < l; i++)
	{
		if (_taglist[i].nameTag() == tag.nameTag())
		{
			index = i;
			break;
		}
	}
	_taglist.erase(_taglist.begin() + index);
}
void TagList::LoadTagList()
{
	ifstream fin;
	fin.open("TagList.txt", ios::in);
	if (fin.is_open())
	{
		int n;
		fin >> n;
		fin.ignore(1000, '\n');
		for (int i = 0; i < n; i++)
		{
			string name;
			getline(fin, name, '\n');
			Tag cur(name);
			cur.LoadTag();
			_taglist.push_back(cur);
		}
		fin.close();
	}
	else
	{
		cout << "Can't open text TagList.\n";
	}
}
void TagList::SaveTagList()
{
	ofstream fout;
	fout.open("TagList.txt", ios::out);
	if (fout.is_open())
	{
		fout << _taglist.size() << endl;
		for (auto i = _taglist.begin(); i != _taglist.end(); i++)
		{
			fout << (*i).nameTag() << endl;
		}
		fout.close();
	}
	else
	{
		cout << "Can't open text TagList.\n";
	}
}