#include <bits/stdc++.h>
using namespace std;

struct Member
{
    string name;
    string position;
    int contribution;
    int level;
    int original_pos;
};

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

bool sortByContribution(const Member& a, const Member& b)
{
    if (a.contribution != b.contribution)
    {
        return a.contribution > b.contribution;
    }
    return a.original_pos < b.original_pos;
}

bool sortByRank(const Member& a, const Member& b)
{
    if (posRank[a.position] != posRank[b.position])
    {
        return posRank[a.position] < posRank[b.position];  // 职位高的排前面
    }
    if (a.level != b.level)
    {
        return a.level > b.level;  // 等级高的排前面
    }
    return a.original_pos < b.original_pos;  // 等级相同时，原来靠前的排前面
}

int main()
{
    int n;
    cin >> n;
    vector<Member> members(n);
    vector<Member> retain;
    vector<Member> change;

    for (int i = 0; i < n; i++)
    {
        cin >> members[i].name >> members[i].position >>
            members[i].contribution >> members[i].level;
        members[i].original_pos = i;

        if (members[i].position == "BangZhu" ||
            members[i].position == "FuBangZhu")
        {
            retain.push_back(members[i]);
        }
        else
        {
            change.push_back(members[i]);
        }
    }

    sort(change.begin(), change.end(), sortByContribution);

    int Hufa = 0, Zhanglao = 0, Tangzhu = 0, Jingying = 0;
    for (auto& m : change)  // Use reference to modify original
    {
        if (Hufa < posLimit["HuFa"])
        {
            m.position = "HuFa";
            Hufa++;
        }
        else if (Zhanglao < posLimit["ZhangLao"])
        {
            m.position = "ZhangLao";
            Zhanglao++;
        }
        else if (Tangzhu < posLimit["TangZhu"])
        {
            m.position = "TangZhu";
            Tangzhu++;
        }
        else if (Jingying < posLimit["JingYing"])
        {
            m.position = "JingYing";
            Jingying++;
        }
        else
        {
            m.position = "BangZhong";
        }
    }

    vector<Member> res;
    res.insert(res.end(), retain.begin(), retain.end());
    res.insert(res.end(), change.begin(), change.end());

    sort(res.begin(), res.end(), sortByRank);

    for (auto m : res)
    {
        cout << m.name << " " << m.position << " " << m.level << endl;
    }

    return 0;
}