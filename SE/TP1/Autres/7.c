#include <stdio.h>

int main(int argc, char** argv, char** env){
  float f1, f2, f3, f4, f5;
  printf("Saisissez 5 nombres flottants : ");
  scanf("%f %f %f %f %f", &f1, &f2, &f3, &f4, &f5);
  printf("%f\n", (f1+f2+f3+f4+f5)/5);
  
  return 0;
}
