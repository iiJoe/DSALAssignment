/**
 * q7.c -- Q7: Knapsack
 *
 * Written on Tuesday, 19 April 2022.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int max(int i, int j) {
  if (i > j) return i;
  else return j;
}

int bottom_up_dp(int n, int *s, int *v, int C) {
  int dp[C + 1][n + 1];

  for (int i = 0; i <= C; i++) dp[i][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= C; j++) {
      dp[j][i] = j >= s[i] ? max(dp[j][i - 1], dp[j - s[i]][i - 1] + v[i]) : dp[j][i - 1];
    }
  }

  return dp[C][n];
}

int main() {
  int n, C;
  int function;
  int *s;
  int *v;
  int i, j;
  printf("Enter the number of items n:\n");
  scanf("%d", &n);
  printf("Enter the capacity C:\n");
  scanf("%d", &C);
  s = (int *)malloc(sizeof(int) * (n + 1));
  v = (int *)malloc(sizeof(int) * (n + 1));

  printf("Enter the sizes of items (as a list, separate by spacing:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &s[i]);

  printf("Enter the values of items (as a list, separate by spacing:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &v[i]);

  printf("The maximum value is: %d \n", bottom_up_dp(n, s, v, C));
}
