#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int *queue = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    int *gifts = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &gifts[i]);
    }

    int count = 0;
    while (n > 0 && m > 0)
    {
        if (queue[0] == gifts[0])
        {
            for (int i = 0; i < n - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            n--;
            for (int i = 0; i < m - 1; i++)
            {
                gifts[i] = gifts[i + 1];
            }
            m--;
            count = 0;
        }
        else
        {
            int temp = queue[0];
            for (int i = 0; i < n - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            queue[n - 1] = temp;
            count++;
            if(count == n) break;
        }
    }

    printf("%d\n", count);

    free(queue);
    free(gifts);

    return 0;
}
