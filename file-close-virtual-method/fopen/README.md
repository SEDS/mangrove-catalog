## `fopen` File-Close-Virtual-Method FP variation

Strangely, **Tool C does *not* flag a FP for the `fopen()` version**. I could not get Tool C to flag a FP by trying many variations (from the requirements list on the wiki page that describes this FP pattern).

Though the example uses access mode w+, none of the possible modes gave a FP: r, w, a, r+, w+, a+.

Even more strangely, Tool C does not flag a TP warning when we remove the call to `fclose()` (with the `fp` file pointer still be passed to the method). However, if we simplify the structure and do not pass the `fp` file pointer to an external callee at all, Tool C *does* flag a TP. Thus, it is almost as if the structure above is getting too complicated for Tool C to understand, so it simply assumes the `fp` file pointer is closed. ***Update:* I now understand that the reason may be because the namespace is obscuring the details for Tool C (see [multi-class](../multi-class) variation).**

I'm not sure why this result using `fopen()` is different from using the lower level `open()` function.
