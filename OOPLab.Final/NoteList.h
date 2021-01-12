#pragma once
#ifndef _H_NoteList_H_
#define _H_NoteList_H_
#include"Note.h"

class NoteList
{
private:
	int _mostID;
	vector<Note> _noteList;
public:
	int makeID();
	void mostIDUpdate(string removeId);
	void setNoTag(int index);
	vector<Note> noteList();
	void LoadNoteList();
	void SaveNoteList();
	void AddNewNote(string contentNewNote,vector<string> tagNewNote);
	void RemoveANote(int indexRemoveNote);
	void RemoveAllNoteHaveTag(string nameTag,vector<Note> notelistOfTag, vector<Note> &notelistOfRemainTag);
	void RemoveTag(int index, vector<string> &remainTagList, string nameTag);
	~NoteList() {};
};
#endif // !_H_NoteList_H_
