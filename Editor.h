#pragma once
#include "Document.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <vector>
#define FIRST_LINE 1
using namespace std;
class Editor
{
private:
    vector<string> newLInes;
    char choice = '*';

public:
    Document d;
    int currLine;
    Editor() : d(), currLine(FIRST_LINE) { ; }
    Editor(string filename) : currLine(FIRST_LINE)
    {
        vector<string> v;
        ifstream input_file(filename);
        string line;

        while (getline(input_file, line))
        {
            string new_line;
            new_line = line + "\n";
            v.push_back(new_line);
        }
        if (v.size() > 0)
            d = v;
    }
    ~Editor()
    {
    }
    void setCurrLine(int pos);
    void loop();
    void moveToLIne(int lineNUmber);
    void moveForward(int steps);
    void moveBackward(int steps);
    void moveToLastLIne();
    void addOrChangeLInes(char choice);
    void searchWord(string word, int pos);
    void changeWord(string input);
    void writeToFile(string file);
    void printVec();
};
