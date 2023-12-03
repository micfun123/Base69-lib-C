## This project is not finnished

### Example
```c
#include <stdio.h>
#include "base69.h"

int main() {
    int input = 100;
    char output[24]; // Allocate enough space for the output including the prefix

    encode_base69(input, output);

    printf("Encoded: %s\n", output);

    return 0;
}
```

```
gcc test.c base69.c -o base69_test
```