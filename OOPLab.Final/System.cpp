#include"System.h"

Note System::listNote(int &index)
{
	NoteList list;
	list.LoadNoteList();
	vector<Note> notelist = list.noteList();
	int choice = 12;//Text color of choice
	int normalcolor = 7;
	TextColor(choice);
	gotoXY(56, 4);
	cout << notelist[0].name();
	TextColor(normalcolor);
	int lengthNoteList = notelist.size();
	for (int i = 1; i < lengthNoteList; i++)
	{
		gotoXY(56, 4 + 4 * i);
		cout << notelist[i].name();
	}
	while (1) {
		if (_kbhit())
		{
			int pointpos = 4 ;
			gotoXY(56, pointpos);
			char ch = _getch();
			while (ch != 13) {
				//Choose a feature and highlight it
				if (ch == key_Up && pointpos != 4)
				{
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << notelist[(pointpos - 4) / 4].name();
					pointpos -= 4;
					gotoXY(56, pointpos);
					TextColor(choice); cout << notelist[(pointpos - 4) / 4].name();
				}
				else if (ch == key_Up && pointpos == 4)
				{
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << notelist[(pointpos - 4) / 4].name();
					pointpos = 4 + 4 * (lengthNoteList - 1);
					gotoXY(56, pointpos);
					TextColor(choice); cout << notelist[(pointpos - 4) / 4].name();
				}
				else if (ch == key_Down && pointpos != 4 + 4 * (lengthNoteList - 1)) {
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << notelist[(pointpos - 4) / 4].name();
					pointpos += 4;
					gotoXY(56, pointpos);
					TextColor(choice); cout << notelist[(pointpos - 4) / 4].name();
				}
				else if (ch == key_Down && pointpos == 4+4*(lengthNoteList-1))
				{
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << notelist[(pointpos - 4) / 4].name();
					pointpos = 4;
					gotoXY(56, pointpos);
					TextColor(choice); cout << notelist[(pointpos - 4) / 4].name();
				}
				ch = _getch();
			}
			if (ch == 13) {
				TextColor(normalcolor);
				index = (pointpos - 4) / 4;
				return notelist[(pointpos - 4) / 4];
			}
		}
	}
}

int System::listTag(vector<Tag> taglist)
{
	int choice = 13;//Text color of choice
	int normalcolor = 7;
	TextColor(choice);
	gotoXY(56, 4);
	cout << taglist[0].nameTag();
	TextColor(normalcolor);
	int lengthNoteList = taglist.size();
	for (int i = 1; i < lengthNoteList; i++)
	{
		gotoXY(56, 4 + 4 * i);
		cout << taglist[i].nameTag();
	}
	while (1) {
		if (_kbhit())
		{
			int pointpos = 4;
			gotoXY(56, pointpos);
			char ch = _getch();
			while (ch != 13) {
				//Choose a feature and highlight it
				if (ch == key_Up && pointpos != 4)
				{
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << taglist[(pointpos - 4) / 4].nameTag();
					pointpos -= 4;
					gotoXY(56, pointpos);
					TextColor(choice); cout << taglist[(pointpos - 4) / 4].nameTag();
				}
				else if (ch == key_Up && pointpos == 4)
				{
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << taglist[(pointpos - 4) / 4].nameTag();
					pointpos = 4 + 4 * (lengthNoteList - 1);
					gotoXY(56, pointpos);
					TextColor(choice); cout << taglist[(pointpos - 4) / 4].nameTag();
				}
				else if (ch == key_Down && pointpos != 4 + 4 * (lengthNoteList - 1)) {
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << taglist[(pointpos - 4) / 4].nameTag();
					pointpos += 4;
					gotoXY(56, pointpos);
					TextColor(choice); cout << taglist[(pointpos - 4) / 4].nameTag();
				}
				else if (ch == key_Down && pointpos == 4 + 4 * (lengthNoteList - 1))
				{
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << taglist[(pointpos - 4) / 4].nameTag();
					pointpos = 4;
					gotoXY(56, pointpos);
					TextColor(choice); cout << taglist[(pointpos - 4) / 4].nameTag();
				}
				ch = _getch();
			}
			if (ch == 13) {
				TextColor(normalcolor);
				return (pointpos - 4) / 4;
			}
		}
	}
}

