#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// 创建一个新节点
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

// 向图中添加边
void addEdge(Node** graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;
}

// 深度优先搜索，计算改变安装状态的软件包数
int dfs(Node** graph, int* installed, int node) {
    int changes = 0;
    Node* current = graph[node];
    while (current != NULL) {
        if (!installed[current->value]) {
            installed[current->value] = 1;
            changes++;
            changes += dfs(graph, installed, current->value);
        }
        current = current->next;
    }
    return changes;
}

int main() {
    int n;
    scanf("%d", &n);

    Node** graph = (Node**)malloc(n * sizeof(Node*));
    int* installed = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n - 1; i++) {
        int dependency;
        scanf("%d", &dependency);
        addEdge(graph, i + 1, dependency);
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        char operation[10];
        int x;
        scanf("%s %d", operation, &x);
        if (operation[0] == 'i') {
            installed[x] = 1;
        } else {
            installed[x] = 0;
        }
        int changes = dfs(graph, installed, x);
        printf("%d\n", changes);
    }

    for (int i = 0; i < n; i++) {
        Node* current = graph[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);
    free(installed);

    return 0;
}