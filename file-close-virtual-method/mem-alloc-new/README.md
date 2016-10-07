## `mem-alloc-new` File-Close-Virtual-Method FP variation

This `mem-alloc-new` version allocates memory using `new` and deletes it in the virtual method. **This version does not flag a FP.**

I tried these combinations of modifications in the table below. (The first row is for the code example given.) Static Code Analysis Tool does not flag a warning for any of these.

user-defined namespace? | object instance in client (ptr, obj, &) | declared type of object in client | virtual base method is... | empty base method? | subclass method defined...
--- | --- | --- | --- | --- | ---
yes | ptr | base | NON-pure | yes | externally
yes | ptr | base | pure | yes | externally
yes | ptr | subclass | pure | yes | externally
yes | obj | subclass | pure | yes | externally
yes | obj | subclass | NON-pure | yes | externally
yes | obj | subclass | NON-pure | no | externally
no | ptr | base | pure | yes | externally
no | ptr | base | NON-pure | no | externally
no | ptr | base | NON-pure | no | internally
no | ptr | base | NON-pure | yes | internally

**Update:** Note that if we remove the `delete` call in [Deallocator.cpp](./Deallocator.cpp), Static Code Analysis Tool flags the warning (now a TP) *only if* a user-defined (non-global) namespace is used (more specifically, if the *class which deletes the memory* is defined in the namespace). This behavior is similar to we observed in the [multi-class](../multi-class) example, where a namespace in the sink apparently obscured things from Static Code Analysis Tool. **However, the only difference is that with this variation (where the resource is memory), a namespace does not cause a FP.**

## Other variations

I tested variations by allocating other types of dynamic memory. For each type, I tested only the configuration from the first row in the table above (this is the configuration that gave a FP with the `open()` function). Below are the variations. None of these give a FP.

* `char` array with `malloc`
* `int` array with `malloc`
* `float` array with `malloc`
* `wchar_t` array with `malloc`
* `struct` with `malloc`
* `int` array with `new`
* `float` array with `new`
* `wchar_t` array with `new`
* `struct` with `new`
