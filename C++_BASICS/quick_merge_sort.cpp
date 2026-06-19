#include <stdio.h>
#include <stdlib.h>

// ------------------------------ 0/1 Knapsack Problem ------------------------------
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

void solveKnapsack() {
    int n, W;
    printf("\n--- 0/1 Knapsack Problem ---\n");
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int val[n], wt[n];

    printf("Enter values and weights of items (value weight):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &val[i], &wt[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val, n));
}

// ------------------------------ Job Sequencing Problem ------------------------------
typedef struct {
    int id, deadline, profit;
} Job;

// Comparison function to sort jobs by decreasing profit
int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

void jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // Find maximum deadline
    int max_deadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;

    // Create a slot array initialized to -1
    int schedule[max_deadline + 1];
    for (int i = 0; i <= max_deadline; i++)
        schedule[i] = -1;

    int totalProfit = 0, countJobs = 0;

    for (int i = 0; i < n; i++) {
        for (int d = jobs[i].deadline; d > 0; d--) {
            if (schedule[d] == -1) {  // If slot is available
                schedule[d] = jobs[i].id;
                totalProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");
    for (int i = 1; i <= max_deadline; i++)
        if (schedule[i] != -1)
            printf("%d ", schedule[i]);

    printf("\nTotal Profit: %d\n", totalProfit);
}

void solveJobSequencing() {
    int n;
    printf("\n--- Job Sequencing Problem ---\n");
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    printf("Enter Job ID, Deadline, Profit:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);

    jobSequencing(jobs, n);
}

// ------------------------------ Main Function ------------------------------
int main() {
    int choice;
    while (1) {
        printf("\nSelect Algorithm:\n");
        printf("1. 0/1 Knapsack Problem\n");
        printf("2. Job Sequencing Problem\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                solveKnapsack();
                break;
            case 2:
                solveJobSequencing();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }
}