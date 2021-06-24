#include "mylib.h"

int main()
{

    cgraph_ivec_t edges = cgraph_ivec_create();
    FILE *fptr;
    fptr = fopen("input.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!\n Cannot open file.\n");
    }
    int sodinh, socanh;
    fscanf(fptr, "%d %d\n", &sodinh, &socanh);
    for (int i = 1; i <= socanh; i++)
    {
        int u, v;
        fscanf(fptr, "%d %d\n", &u, &v);
        cgraph_ivec_push_back(&edges, u);
        cgraph_ivec_push_back(&edges, v);
    }
    cgraph_t g = cgraph_create(edges, 0, true);
    int w[] = {9, 24, 6, 2, 18, 6, 11, 30, 20, 14, 15, 44, 16, 19, 12, 23, 56, 1, 6, 23, 12, 22, 34, 2, 8, 43, 56, 12, 11, 15, 17, 25};
    cgraph_ivec_t weights = cgraph_ivec_from_array(w, sizeof(w));
    int parent[g->n];
    printf("****** MENU ********\n");
    printf("1. In Prufer Code\n");
    printf("2. In Father Code\n");
    printf("3. Prim MST\n");
    printf("4. Kruskal MST\n");
    printf("5. DFS\n");
    printf("6. BFS\n");
    printf("7. Tìm thành phần liên thông mạnh\n");
    printf("8. Kiểm tra đồ thị có tru trình ?\n");
    printf("9. Sắp topo cho đồ thị\n");
    printf("10. Tìm đường đi ngắn nhất\n");
    printf("11. Tô màu cho đồ thị\n");
    printf("12. Thoát\n");

    int choice;
    do
    {
        printf("Nhập lựa chọn: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Prufer code: ");
            cgraph_ivec_t p = cgraph_ivec_create();
            prufer(g, p);
        }
        else if (choice == 2)
        {
            printf("Father code: ");
            print_fathercode(g);
        }
        else if (choice == 3)
        {
            printf("\nPrim:\n");
            find_mst(g, weights);
        }
        else if (choice == 4)
        {
            printf("\nKruskal:\n");
            print_kruskal(g, parent, weights);
        }
        else if (choice == 5)
        {
            printf("DFS\n");
            print_dfs(g);
        }
        else if (choice == 6)
        {
            int u;
            printf("Nhập vào đỉnh duyệt BFS:");
            scanf("%d", &u);
            print_bfs(g, u);
        }
        else if (choice == 7)
        {
            find_scc(g);
        }
        else if (choice == 8)
        {
            if (cgraph_is_dag(g))
            {
                printf("Là DAG\n");
            }
            else
                printf("Không là DAG\n");
        }
        else if (choice == 9)
        {
            if (cgraph_is_dag(g))
            {
                cgraph_ivec_t res = cgraph_ivec_create();
                cgraph_topological_sorting(g, &res, CGRAPH_OUT);
                for (int i = 0; i < cgraph_ivec_size(res); i++)
                {
                    printf("%d ", res[i]);
                }
                printf("\n");
            }
            else
                printf("Không thể sắp topo cho đồ thị có chu trình\n");
        }
        else if (choice == 10)
        {
            int u, v;
            printf("Nhập vào đỉnh đi: ");
            scanf("%d", &u);
            printf("Nhập vào đỉnh đến: ");
            scanf("%d", &v);
            cgraph_ivec_t res = cgraph_ivec_create();
            cgraph_ivec_t resedges = cgraph_ivec_create();
            cgraph_get_shortest_path_dijkstra(g, &res, &resedges, u, v, weights, CGRAPH_OUT);
            if (cgraph_ivec_size(res) == 0)
            {
                printf("Không có đường đi\n");
            }
            else
            {
                for (int i = 0; i < cgraph_ivec_size(res); i++)
                {
                    printf("%d ", res[i]);
                }
                printf("\n");
            }
        }
        else if (choice == 11)
        {
            colorgraph(g);
        }
        else
            printf("Xin mời chọn lại\n");
    } while (choice != 12);
    cgraph_ivec_free(&edges);
    cgraph_ivec_free(&weights);
    return 0;
}
