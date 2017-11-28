#include <stdio.h>

using namespace std;

/* Routing table */

typedef struct {
    int dist;
    int nextHop;
    bool connected;
} Table;

/* Global variables */

int n,m; // n = nodes, m = edges
int x,y; // x and y = interconnected nodes
int s; // s = table exchange scenario

Table table[1001][1001]; // table[x][y] = x's table for node y

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i == j)
            {
                table[i][j].dist = 0;
                table[i][j].nextHop = i;
                table[i][j].connected = true;
            }
            else
            {
                table[i][j].dist = -1;
                table[i][j].nextHop = -1;
                table[i][j].connected = false;
            }
        }
    }

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);

        table[x][y].dist = 1;
        table[x][y].nextHop = y;
        table[x][y].connected = true;

        table[y][x].dist = 1;
        table[y][x].nextHop = x;
        table[y][x].connected = true;
    }

    //scanf("%d",&s);

    return 0;
}