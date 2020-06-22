#ifndef DIARY_HPP
#define DIARY_HPP

#include <stdio.h>
#include <fstream>

struct Message{
    std::string date;
    std::string time;
    std::string text;
};

void instructions(const std::string &prog_name);
void addText(const std::string file_name, const std::string text);
void listText();

#endif
