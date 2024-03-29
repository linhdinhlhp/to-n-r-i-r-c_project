void prufer(cgraph_t g, cgraph_ivec_t prufer)
{
    int sz[g->n];
    for (int i = 0; i < g->n; i++)
    {
        sz[i] = 0;
    }
    bool adj[g->n][g->n];
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < cgraph_ivec_size(g->from); i++)
    {
        sz[g->from[i]]++;
        sz[g->to[i]]++;
        adj[g->from[i]][g->to[i]] = 1;
        adj[g->to[i]][g->from[i]] = 1;
    }
    for (int j = 1; j < g->n - 1; j++)
    {
        for (int i = 1; i <= g->n; i++)
        {
            if (sz[i] == 1)
            {
                for (int v = 0; v < g->n; v++)
                {
                    if (adj[i][v])
                    {
                        cgraph_ivec_push_back(&prufer, v);
                        adj[i][v] = 0;
                        adj[v][i] = 0;
                        sz[i]--;
                        sz[v]--;
                    }
                }
                break;
            }
        }
    }
    if (cgraph_ivec_size(prufer) < cgraph_ivec_size(g->from) - 1)
    {
        printf("Không phải là cây !\n");
    }
    else
    {
        printf("Prufer code: ");
        cgraph_ivec_print(prufer);
    }
}

