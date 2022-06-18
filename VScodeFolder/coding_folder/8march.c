#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define push(sp, n) (*((sp)++) = (n)) && (top ++)
#define pop(sp) (*--(sp)) && (top--)
#define top(sp) (*(sp - 1))

bool IsEmpty(int top)
{
  bool flag = false;
  if (top == -1) flag = true;
  return flag;
}

int main(void)
{
  char stack[5];
  char huevo[] = "hui";
  char * sp;
  sp = stack;
  int top = -1;
  push(sp,huevo[2]);
  push(sp,huevo[2]);
  push(sp,huevo[1]);
  push(sp,huevo[0]);
  top(sp);
  printf("%d", top);
  printf("%d", top);
}