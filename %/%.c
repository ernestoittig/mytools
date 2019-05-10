/*gcc -std=c99 -Wall "%.c" -lm -o "../bin/%/%"*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>

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
    int opt, isArgs = 0, final;
    while ((opt = getopt(argc, argv, ":tfe")) != -1) {
        isArgs = 1;
        final = opt;
        if (opt == '?') {
            if (optopt > 47 && optopt < 58) 
            printf("unknow option %c\n", optopt);
            exit(2);
        }
    }
    
    if (argc < 3) {
        fprintf(stderr, "Two arguments are needed\n");
        exit(2);
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

