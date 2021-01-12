#include"Note.h"

string Note::content()
{
	return _content;
}
string Note::name()
{
	return _name;
}
vector<string> Note::tag()
{
	return _tag;
}
Note::Note(string name, vector<string> tag)
{
	_name = name;
	_tag = tag;
}
Note::Note(string name, vector<string> tag, string content)
{
	_name = name;
	_tag = tag;
	_content = content;
}
void Note::setNoTag()
{
	vector<string> tag;
	tag.push_back("NoTag");
	_tag = tag;
}
void Note::RemoveTag(string removetagname)
{
	int l = _tag.size(),index;
	for (int i = 0; i < l; i++)
	{
		if (_tag[i] == removetagname)index = i;
	}
	_tag.erase(_tag.begin() + index);
}
void Note::LoadNote()
{
	ifstream fin;
	fin.open(_name + ".txt", ios::in);
	if (fin.is_open())
	{
		getline(fin, _content, '\n');
		fin.close();
	}
	else {
		cout << "Can't open file note " << _name << " to load.\n";
	}
}
void Note::SaveNote()
{
	ofstream fout;
	fout.open(_name + ".txt", ios::out);
	if (fout.is_open())
	{
		fout << _content << endl;
		fout.close();
	}
	else
	{
		cout << "Can't open file note " << _name << " to save.\n";
	}
}