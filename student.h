#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
struct student{
    std::string name, id;
    float gpa;
};

void get(student &s, std::string line1);
void calgpa(student &s,std::string line2);

#endif