#include <stdio.h>

int main() {
    int i, j, n, time, remain, flag = 0, ts;
    float totwtime = 0, totttime = 0;
    int at[10], bt[10], rt[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time slice: ");
    scanf("%d", &ts);

    for(time = 0, i = 0; remain != 0;) {
        if(rt[i] <= ts && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if(rt[i] > 0) {
            rt[i] -= ts;
            time += ts;
        }

        if(rt[i] == 0 && flag == 1) {
            remain--;
            totwtime += time - at[i] - bt[i];
            totttime += time - at[i];
            flag = 0;
        }

        if(i == n - 1)
            i = 0;
        else if(at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nTotal waiting time: %f", totwtime);
    printf("\nAverage waiting time: %f", totwtime / n);
    printf("\nTotal turn around time: %f", totttime);
    printf("\nAverage turn around time: %f", totttime / n);

    return 0;
}

