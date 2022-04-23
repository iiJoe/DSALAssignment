/**
 * q6.c -- Q6: Linear Recurrence
 *
 * Written on Tuesday, 19 April 2022.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int *arr; //used for top-down appraoch

int top_down_dp(int n) {

  // top-down approach
  if (n > 2) {
    top_down_dp(n - 1);
    arr[n] = arr[n - 1] + 2 * arr[n - 2] - 3 * arr[n - 3];
  }
  return arr[n];

  // bottom-up approach
  /* int arr[n + 1]; */
  /* arr[0] = 0; */
  /* arr[1] = 1; */
  /* arr[2] = 2; */
  /* for (int i = 3; i <= n; i++) { */
  /*   arr[i] = arr[i - 1] + 2 * arr[i - 2] - 3 * arr[i - 3]; */
  /* } */
  /* return arr[n]; */
}

int main() {
  int n;
  int function;
  int i;
  printf("Enter the value of n:\n");
  scanf("%d", &n);

  //top-down approach
  arr = (int *) malloc(sizeof(int) * n + 1);
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;

  printf("The value of F(%d) is: %d \n", n, top_down_dp(n));
}
