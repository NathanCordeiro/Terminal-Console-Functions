#include<iostream>
#include<windows.h>
using namespace std;

void hideCursor()
{
	CONSOLE_CURSOR_INFO cursor; // Create a CONSOLE_CURSOR_INFO object
	cursor.dwSize = 100; // Assigning size of cursor
	cursor.bVisible = false; // Making cursor invisible
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor); // Set the cursor for next thing to be printed
}
int main()
{
    hideCursor();
    return 0;
}
