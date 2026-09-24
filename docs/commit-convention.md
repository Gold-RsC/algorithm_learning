# 提交信息规范

本仓库所有 commit message 按下面的写法组织。

## 基本格式

```
<图标><模块>(<类型>): <主题>
```

```text
✨template(update): 网络流
✏️practice(add): 二分图
🚩competition(add): 河北 9
🗑️tmp(add): 测试代码
```

## 硬性规则

1. **图标和模块名紧挨着**，中间不加空格。写 `✨template`，不写 `✨ template`。
2. **括号里放提交类型**，英文小写，取值见下面的表。
3. **冒号一律用英文冒号加一个空格**（`: `）。全文不出现中文冒号「：」。
4. **一行只写一个主题**。一次提交涉及几个主题就写几行：

   ```text
   ✏️practice(add): 二分图
   ✏️practice(add): 最大流
   ```

5. **同一主题内的并列项用「、」**，不再拆行：

   ```text
   ✨template(add): 最小生成树、二分图、线段树
   ```

6. **不写题目编号**。`P1616`、`AcWing102`、`poj1273`、`UVA455`、`LibreOJ10147` 这类编号一律不出现，改了哪些题看 diff 就知道。
7. **不出现 `/`**。

## 一个主题里新增和修改同时出现

只写一行，类型写 `add`。加新题往往连带更新配套模板，用 `add` 概括即可。

```text
✏️practice(add): 最大流      ← 既加了新题，又改了同目录的 template.cpp
```

在已有内容上继续改（补题、修板子）而**没有新增文件**时才写 `update`：

```text
🚩competition(update): CCPC 河北 9     ← 赛后补题
```

## 模块与图标

| 图标 | 模块 | 对应目录 / 文件 |
| --- | --- | --- |
| ✨ | `template` | `template/` |
| ✏️ | `practice` | `practice/` |
| 🚩 | `competition` | `competitions/` |
| 🗑️ | `tmp` | `tmp/` |
| 📝 | `docs` | `README.md`、`docs/`、`Question.md` |
| 🚚 | `chore` | 跨模块的整理（仓库级改名、移动、清理） |

## 提交类型

| 类型 | 含义 |
| --- | --- |
| `add` | 新增 |
| `update` | 修改 |
| `delete` | 删除 |
| `move` | 移动 / 改名 |
| `fix` | 修正错误 |

## 冒号后的主题

取所改文件**最近一级目录名**对应的知识点。

| 目录 | 主题 |
| --- | --- |
| `practice/tu2lun4/MST/` | 最小生成树 |
| `practice/tu2lun4/er4fen1tu2/` | 二分图 |
| `practice/tu2lun4/lian2tong1xing4/` | 连通性 |
| `practice/tu2lun4/wang3luo4liu2/max_flow/` | 最大流 |
| `practice/tu2lun4/zui4duan3lu4/` | 最短路 |
| `practice/tu2lun4/tree/LCA/` | 最近公共祖先 |
| `practice/tu2lun4/tree/center/` | 树的中心 |
| `practice/dp/bei1bao1dp/` | 背包 |
| `practice/dp/zhuang4tai4ya1suo1/` | 状压 DP |
| `practice/pai2xu4/` | 排序 |
| `practice/er4fen1/` | 二分 |
| `practice/math/prime/` | 质数 |
| `practice/qian2zhui4he2cha1fen1/` | 前缀和与差分 |
| `template/` 里的某块板子 | 直接写板子名，如 `网络流`、`Dijkstra` |
| `competitions/<赛事>/` | 赛事名 + 场次，如 `CCPC 河北 9`、`科中周赛 4` |

同一赛事的不同场次算同一个主题，用「、」并列：

```text
🚩competition(add): 科中周赛 1、2
```

`practice/` 下面的 `template.cpp` 属于 `practice`，**不算** `✨template`——`✨template` 只指 `template/` 目录本身。

## 模块内的改名 / 移动

用**受影响模块**的图标，类型写 `move`：

```text
✏️practice(move): tu3lun4 重命名为 tu2lun4
🚩competition(move): weekly_competition 重命名为 competitions
```

只有跨模块、说不清归属的整理才用 🚚`chore`：

```text
🚚chore(delete): 清理各目录下的 .vscode/tasks.json
```

## 正反例

对的：

```text
✨template(update): 网络流
✏️practice(add): 网络流
✏️practice(add): 连通性
```

错的：

```text
✨template：网络流                     ← 中文冒号
✨ template(update): 网络流            ← 图标和模块名之间有空格
✏️practice(add): 二分图/最大流         ← 用 / 并列，应该分成两行
✏️practice(tu2lun4/max_flow): 最大流   ← 括号里应是类型不是目录，且出现了 /
✏️practice(add): 最大流 poj1273        ← 写了题目编号
```

## 其它

- commit message 统一 UTF-8。git 本身就按 UTF-8 存 message，而且上面这些图标 GBK 也编码不了。
- `docs/` 下的 Markdown 文档统一 UTF-8，本文档也是。
