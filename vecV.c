#include "libs/data_structures/vector/vectorVoid.c"

int main() {
    size_t n;
    scanf("%zd", &n);
    vectorVoid vec = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pushBackV(&vec, &x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&vec, i, &x);
        printf("%d ", x);
    }

    return 0;
}
