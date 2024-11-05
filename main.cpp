#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;

class Problem
{
public:
    string id;
    string speciality;
};

class Doctor
{
public:
    string id;
    string speciality;
};

vector<Problem> problems;
vector<Doctor> doctors;

void solution1()
{

    for (const auto& doctor : doctors)
    {
        auto probl = find_if(problems.begin(), problems.end(), [doctor](const Problem& problem) {
            return doctor.speciality == problem.speciality;
            });
        if (probl != problems.end()) {
            cout << probl->id << " Acceptat" << endl;
        }
        else
        {
            cout << probl->id << " Respins" << endl;
        }
    }
}

int main()
{
    ifstream inFile("input.txt");


    int sizeProblems = problems.size();
    inFile >> sizeProblems;

    for (int i = 0; i < sizeProblems; i++)
    {
        string name;
        string speciality;
        inFile >> name >> speciality;
        problems.push_back({ name, speciality });
    }

    cout << "===" << endl;
    int sizeDoctors = doctors.size();
    inFile >> sizeDoctors;

    for (int i = 0; i < sizeDoctors; i++)
    {
        string name;
        string speciality;
        inFile >> name >> speciality;
        doctors.push_back({ name,speciality });
    }

    solution1();

    return 0;
}