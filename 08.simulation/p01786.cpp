#include <bits/stdc++.h>
using namespace std;

// 定义职位及其对应的优先级（数字越小优先级越高）
map<string, int> posRank = {{"BangZhu", 1},  {"FuBangZhu", 2}, {"HuFa", 3},
                            {"ZhangLao", 4}, {"TangZhu", 5},   {"JingYing", 6},
                            {"BangZhong", 7}};

// 定义各职位的最大人数
map<string, int> posLimit =
    {
        {"BangZhu", 1},        {"FuBangZhu", 2}, {"HuFa", 2},
        {"ZhangLao", 4},       {"TangZhu", 7},   {"JingYing", 25},
        {"BangZhong", INT_MAX}  // 帮众没有人数限制
};

// 定义帮派成员结构体
struct Member
{
    string name;        // 名字
    string position;    // 职位
    int contribution;   // 帮贡
    int level;          // 等级
    int originalIndex;  // 原始顺序，用于处理等级相同的情况
};

// 按帮贡排序的比较函数
bool compareByContribution(const Member &a, const Member &b)
{
    if (a.contribution != b.contribution)
    {
        return a.contribution > b.contribution;  // 帮贡高的排前面
    }
    return a.originalIndex < b.originalIndex;  // 帮贡相同时，原来靠前的排前面
}

// 按职位和等级排序的比较函数
bool compareByPositionAndLevel(const Member &a, const Member &b)
{
    if (posRank[a.position] != posRank[b.position])
    {
        return posRank[a.position] < posRank[b.position];  // 职位高的排前面
    }
    if (a.level != b.level)
    {
        return a.level > b.level;  // 等级高的排前面
    }
    return a.originalIndex < b.originalIndex;  // 等级相同时，原来靠前的排前面
}

int main()
{
    int n;
    cin >> n;

    vector<Member> members(n);
    vector<Member> unchangeable;  // 存储帮主和副帮主
    vector<Member> changeable;    // 存储可以调整职位的成员

    // 读取输入
    for (int i = 0; i < n; i++)
    {
        cin >> members[i].name >> members[i].position >>
            members[i].contribution >> members[i].level;
        members[i].originalIndex = i;

        // 分离帮主和副帮主
        if (members[i].position == "BangZhu" ||
            members[i].position == "FuBangZhu")
        {
            unchangeable.push_back(members[i]);
        }
        else
        {
            changeable.push_back(members[i]);
        }
    }

    // 按帮贡排序可调整职位的成员
    sort(changeable.begin(), changeable.end(), compareByContribution);

    // 重新分配职位
    int huFaCount = 0, zhangLaoCount = 0, tangZhuCount = 0, jingYingCount = 0;

    for (auto &member : changeable)
    {
        if (huFaCount < posLimit["HuFa"])
        {
            member.position = "HuFa";
            huFaCount++;
        }
        else if (zhangLaoCount < posLimit["ZhangLao"])
        {
            member.position = "ZhangLao";
            zhangLaoCount++;
        }
        else if (tangZhuCount < posLimit["TangZhu"])
        {
            member.position = "TangZhu";
            tangZhuCount++;
        }
        else if (jingYingCount < posLimit["JingYing"])
        {
            member.position = "JingYing";
            jingYingCount++;
        }
        else
        {
            member.position = "BangZhong";
        }
    }

    // 合并帮主、副帮主和其他成员
    vector<Member> result;
    result.insert(result.end(), unchangeable.begin(), unchangeable.end());
    result.insert(result.end(), changeable.begin(), changeable.end());

    // 按职位和等级排序
    sort(result.begin(), result.end(), compareByPositionAndLevel);

    // 输出结果
    for (const auto &member : result)
    {
        cout << member.name << " " << member.position << " " << member.level
             << endl;
    }

    return 0;
}