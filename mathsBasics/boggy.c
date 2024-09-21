
#include <stdio.h>
#include <ctype.h>

int main() {
        int c;
        static int first = 0;
        while ((c = getchar()) != EOF) {
                if (!isspace(c)) {
                        if (!first) {
                                printf("\n\n");
                                first = 1;
                        } else {
                                putchar('*');
                        }
                } else{
                        putchar('\n');
                }
        }
}