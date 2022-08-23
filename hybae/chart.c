#include <stdio.h>
#include <stdlib.h> //srand, rand를 사용하기 위한 헤더파일
#include <time.h> 
#include <unistd.h>
#define COLOR_RED "\x1b[1;31m"
#define BACK_RED "\x1b[48;5;1m"
#define BACK_BLU "\x1b[48;5;4m"
#define BACK_WHI "\x1b[48;5;7m"
#define COLOR_BLU "\x1b[1;34m"
#define COLOR_RES "\x1b[1;0m"

void colorprint(char *color, char *str) {
  printf(" %s%s%s ", color, str, COLOR_RES);
}

void printNum(int num) {
  if (num == 100)
    printf(" %d", num);
  else if (num > 9)
    printf("  %d", num);
  else
    printf("   %d", num);
}

void chartMap(int nums[]) {
  int grid = 5;
  int level = 20;

  for (int col = 0; col < 20; col++) {
    printf("| ");
    for (int row = 0; row < 10; row++) {
      if ((nums[row] / 5) >= level) {
        colorprint(BACK_WHI, "  ");
      }
      else {
        printf("    ");
      }
    }
    printf("\n");
    level--;
  }
  for (int col = 0; col < 21; col++)
    printf("￣");
  printf("\n ");
  for (int i = 0; i < 10; i++) {
    printNum(nums[i]);
  }
  printf("\n");
}

int getRand() {
  return (rand() % 101);
}

void shiftArray(int *num, int new) {
  for (int i = 0; i < 9; i++) {
    *(num + i) = *(num + i + 1);
  }
  *(num + 9) = new;
}

int main(void) {
  int nums[10];
  srand(time(NULL));
    for (int i = 0; i < 10; i++) {
      nums[i] = getRand();
    }

  while(1) {
    shiftArray(nums, getRand());
    chartMap(nums);
    usleep(1000 * 1000);
  }
  return (0);
}