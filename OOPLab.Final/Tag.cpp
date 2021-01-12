#include"Tag.h"

void Tag::addnewNote(Note newNote)
{
	_noteList.push_back(newNote);
}
void Tag::removeNote(Note removeNote)
{
	int index;
	for (int i = 0; i < _noteList.size(); i++)
	{
		if (_noteList[i]._name == removeNote._name)
		{
			index = i;
			break;
		}
	}
	_noteList.erase(_noteList.begin() + index);
}
void Tag::removeATag(string removeNameTag, string nameNote)
{
	for (auto i = _noteList.begin(); i != _noteList.end(); i++)
	{
		if ((*i)._name == nameNote)
		{
			(*i).RemoveTag(removeNameTag);
			int l = (*i).tag().size();
			if (l == 0)
			{
				(*i).setNoTag();
			}
			break;
		}
	}
}
Tag::Tag(string nameTag)
{
	_nameTag = nameTag;
}
string Tag::nameTag()
{
	return _nameTag;
}
vector<Note> Tag::noteList()
{
	return _noteList;
}
void Tag::LoadTag()
{
	ifstream fin;
	fin.open(_nameTag+".txt", ios::in);
	if (fin.is_open())
	{
		int n;
		string seperator = ",";
		fin >> n;
		fin.ignore(1000, '\n');
		for (int i = 0; i < n; i++)
		{
			string name, taglist;
			getline(fin, name, '\n');
			getline(fin, taglist, '\n');
			vector<string> tags;
			int startPos = 0;
			size_t foundPos = taglist.find(seperator, startPos);
			while (foundPos != string::npos)
			{
				int count = foundPos - startPos;
				string tag = taglist.substr(startPos, count);
				tags.push_back(tag);
				startPos = foundPos + seperator.length();
				foundPos = taglist.find(seperator, startPos);
			}
			int count = foundPos - startPos;
			string tag = taglist.substr(startPos, count);
			tags.push_back(tag);
			Note cur(name, tags);
			cur.LoadNote();
			_noteList.push_back(cur);
		}
		fin.close();
	}
	else
	{
		cout << "Can't open text "<<_nameTag<<" of tag.\n";
	}
}
void Tag::SaveTag()
{
	ofstream fout;
	fout.open(_nameTag+".txt", ios::out);
	if (fout.is_open())
	{
		fout << _noteList.size() << endl;
		for (auto i = _noteList.begin(); i != _noteList.end(); i++)
		{
			fout << (*i)._name << endl;
			vector<string> cur = (*i)._tag;
			for (auto j = cur.begin(); j != cur.end() - 1; j++)
			{
				fout << (*j) << ",";
			}
			fout << cur.back() << endl;
		}
		fout.close();
	}
	else
	{
		cout << "Can't open text NoteList.\n";
	}
}
