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
    int duration;
};

class Doctor
{
public:
    string id;
    string speciality;
    int timeForProblems;
};

vector<Problem> problems;
vector<Doctor> doctors;

void solution1()
{
    vector<bool> resolved(problems.size(), false);
    for (const auto& doctor : doctors)
    {
        int problemCount = 0;
        int doctorTime = doctor.timeForProblems;
        vector<Problem> problemeRezolvate;

        for_each(problems.begin(), problems.end(), [&](const Problem& problem)
            {
                auto index = &problem - &problems[0];
                if (!resolved[index] && problem.speciality == doctor.speciality && problem.duration <= doctorTime)
                {
                    doctorTime -= problem.duration;
                    problemCount++;
                    problemeRezolvate.push_back(problem);
                    resolved[index] = true;
                }
            });


        cout << doctor.id << " " << problemCount << " ";
        for (auto& rezolvata : problemeRezolvate)
        {
            cout << rezolvata.id << " ";
        }
        cout << endl;
    }
}

int main()
{
    ifstream inFile("input4_bonus.txt");

    int sizeProblems;
    inFile >> sizeProblems;

    for (int i = 0; i < sizeProblems; i++)
    {
        string name;
        string speciality;
        int duration;
        inFile >> name >> speciality >> duration;
        problems.push_back({ name, speciality, duration });
    }

    cout << "===" << endl;
    int sizeDoctors;
    inFile >> sizeDoctors;

    for (int i = 0; i < sizeDoctors; i++)
    {
        string name;
        string speciality;
        int timeForProblems = 8;
        inFile >> name >> speciality;
        doctors.push_back({ name, speciality, timeForProblems });
    }

    solution1();

    return 0;
}