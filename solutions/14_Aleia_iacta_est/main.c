#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int main(void) {
    /*
    * time_t is a struct type from time.h. We use two variables to store the
    * the current system time at the start and the end.
    */
    srand(time(NULL));

    printf("Result: %d\n", rand() % 6 + 1);
    return 0;
}
