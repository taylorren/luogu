#include <bits/stdc++.h>
using namespace std;

class Process
{
   public:
    int id;
    int duration;
    int start, end;

    Process(int _id = 0, int _duration = 0)
        : id(_id), duration(_duration), start(0), end(0)
    {
    }
};

class Component
{
   public:
    int id;
    vector<Process> processes;
    int current_process_id;

    Component(int _id = 0, int _process_count = 0)
        : id(_id), current_process_id(0)
    {
        processes.resize(_process_count + 1);
    }

    Process& getCurrentProcess()
    {
        return processes[current_process_id];
    }
    int getLastProcessFinishTime()
    {
        return current_process_id <= 1 ? 0
                                       : processes[current_process_id - 1].end;
    }
    void moveToNextProcess()
    {
        current_process_id++;
    }
};

class Machine
{
   public:
    int id;
    vector<bool> used_Time;

    Machine(int _id = 0, int _max_duration = 10000) : id(_id)
    {
        used_Time.resize(_max_duration, false);
    }
    int findEarliestStartTime(int possible, int duration)
    {
        int start = possible;

        while (true)
        {
            bool canProcess = true;
            for (int t = start + 1; t <= start + duration; t++)
            {
                if (used_Time[t])  // Occupied
                {
                    start = t;
                    canProcess = false;
                    break;
                }
            }

            if (canProcess)
            {
                return start;
            }
        }
    }
    void reserve(int s, int e)
    {
        for (int i = s; i <= e; i++)
        {
            used_Time[i] = true;
        }
    }
};

class Schedule
{
   public:
    int m, n;  // m: machines, n: components
    vector<Machine> machines;
    vector<Component> components;
    vector<int> processes;

    Schedule(int _m, int _n) : m(_m), n(_n)
    {
        machines.resize(m + 1);
        components.resize(n + 1);
        processes.resize(m * n + 1);

        for (int i = 1; i <= n; i++)
        {
            components[i] = Component(i, m);
        }

        for (int i = 1; i <= m; i++)  // Fixed: should be m, not n
        {
            machines[i] = Machine(i);
        }
    }

    void readInput()
    {
        for (int i = 1; i <= m * n; i++)  // Read Process
        {
            cin >> processes[i];
        }

        for (int i = 1; i <= n;
             i++)  // Read i-component j-process on which machine
        {
            for (int j = 1; j <= m; j++)
            {
                int m_id;
                cin >> m_id;
                components[i].processes[j].id = m_id;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int duration;
                cin >> duration;
                components[i].processes[j].duration = duration;
            }
        }
    }

    int plan()
    {
        int max_duration;

        for (int i = 1; i <= m * n; i++)
        {
            int component_id = processes[i];
            components[component_id].moveToNextProcess();
            int process_id = components[component_id].current_process_id;

            Process& process = components[component_id].processes[process_id];

            int m_id, duration;
            m_id = process.id;
            duration = process.duration;

            int earliest = components[component_id].getLastProcessFinishTime();
            int real_start =
                machines[m_id].findEarliestStartTime(earliest, duration);
            machines[m_id].reserve(real_start + 1, real_start + duration);
            process.start = real_start + 1;
            process.end = real_start + duration;

            max_duration = max(max_duration, process.end);
        }

        return max_duration;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    Schedule s(m, n);
    s.readInput();
    int result = s.plan();
    cout << result << endl;
}