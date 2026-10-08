#include <stdio.h>

void sort(void);

static int dsp[10][10], nodes;

struct
{
    char src;
    char dest;
    int length;
} stemp, permanent[10] = {{' ', ' ', 0}}, temp[10] = {{' ', ' ', -1}};

static int perm, tem;

int main()
{
    int i, j, k, l, m, n = 0, point;
    char initial, dest, path[10] = {' '};

    printf("\t\tShortest Path (Dijkstra's algorithm)");
    printf("\n*******************************************************");

    printf("\nEnter the number of nodes: ");
    scanf("%d", &nodes);

    printf("\nEnter the adjacency matrix for the graph:\n");

    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            scanf("%d", &dsp[i][j]);
        }
    }

    printf("\nEnter the source node: ");
    scanf(" %c", &initial);

    printf("\nEnter the destination node: ");
    scanf(" %c", &dest);

    permanent[perm].src = initial;
    permanent[perm].dest = initial;
    permanent[perm++].length = 0;

    i = permanent[perm - 1].dest - 97;

    for (j = 0; j < nodes; j++)
    {
        if (i != j)
        {
            if (dsp[i][j] > 0)
            {
                temp[tem].src = permanent[perm - 1].src;
                temp[tem].dest = j + 97;
                temp[tem++].length = dsp[i][j];
            }
        }
    }

    sort();

    while (tem >= 0)
    {
        j = permanent[perm - 1].dest - 97;

        for (i = 0; i < nodes; i++)
        {
            if (i != initial - 97)
            {
                if (dsp[j][i] > 0)
                {
                    l = -1;

                    for (k = 0; k < perm; k++)
                    {
                        if (permanent[k].dest == (i + 97))
                            l = k;
                    }

                    for (k = 0; k <= tem; k++)
                    {
                        if (temp[k].dest == (i + 97))
                            l = k;
                    }

                    if (l < 0)
                    {
                        temp[tem].src = j + 97;
                        temp[tem].dest = i + 97;

                        for (m = 0; m < perm; m++)
                        {
                            if (permanent[m].dest == temp[tem].src)
                                n = permanent[m].length;
                        }

                        temp[tem++].length = dsp[j][i] + n;
                    }
                    else
                    {
                        for (m = 0; m < perm; m++)
                        {
                            if (permanent[m].dest == j + 97)
                            {
                                n = permanent[m].length + dsp[j][i];
                                break;
                            }
                            else
                            {
                                n = dsp[j][i];
                            }
                        }

                        if (n < temp[l].length)
                        {
                            temp[l].length = n;
                            temp[l].src = j + 97;
                            temp[l].dest = i + 97;
                        }
                    }
                }
            }
        }

        sort();
    }

    printf("\nShortest path:\n");
    printf("From %c to %c is: ", initial, dest);

    for (i = 0; i < perm - 1; i++)
    {
        if (permanent[i].dest == dest)
        {
            point = i;
            n = i;
            break;
        }
    }

    i = 0;

    for (j = perm; j > 0; j--)
    {
        if (permanent[j - 1].dest == permanent[point].src)
        {
            path[i++] = permanent[point].dest;
            point = j - 1;
        }
    }

    path[i] = initial;

    for (j = i; j >= 0; j--)
        printf("%c ", path[j]);

    printf("\tlength=%d", permanent[n].length);

    return 0;
}

void sort()
{
    int i, j, k;

    for (i = 0; i <= tem; i++)
    {
        k = 1;

        for (j = 0; j <= tem; j++)
        {
            if (temp[j].length <= temp[j + 1].length)
            {
                stemp = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = stemp;
                k = 0;
            }
        }

        if (k)
            break;
    }

    permanent[perm++] = temp[tem - 1];

    temp[tem - 1].src = ' ';
    temp[tem - 1].dest = ' ';
    temp[tem - 1].length = -1;

    tem--;
}