#include <cstdio>
#include <map>

int main()
{
    int n, min_group_size = 0x3f3f3f3f;
    scanf("%d", &n);

    std::map<int, int> ability_count;
    for (int i = 0; i < n; i++)
    {
        int ability;
        scanf("%d", &ability);
        ability_count[ability]++;
    }

    while (!ability_count.empty())
    {
        auto current = ability_count.begin();
        auto next = ability_count.begin();

        // 第一个（最小）能力值的队友，无论如何总归要有一组。此时该能力值的人数减一，当前分组长度是1
        current->second--;
        int segment_length = 1;

        ++next;
        // 没到结束 &&
        //  下一个能力值比当前大1 &&
        //  下一个能力值的人数比当前多
        while (next != ability_count.end() &&
               next->first == current->first + 1 &&
               next->second > current->second)
        {
            segment_length++;
            next->second--;
            // 迭代找下一个
            current = next;
            ++next;
        }

        // 优化：只删除必要的元素，而不是遍历整个map
        // 按照我们的方法，0肯定出现在整个map比较靠前的地方
        current = ability_count.begin();
        while (current != ability_count.end() && current->second == 0)
        {
            ability_count.erase(current++);
        }

        min_group_size = std::min(min_group_size, segment_length);
    }

    printf("%d\n", min_group_size);
    return 0;
}