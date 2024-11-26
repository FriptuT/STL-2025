#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

using namespace std;

class Problem
{
public:
    string id;
    string speciality;
    int duration;
    int priority;

    bool operator<(const Problem &rhs)const
    {
        //return this->priority < rhs.priority;
        if (priority == rhs.priority)
            return duration > rhs.duration;
        return priority < rhs.priority;
    }
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


void handsOn3()
{
    //vector<bool> resolved(problems.size(), false);
    unordered_set<string> solvedProblems;
        for (const auto& doctor : doctors)
        {
            int problemCount = 0;
            int doctorTime = doctor.timeForProblems;

            priority_queue<Problem> problemQueue;

            for(const auto& problem: problems)
            {
	            if(problem.speciality == doctor.speciality && solvedProblems.find(problem.id) == solvedProblems.end())
	            {
                    problemQueue.push(problem); // 4 1
	            }
            }

            vector<Problem> solvedByThisDoc;


            while (!problemQueue.empty() && doctorTime > 0)
            {
                Problem problem = problemQueue.top();

                problemQueue.pop();

                if(problem.duration <= doctorTime)
                {
                    doctorTime -= problem.duration;
                    solvedByThisDoc.push_back(problem);
                    problemCount++;
                    solvedProblems.insert(problem.id);
                }

            }

    
		// afisare

            if (problemCount > 0)
            {
                cout << doctor.id << " " << problemCount << " ";
                for (auto& rezolvata : solvedByThisDoc)
                {
                    cout << rezolvata.id << " ";
                }
                cout << endl;
            }

            
        }
}

//void solution1()
//{
//    vector<bool> resolved(problems.size(), false);
//    for (const auto& doctor : doctors)
//    {
//        int problemCount = 0;
//        int doctorTime = doctor.timeForProblems;
//        vector<Problem> problemeRezolvate;
//
//        for_each(problems.begin(), problems.end(), [&](const Problem& problem)
//            {
//                auto index = &problem - &problems[0];
//                if (!resolved[index] && problem.speciality == doctor.speciality && problem.duration <= doctorTime)
//                {
//                    doctorTime -= problem.duration;
//                    problemCount++;
//                    problemeRezolvate.push_back(problem);
//                    resolved[index] = true;
//                }
//            });
//
//
//        cout << doctor.id << " " << problemCount << " ";
//        for (auto& rezolvata : problemeRezolvate)
//        {
//            cout << rezolvata.id << " ";
//        }
//        cout << endl;
//    }
//}


int main()
{
    ifstream inFile("input.txt");

    int sizeProblems;
    inFile >> sizeProblems;

    for (int i = 0; i < sizeProblems; i++)
    {
        string name;
        string speciality;
        int duration;
        int priority;
        inFile >> name >> speciality >> duration >> priority;
        problems.push_back({ name, speciality, duration, priority });
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

     // solution1();
    handsOn3();

    return 0;
}