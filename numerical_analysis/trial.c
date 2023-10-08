#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("%+15f\n",6.28);
    printf("%zd\n", sizeof(char));
    printf("%lld\n",LLONG_MAX);
    printf("%d\n", FLT_DIG);
    printf("%2.0f\n",1.1);
}