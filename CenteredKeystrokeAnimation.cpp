#include <iostream>
#include <windows.h>
#include <string>
#include <thread>

using namespace std;

void centerMovingText(const  string& text, int duration)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int textWidth = static_cast<int>(text.length());

    int startPos = (screenWidth - textWidth) / 2;

    for (int i = 0; i < startPos; ++i)
    {
         cout << " ";
    }

    for (int i = 0; i < textWidth; ++i)
    {
         cout << text[i];
         this_thread::sleep_for( chrono::milliseconds(duration));
    }

     cout <<  endl;
}

int main()
{
    centerMovingText("This is scrolling text!\n", 100);
    centerMovingText("hello world\n",100);
    return 0;
}
