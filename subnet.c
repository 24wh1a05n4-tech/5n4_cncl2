#include <stdio.h>

int distance[20];
int n;

int min(void);

int main(void)
{
    int adj[20][20], adj1[20][20] = {0}, flag[20];
    int i, j, root, x;
    int source, count = 1, y = 0;

    printf("Enter no of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the source for broadcasting: ");
    scanf("%d", &source);

    for (i = 0; i < n; i++)
    {
        flag[i] = 0;
    }

    for (root = 0; root < n; root++)
    {
        for (i = 0; i < n; i++)
        {
            distance[i] = adj[root][i];
        }

        x = min();

        for (i = 0; i < n; i++)
        {
            if (distance[i] == x && x != 0)
            {
                adj1[root][i] = x;
                adj1[i][root] = x;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj1[i][j] != 0)
            {
                adj1[j][i] = adj[i][j];
            }
        }
    }

    printf("\nGiven adjacency matrix is:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimal spanning tree:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adj1[i][j]);
        }
        printf("\n");
    }

    root = source;
    flag[root] = 1;

    printf("\nBroadcasting messages:\n");

    while (count != y)
    {
        for (i = 0; i < n; i++)
        {
            if (adj1[root][i] != 0 &&
                flag[root] == 1 &&
                flag[i] != 1)
            {
                printf("%d sends message to %d\n", root, i);
                flag[i] = 1;
            }
        }

        if (root < n - 1)
            root++;
        else
            root = 0;

        for (i = 0; i < n; i++)
        {
            if (flag[i] == 0)
                break;
        }

        if (i == n)
            count = y;
    }

    return 0;
}

int min(void)
{
    int i, min = 999;

    for (i = 0; i < n; i++)
    {
        if (distance[i] != 0 && distance[i] < min)
        {
            min = distance[i];
        }
    }

    return min;
}