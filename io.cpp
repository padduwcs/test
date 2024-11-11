
#include"student.h"
#include<fstream>
#include<iostream>
#include<iomanip>


bool input(student stu[], int &n) {
    std::fstream fin("STUDENT.TXT", std::ios::in);
    if(!fin) {
        std::cerr << "File Error.";
        return false;
    }
    std::string line1, line2;
    while(std::getline(fin, line1)) {
        std::getline(fin, line2);
        get(stu[n], line1);
        calgpa(stu[n], line2);
        ++n;
    }
    fin.close();
    return true;
}

bool ouput(student stu[], int &n) {
    std::fstream fout("GPA.TXT", std::ios::out);
    if(!fout) {
        std::cerr << "File Error.";
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        fout << stu[i].id << '|' << stu[i].name << '|' << std::fixed << std::setprecision(1) << stu[i].gpa << '\n';
    }
    fout.close();
    return true;
}

