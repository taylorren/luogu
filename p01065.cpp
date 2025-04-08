#include <bits/stdc++.h>
using namespace std;

// 工序类
class Process
{
   public:
    int machine_id;  // 使用的机器ID
    int duration;    // 加工时间
    int start_time;  // 开始时间
    int end_time;    // 结束时间

    Process(int m_id = 0, int dur = 0)
        : machine_id(m_id), duration(dur), start_time(0), end_time(0)
    {
    }
};

// 工件类
class Component
{
   public:
    int id;                     // 工件ID
    vector<Process> processes;  // 工序列表
    int current_process_index;  // 当前处理到哪道工序

    Component(int component_id = 0, int process_count = 0)
        : id(component_id), current_process_index(0)
    {
        processes.resize(process_count + 1);  // +1是因为我们从索引1开始
    }

    // 获取当前工序
    Process& getCurrentProcess()
    {
        return processes[current_process_index];
    }

    // 获取上一道工序的完成时间
    int getLastFinishTime()
    {
        if (current_process_index <= 1)
            return 0;
        return processes[current_process_index - 1].end_time;
    }

    // 移动到下一道工序
    void moveToNextProcess()
    {
        current_process_index++;
    }
};

// 机器类
class Machine
{
   public:
    int id;                      // 机器ID
    vector<bool> time_occupied;  // 时间占用情况

    Machine(int machine_id = 0, int max_time = 10001) : id(machine_id)
    {
        time_occupied.resize(max_time, false);
    }

    // 找到最早可用的时间点
    int findEarliestAvailableTime(int earliest_possible_start, int duration)
    {
        int start_time = earliest_possible_start;
        while (true)
        {
            bool can_process = true;
            for (int t = start_time + 1; t <= start_time + duration; t++)
            {
                if (time_occupied[t])
                {
                    can_process = false;
                    start_time = t;
                    break;
                }
            }
            if (can_process)
            {
                return start_time;
            }
        }
    }

    // 标记时间段为已占用
    void occupyTimeRange(int start, int end)
    {
        for (int t = start; t <= end; t++)
        {
            time_occupied[t] = true;
        }
    }
};

// 调度器类
class Scheduler
{
   private:
    int m;                         // 机器数量
    int n;                         // 工件数量
    vector<int> sequence;          // 加工顺序
    vector<Component> components;  // 工件列表
    vector<Machine> machines;      // 机器列表

   public:
    Scheduler(int machine_count, int component_count)
        : m(machine_count), n(component_count)
    {
        sequence.resize(m * n + 1);
        components.resize(n + 1);
        machines.resize(m + 1);

        // 初始化工件和机器
        for (int i = 1; i <= n; i++)
        {
            components[i] = Component(i, m);
        }

        for (int i = 1; i <= m; i++)
        {
            machines[i] = Machine(i);
        }
    }

    // 读取输入数据
    void readInput()
    {
        // 读取加工顺序
        for (int i = 1; i <= m * n; i++)
        {
            cin >> sequence[i];
        }

        // 读取每个工件的每道工序的机器编号
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int machine_id;
                cin >> machine_id;
                components[i].processes[j].machine_id = machine_id;
            }
        }

        // 读取每个工件的每道工序的加工时间
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

    // 执行调度
    int schedule()
    {
        int max_finish_time = 0;

        // 按照sequence顺序处理每个工件
        for (int i = 1; i <= m * n; i++)
        {
            int component_id = sequence[i];

            // 移动到下一道工序
            components[component_id].moveToNextProcess();
            int process_index = components[component_id].current_process_index;
            Process& current_process =
                components[component_id].processes[process_index];

            // 获取该工序所需的机器
            int machine_id = current_process.machine_id;
            int duration = current_process.duration;

            // 找到可以开始加工的最早时间
            int earliest_start_time =
                components[component_id].getLastFinishTime();

            // 在机器上寻找最早可用的时间段
            int start_time = machines[machine_id].findEarliestAvailableTime(
                earliest_start_time, duration);

            // 标记机器占用时间
            machines[machine_id].occupyTimeRange(start_time + 1,
                                                 start_time + duration);

            // 更新工序的开始和结束时间
            current_process.start_time = start_time + 1;
            current_process.end_time = start_time + duration;

            // 更新最大完成时间
            max_finish_time = max(max_finish_time, current_process.end_time);
        }

        return max_finish_time;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;  // m是机器数量，n是工件数量

    Scheduler scheduler(m, n);
    scheduler.readInput();
    int result = scheduler.schedule();

    cout << result << endl;

    return 0;
}
