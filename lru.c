#include <stdio.h>

void main() {
    int i, j, k, n, f, pf = 0;
    int m[25], used[25] = {0}, rs[50];

    printf("Enter the length: ");
    scanf("%d", &n);

    printf("Reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        m[i] = -1;
        used[i] = -1;
    }

    printf("Page Replacement\n");
    
    for (i = 0; i < n; i++) {
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                used[k] = i; 
                break;
            }
        }

        if (k == f) {
            int minIndex = 0;
            for (j = 1; j < f; j++) {
                if (used[j] < used[minIndex]) {
                    minIndex = j;
                }
            }
            m[minIndex] = rs[i];
            used[minIndex] = i;
            pf++;
        }

        for (j = 0; j < f; j++) {
            if (m[j] != -1) {
                printf("%d\t", m[j]);
            } else {
                printf("-\t");
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", pf);
}
