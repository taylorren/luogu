# BFS 总结笔记

> 基于 `14.bdfs/` 目录下 6 道 BFS 题目总结，与 [DFS_NOTES.md](./DFS_NOTES.md) 配套阅读

---

## 一、BFS 题目总览

| 文件 | 题目 | 难度 | 特征 |
|------|------|:--:|------|
| `p01135.cpp` | P1135 奇怪的电梯 | ★☆☆ | 一维状态，最短路 |
| `p01443.cpp` | P1443 马的遍历 | ★☆☆ | 二维网格，多源最短路 |
| `p01596_bfs.cpp` | P1596 Lake Counting | ★☆☆ | BFS 版洪水填充（连通块计数） |
| `p01825.cpp` | P1825 Corn Maze | ★★☆ | 带传送门的网格最短路 |
| `p01032.cpp` | P1032 字串变换 | ★★★ | 字符串状态空间，双向搜索可优化 |
| `p02895.cpp` | P2895 Meteor Shower | ★★★ | 时间约束 + BFS（在格子被摧毁前到达） |

---

## 二、BFS 的核心结构

BFS 的本质是**按层扩展**。每一层的所有节点到起点的距离相同，这是 BFS 能求最短路的根本原因。

```cpp
void bfs(start) {
    queue<State> q;
    dist[start] = 0;        // 起点距离为 0
    q.push(start);

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        for (each neighbor of cur) {
            if (neighbor 合法 && dist[neighbor] == -1) {
                dist[neighbor] = dist[cur] + 1;  // 距离 = 父节点距离 + 1
                q.push(neighbor);
            }
        }
    }
}
```

> **关键性质**：`dist[]` 第一次被赋值时，一定是最短距离。因为 BFS 按层扩展，第一个到达某个状态的路径一定是最短的。

---

## 三、BFS 的三种典型形态

### 1. 最短路型 BFS

求从起点到目标点的**最少步数**。这是 BFS 最常见也最擅长的场景。

**代表题目：P1135（电梯）、P1443（马的遍历）**

```cpp
// P1135 核心逻辑 —— 每个状态向两个方向扩展
int up = cur + k[cur];     // 向上走
int down = cur - k[cur];   // 向下走
if (valid(up) && dist[up] == -1) {
    dist[up] = dist[cur] + 1;
    q.push(up);
}
```

```cpp
// P1443 核心逻辑 —— 8 方向扩展
for (int i = 0; i < 8; i++) {
    int nx = cur.x + dx[i], ny = cur.y + dy[i];
    if (valid(nx, ny) && dist[nx][ny] == -1) {
        dist[nx][ny] = dist[cur.x][cur.y] + 1;
        q.push({nx, ny});
    }
}
```

> **特点**：`dist` 数组初始化为 `-1` 表示未访问，首次赋值即最短距离，访问后不再更新。

### 2. 洪水填充型 BFS

遍历连通区域，一次性标记整个连通块。与 DFS 版本功能等价，只是遍历顺序不同。

**代表题目：P1596（Lake Counting BFS 版）**

```cpp
// BFS 版洪水填充
void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    grid[x][y] = '.';       // 入队时立即标记！

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (valid(nx, ny) && grid[nx][ny] == 'W') {
                grid[nx][ny] = '.';  // 标记在先，避免重复入队
                q.push({nx, ny});
            }
        }
    }
}
```

> ⚠️ **关键坑**：BFS 中要**在入队时立即标记**，而不是出队时再标记。否则同一个节点会被反复入队，导致 TLE 或 MLE。

**对比 DFS 版**：
```cpp
void dfs(int x, int y) {
    if (out_of_bounds || grid[x][y] != 'W') return;
    grid[x][y] = '.';
    for (int i = 0; i < 8; i++)
        dfs(x + dx[i], y + dy[i]);
}
```

| | DFS | BFS |
|---|---|---|
| 代码量 | 更短（4 行核心逻辑） | 略长（需显式管理队列） |
| 内存 | 递归栈 O(连通块大小) | 队列 O(连通块大小) |
| 连通块极大时 | 可能爆栈 | 队列占内存但不会爆栈 |

### 3. 带额外状态 / 约束的 BFS

BFS 的 `dist` 或 `visited` 不止记录距离，还承载更多信息。

**代表题目：P1825（传送门）、P2895（流星时间约束）、P1032（字符串变换）**

```cpp
// P2895 核心 —— 在格子被流星摧毁之前到达
// destroyed[x][y] 记录该格子最早被摧毁的时间
if (valid(nx, ny) && dist[nx][ny] == -1 && nt < destroyed[nx][ny]) {
    dist[nx][ny] = nt;
    q.push({nx, ny, nt});
}
// 到达永远不会被摧毁的格子 = 安全
if (destroyed[cur.x][cur.y] == INF) { ans = cur.t; break; }
```

