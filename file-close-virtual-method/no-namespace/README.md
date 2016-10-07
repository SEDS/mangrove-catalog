## `no-namespace` File-Close-Virtual-Method FP variation

**The no-namespace version (using `open()`) does *not* give a FP in Static Code Analysis Tool.**

When not using a user-defined namespace, Static Code Analysis Tool does ***not*** flag a FP (or using the `std` namespace). More research may still be needed to learn how Static Code Analysis Tool behaves when only *part* of the code is in the user-defined namespace.
