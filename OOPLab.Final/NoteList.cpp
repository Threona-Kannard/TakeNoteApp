#include"NoteList.h"

vector<Note>NoteList::noteList()
{
	return _noteList;
}
int NoteList::makeID()
{
	int ID = ++_mostID;
	return ID;
}
void NoteList::mostIDUpdate(string removeId)
{
	if (_mostID == stoi(removeId))
	{
		_mostID--;
	}
}
void NoteList::setNoTag(int index)
{
	_noteList[index].setNoTag();
}
void NoteList::LoadNoteList()
{
	ifstream fin;
	fin.open("NoteList.txt", ios::in);
	if (fin.is_open())
	{
		int n;
		string seperator=",";
		fin >> n;
		fin >> _mostID;
		fin.ignore(1000, '\n');
		for (int i = 0; i < n; i++)
		{
			string name,taglist;
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
		cout << "Can't open text NoteList.\n";
	}
}
void NoteList::SaveNoteList()
{
	ofstream fout;
	fout.open("NoteList.txt", ios::out);
	if (fout.is_open())
	{
		fout << _noteList.size()<<endl;
		fout << _mostID << endl;
		for (auto i = _noteList.begin(); i != _noteList.end(); i++)
		{
			fout << (*i).name() << endl;
			vector<string> cur = (*i).tag();
			for (auto j = cur.begin(); j != cur.end() - 1; j++)
			{
				fout << (*j) << ",";
			}
			fout << cur.back()<<endl;
		}
		fout.close();
	}
	else
	{
		cout << "Can't open text NoteList.\n";
	}
}
void NoteList::AddNewNote(string contentNewNote, vector<string> tagNewNote)
{
	int ID = makeID();
	stringstream ss;
	ss << ID;
	string nameNote = "File" + ss.str();
	Note newNote(nameNote, tagNewNote,contentNewNote);
	newNote.SaveNote();
	_noteList.push_back(newNote);
}
void NoteList::RemoveANote(int indexRemoveNote)
{
	_noteList.erase(_noteList.begin() + indexRemoveNote);
}
void NoteList::RemoveAllNoteHaveTag(string nameTag, vector<Note> notelistOfTag, vector<Note> &notelistOfRemainTag)
{
	for (auto i = notelistOfTag.begin(); i != notelistOfTag.end(); i++)
	{
		int length = _noteList.size();
		for (int j=0;j<length;j++)
		{
			if (_noteList[j].name() == (*i).name())
			{
				_noteList[j].RemoveTag(nameTag);
				int l = _noteList[j].tag().size();
				if (l == 0)
				{
					_noteList[j].setNoTag();
				}
				notelistOfRemainTag.push_back(_noteList[j]);
				break;
			}
		}
	}
}
void NoteList::RemoveTag(int index, vector<string> &remainTagList, string nameTag)
{
	_noteList[index].RemoveTag(nameTag);
	remainTagList = _noteList[index].tag();
}