void print_dfs(cgraph_t g)
{
    cgraph_ivec_t order = cgraph_ivec_create(),
                  order_out = cgraph_ivec_create(),
                  father = cgraph_ivec_create(),
                  dist = cgraph_ivec_create();
    cgraph_dfs(g, 0, CGRAPH_OUT, true, &order, &order_out, &father, &dist);
    for (int i = 0; i < cgraph_ivec_size(order); i++)
    {
        printf("%d ", order[i]);
    }
    printf("\n");
}
void print_bfs(cgraph_t g, int u)
{
    cgraph_ivec_t father = cgraph_ivec_create(),
                  dist = cgraph_ivec_create();
    cgraph_simple_bfs(g, u, CGRAPH_OUT, 0, &father, &dist);
    printf("Từ đỉnh %d đi tới được : ", u);
    for (int i = 0; i < cgraph_ivec_size(dist); i++)
    {
        if (dist[i] >= 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int minKey(int key[], bool mstSet[], cgraph_t g)
{
    int min = INT_MAX;
    int minkey;
    for (int v = 0; v < g->n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], minkey = v;
    return minkey;
}
void restructgraph(cgraph_t g, cgraph_ivec_t weights, int graph[g->n][g->n])
{
    for (int i = 0; i < g->n; i++)
    {
        for (int j = i; j < g->n; j++)
        {
            graph[i][j] = 0;
            graph[j][i] = 0;
        }
    }
    for (int i = 0; i < cgraph_ivec_size(g->from); i++) //tranform graph
    {
        graph[g->from[i]][g->to[i]] = weights[i];
        graph[g->to[i]][g->from[i]] = weights[i];
    }
}

cgraph_t find_mst(cgraph_t g, cgraph_ivec_t weights)
{
    int graph[g->n][g->n];
    int mincost = 0;
    restructgraph(g, weights, graph);
    int parent[g->n];
    int key[g->n];
    bool mstSet[g->n];

    for (int i = 0; i < g->n; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < g->n - 1; i++)
    {
        int u = minKey(key, mstSet, g);
        mstSet[u] = true;
        for (int v = 0; v < g->n; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cgraph_ivec_t mst = cgraph_ivec_create();
    printf("Edge \tWeight\n");
    FILE *fptr1 = fopen("primmst.dot", "w");
    if (fptr1 == NULL)
    {
        printf("Error!\n Cannot open file.\n");
    }
    fprintf(fptr1, "graph mst\n{\n");
    for (int i = 1; i < g->n; i++)
    {
        fprintf(fptr1, "%d -- %d;\n", parent[i], i);
        cgraph_ivec_push_back(&mst, parent[i]);
        cgraph_ivec_push_back(&mst, i);
        mincost += graph[i][parent[i]];
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
    fprintf(fptr1, "}");
    fclose(fptr1);
    printf("Minimum cost: %d\n", mincost);
    cgraph_t MST = cgraph_create(mst, 0, true);
    return MST;
}

cgraph_t reversegraph(cgraph_t g)
{
    int *a = (int *)malloc(cgraph_ivec_size(g->from) * 2 * sizeof(int));
    for (int i = 0; i < cgraph_ivec_size(g->from) * 2; i += 2)
    {
        a[i] = g->to[i / 2];
        a[i + 1] = g->from[i / 2];
    }
    cgraph_ivec_t edges = cgraph_ivec_from_array(a, cgraph_ivec_size(g->from) * 2);
    cgraph_t gr = cgraph_create(edges, 0, true);
    return gr;
}
void print_fathercode(cgraph_t g)
{
    cgraph_ivec_t father = cgraph_ivec_create(),
                  dist = cgraph_ivec_create();

    cgraph_simple_bfs(g, 0, CGRAPH_ALL, 0, &father, &dist);
    for (int i = 1; i < cgraph_ivec_size(father); i++)
    {
        printf("%d ", father[i]);
    }
    printf("\n");
}
void find_scc(cgraph_t g)
{

    cgraph_t gr = reversegraph(g);
    cgraph_ivec_t order = cgraph_ivec_create(),
                  order_out = cgraph_ivec_create(),
                  father = cgraph_ivec_create(),
                  dist = cgraph_ivec_create();
    cgraph_dfs(gr, 0, CGRAPH_OUT, true, &order, &order_out, &father, &dist);
    int sz = cgraph_ivec_size(order_out);
    bool visited[g->n];
    for (int i = 0; i < g->n; i++)
    {
        visited[i] = false;
    }
    int cc = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        if (visited[order_out[i]] == false)
        {
            cc++;
            printf("Thành phần liên thông mạnh thứ %d gồm: ", cc);
            cgraph_ivec_t sorder = cgraph_ivec_create(),
                          sorder_out = cgraph_ivec_create(),
                          sfather = cgraph_ivec_create(),
                          sdist = cgraph_ivec_create();
            cgraph_dfs(g, order_out[i], CGRAPH_OUT, false, &sorder, &sorder_out, &sfather, &sdist);
            for (int j = 0; j < sz; j++)
            {
                if (sorder_out[j] != CGRAPH_NAN && visited[sorder_out[j]] == false)
                {
                    printf("%d ", sorder_out[j]);
                    visited[sorder_out[j]] = true;
                }
            }
            printf("\n");
        }
    }
    printf("Số thành phần liên thông mạnh: %d\n", cc);
}
void printMST(int a[], int b[], int weight[], cgraph_t g)
{
    int mincost = 0;
    FILE *fptr1 = fopen("kruskalmst.dot", "w");
    if (fptr1 == NULL)
    {
        printf("Error!\n Cannot open file.\n");
    }
    fprintf(fptr1, "graph mst\n{\n");
    printf("Edge \tWeight\n");
    for (int i = 0; i < g->n - 1; i++)
    {
        fprintf(fptr1, "%d -- %d;\n", a[i], b[i]);
        printf("%d - %d\t%d\n", a[i], b[i], weight[i]);
        mincost = mincost + weight[i];
    }
    fprintf(fptr1, "}");
    fclose(fptr1);
    printf("Mincost = %d\n", mincost);
}

int findParent(int node, int parent[])
{
    while (parent[node] >= 0)
    {
        node = parent[node];
    }
    return node;
}

int findParentPathCompression(int node, int parent[])
{
    if (node == parent[node])
    {
        return node;
    }

    return parent[node] = findParentPathCompression(parent[node], parent);
}

void print_kruskal(cgraph_t g, int parent[], cgraph_ivec_t weights)
{
    int u, v, m = 0, count = 0;
    int firstNode, secondNode;
    int a[g->n];
    int b[g->n];
    int weight[g->n];
    int min;
    int graph[g->n][g->n];
    restructgraph(g, weights, graph);
    for (int i = 0; i < g->n; i++)
    {
        parent[i] = -1;
    }
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }
    while (count < g->n - 1)
    {
        min = INT_MAX;

        for (int i = 0; i < g->n; i++)
        {
            for (int j = 0; j < g->n; j++)
            {
                if (graph[i][j] < min)
                {
                    min = graph[i][j];
                    firstNode = i;
                    secondNode = j;
                }
            }
        }

        u = findParent(firstNode, parent);
        v = findParent(secondNode, parent);

        if (u != v)
        {
            parent[v] = u;
            a[m] = firstNode;
            b[m] = secondNode;
            weight[m] = graph[firstNode][secondNode];
            count++;
            m++;
        }
        graph[firstNode][secondNode] = graph[secondNode][firstNode] = INT_MAX;
    }

    printMST(a, b, weight, g);
}
void colorgraph(cgraph_t g)
{
    bool adj[g->n][g->n];
    for (int i = 0; i < g->n; i++)
    {
        for (int j = 0; j < g->n; j++)
        {
            adj[i][j] = 0;
        }
    }
    int color[g->n];
    for (int i = 0; i < g->n; i++)
    {
        color[i] = 0;
    }
    int visited[g->n];
    for (int i = 0; i < cgraph_ivec_size(g->from); i++)
    {
        adj[g->from[i]][g->to[i]] = 1;
        adj[g->to[i]][g->from[i]] = 1;
    }
    color[0] = 1;
    for (int j = 1; j < g->n; j++)
    {
        int count_nei = 0;
        int color_adj[1000];
        for (int i = 0; i < g->n; i++)
        {
            if (adj[i][j] == 1 && color[i] != 0)
            {
                color_adj[count_nei] = color[i];
                count_nei++;
            }
        }
        for (int i = 1; i <= g->n; i++)
        {
            visited[i] = 0;
        }
        for (int i = 0; i < count_nei; i++)
        {
            visited[color_adj[i]] = 1;
        }
        for (int i = 1; i <= g->n; i++)
        {
            if (visited[i] == 0)
            {
                color[j] = i;
                break;
            }
        }
    }
    for (int i = 0; i < g->n; i++)
    {
        printf("%d %d\n", i, color[i]);
    }
    const char *colorlist[] = {"yellow", "red", "blue", "LightSlateGrey", "green", "black", "pink",
                               "grey", "light steel blue", "DarkGreen", "DarkSeaGreen", "DarkKhaki",
                               "ivory3", "LightCyan2", "CadetBlue4", "SeaGreen4",
                               "chartreuse4", "white", "goldenrod3", "gold3", "tan4",
                               "coral1", "pink4", "blue4", "goldenrod", "LightGreen", "maroon1",
                               "sgi beet", "SGIMediumGrey", "Crimson", "dark grey", "HotPink", "bisque1"};
    FILE *fptr1 = fopen("dothitomau.dot", "w");
    if (fptr1 == NULL)
    {
        printf("Error!\n Cannot open file.\n");
    }
    fprintf(fptr1, "graph dothi\n{\n");
    for (int i = 0; i < g->n; i++)
    {
        fprintf(fptr1, "%d [fillcolor= %s, style=filled];\n", i, colorlist[color[i]]);
    }
    for (int i = 0; i < cgraph_ivec_size(g->from); i++)
    {

        fprintf(fptr1, "%d -- %d;\n", g->from[i], g->to[i]);
    }
    fprintf(fptr1, "}");
    fclose(fptr1);
}