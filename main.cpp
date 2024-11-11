#include<iostream>
#include"student.h"
#include"process.h"
#include"io.h"

student stu[100000];

int main() {

    int n = 0;
    if(!input(stu, n)) return 0;
    Capitalize(stu, n);
    Sort(stu, n);
    if(!ouput(stu, n)) return 0;

    return 0;
}