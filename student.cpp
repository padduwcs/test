#include<iostream>
#include"student.h"
#include<sstream>

std::string fix(std::string s) {
    std::string res = "";
    int cur_pos = 0, add_space = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(isspace(s[i])) {
            if(i > 0 && !isspace(s[i - 1])) add_space = 1;
            else continue;
        }
        else {
            if(add_space) {
                res += ' ';
                add_space = 0;
            }
            res += s[i];
        }
    }
    return res;
}

void get(student &s, std::string line1) {
    for(int i = 0; i < line1.length(); ++i) {
        if(line1[i] == '|') {
            s.name = line1.substr(0, i);
            s.name = fix(s.name);
            s.id = line1.substr(i + 1, line1.length() - i - 1);
            break;
        }
    }
}

void calgpa(student &s,std::string line2) {
    int cnt = 0; float sum = 0, x;
    std::stringstream ss(line2);
    while(ss >> x) {
        sum += x;
        ++cnt;
    }
    s.gpa = (float)sum / cnt;
}