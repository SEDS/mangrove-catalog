## `fopen` File-Close-Virtual-Method FP variation

Strangely, **Static Code Analysis Tool does *not* flag a FP for the `fopen()` version**. I could not get Static Code Analysis Tool to flag a FP by trying many variations (from the requirements list on the wiki page that describes this FP pattern).

Though the example uses access mode w+, none of the possible modes gave a FP: r, w, a, r+, w+, a+.

Even more strangely, Static Code Analysis Tool does not flag a TP warning when we remove the call to `fclose()` (with the `fp` file pointer still be passed to the method). However, if we simplify the structure and do not pass the `fp` file pointer to an external callee at all, Static Code Analysis Tool *does* flag a TP. Thus, it is almost as if the structure above is getting too complicated for Static Code Analysis Tool to understand, so it simply assumes the `fp` file pointer is closed. ***Update:* I now understand that the reason may be because the namespace is obscuring the details for Static Code Analysis Tool (see [multi-class](../multi-class) variation).**

I'm not sure why this result using `fopen()` is different from using the lower level `open()` function.
