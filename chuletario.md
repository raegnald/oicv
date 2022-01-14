
## Random numbers

```c
#include <stdlib.h>
#include <time.h>

srand(time(NULL));               // set seed, do only once

rand() % MAX;                    // from 0 to MAX_NUM
MIN + rand() % (MAX - MIN + 1);  // from MIN to MAX
```


## Sorting
This a way of implementing insertion sort
```c
void sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      int tmp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = tmp;
    }
  }
}
```
<!--
Bubble sort
```c
void bubble_sort(int *arr, int size) {
  for (int i = size - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}
``` -->


## Get input line to int array
```c
#include <stdlib.h>
#include <string.h>

void get_line(int *arr, char *size) {
  int line_size = size*5;
  char line[line_size], *token;

  fgets(line, line_size, stdin);

  token = strtok(line, " ");
  for (int i = 0; i < size && token != NULL; i++) {
    arr[i] = atoi(token);
    token = strtok(NULL, " ");
  }
}
```

## Transform from char to int

```c
char x = '9';
int y = x - '0';    //=> int:9
```