# Recursion Template
## Basic Rules
1. invoke itself
2. has terminate condition

## c++ template

```
void recursion(int level, int param1, ...) {

    // recursion terminator
    if (level > MAX_LEVEL)
        PrintResult();
        return;

    // process logic in current level
    ProcessData(level);

    // drill down
    recursion(level + 1, p1, ...);

    // reverse the current level status if needed
    ReverseState(level);
}

```