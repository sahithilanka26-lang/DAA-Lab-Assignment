
#include <stdio.h>

#define N 9
#define MAX 17

struct Node {
    char ch;
    int freq, left, right, parent;
} h[MAX];

int minNode(int n) {
    int m = -1;
    for (int i = 0; i < n; i++) {
        if (h[i].parent == -1 &&
            (m == -1 || h[i].freq < h[m].freq))
            m = i;
    }
    return m;
}

int main() {
    char ch[] = {'a','c','d','e','o','m','s','t','u'};
    int f[] = {20,11,2,10,15,8,10,22,2};

    for (int i = 0; i < N; i++) {
        h[i].ch = ch[i];
        h[i].freq = f[i];
        h[i].left = h[i].right = -1;
        h[i].parent = -1;
    }

    int n = N, step = 1;

    while (n < MAX) {
        int x = minNode(n);
        h[x].parent = n;

        int y = minNode(n);
        h[y].parent = n;

        h[n].ch = '#';
        h[n].freq = h[x].freq + h[y].freq;
        h[n].left = x;
        h[n].right = y;
        h[n].parent = -1;

        printf("Step %d: %d + %d = %d\n",
               step++, h[x].freq, h[y].freq, h[n].freq);
        n++;
    }

    printf("Huffman tree constructed successfully.\n");
    return 0;
}
