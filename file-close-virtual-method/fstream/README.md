## `fstream` File-Close-Virtual-Method FP variation

**The `fstream` version does *not* give a FP in Tool C.**

The `fstream` version is irrelevant for our purposes because this object automatically closes the file at the end of scope. Thus, even without explicitly closing a file, it is usually closed automatically. I verified that Tool C does not give a warning even when a file is not closed manually.

Note: I forced a leak by issuing the `exit(0)` call after the file is opened and before the scope is left. (I verified the leak with Valgrind.) Even in this situation Tool C did not give a warning. I am quite confident Tool C will not give leak FPs related to `fstream`.
