#include <stdio.h>

#define COLOR_RED "\x1b[1;31m"
#define BACK_RED "\x1b[48;5;1m"
#define BACK_BLU "\x1b[48;5;4m"
#define BACK_WHI "\x1b[48;5;7m"
#define COLOR_BLU "\x1b[1;34m"
#define COLOR_RES "\x1b[1;0m"

void colorprint(char *color, char *str) {
  printf(" %s%s%s ", color, str, COLOR_RES);
}

int main()
{
  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  printf("\n");
  colorprint(BACK_RED, "      ");  colorprint(BACK_RED, "      ");  colorprint(BACK_RED, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_RED, "      ");  colorprint(BACK_RED, "      ");  colorprint(BACK_RED, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_RED, "      ");  colorprint(BACK_RED, "      ");  colorprint(BACK_RED, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_BLU, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  colorprint(BACK_WHI, "      ");  printf("\n");
  printf("\n");
  // printf("  ---   ---   ---   ---   ---  \n");
  // printf("|      |      |      |      |      |\n");
  // printf("|      |      |      |      |      |\n");
  // printf("  ---   ---   ---   ---   ---  \n");
  // printf("|      |      |      |      |      |\n");
  // printf("|      |      |      |      |      |\n");
  // printf("  ---   ---   ---   ---   ---  \n");
  // printf("|"); printf(BACK_RED); printf("      "); printf(COLOR_RES); printf("|      |      |      |      |\n");
  // printf("|"); printf(BACK_RED); printf("      "); printf(COLOR_RES); printf("|      |      |      |      |\n");
  // printf("  ---   ---   ---   ---   ---  \n");
  // printf("|      |      |      |      |      |\n");
  // printf("|      |      |      |      |      |\n");
  // printf("  ---   ---   ---   ---   ---  \n");
  // printf("|      |      |      |      |      |\n");
  // printf("|      |      |      |      |      |\n");
  // printf("  ---   ---   ---   ---   ---  \n");
  

    // printf("■ ■ ■ ■ ■ \n");
    // printf("■ ");
    // printf(BACK_RED);
    // printf("■ ");
    // printf(COLOR_RES);
    // printf("");
    // printf(COLOR_BLU);
    // printf("■ ");
    // printf(COLOR_RES);
    // printf("■ ■ \n");
    // printf("■ ■ ■ ■ ■ \n");
    // printf("■ ■ ■ ■ ■ \n");
    
    return 0;
}