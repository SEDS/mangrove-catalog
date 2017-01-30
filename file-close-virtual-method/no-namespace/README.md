## `no-namespace` File-Close-Virtual-Method FP variation

**The no-namespace version (using `open()`) does *not* give a FP in Tool C.**

When not using a user-defined namespace, Tool C does ***not*** flag a FP (or using the `std` namespace). More research may still be needed to learn how Tool C behaves when only *part* of the code is in the user-defined namespace.
