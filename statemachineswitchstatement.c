/*State machine in C by Richard Maw*/
/*https://yakking.branchable.com/posts/state-machines-in-c/*/

#include <stdio.h>

enum states {
    START,
    LOOP,
    END,
} state;

enum events {
    START_LOOPING,
    PRINT_HELLO,
    STOP_LOOPING,
};

int main(void) {
    step_state(START_LOOPING);
    step_state(PRINT_HELLO);
    step_state(PRINT_HELLO);
    step_state(STOP_LOOPING);
    return 0;
}

void step_state(enum events event) {
    switch(state) {
    case START:
        switch(event) {
        case START_LOOPING:
            printf("Start\n");
            state = LOOP;
            break;
        default:
            exit(1);
            break;
        }       
        break;
    case LOOP:
        switch(event) {
        case PRINT_HELLO:
            printf("Hello World!\n");
            break;
        case STOP_LOOPING:
            printf("End\n");
            state = END;
            break;
        default:
            exit(1);
            break;
        }
        break;
    case END:
        exit(1);
        break;
    }
}
