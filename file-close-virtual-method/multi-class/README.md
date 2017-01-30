## `multi-class` File-Close-Virtual-Method FP variation

**Multi-class variation: Use a hierarchy of classes to understand the effect of namespaces on the `File-Close-Virtual-Method` FP pattern.**

## Class hierarchy

I used a hierarchy of classes to test how changing the namespace affected the Tool C warning message. Class C inherits from B, which inherits from A. For each class, the virtual `action()` method closes a file given a file descriptor. Thus, clients that depend on these classes should not have any leak errors (files not being closed). In the code above everything is defined in the global namespace, but I made modifications to define certain classes in a different namespace (see next section).

## Namespace configurations

Each row of the table gives a "configuration," which shows the namespaces that classes were defined in. Either no user-defined namespace was used, or a `test` namespace was used. (The `client.cpp` program uses the default global namespace.) The `Declared type` and `Actual type` are the object types used by the client. (For the program above, the declared type is B and the actual type is C.) The last field tells whether Tool C gave a `Leak` false positive. Again, none of these configurations cause an *actual* error.

I simplified my analysis by ignoring other factors (e.g. pointer vs. object access in client, pure vs. non-pure virtual methods, defining methods in separate `cpp` file vs. in the header file, etc.). I studied some of these factors elsewhere ([see other variations](../)). This study focuses on namespaces. Also, this experiment tests only the low-level `open()`/`close()` functions; I do not test other kinds of resource allocators here (see other variations for that).

A namespace | B namespace | C namespace | Declared type | Actual type | Tool C FP?
--- | --- | --- | --- | --- | ---
global | test | global | B | B | FP
global | test | global | B | C | no FP
global | test | test | B | C | FP
global | global | test | B | C | FP
test | global | global | B | C | no FP
global | test | global | A | A | no FP
test | test | global | A | A | FP
test | global | global | A | B | no FP
test | test | global | A | B | FP
global | test | global | A | B | FP
global | global | test | A | C | FP
global | test | global | A | C | no FP
global | test | global | C | C | no FP
global | global | global | C | C | no FP
global | global | test | C | C | FP

## Discussion

Notice that in all these cases, Tool C gave a FP if and only if the class of the actual type was defined in a user-defined namespace (not the global namespace). This suggests that Tool C can actually follow the virtual table lookup and knows at which level of the hierarchy the method will be invoked. I verified this by changing the `action()` method of one of the classes to ***not*** close the file. Then, using the global namespace for all classes, I tested several pairs of `Declared type` and `Actual type` with Tool C. In all cases Tool C correctly flagged whether or not the file was leaked.

This suggests that the `File-Close-Virtual-Method` FP might not be related to virtual calls as much as with namespaces. It is almost as if namespaces obscure things from Tool C. More research should be done to test this hypothesis in other contexts.
