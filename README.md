# False Positive Catalogue

Here are source code samples of the false positive patterns listed on the [False Positive Catalogue](https://github.com/SEDS/mangrove-catalogue/wiki/FP-Catalog). Rather than browsing the repository above, we recommend that you let the wiki page guide you through the patterns. Static code analysis tool names are replaced with "Static Code Analysis Tool" to achieve anonymity.

## List of Abbreviations

These abbreviations are used throughout the repository and catalogue.

* FP: false positive
* TP: true positive
* SCA: static code analysis
* CWE: Common Weakness Enumeration ([cwe.mitre.org](https://cwe.mitre.org/))

## Catalogue Organization

We use a flat organization structure for storing the code samples. Code samples for a pattern reside in a directory of the same name as the pattern. Each code sample is the minimized structure to reproduce the false warning. We simplified the structures (e.g. replacing variables with literal constant values, combining variable declaration and initialization, etc.) as long as the FP did not go away or was converted to a TP.

Each code sample is annotated with the following details:

* Juliet test case from which the sample is derived
* Name of the FP structure
* False warning for each SCA tool
* For *changes* (see below), a description of what was changed in the code.

Unless noted otherwise in the code, samples are self-contained and do not need external libraries to be compiled (e.g. no need for Juliet test case support).

## Changes

Some directories (FP patterns) have more than one code sample. In this case, the additional code samples are called *changes*. These changes are numbered arbitrarily, and the number is given in the code sample's filename. Changes are small edits to the original FP pattern in an effort to identify what is causing the FP. (A typical change ends up simplifying the code structure to the point where the SCA tool can reason through the situation and not flag a FP.) Code samples for changes are commented with a brief phrase that describes how the code was modified. Each change is performed independently against the original code.

## Toolset

* Static Code Analysis Tool [tool version details removed]
* Static Code Analysis Tool [tool version details removed]
* Static Code Analysis Tool [tool version details removed]
