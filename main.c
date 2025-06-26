#include "ft_printf.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *a = "ege";
    int e = 123;
    int c = 123;

   ft_printf("ft_printf nida 3. en yakin arkadisim adamin %X amina koyar.\n", e);
   printf("printf   nida 3. en yakin arkadisim adamin %X amina koyar.\n",c);
   printf("%d\n%d",e, c);
    return 0;
}
