#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int main(void) {
    /*
    * time_t is a struct type from time.h. We use two variables to store the
    * the current system time at the start and the end.
    */
    time_t start, end;

    srand(time(NULL));

    time(&start);
    for (int i = 5; i > 0; --i) {
        int a = rand() % 9 + 1;
        int b = rand() % 9 + 1;
        int s;

        printf("%d + %d = ", a, b);

        scanf("%d", &s);

        assert(s == a + b);

    }
    time(&end);
    /*
    *  difftime is a function form time.h which calculates the difference in
    *  seconds. The result is as double and we use the specifier ".1lf" to print
    *  a long float (dobule) value with one decimal place.
    */
    printf("It took you %.1lf seconds to answer all questions!\n", difftime(end, start));
    return 0;
}
