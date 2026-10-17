
#include <stdio.h>

#define N 9
#define MAX 17

struct Node {
    char ch;
    int freq, left, right, parent;
} h[MAX];

char code[N];

int minNode(int n) {
    int m = -1;
    for (int i = 0; i < n; i++) {
        if (h[i].parent == -1 &&
            (m == -1 || h[i].freq < h[m].freq))
            m = i;
    }
    return m;
}

void printCode(int root, int depth) {
    if (h[root].left == -1 && h[root].right == -1) {
        code[depth] = '\0';
        printf("%c\t%d\t%s\n",
               h[root].ch, h[root].freq, code);
        return;
    }

    code[depth] = '0';
    printCode(h[root].left, depth + 1);

    code[depth] = '1';
    printCode(h[root].right, depth + 1);
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

    int n = N;

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
        n++;
    }

    printf("Character\tFrequency\tHuffman Code\n");
    printCode(MAX - 1, 0);

    return 0;
}
