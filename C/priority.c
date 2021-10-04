
#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i;
    printf("Enter the no of process:\n");
    scanf("%d", &n);
    printf("Enter the arrival time:\n");
    int at[50];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    printf("Enter the burst time:\n");
    int bt[50];
    int rem_bt[50];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    int pt[50];
    printf("Enter the priority of process:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pt[i]);
    }
    int procom[50];
    for (i = 0; i < 50; i++)
    {
        procom[i] = 0;
    }

    int ct[50];
    int wt[50];
    int tt[50];
    int rt[50];
    int st[50];
    int avgwt = 0;
    int avgtt = 0;
    int avgrt = 0;
    int completed = 0;
    int currenttime = 0;
    while (completed != n)
    {
        int index = -1;
        int min = INT_MAX;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= currenttime && procom[i] == 0)
            {
                if (pt[i] < min)
                {
                    min = pt[i];
                    index = i;
                }
                if (rem_bt[i] == min)
                {
                    if (at[i] < at[index])
                    {
                        min = rem_bt[i];
                        index = i;
                    }
                }
            }
        }
        if (index != -1)
        {
            if (rem_bt[index] == bt[index])
            {
                st[index] = currenttime;
            }
            rem_bt[index] -= 1;
            currenttime++;
            if (rem_bt[index] == 0)
            {
                ct[index] = currenttime;
                tt[index] = ct[index] - at[index];
                wt[index] = tt[index] - bt[index];
                rt[index] = st[index] - at[index];
                avgwt += wt[index];
                avgtt += tt[index];
                avgrt += rt[index];
                procom[index] = 1;
                completed++;
            }
        }
        else
        {
            currenttime++;
        }
    }
    float average_wt = (float)avgwt / n;
    float average_tt = (float)avgtt / n;
    float average_rp = (float)avgrt / n;
    for (int i = 0; i < n; i++)
    {
        printf("Waiting time for Process%d is: %d\n", i + 1, wt[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Turnaround time for Process%d is: %d\n", i + 1, tt[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Response time for process%d is: %d\n", i + 1, rt[i]);
    }
    printf("\n");
    printf("Average Turnaround Time = %f\n", average_tt);
    printf("Average Waiting Time = %f\n", average_wt);
    printf("Average Response Time = %f\n", average_rp);
}
