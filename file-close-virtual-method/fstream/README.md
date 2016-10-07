## `fstream` File-Close-Virtual-Method FP variation

**The `fstream` version does *not* give a FP in Static Code Analysis Tool.**

The `fstream` version is irrelevant for our purposes because this object automatically closes the file at the end of scope. Thus, even without explicitly closing a file, it is usually closed automatically. I verified that Static Code Analysis Tool does not give a warning even when a file is not closed manually.

Note: I forced a leak by issuing the `exit(0)` call after the file is opened and before the scope is left. (I verified the leak with Valgrind.) Even in this situation Static Code Analysis Tool did not give a warning. I am quite confident Static Code Analysis Tool will not give leak FPs related to `fstream`.
