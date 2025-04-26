#include <stdlib.h>
#include <stdio.h>


void null_pointer_error(){
    fprintf(stderr, "NULL pointer error: %s: %s(): Line:%d\n", __FILE__, __FUNCTION__, __LINE__ -1);
    abort();
}