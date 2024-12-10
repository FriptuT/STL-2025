#include <iostream>
#include <vector>
using namespace std;

void solution1()
{
    cout << "Solution 1" << endl;
    /*vector<bool> resolved(problems.size(), false);
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
    }*/
}
