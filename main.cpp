
#include "Editor.h"
using namespace std;
int main(int argc, char *argv[])
{
    Editor editor;
    switch (argc)
    {
    case 2:
        editor = Editor(argv[1]);
        break;
    default:
        break;
    }
    editor.loop();
    return 0;
}