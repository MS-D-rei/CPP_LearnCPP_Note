## Header files location setting

### For Visual Studio users

Right click on your project in the Solution Explorer, and choose Properties,
then the VC++ Directories tab.
From here, you will see a line called Include Directories.
Add the directories you’d like the compiler to search for additional headers there.

### For GCC/G++ users

Using g++, you can use the -I option to specify an alternate include directory:

```
g++ -o main -I/source/includes main.cpp
```

There is no space after the -I.

### For VS Code users

In your tasks.json configuration file, add a new line in the “Args” section:

```
-I/source/includes
```

## The #include order of header files

If your header files are written properly and #include everything they need, 
the order of inclusion shouldn’t matter.

Now consider the following scenario: let’s say header A needs declarations from header B, but forgets to include it. In our code file, if we include header B before header A, our code will still compile! This is because the compiler will compile all the declarations from B before it compiles the code from A that depends on those declarations.

However, if we include header A first, then the compiler will complain because the code from A will be compiled before the compiler has seen the declarations from B. This is actually preferable, because the error has been surfaced, and we can then fix it.


Best practice

To maximize the chance that missing includes will be flagged by compiler,
order your #includes as follows:

1. The paired header file
2. Other headers from your project
3. 3rd party library headers
4. Standard library headers

The headers for each grouping should be sorted alphabetically
(unless the documentation for a 3rd party library instructs you to do otherwise).

That way, if one of your user-defined headers is missing an #include for a 3rd party library or standard library header, it’s more likely to cause a compile error so you can fix it.

## Header file best practices

Header file best practices

Here are a few more recommendations for creating and using header files.

- Always include header guards (we’ll cover these next lesson).
- Do not define variables and functions in header files (for now).
- Give a header file the same name as the source file it’s associated with (e.g. grades.h is paired with grades.cpp).
- Each header file should have a specific job, and be as independent as possible. For example, you might put all your declarations related to functionality A in A.h and all your declarations related to functionality B in B.h. That way if you only care about A later, you can just include A.h and not get any of the stuff related to B.
- Be mindful of which headers you need to explicitly include for the functionality that you are using in your code files, to avoid inadvertent transitive includes.
- A header file should #include any other headers containing functionality it needs. Such a header should compile successfully when #included into a .cpp file by itself.
- Only #include what you need (don’t include everything just because you can).
- Do not #include .cpp files.
- Prefer putting documentation on what something does or how to use it in the header. It’s more likely to be seen there. Documentation describing how something works should remain in the source files.
