/*gcc -std=c99 -Wall "%.c" -lm -o "../bin/%/%"*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long modE(long D, long d) {
    long r = D%d;
    if (r < 0) {
        if (d > 0) r += d;
        else r -= d;
    }
    return r;
}

long modF(long D, long d) {
    long r = D%d;
    if ((r > 0 && d < 0) || (r < 0 && d > 0)) r += d;
    return r;
}

int main(int argc, char *const *argv) {
    if (argc < 3) {
        fprintf(stderr, "Two arguments are needed\n");
        exit(2);
    }
    
    int isArgs = 0, optind = 1, final;

    int nOpts = 3;
    char opts[] = {'t', 'f', 'e'};

    for (int i = 0; i < nOpts; i++) {
        const char _buf[] = {'-', opts[i], 0};
        const char *buf = _buf;
        if (strcmp(buf, argv[1]) == 0) {
            isArgs = 1;
            final = opts[i];
            optind = 2;
            break;
        }
    }

    long a = atoi(argv[optind]);
    long b = atoi(argv[optind+1]);
    if (isArgs) {
        switch (final) {
            case 't':
                printf("%ld\n", a % b);
                break;
            case 'f':
                printf("%ld\n", modF(a, b));
                break;
            case 'e':
                printf("%ld\n", modE(a, b));
                break;
        }
    } else {
        printf("truncated=%ld\n", a % b);
        printf("floored=%ld\n", modF(a, b));
        printf("euclidean=%ld\n", modE(a, b));
    }
    return 0;
}

