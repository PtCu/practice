#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void success()
{
  printf("success\n");
}

void fail()
{
  printf("fail\n");
}

int main(int argc, char **argv)
{

  char answer[8] = "excited";
  char input[8];
  while (1)
  {
    printf("请输入密码：");
    gets(input);
    if (strcmp(input, answer) == 0)
    {
      success();
      break;
    }
    else
    {
      fail();
    }
  }
  return 0;
}