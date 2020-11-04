#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Document
{
private:
public:
    vector<string> text;
    Document() : text()
    {
    }
    Document(vector<string> v) : text(v)
    {
    }
    ~Document()
    {
    }
    void addAFteroCurrLIne(vector<string> &newLInes, int pos);
    void addBeforeCurrLIne(vector<string> &newLInes, int pos);
    void changeCurrLine(vector<string> &newLInes, int pos);
    void deleteCurrLine(int pos);
    void appendNextLine(int pos);
    void findAndReplacehWord(string oldWord, string newWord, int pos);
};
