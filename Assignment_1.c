#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct {
    char data[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} CircularBuff;

void initBuffer(CircularBuff *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

void writeBuffer(CircularBuff *cb, char value) {
    if (cb->count == BUFFER_SIZE) {
        printf("\nBuffer is full! Cannot write '%c'\n", value);
        return;   
    }

    cb->data[cb->head] = value;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;

    printf("Written '%c' -> head=%d tail=%d count=%d\n",
           value, cb->head, cb->tail, cb->count);
}

char readBuffer(CircularBuff *cb) {
    if (cb->count == 0) {
        printf("\nBuffer is empty!\n");
        return '\0';
    }

    char value = cb->data[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;

    printf("Read '%c' -> head=%d tail=%d count=%d\n",
           value, cb->head, cb->tail, cb->count);

    return value;
}

int main() {
    CircularBuff buffer;
    initBuffer(&buffer);

    char userName[50];

    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);

    userName[strcspn(userName, "\n")] = 0;

    printf("\n--- Writing to Buffer ---\n");
    for (int i = 0; i < strlen(userName); i++) {
        writeBuffer(&buffer, userName[i]);
    }

    const char *suffix = " CE-ESY";
    for (int i = 0; i < strlen(suffix); i++) {
        writeBuffer(&buffer, suffix[i]);
    }

    printf("\n--- Reading from Buffer ---\n");
    while (buffer.count > 0) {
        char ch = readBuffer(&buffer);
        if (ch != '\0') {
            printf("%c", ch);
        }
    }

    printf("\n");
    if (buffer.count == 0) {
        printf("Buffer is now completely empty.\n");
    }

    return 0;
}