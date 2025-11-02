#include <algorithm>
#include <iostream>
#include <vector>
struct Triangle
{
    int x, y, m, x1, y1;
    constexpr Triangle(int x_, int y_, int m_)
        : x(x_), y(y_), m(m_), x1(x_ + m_), y1(y_ + m_)
    {
    }
    constexpr bool operator<(const Triangle& e) const
    {
        return (x < e.x) || (x == e.x) && (y < e.y);
    }
    constexpr int height(int x_) const
    {
        return (x_ < x) ? 0 : x_ >= x1 ? 0 : (m + x - x_);
    }
};
struct Section
{
    int a, b;
    constexpr Section(int a_, int b_) : a(a_), b(b_) {}
    constexpr bool operator<(const Section& e) const
    {
        return (a < e.a) || (a == e.a) && (b > e.b);
    }
    constexpr operator int() const
    {
        return b - a;
    }
};
std::vector<Triangle> tri;
std::vector<Triangle> ctx;

int main()
{
    int n, x, _x, _y, _m, S = 0, loop = 1;
    std::cin >> n;
    while (n-- && ((std::cin >> _x >> _y >> _m), 1))
    {
        tri.emplace_back(_x, _y, _m);   // read 三角形
    }

    std::sort(tri.begin(), tri.end());  // sort 三角形
    
    x = tri[0].x;                       // first 三角形
    for (size_t i = 0; i < tri.size(); i++)
    {
        ctx.emplace_back(tri[i]);
        while (!(ctx.end()[-1].x == x && i + 1 < tri.size()))
        {
            int x1 = x + 1, h1 = 0;
            std::vector<Section> section;
            for (const auto& e : ctx)
                if (Section tmp = {e.y, e.y + e.height(x)})
                    section.emplace_back(tmp);  // push 有效区间
            std::sort(section.begin(), section.end());
            for (size_t i = 0; i + 1 < section.size(); i++){
                while (loop++)  // 区间合并 ++ 是在复位之前 判断是否继续循环
                {
                    loop = 0;
                    while (i + 1 < section.size() &&
                           section[i].a == section[i + 1].a)
                        section.erase(section.begin() + i + 1), loop = 1;
                    while (i + 1 < section.size() &&
                           section[i].b > section[i + 1].a)
                        section[i].b = std::max(section[i].b, section[i + 1].b),
                        section.erase(section.begin() + i + 1), loop = 1;
                }
            }
            for (const auto& e : section)
            {
                S += 2ull * e - x1 + x;  // S += (左底 + 右底) * 1 //* 0.5
                h1 = h1 + e - x1 + x;    // 右底
            }
            x = x1;  // x++
            if (!h1)
            {
                for (size_t i = 0; i < ctx.size(); i++)
                    if (ctx[i].x1 <= x)
                        ctx.erase(ctx.begin() + i--);  // TODO(可优化，内存复制浪费时间)
                                                       // // 移除失活三角形
                if (!ctx.size())
                    break;
                x = ctx[0].x;  // 跳到下一个三角形
            }
        }
    }
    return printf("%d.%01d", S / 2, 5 * (S % 2)), 0;  // S *= 0.5
}