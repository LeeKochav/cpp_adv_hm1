#include "Editor.h"

void Editor::loop()
{
    while (true)
    {
        string input;
        getline(cin, input);
        if ((this->choice != '*') && (input != ".")) // read new Lines
        {
            this->newLInes.push_back(input + "\n");
        }
        switch (input[0])
        {
        case '1' ... '9':
            setCurrLine(int(input[0]) - 48);
            break;
        case '+':
            moveForward((int)input[1] - 48);
            break;
        case '-':
            moveBackward((int)input[1] - 48);
            break;
        case '$':
            moveToLastLIne();
            break;
        case 'a':
            this->choice = 'a';
            break;
        case 'i':
            this->choice = 'i';
            break;
        case 'c':
            this->choice = 'c';
            break;
        case '.':
            addOrChangeLInes(choice);
            break;
        case 'd':
            this->d.deleteCurrLine(this->currLine - 1);
            break;
        case '/':
            searchWord(input, this->currLine);
            break;
        case 's':
            changeWord(input);
            break;
        case 'q':
            exit(0);
            break;
        case 'j':
            this->d.appendNextLine(this->currLine - 1);
            break;
        case 'w':
            writeToFile(input);
            break;
        case 'p':
            printVec();
            break;
        default:
            break;
        }
    }
}
void Editor::moveToLastLIne()
{
    this->setCurrLine(this->d.text.size());
}

void Editor::moveBackward(int steps)
{
    this->setCurrLine(this->currLine - steps);
}
void Editor::moveForward(int steps)
{
    this->setCurrLine(this->currLine + steps);
}
void Editor::setCurrLine(int pos)
{
    if (pos == 0)
    {
        cout << "Error : first line deafult parameter is 1.";
    }

    else if (this->d.text.size() >= pos)
    {
        this->currLine = pos;
    }
    else
    {
        cout << "Line number not found";
    }
    return;
}
void Editor::addOrChangeLInes(char choice)
{
    if (!this->d.text.empty())
    {
        switch (this->choice)
        {
        case 'a':
            this->d.addAFteroCurrLIne(this->newLInes, this->currLine);
            break;
        case 'i':
            this->d.addBeforeCurrLIne(this->newLInes, this->currLine - 1);
            break;
        case 'c':
            this->d.changeCurrLine(this->newLInes, this->currLine - 1);
            break;
        default:
            break;
        }
    }
    else
    {
        this->d.text = newLInes;
    }
    this->newLInes.clear();
    this->choice = '*';
}
void Editor::searchWord(string input, int pos)
{
    int checks = 0;
    string word;
    if (!input.empty() && (input[input.length() - 1] == '/'))
    {
        input.erase(input.length() - 1);
        word = input.substr(1);
        for (int i = pos; i < this->d.text.size(); i++)
        {
            checks++;
            string line = this->d.text.at(i);
            if (line.find(word) != string::npos)
            {
                this->setCurrLine(pos + checks);
                return;
            }
        }
        checks = 0;
        for (int i = 0; i < pos; i++)
        {
            checks++;
            string line = this->d.text.at(i);
            if (line.find(word) != string::npos)
            {
                this->setCurrLine(checks);
                return;
            }
        }
        cout << "Word not found";
    }
}
void Editor::changeWord(string input)
{
    vector<string> res;
    stringstream strInput(input);
    string s;
    while (getline(strInput, s, '/'))
    {
        res.push_back(s);
    }
    if (!res.empty())
    {
        this->d.findAndReplacehWord(res.at(1), res.at(2), this->currLine - 1);
    }
}
void Editor::printVec()
{
    vector<string>::iterator it;
    for (it = this->d.text.begin(); it != this->d.text.end(); ++it)
    {
        cout << *it;
    }
}
void Editor::writeToFile(string file)
{
    string f = file.substr(2);
    ofstream outFile(f);
    vector<string>::iterator it;
    for (it = this->d.text.begin(); it != this->d.text.end(); ++it)
    {
        outFile << *it;
    }
}