#include <stdio.h>

#define MAX 10
#define INF 99

int n;

typedef struct
{
    char adj_new[MAX];
    char adj_old[MAX];
    int table_new[MAX];
    int table_old[MAX];
} Router;

Router r[MAX];

void init_router(int j)
{
    int i;

    for (i = 0; i < n; i++)
    {
        r[j].table_new[i] = INF;
        r[j].table_old[i] = INF;
        r[j].adj_new[i] = (char)('A' + i);
        r[j].adj_old[i] = (char)('A' + i);
    }
}

void copy_table(int j)
{
    int i;

    for (i = 0; i < n; i++)
    {
        r[j].adj_old[i] = r[j].adj_new[i];
        r[j].table_old[i] = r[j].table_new[i];
    }
}

int equal_table(int j)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (r[j].table_old[i] != r[j].table_new[i] ||
            r[j].adj_old[i] != r[j].adj_new[i])
        {
            return 0;
        }
    }

    return 1;
}

void input_router(int j)
{
    int i;

    printf("\nEnter routing table for Router %c:\n", (char)('A' + j));
    printf("Enter the cost to:\n");

    for (i = 0; i < n; i++)
    {
        if (i == j)
        {
            r[j].table_new[i] = 0;
        }
        else
        {
            printf("Router %c: ", (char)('A' + i));
            scanf("%d", &r[j].table_new[i]);
        }

        r[j].adj_new[i] = (char)('A' + i);
    }
}

void build(int j)
{
    int i, k;

    for (i = 0; i < n; i++)
    {
        if (i == j)
            continue;

        for (k = 0; k < n; k++)
        {
            if (r[j].table_new[i] != INF &&
                r[i].table_new[k] != INF)
            {
                if (r[j].table_new[i] + r[i].table_new[k] <
                    r[j].table_new[k])
                {
                    r[j].table_new[k] =
                        r[j].table_new[i] + r[i].table_new[k];

                    r[j].adj_new[k] = (char)('A' + i);
                }
            }
        }
    }
}

void build_table(void)
{
    int i;
    int changed;

    do
    {
        changed = 0;

        for (i = 0; i < n; i++)
        {
            copy_table(i);
        }

        for (i = 0; i < n; i++)
        {
            build(i);
        }

        for (i = 0; i < n; i++)
        {
            if (!equal_table(i))
            {
                changed = 1;
                break;
            }
        }

    } while (changed);
}

void display(int j)
{
    int i;

    printf("\n\nRouter Table for Router %c\n", (char)('A' + j));
    printf("Destination\tNext Hop\tHop Count\n");

    for (i = 0; i < n; i++)
    {
        printf(" %c\t\t %c\t\t %d\n",
               (char)('A' + i),
               r[j].adj_new[i],
               r[j].table_new[i]);
    }
}

int main(void)
{
    int i;

    printf("Enter the number of routers (maximum %d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of routers.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        init_router(i);
    }

    for (i = 0; i < n; i++)
    {
        input_router(i);
    }

    build_table();

    for (i = 0; i < n; i++)
    {
        display(i);
    }

    return 0;
}