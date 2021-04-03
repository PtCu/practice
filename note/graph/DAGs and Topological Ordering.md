## Directed Acyclic Graphs

**Def**.  An DAG is a directed graph that contains no directed cycles. DAG是一个没有环的有向图

**Ex**.  Precedence constraints:  edge (vi, vj) means vi must precede vj.

**Def**.  A topological order of a directed graph G = (V, E) is an ordering of its nodes as v1, v2, …, vn so that for every edge (vi, vj) we have i < j.

**Lemma**.  If G is a DAG, then G has a topological ordering.

**Theorem**.  Algorithm finds a topological order in O(m + n) time.

    1. 从 DAG 图中选择一个 没有前驱（即入度为0）的顶点并输出。
    2. 从图中删除该顶点和所有以它为起点的有向边。
    3. 重复 1 和 2 直到当前的 DAG 图为空或当前图中不存在无前驱的顶点为止。后一种情况说明有向图中必然存在环。