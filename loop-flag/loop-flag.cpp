// Custom code
// Structure: loop-flag

int helper (void) {
    bool flag = false;
    for (int i = 0; i < 10; i++) {
        if (flag) {
            // Static Code Analysis Tool FP: Unreachable Data Flow. The highlighted code will not execute under any circumstances.
            // Static Code Analysis Tool FP: none
            // Static Code Analysis Tool FP: none
            return 1;
        }
        flag = true;
    }
    // Note: Static Code Analysis Tool gives a TP Unreachable Data Flow warning here.
    return 0;
}

int main(void) {
    // Static Code Analysis Tool FP: Unreachable Data Flow. The highlighted code will not execute under any circumstances.
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: none
    int result = helper();
    return 0;
}