```cpp
// P1825 核心 —— 传送门瞬移，不消耗额外步数
if (isupper(maze[nx][ny])) {
    // 找到配对的另一端传送门
    auto [ex, ey] = find_partner(nx, ny);
    if (dist[ex][ey] == -1) {
        dist[ex][ey] = new_time;  // 传送不花时间
        q.push({ex, ey, new_time});
    }
}
```

---

## 四、DFS vs BFS 选择指南（详细版）

### 4.1 一句话决策树

```
需要枚举所有方案 / 计数？     → DFS（回溯）
需要找最短路径 / 最少步数？   → BFS
只是遍历 / 标记连通块？       → 都可以，DFS 代码更短
状态空间特别深（>10⁴）？      → BFS（避免爆栈）
需要按字典序输出？            → DFS（天然有序）
```

### 4.2 逐条详解

#### 规则 1：求所有方案 → DFS

DFS 通过回溯可以自然地枚举所有可能路径，在递归树的叶节点收集答案。

```cpp
// P1605 迷宫 —— 数所有路径
void dfs(int x, int y) {
    if (x == fx && y == fy) { ans++; return; }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        if (valid(nx, ny) && !visited[nx][ny])
            dfs(nx, ny);
    }
    visited[x][y] = false;  // 回溯
}
```

BFS 无法做到这一点：BFS 节点出队后不会再访问，无法枚举不同路径到达同一节点的所有情况。

#### 规则 2：求最短路径 / 最少步数 → BFS

BFS 的按层扩展保证了**首次到达即最优**。DFS 需要遍历所有路径后取最小值，效率低得多。

| | BFS（P1135 电梯） | DFS（求电梯最少按键） |
|---|---|---|
| 时间复杂度 | O(n) | O(2^n)，每条可能路径都走 |
| 首次到达 | 即最优 | 不保证，需比大小 |
| 代码实现 | 队列 + dist 数组 | 回溯 + 全局 min |

```
假设电梯有 200 层，每层数字交替为 +1/-1：
→ BFS：最多访问 200 个状态，O(n)
→ DFS：可能走 2^200 条路径（不剪枝的话）
```

#### 规则 3：连通块 / 洪水填充 → DFS 代码更短，BFS 不爆栈

| | DFS | BFS |
|---|---|---|
| 代码量 | ≈4 行 | ≈12 行 |
| 最大连通块 | 受递归栈限制 (~10⁴) | 受堆内存限制 (~10⁶+) |
| 实际选择 | 网格 ≤ 1000×1000 用 DFS | 更大网格用 BFS |

> P1596 同时提供了 DFS 和 BFS 两版实现，可以直观对比。

#### 规则 4：状态空间很深 → BFS

DFS 递归深度 = 路径长度。如果解可能在很深的位置，DFS 会爆栈。

```
P1135 电梯：最坏情况需要 200 步
→ DFS 递归深度可达 200，虽然勉强安全
→ BFS 无递归栈问题

一般规律：
  深度 < 10³  → DFS 安全
  深度 10³-10⁴ → 需要检查，或开大栈
  深度 > 10⁴  → 必须 BFS 或迭代 DFS
```

#### 规则 5：需要字典序输出 → DFS

DFS 的搜索顺序天然与递归中循环遍历的顺序一致。如果按字典序遍历选项，DFS 找到的第一个解就是字典序最小的。

```cpp
// P2404 自然数拆分 —— 需要按字典序输出
void dfs(int remain, int last) {
    for (int i = last; i <= remain; i++) {  // 从小到大
        path.push_back(i);
        dfs(remain - i, i);
        path.pop_back();
    }
}
```

BFS 很难保证字典序，需要额外的排序开销。

#### 规则 6：判断是否存在解 → BFS 通常更快

如果只需要判断**是否可达**（不需要路径本身），BFS 通常能更快找到解，因为它是"广撒网"，而 DFS 可能深入一条死路很久才回头。

#### 规则 7：状态空间是图 / 有环 → BFS 天然去重

| | 有环图的最短路 | 说明 |
|---|---|---|
| BFS | ✅ 天然支持 | `dist[] == -1` 保证每个节点只访问一次 |
| DFS | ❌ 需要额外处理 | 可能无限递归，需要 `visited[]` + 回溯小心管理 |

### 4.3 快速对照表

| 问题类型 | 推荐算法 | 典型题目 |
|----------|:------:|----------|
| 最短路径（无权） | **BFS** | P1135, P1443, P1825 |
| 最少变换步数 | **BFS** | P1032 |
| 迷宫所有路径计数 | **DFS** | P1605 |
| 枚举所有方案（排列/组合/子集） | **DFS** | P1219, P2036, P2392, P2404 |
| 连通块计数 / 洪水填充 | DFS（优先） | P1596, P1162 |
| 单词接龙最长链 | **DFS** | P1019 |
| 是否存在解（不关心路径） | BFS | — |
| 时间约束下的可达性 | **BFS** | P2895 |
| 按字典序输出所有方案 | **DFS** | P2404 |
| 图的最短路（带边权 0/1） | 0-1 BFS | — |

