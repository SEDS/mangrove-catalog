## `open` File-Close-Virtual-Method FP variation

**`Open` variation: Original FP version that uses object inheritance and the `open()` function. This is the version present in Juliet.**

Static Code Analysis Tool flags a "Leak" false positive error for the above code, assuming an opened file is never closed. However, the file *is* closed after being passed to a virtual method of a class.

The FP pattern appears in OOP situations with and without inheritance.

#### [No-inheritance requirements (single class):](../no-inheritance)
* Must define the sink of the resource (class that closes the file) in a user-defined namespace. ***(UPDATE: See the [multi-class](../multi-class) variation for details. This point seems to be the key requirement for the FP.)***
* Method **must** be defined in separate `cpp` file.
* Method **must** be declared `virtual`.
* Caller may use either a *pointer* or an *object* type to refer to the instance.
* Client may either explicitly include the namespace or use the scope resolution operator.

#### Inheritance requirements (two classes):

I assume the caller uses a *subclass* instance for the actual type. Otherwise, we revert to the single-class case above.

* Must define the sink of the resource (class that closes the file) in a user-defined namespace. ***(UPDATE: See the [multi-class](../multi-class) variation for details. This point seems to be the key requirement for the FP.)***
* Method **must** be defined in separate `cpp` file.
* Method must be declared `virtual` in base class (method may or may not be pure virtual).
* (For *pointer* type in the caller) Caller may use either *base class* or *subclass* as the declared type.
*  Caller may use either a *pointer* or an *object* type to refer to the instance (although if using an object type, the object ***must*** be declared as the subclass type...otherwise, it is a TP).
* Client may either explicitly include the namespace or use the scope resolution operator.
 
## Other functions

I tested other C allocators/deallocators besides `open()` to observe Static Code Analysis Tool's behavior with them. The table below lists functions I tested and the Static Code Analysis Tool warning message flagged for a given configuration. Here are the meanings of the column names:

* "Namespace": code is defined in a user-defined namespace (as in the example), except for `main()`.
* "No namespace": everything is defined in the (default) global namespace.
* "Dealloc": the virtual method deallocates the resource.
* "No dealloc": the virtual method does nothing with the resource--it is not closed explicitly.

In general, a `leak` warning in a "dealloc" column is a FP, while a `leak` warning in a "no dealloc" column is a TP.

**The fact that the "Namespace, dealloc" column and the "Namespace, no dealloc" column are the same for each function suggests that Static Code Analysis Tool may have trouble reasoning through a data sink that resides in a user-defined namespace.**

Function | Namespace, dealloc | No namespace, dealloc | Namespace, no dealloc | No namespace, no dealloc
--- | --- | --- | --- | ---
open | ***leak*** | none | ***leak*** | ***leak***
open64 | ***leak*** | none | ***leak*** | ***leak***
creat | ***leak*** | none | ***leak*** | ***leak***
[fopen](../fopen) | none | none | none | ***leak***
freopen | none | none | none | none
popen | none | none | none | ***leak***
dlopen | none | none | none | ***leak***
catopen | none | none | none | ***leak***
closedir | none | none | none | ***leak***
fdopen | none | ??\* | none | ***leak***\*\*
pipe | none | none | none | none\*\*\*

\*Static Code Analysis Tool flags a "double close" warning for this configuration. I'm not sure if this is a TP or FP--more research into the `fdopen()` function would help.  
\*\*Running valgrind against this configuration shows that no files are actually left open. Apparently the stream opened by fdopen is implicitly closed at exit.  
\*\*\*Valgrind clearly showed two unclosed files in this case (*two* since `pipe()` opens two file descriptors). I am not sure why Static Code Analysis Tool did not flag this TP.
