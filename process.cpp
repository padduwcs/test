#include<iostream>
#include"student.h"

void Sort(student stu[], int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(stu[i].gpa < stu[j].gpa) std::swap(stu[i], stu[j]);
        }
    }
}
void Fix(std::string &s) {
    for(int i = 0; i < s.length(); ++i) {
        if(i == 0) s[i] = toupper(s[i]);
        else if(isspace(s[i - 1]) && isalpha(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
}
void Capitalize(student stu[], int n) {
    for(int i = 0; i < n; ++i) {
        Fix(stu[i].name);
    }
}