---

## 五、BFS 常见技巧与坑

### 5.1 入队时标记 vs 出队时标记

```cpp
// ❌ 错误写法 —— 出队时才标记，导致重复入队
while (!q.empty()) {
    auto cur = q.front(); q.pop();
    visited[cur] = true;  // 太晚了！
    for (auto& next : neighbors(cur)) {
        if (!visited[next])
            q.push(next);   // 同一个 next 可能重复入队
    }
}

// ✅ 正确写法 —— 入队时立刻标记
while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (auto& next : neighbors(cur)) {
        if (!visited[next]) {
            visited[next] = true;  // 立刻标记
            q.push(next);
        }
    }
}
```

> 为什么？考虑 A 和 B 同时与 C 相邻。A 出队时发现 C，入队。B 出队时 C 还没出队（visited 仍为 false），B 又把 C 入队一次。结果：C 被重复处理，性能急剧下降。

### 5.2 dist 数组的初始化

| 场景 | 初始化 | 原因 |
|------|--------|------|
| 求最短路 | `-1`（或 INF） | `-1` 表示未访问，首次赋值即最短 |
| 只判断连通 | `false` | bool 数组即可，不需要存距离 |
| 有多个起点 | 所有起点 `dist = 0`，同时入队 | 多源 BFS |

### 5.3 BFS 状态的存储

```cpp
// 方式 A：使用 struct
struct State { int x, y, time; };
queue<State> q;

// 方式 B：使用 pair / tuple
queue<tuple<int,int,int>> q;
q.push({x, y, 0});

// 方式 C：使用多个平行队列（不推荐，容易出错）
queue<int> qx, qy, qt;
```

> 推荐方式 A（struct），可读性好，扩展方便。

### 5.4 双向 BFS（进阶）

当状态空间很大但起点和终点都已知时，可以从两端同时 BFS，在中间相遇。

```
P1032 字串变换：搜索深度 ≤ 10
  单向 BFS：最坏 6^10 个状态
  双向 BFS：最坏 2 × 6^5 个状态，大幅剪枝
```

### 5.5 0-1 BFS（进阶）

当边权只有 0 和 1 时，用 `deque` 代替 `queue`：边权 0 的放队首，边权 1 的放队尾。

```
适用场景：传送门不消耗步数、走草地 1 步走道路 0 步等
```

---

## 六、BFS 的局限性

| 局限 | 说明 | 解决方案 |
|------|------|----------|
| 边权不为 1 | BFS 只能处理无权图 | Dijkstra / SPFA |
| 状态空间巨大 | 队列可能爆内存 | 双向 BFS / A* / IDA* |
| 需要记录路径 | BFS 只能给出距离 | 额外用 `pre[]` 数组记录前驱 |
| 不能求所有方案 | BFS 每个状态只访问一次 | 用 DFS 回溯 |

### 记录路径的方法

```cpp
// 在 BFS 中记录前驱，最后回溯输出路径
int pre[MAXN];  // pre[v] = u 表示 v 由 u 扩展而来
memset(pre, -1, sizeof(pre));

// BFS 时：
pre[neighbor] = cur;

// 回溯输出：
vector<int> path;
for (int v = target; v != -1; v = pre[v])
    path.push_back(v);
reverse(path.begin(), path.end());
```

---

## 七、DFS 与 BFS 的本质区别

```
              DFS                          BFS
           ┌─────────────────┐        ┌─────────────────┐
           │  栈 (递归/显式)  │        │     队列         │
           │  纵深优先        │        │  广度优先         │
           │  一条路走到黑    │        │  一层一层扫       │
           │  天然适合回溯    │        │  天然适合最短路   │
           │  空间 O(深度)    │        │  空间 O(宽度)     │
           └─────────────────┘        └─────────────────┘

共同的底层逻辑：
  → 都是「状态空间搜索」
  → 都需要 visited / dist 避免重复访问
  → 都能解决连通性问题
  → 区别只在于「下一个扩展谁」的策略不同
```

### 七字口诀

> **最短用 BFS，计数用 DFS，连通随便选，深了要 BFS。**

---

## 八、学习路线

```
★☆☆ BFS 入门：最短路模板 + 洪水填充对比
     P1135（一维最短路）→ P1443（二维最短路）→ P1596（BFS vs DFS 对比）

★★☆ BFS 进阶：带额外状态
     P1825（传送门）→ 更多网格变种

★★★ BFS 高阶：状态空间 + 约束
     P2895（时间维度）→ P1032（字符串状态空间）→ 双向 BFS / 0-1 BFS
```

> 建议学完 DFS_NOTES 后来看本篇，对比 P1596 的 DFS/BFS 两版实现，体会两种搜索在连通块上的写法差异。最短路类问题优先选择 BFS。
