#include <stdio.h>
#include <math.h>

int main ()
{
   char str[80];
   sprintf(str, "a=%d_s=%s", 1, "asf");
   printf("%s\n" ,str);
   return(0);
}
