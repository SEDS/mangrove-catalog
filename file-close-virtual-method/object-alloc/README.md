## `object-alloc` File-Close-Virtual-Method FP variation

This `object-alloc` version allocates an object on the heap and deletes it in the virtual method. **This version does *not* flag a FP.**

Below are the test cases I tried. Static Code Analysis Tool does not give a warning in any cases.

### Multiple-class structure (inheritance)

user-defined namespace? | object instance in client (ptr, obj, &) | declared type of dealloc object | virtual base method... | empty base method? | subclass method defined...
--- | --- | --- | --- | --- | ---
yes - but not data class | ptr | base | NON-pure | yes | externally
yes - all but main() | ptr | base | NON-pure | yes | externally
yes - but not data class | obj | subclass | NON-pure | yes | externally


### Single-class structure (no inheritance)

user-defined namespace? | object instance in client (ptr, obj, &) | method is virtual? | method defined...
--- |--- |--- | ---
yes - but not data class | ptr | yes | externally
yes - but not data class | ptr | yes | internally
yes - but not data class | ptr | no | internally

