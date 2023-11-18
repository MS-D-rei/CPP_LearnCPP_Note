## #pragma once
This is 'almost' the same to #ifndef header guard.
However, there is one specific fail case.
If a header file is copied so that it exists in multiple places on the file system, if somehow both copies of the header get included, header guards will successfully de-dupe the identical headers, but #pragma once won’t (because the compiler won’t realize they are actually identical content).
