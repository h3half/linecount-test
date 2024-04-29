Both the C program and the Python script load the same input and count the number of lines of text it contains 100,000 times.

The results below show the runtime length, averaged over 100 executions, of each language.

| Language | Average Runtime (s) |
| --- | --- |
| C | 0.2383 |
| Python | 2.5461 |

This gives the C implementation a speed advantage of about 10.7x.

The full source code is in this repository, but for convenience the hot loops are shown here:

**C:**
```c
void countLines() {
    // Setup
    FILE* fileHandle = fopen("source.txt", "r");
    fseek(fileHandle, 0, SEEK_END);
    size_t flen = ftell(fileHandle);
    char *body = (char*)calloc(1, flen + 1);
    fseek(fileHandle, 0, SEEK_SET);
    fclose(fileHandle);

    // Count
    char *nb = body;
    int count = 0;
    while (nb = strchr(nb, '\n')) {
        ++count;
        ++nb;
    }

    free(body);
}
```

**Python:**
```python
def countLines():
    inputFile = open("source.txt", "r")
    lines = inputFile.readlines()
    count = len(lines)
    inputFile.close()
```

The rest of both `c.c` and `python.py` are essentially just wrappers to call these functions the appropriate number of times and to time their execution.
