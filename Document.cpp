#include "Document.h"

void Document::addAFteroCurrLIne(vector<string> &newLInes, int pos)
{
    this->text.insert(this->text.begin() + pos, newLInes.begin(), newLInes.end());
}

void Document::addBeforeCurrLIne(vector<string> &newLInes, int pos)
{
    this->text.insert(this->text.begin() + pos, newLInes.begin(), newLInes.end());
}
void Document::changeCurrLine(vector<string> &newLInes, int pos)
{
    int index = pos;
    vector<string>::iterator it;
    for (it = newLInes.begin(); it != newLInes.end(); it++)
    {
        this->text.at(index) = *it;
        index++;
    }
}
void Document::deleteCurrLine(int pos)
{
    this->text.erase(this->text.begin() + pos);
}

void Document::appendNextLine(int pos)
{
    if (this->text.size() > pos + 1)
    {
        string s = this->text.at(pos);
        string s2 = this->text.at(pos + 1);
        if ((!s.empty() && s[s.length() - 1] == '\n') && (!s2.empty() && s2[s2.length() - 1] == '\n'))
        {
            s.erase(s.length() - 1);
            s2.erase(s2.length() - 1);
            string appendNext = s + " " + s2 + "\n";
            this->text.at(pos) = appendNext;
            this->text.erase(this->text.begin() + pos + 1);
        }
        else
        {
            cout << "Cannot append";
        }
    }
    else
    {
        cout << "Next line not found";
    }
}
void Document::findAndReplacehWord(string oldWord, string newWord, int pos)
{
    string textLine = this->text.at(pos);
    size_t index = textLine.find(oldWord);
    if (index != string::npos)
    {
        textLine.replace(index, oldWord.length(), newWord);
        this->text.at(pos) = textLine;
    }
    else
    {
        cout << "Word to replace did not found in current line";
    }
}