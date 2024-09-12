#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* greet()
{
  printf("88  88 888888 88     88      dP\"Yb      Yb        dP  dP\"Yb  88\"\"Yb 88     8888b.  d8b \n");
  printf("88  88 88__   88     88     dP   Yb      Yb  db  dP  dP   Yb 88__dP 88      8I  Yb Y8P \n");
  printf("888888 88\"\"   88  .o 88  .o Yb   dP       YbdPYbdP   Yb   dP 88\"Yb  88  .o  8I  dY `\"\' \n");
  printf("88  88 888888 88ood8 88ood8  YbodP         YP  YP     YbodP  88  Yb 88ood8 8888Y\"  (8) \n");
  return (strdup("hello world!"));
}

int main()
{
  greet();
  return 0;
}