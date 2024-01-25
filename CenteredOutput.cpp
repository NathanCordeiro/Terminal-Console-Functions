#include <iostream>
#include <Windows.h>

using namespace std;

class CenteredOutput
{
public:
    CenteredOutput()
    {
        // Get the handle to the console window
        consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        // Get the screen buffer info
        GetConsoleScreenBufferInfo(consoleHandle, &originalCsbi);

        // Initialize center position
        centerX = originalCsbi.srWindow.Left + (originalCsbi.srWindow.Right - originalCsbi.srWindow.Left) / 2;
        centerY = originalCsbi.srWindow.Top + (originalCsbi.srWindow.Bottom - originalCsbi.srWindow.Top) / 2;
    }

    ~CenteredOutput()
    {
        // Restore the original cursor position when the object is destroyed
        SetConsoleCursorPosition(consoleHandle, originalCsbi.dwCursorPosition);
    }

    template <typename T>
    CenteredOutput& print(const T& value)
    {
        // Set the cursor position to the center
        SetConsoleCursorPosition(consoleHandle, { static_cast<SHORT>(centerX), static_cast<SHORT>(centerY) });

        // Output the value
         cout << value;

        // Update center position for the next output
        COORD newPosition = { static_cast<SHORT>(centerX), static_cast<SHORT>(++centerY) };
        SetConsoleCursorPosition(consoleHandle, newPosition);

        return *this;
    }

    CenteredOutput& print( ostream& (*manipulator)( ostream&))
    {
        // Handle  endl
        if (manipulator == static_cast< ostream& (*)( ostream&)>( endl))
        {
            // Move to the next line
            ++centerY;
        }

        return *this;
    }

private:
    HANDLE consoleHandle;
    CONSOLE_SCREEN_BUFFER_INFO originalCsbi;
    int centerX;
    int centerY;
};

int main()
{
    {
        // Create an instance of CenteredOutput to move the cursor to the center
        CenteredOutput centeredOutput;

        // Perform tasks with the cursor at the center
        centeredOutput.print("This is centered text.").print( endl);
        centeredOutput.print(42).print( endl);
        centeredOutput.print("wassup").print( endl);
    }

    // Cursor is back to the original position
     cout << "Back to the original position." <<  endl;

    return 0;
}

