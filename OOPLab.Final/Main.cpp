#include"System.h"

int main()
{
	System sys;
	sys.ShowConsoleCursor(false);
	sys.MenuDisplay();
	sys.gotoXY(46, 13);
	system("pause");
	return 0;
}