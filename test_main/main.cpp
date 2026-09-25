#include <iostream>
#include <vector>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[H";
}

char getKey()
{
    char c;
    cin.get(c);

    if (c == '\033')
    {
        cin.get(c);
        cin.get(c);

        if (c == 'A') return 'U'; // ↑
        if (c == 'B') return 'D'; // ↓
    }

    if (c == '\n')
        return 'E'; // Enter

    return c;
}

void printCentered(const string& text)
{
    int width = 80; // ширина терминала
    int spaces = (width - text.length()) / 2;

    if (spaces < 0)
        spaces = 0;

    cout << string(spaces, ' ') << text << '\n';
}

int main()
{
    // Включаем режим чтения клавиш без ожидания Enter
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    vector<string> menu = {
        "START GAME",
        "LOAD GAME",
        "SETTINGS",
        "EXIT"
    };

    int selected = 0;

    while (true)
    {
        clearScreen();

        cout << "\n\n\n";

        for (int i = 0; i < menu.size(); i++)
        {
            if (i == selected)
                printCentered("> " + menu[i]);
            else
                printCentered("  " + menu[i]);
        }

        char key = getKey();

        if (key == 'U')
        {
            selected--;

            if (selected < 0)
                selected = menu.size() - 1;
        }

        if (key == 'D')
        {
            selected++;

            if (selected >= menu.size())
                selected = 0;
        }

        if (key == 'E')
        {
            break;
        }
    }

    // Возвращаем настройки терминала
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    clearScreen();

    cout << "Selected: " << menu[selected] << '\n';
}
