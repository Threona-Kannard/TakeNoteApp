#pragma once
#ifndef _H_System_H_
#define _H_System_H_

#include <stdio.h>
#include <conio.h>
#include<Windows.h>

#include"NoteList.h"
#include"TagList.h"
#include"InvertedIndex.h"
#define TextColorCode_Back			0
#define TextColorCode_DarkBlue		1
#define TextColorCode_DarkGreen		2
#define TextColorCode_DarkCyan		3
#define TextColorCode_DarkRed		4
#define TextColorCode_DarkPink		5
#define TextColorCode_DarkYellow	6
#define TextColorCode_DarkWhite		7
#define TextColorCode_Grey			8
#define TextColorCode_Blue			9
#define TextColorCode_Green			10
#define TextColorCode_Cyan			11
#define TextColorCode_Red			12
#define TextColorCode_Pink			13
#define TextColorCode_Yellow		14
#define TextColorCode_White			15

#define key_Up		72
#define key_Down	80
#define key_Left	75
#define key_Right	77
#define key_none	-1

//-------------------------Screen-------------------------

class System
{
public:
	//set the visibility of the cursor
	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}
	
	//Clear Screen
	void clrscr()
	{
		CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
		HANDLE	hConsoleOut;
		COORD	Home = { 0,0 };
		DWORD	dummy;

		hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

		FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
		csbiInfo.dwCursorPosition.X = 0;
		csbiInfo.dwCursorPosition.Y = 0;
		SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
	}
	
	
	int inputKey()
	{
		if (_kbhit())
		{
			int key = _getch();

			return key;
		}
		else
		{
			return key_none;
		}
	}

	//Control the cursor axis
	void gotoXY(int column, int line)
	{
		COORD coord;
		coord.X = column;
		coord.Y = line;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	//Set color for test
	void TextColor(int TextColor)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TextColor);
	}
	
	//Draw a Border
	void DrawBorder(int x, int y, int width, int height, bool draw) {
		if (draw) {
			//Draw 4 vertex first	
			//Top-Left
			gotoXY(x, y);
			cout << char(218);
			//Top-Right
			gotoXY(x + width, y);
			cout << char(191);
			//Bottom-Left
			gotoXY(x, y + height);
			cout << char(192);
			//Bottom-Right
			gotoXY(x + width, y + height);
			cout << char(217);

			//Top Edge
			for (int i = x + 1; i < (x + width); i++) {
				gotoXY(i, y);
				cout << char(196);
			}
			//Bottom Edge
			for (int i = x + 1; i < (x + width); i++) {
				gotoXY(i, y + height);
				cout << char(196);
			}
			//Left Edge
			for (int i = y + 1; i < (y + height); i++) {
				gotoXY(x, i);
				cout << char(179);
			}
			//Right Edge
			for (int i = y + 1; i < (y + height); i++) {
				gotoXY(x + width, i);
				cout << char(179);
			}
		}
		else {
			//4 Vertex first
			//Top-Left
			gotoXY(x, y);
			cout << " ";
			//Top-Right
			gotoXY(x + width, y);
			cout << " ";
			//Bottom-Left
			gotoXY(x, y + height);
			cout << " ";
			//Bottom-Right
			gotoXY(x + width, y + height);
			cout << " ";

			//Top Edge
			for (int i = x + 1; i < (x + width); i++) {
				gotoXY(i, y);
				cout << " ";
			}
			//Bottom Edge
			for (int i = x + 1; i < (x + width); i++) {
				gotoXY(i, y + height);
				cout << " ";
			}
			//Left Edge
			for (int i = y + 1; i < (y + height); i++) {
				gotoXY(x, i);
				cout << " ";
			}
			//Right Edge
			for (int i = y + 1; i < (y + height); i++) {
				gotoXY(x + width, i);
				cout << " ";
			}

		}
	}
	
	void ViewAllNote(vector<Note> notelist);
	void ViewANote(Note note);
	void RemoveTagInNote();
	void RemoveANote();
	void RemoveATag();
	void AddANote();
	void SearchKeyWord(string word);
	void DisplayAllNote();
	void DisplayAllTag();
	Note listNote(int &index);
	int listTag(vector<Tag> taglist);
	void MenuDisplay();
	void MenuTag();
	void MenuNote();
	~System() {};
};

#endif // !_H_System_H_