void System::MenuDisplay()
{
	int choice = 10;//Highlight choosen path
	int normalcolor = 7;
	vector<string>Menu;
	Menu.push_back("Note"); Menu.push_back("Tag"); Menu.push_back("Exit");
	TextColor(choice); 
	gotoXY(56, 4); 
	cout << Menu[0];
	TextColor(normalcolor); 
	gotoXY(56, 6); 
	cout << Menu[1];
	gotoXY(56, 8); 
	cout << Menu[2];
	while (1) {
		if (_kbhit())
		{
			int pointpos = 4;
			gotoXY(56, pointpos);
			char ch = _getch();
			while (ch != 13) {
				//Choose a feature and highlight it
				if (ch == key_Up && pointpos != 4)
				{
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos -= 2;
					gotoXY(56, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Up && pointpos == 4)
				{
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos = 8;
					gotoXY(56, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Down && pointpos != 8) {
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos += 2;
					gotoXY(56, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Down && pointpos == 8) {
					gotoXY(56, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos = 4;
					gotoXY(56, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				ch = _getch();
			}
			if (ch == 13) {
				TextColor(normalcolor);
				if (pointpos == 4)
				{
					clrscr();
					return MenuNote();//Note
				}
				if (pointpos == 6)
				{
					return MenuTag();//Tag
				}
				if (pointpos == 8) // Exit
				{
					clrscr();
					TextColor(10);
					gotoXY(46, 8);
					cout << "Thanks for using this program.\n";
					TextColor(7);
					return;
				}
			}
		}
	}
}

void System::MenuNote()
{
	int choice = 14;//Text color of Choice
	int normalcolor = 7;
	vector<string>Menu;
	Menu.push_back("Search KeyWord");
	Menu.push_back("Add A New Note"); 
	Menu.push_back("Remove A Note"); 
	Menu.push_back("Remove A Tag In Note"); 
	Menu.push_back("View All Note"); 
	Menu.push_back("Return Menu");
	TextColor(choice);
	gotoXY(52, 4);
	cout << Menu[0];
	TextColor(normalcolor);
	gotoXY(52, 6);
	cout << Menu[1];
	gotoXY(52, 8);
	cout << Menu[2];
	gotoXY(52, 10);
	cout << Menu[3];
	gotoXY(52, 12);
	cout << Menu[4];
	gotoXY(52, 14);
	cout << Menu[5];
	while (1) {
		if (_kbhit())
		{
			int pointpos = 4;
			gotoXY(52, pointpos);
			char ch = _getch();
			while (ch != 13) {
				//Choose a feature and highlight it
				if (ch == key_Up && pointpos != 4)
				{
					gotoXY(52, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos -= 2;
					gotoXY(52, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Up && pointpos == 4)
				{
					gotoXY(52, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos = 12 ;
					gotoXY(52, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Down && pointpos != 14) {
					gotoXY(52, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos += 2;
					gotoXY(52, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Down && pointpos == 14)
				{
					gotoXY(52, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos = 4;
					gotoXY(52, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				ch = _getch();
			}
			if (ch == 13) {
				TextColor(normalcolor);
				if (pointpos == 4)//Search for keyword
				{
					clrscr();
					gotoXY(40, 6);
					cout << "Please enter keyword : ";
					string keyword;
					getline(cin, keyword, '\n');
					clrscr();
					gotoXY(48, 2);
					cout << "List of Note has keyword ";
					return SearchKeyWord(keyword);
				}
				if (pointpos == 6)
				{
					clrscr();
					return AddANote();//Add A Note
				}
				if (pointpos == 8)
				{
					clrscr();
					return RemoveANote();//Remove A Note
				}
				if (pointpos == 10)//Remove A Tag
				{
					clrscr();
					return RemoveTagInNote();
				}
				if (pointpos == 12)
				{
					return DisplayAllNote();
				}
				if (pointpos == 14)
				{
					clrscr();
					return MenuDisplay();//Return Menu
				}
			}
		}
	}
}

void System::MenuTag()
{
	int choice = 9;//Text color of choice
	int normalcolor = 7;
	vector<string>Menu;
	Menu.push_back("Remove A Tag");
	Menu.push_back("View All Tag");
	Menu.push_back("Return Menu");
	TextColor(choice);
	gotoXY(52, 4);
	cout << Menu[0];
	TextColor(normalcolor);
	gotoXY(52, 6);
	cout << Menu[1];
	gotoXY(52, 8);
	cout << Menu[2];
	while (1) {
		if (_kbhit())
		{
			int pointpos = 4;
			gotoXY(52, pointpos);
			char ch = _getch();
			while (ch != 13) {
				//Choose a feature and highlight it
				if (ch == key_Up && pointpos != 4)
				{
					gotoXY(52, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos -= 2;
					gotoXY(52, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Up && pointpos == 4)
				{
					gotoXY(52, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos = 12;
					gotoXY(52, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Down && pointpos != 8) {
					gotoXY(52, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos += 2;
					gotoXY(52, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				else if (ch == key_Down && pointpos == 8)
				{
					gotoXY(52, pointpos); TextColor(normalcolor);
					cout << Menu[(pointpos - 4) / 2];
					pointpos = 4;
					gotoXY(52, pointpos);
					TextColor(choice); cout << Menu[(pointpos - 4) / 2];
				}
				ch = _getch();
			}
			if (ch == 13) {
				TextColor(normalcolor);
				if (pointpos == 4)//Remove A Tag
				{
					return RemoveATag();
				}
				if (pointpos == 6)//View All Tag
				{
					return DisplayAllTag();
				}
				if (pointpos == 8)
				{
					clrscr();
					return MenuDisplay();//Return Menu
				}
			}
		}
	}
}

void System::ViewAllNote(vector<Note> notelist)
{
	int lengthOfNoteList = notelist.size();
	for (int i=0;i<lengthOfNoteList;i++)
	{
		DrawBorder(35, 4 + 8 * i, 50, 6, true);
		TextColor(8);
		gotoXY(37, 5 + 8 * i); cout << "ID : "<<notelist[i].name();
		gotoXY(37, 6 + 8 * i);
		vector<string> taglist= notelist[i].tag();
		int sizeTagList = taglist.size();
		if (sizeTagList > 3)
		{
			cout <<"Tag : "<< taglist[0]<<","<<taglist[1]<<","<<taglist[2];
			gotoXY(37, 7 + 8 * i);
			cout << taglist[3];
			for (int j = 4; j < sizeTagList; j++)
			{
				cout << "," << taglist[j];
			}
		}
		else
		{
			if (sizeTagList == 1 && taglist[0] == "NoTag")
			{
				cout << "Tag :";
			}
			else
			{
				cout << "Tag : " << taglist[0];
				for (int j = 1; j < sizeTagList; j++)
				{
					cout << "," << taglist[j];
				}
			}
		}
		TextColor(7);
		string content = notelist[i].content();
		int l = content.size();
		if (l >= 80)
		{
			content = content.substr(0, 76);
			content += "...";
		}
		vector<string> line;
		int check = (l / 40) + 1;
		int position = 40;
		while (check != 1)
		{
			while (content[position] != ' ')
			{
				position++;
			}
			line.push_back(content.substr(0, position));
			content = content.substr(position + 1, l - position - 1);
			int remainLength = content.size();
			position = 40;
			check = (remainLength / 40) + 1;
		}
		line.push_back(content);
		int LengthOfLine = line.size();
		for (int j = 0; j < LengthOfLine; j++)
		{
			gotoXY(37, 8 + j + 8 * i);
			cout << line[j];
		}
	}
}

void System::ViewANote(Note note)
{
	TextColor(11);
	gotoXY(37, 5); cout << "ID : " << note.name();
	gotoXY(37, 6);
	vector<string> taglist = note.tag();
	int sizeTagList = taglist.size();
	if (sizeTagList > 3)
	{
		cout << "Tag : " << taglist[0] << "," << taglist[1] << "," << taglist[2];
		gotoXY(37, 7);
		cout << taglist[3];
		for (int j = 4; j < sizeTagList; j++)
		{
			cout << "," << taglist[j];
		}
	}
	else
	{
		if (sizeTagList == 1 && taglist[0] == "NoTag")
		{
			cout << "Tag :";
		}
		else
		{
			cout << "Tag : " << taglist[0];
			for (int j = 1; j < sizeTagList; j++)
			{
				cout << "," << taglist[j];
			}
		}
	}
	TextColor(15);
	string content = note.content();
	int l = content.size();
	vector<string> line;
	int check = (l / 40) + 1;
	int position = 40;
	while (check != 1)
	{
		while (content[position] != ' ')
		{
			position++;
		}
		line.push_back(content.substr(0, position));
		content = content.substr(position + 1, l - position - 1);
		int remainLength = content.size();
		position = 40;
		check = (remainLength / 40) + 1;
	}
	line.push_back(content);
	int LengthOfLine = line.size();
	for (int j = 0; j < LengthOfLine; j++)
	{
		gotoXY(37, 8 + j);
		cout << line[j];
	}
	DrawBorder(35, 4, 50, 5 + (l / 40), true);
}

void System::RemoveTagInNote()
{
	int indexNote;
	clrscr();
	gotoXY(40, 2);
	cout << "Please choose the ID of Note you want to remove a Tag : ";
	Note note = listNote(indexNote);
	vector<string> taglist = note.tag();
	vector<Tag> ListTag;
	for (auto i = taglist.begin(); i != taglist.end(); i++)
	{
		Tag cur(*i);
		cur.LoadTag();
		ListTag.push_back(cur);
	}
	clrscr();
	int LengthOfTaglist = taglist.size();
	if (LengthOfTaglist == 1 && taglist[0] == "NoTag")
	{
		gotoXY(40, 10);
		TextColor(10);
		cout << "The Note don't have any Tag.";
	}
	else {
		gotoXY(40, 2);
		cout << "Please choose the Tag of Note you want to remove : ";
		int indexRemoveTag;
		indexRemoveTag = listTag(ListTag);
		Tag removeTag = ListTag[indexRemoveTag];
		removeTag.removeNote(note);
		removeTag.SaveTag();
		int length = removeTag.noteList().size();
		if (length == 0)
		{
			TagList tl;
			tl.LoadTagList();
			tl.RemoveTag(removeTag);
			tl.SaveTagList();
		}
		vector<string> remainTagList;
		NoteList l;
		l.LoadNoteList();
		l.RemoveTag(indexNote, remainTagList, taglist[indexRemoveTag]);
		int remainTaglistLength = remainTagList.size();
		if (remainTaglistLength == 0)
		{
			l.setNoTag(indexNote);
		}
		l.SaveNoteList();
		for (auto i = remainTagList.begin(); i != remainTagList.end(); i++)
		{
			Tag cur(*i);
			cur.LoadTag();
			cur.removeATag(taglist[indexRemoveTag], note.name());
			cur.SaveTag();
		}
		clrscr();
		gotoXY(40, 10);
		TextColor(10);
		cout << "Remove a Tag completely.";
	}
	gotoXY(40, 12);
	cout << "Please press the Esc to return back.";
	TextColor(7);
	char ch = _getch();
	while (ch != 27)
	{
		ch = _getch();
	}
	if (ch == 27)
	{
		clrscr();
		return MenuNote();
	}
}

void System::RemoveATag()
{
	clrscr();
	TagList tl;
	tl.LoadTagList();
	vector<Tag> taglist = tl.taglist();
	gotoXY(40, 2);
	cout << "Please choose the Tag of Note you want to remove : ";
	int indexTag = listTag(taglist);
	clrscr();
	Tag a = taglist[indexTag];
	tl.RemoveTag(a);
	tl.SaveTagList();
	vector<Note> notelistOfTag = a.noteList();
	vector<Note> notelistOfRemovedTag;
	NoteList l;
	l.LoadNoteList();
	l.RemoveAllNoteHaveTag(a.nameTag(), notelistOfTag, notelistOfRemovedTag);
	l.SaveNoteList();
	a.SaveTag();
	for (auto i = notelistOfRemovedTag.begin(); i != notelistOfRemovedTag.end(); i++)
	{
		vector<string> tagList = (*i).tag();
		for (auto j = tagList.begin(); j != tagList.end(); j++)
		{
			if ((*j) != "NoTag")
			{
				Tag cur(*j);
				cur.LoadTag();
				cur.removeATag(a.nameTag(), (*i).name());
				cur.SaveTag();
			}
		}
	}
	gotoXY(40, 10);
	TextColor(10);
	cout << "Remove A Tag completely.";
	gotoXY(40, 12);
	cout << "Please press the Esc to return back.";
	TextColor(7);
	char ch = _getch();
	while (ch != 27)
	{
		ch = _getch();
	}
	if (ch == 27)
	{
		clrscr();
		return MenuTag();
	}
}

void System::RemoveANote()
{
	int indexRemoveNote;
	gotoXY(40, 2);
	cout << "Please choose the ID of Note you want to remove : ";
	Note removeNote = listNote(indexRemoveNote);
	NoteList l;
	l.LoadNoteList();
	string removeId = removeNote.name().substr(4, 1);
	l.mostIDUpdate(removeId);
	vector<string> now = removeNote.tag();
	l.RemoveANote(indexRemoveNote);
	for (auto i = now.begin(); i != now.end(); i++)
	{
		if ((*i) != "NoTag")
		{
			Tag cur(*i);
			cur.LoadTag();
			cur.removeNote(removeNote);
			vector<Note> tmp = cur.noteList();
			if (tmp.empty())
			{
				TagList tl;
				tl.LoadTagList();
				tl.RemoveTag(cur);
				tl.SaveTagList();
			}
			cur.SaveTag();
		}
	}
	l.SaveNoteList();
	clrscr();
	gotoXY(40, 10);
	TextColor(10);
	cout << "Remove A Note completely.";
	gotoXY(40, 12);
	cout << "Please press the Esc to return back.";
	TextColor(7);
	char ch = _getch();
	while (ch != 27)
	{
		ch = _getch();
	}
	if (ch == 27)
	{
		clrscr();
		return MenuNote();
	}
}

void System::AddANote()
{
	string content,name;
	vector<string> tagName;
	gotoXY(40, 6);
	cout << "Please enter the content of the Note : ";
	gotoXY(45, 8);
	getline(cin, content, '\n');
	gotoXY(40, 10);
	int amountTag;
	cout << "How many tag you want to add to the Note : ";
	cin >> amountTag;
	cin.ignore(1000, '\n');
	for (int i = 0; i < amountTag; i++)
	{
		gotoXY(45, 12 + 2 * i);
		cout << "Name of Tag : ";
		getline(cin, name, '\n');
		tagName.push_back(name);
	}
	NoteList l;
	l.LoadNoteList();                                                   //add a note
	l.AddNewNote(content, tagName);
	l.SaveNoteList();
	Note a = l.noteList().back();
	TagList tl;
	tl.LoadTagList();
	for (auto i = tagName.begin(); i != tagName.end(); i++)
	{
		Tag cur(*i);
		int index;
		if (!tl.Check(cur, index))cur.LoadTag();
		cur.addnewNote(a);
		cur.SaveTag();
		tl.AddNewTag(cur);
	}
	tl.SaveTagList();
	TextColor(10);
	gotoXY(40, 14 + amountTag);
	cout << "Add a Note completely.";
	gotoXY(40, 16 + amountTag);
	cout << "Please press the Esc to return back.";
	TextColor(7);
	char ch = _getch();
	while (ch != 27)
	{
		ch = _getch();
	}
	if (ch == 27)
	{
		clrscr();
		return MenuNote();
	}

}

void System::SearchKeyWord(string word)
{
	NoteList l;
	l.LoadNoteList();
	vector<Note> notelist = l.noteList();
	InvertedIndex data;		
	for (auto i = notelist.begin(); i != notelist.end(); i++)
	{
		data.addfile((*i).name());
	}
	gotoXY(52, 3);
	vector<int> f = data.search(word);
	vector<Note> searchNoteList;
	vector<int> positionWord;
	string file = "File";
	int size = f.size();
	for (int i = 0; i < size; i += 2)
	{
		stringstream ss;
		ss << f[i];
		string namefile = file + ss.str();
		for (auto j = notelist.begin(); j != notelist.end(); j++)
		{
			if ((*j).name() == namefile)
			{
				searchNoteList.push_back(*j);
				break;
			}
		}
		positionWord.push_back(i + 1);
	}
	ViewAllNote(searchNoteList);
	int length = searchNoteList.size();
	TextColor(10);
	gotoXY(40, 4 + 8 * (length - 1) + 8);
	cout << "Please press the Esc to return back.";
	TextColor(7);
	char ch = _getch();
	while (ch != 27)
	{
		ch = _getch();
	}
	if (ch == 27)
	{
		clrscr();
		return MenuNote();
	}
}

void System::DisplayAllNote()
{
	clrscr();
	NoteList l;
	l.LoadNoteList();
	vector<Note> notelist = l.noteList();
	int length = notelist.size();
	if (length == 0)
	{
		gotoXY(40, 10);
		TextColor(10);
		cout << "The list of Note don't have any Note.";
		gotoXY(40, 12);
		cout << "Please press the Esc to return back.";
		TextColor(7);
		char ch = _getch();
		while (ch != 27)
		{
			ch = _getch();
		}
		if (ch == 27)
		{
			clrscr();
			return MenuNote();
		}
	}
	else
	{
		ViewAllNote(notelist);
		gotoXY(30, 4 + 8 * (length - 1) + 8);
		cout << "Please enter the ID of Note you want to see more : ";
		string name;
		getline(cin, name, '\n');
		int index;
		for (int i = 0; i < length; i++)
		{
			if (notelist[i].name() == name)
			{
				index = i;
				break;
			}
		}
		clrscr();
		ViewANote(notelist[index]);
		int size = notelist[index].content().size();
		gotoXY(40, 11 + (size / 40));
		TextColor(10);
		cout << "Please press the Esc to return back.";
		TextColor(7);
		char ch = _getch();
		while (ch != 27)
		{
			ch = _getch();
		}
		if (ch == 27)
		{
			clrscr();
			return MenuNote();
		}
	}
}

void System::DisplayAllTag()
{
	clrscr();
	TagList tl;
	tl.LoadTagList();
	vector<Tag> taglist = tl.taglist();
	int lengthofTagList = taglist.size();
	if (lengthofTagList == 0)
	{
		gotoXY(40, 10);
		TextColor(10);
		cout << "The list of Note don't have any Note.";
		gotoXY(40, 12);
		cout << "Please press the Esc to return back.";
		TextColor(7);
		char ch = _getch();
		while (ch != 27)
		{
			ch = _getch();
		}
		if (ch == 27)
		{
			clrscr();
			return MenuTag();
		}
	}
	else
	{
		gotoXY(40, 2);
		cout << "Please choose the Tag of Note you want to see : ";
		int indexTag = listTag(taglist);
		clrscr();
		vector<Note> notelist = taglist[indexTag].noteList();
		int length = notelist.size();
		ViewAllNote(notelist);
		gotoXY(30, 4 + 8 * (length - 1) + 8);
		cout << "Please enter the ID of Note you want to see more : ";
		string name;
		getline(cin, name, '\n');
		int index;
		for (int i = 0; i < length; i++)
		{
			if (notelist[i].name() == name)
			{
				index = i;
				break;
			}
		}
		clrscr();
		ViewANote(notelist[index]);
		int size = notelist[index].content().size();
		gotoXY(40, 11 + (size / 40));
		TextColor(10);
		cout << "Please press the Esc to return back.";
		TextColor(7);
		char ch = _getch();
		while (ch != 27)
		{
			ch = _getch();
		}
		if (ch == 27)
		{
			clrscr();
			return MenuTag();
		}
	}
}