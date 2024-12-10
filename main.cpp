#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

using namespace std;

class Problem
{
public:
    string id;
    string speciality;
    int arrivalHour;
    int duration;
    int priority;

    bool operator<(const Problem & other)const
    {
        if (arrivalHour != other.arrivalHour)
            return (arrivalHour > other.arrivalHour);

        if (priority != other.priority)
            return priority < other.priority;

        return duration > other.duration;
    }
};

class Doctor
{
public:
    string id;
    set<string> specialities;

    int availableFromHour;

    vector<Problem> solvedProblems;
};

const int hospitalOpenTime = 9;
const int hospitalCloseTime = 17;
// problems
priority_queue<Problem> problemsQueue;
// doctors
map<string, Doctor> doctorsById;
map<string, set<string>> doctorIdsBySpeciality;


void handsOn4()
{
    while (!problemsQueue.empty() )
    {
        Problem currentProblem = problemsQueue.top();
        problemsQueue.pop();

        // find available doctor
        const auto& doctorsIt = doctorIdsBySpeciality.find(currentProblem.speciality);
        if (doctorsIt == doctorIdsBySpeciality.end())
            continue;   // no doctor for this speciality

        const set<string>& doctorIdsSet = doctorsIt->second;
        
        for (const string& doctorId : doctorIdsSet) {
            Doctor& doctor = doctorsById[doctorId];

            if (doctor.availableFromHour <= currentProblem.arrivalHour
                && currentProblem.arrivalHour + currentProblem.duration <= hospitalCloseTime) {
                // asign problem to doctor
                doctor.availableFromHour = currentProblem.arrivalHour + currentProblem.duration;
                doctor.solvedProblems.push_back(currentProblem);
                break;
            }
        }
    }

    // output
    for (auto& doctorEntry : doctorsById) {
        Doctor& doctor = doctorEntry.second;

        if (doctor.solvedProblems.size() > 0) {
            cout << doctor.id << " " << doctor.solvedProblems.size() << " ";

            for (const Problem& problem : doctor.solvedProblems) {
                cout << problem.id << " " << problem.arrivalHour << " ";
            }
            cout << endl;
        }
    }
}



int main()
{
    ifstream inFile("input2.txt");

    if (!inFile) {
        cerr << "Error: Could not open input file." << endl;
        return 0;
    }

    int sizeProblems;
    inFile >> sizeProblems;


    for (int i = 0; i < sizeProblems; i++)
    {
        Problem problem;
        inFile >> problem.id >> problem.speciality >> problem.arrivalHour >> problem.duration >> problem.priority;
        problemsQueue.push(problem);
    }

    cout << "===" << endl;
    int sizeDoctors;
    inFile >> sizeDoctors;


    for (int i = 0; i < sizeDoctors; i++)
    {
        Doctor doctor;
        inFile >> doctor.id;

        int specialitiesNum;
        inFile >> specialitiesNum;

        
        for (int i = 0; i < specialitiesNum; i++) {
            string speciality;
            inFile >> speciality;
            doctor.specialities.insert(speciality);
            doctorIdsBySpeciality[speciality].insert(doctor.id);
        }

        doctor.availableFromHour = hospitalOpenTime;

        doctorsById[doctor.id] = doctor;
    }

    handsOn4();

    return 0;
}