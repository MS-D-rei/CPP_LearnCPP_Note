## Fundamental data type sizes

Perhaps surprisingly, the C++ standard does not define the exact size of any of the fundamental types. Instead, it only defines a minimum size (in bits) for the integral and char types, and leaves the actual size of all types to be implementation-defined! The C++ standard also does not assume that a byte is 8 bits.

## Fundamental data type performance

On modern machines, objects of the fundamental data types are fast, so performance while using or copying these types should generally not be a concern.

You might assume that types that use less memory would be faster than types that use more memory. This is not always true. CPUs are often optimized to process data of a certain size (e.g. 32 bits), and types that match that size may be processed quicker. On such a machine, a 32-bit int could be faster than a 16-bit short or an 8-bit char.
