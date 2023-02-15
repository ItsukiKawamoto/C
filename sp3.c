#include <stdio.h>
#include <stdlib.h>

enum state_e {
    FACTOR,
    INDEX,
    VARIABLE,
    OPERATOR,
};

int isNum(char c);
int readNum(char *pos);

int main() {
    enum state_e state;
    char buf[256];
    char *pos = buf;
    int factor[256] = {};
    int index[256] = {};
    int term = 0;

    printf("Input: ");
    if (scanf("%255s%*[^\n]", buf) != 1) {
        return 1;
    }
    scanf("%*c");

    printf("Output: %s\n", buf);

    if (isNum(buf[0])) {
        factor[term] = 1;
        state = FACTOR;
    } else if (buf[0] == '-') {
        factor[term] = -1;
        state = FACTOR;
    } else {
        state = VARIABLE;
    }

    while (*pos != '\0') {
        switch (state) {
        case FACTOR:
            factor[term] *= readNum(pos);
            state = VARIABLE;
            break;
        case INDEX:
            index[term] = readNum(pos);
            state = OPERATOR;
            break;
        case VARIABLE:
            if (*(pos + 1) != '*') {
                index[term] = 1;
                state = OPERATOR;
            } else {
                state = INDEX;
            }
            break;
        case OPERATOR:
            term++;
            if (*pos == '+') {
                factor[term] = 1;
            } else {
                factor[term] = -1;
            }
            break;
        }
        pos++;
        if (isNum(*pos)) {
        }
    }

    return 0;
}

int isNum(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int readNum(char *reader) {
    char num[256];
    int i = 0;
    do {
        num[i] = *reader;
        reader++;
    } while (isNum(*reader));
    pos = reader;
    return atoi(num);
}

/*
void changeState(){

}*/