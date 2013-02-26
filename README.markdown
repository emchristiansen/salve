# Salve

Salve is a simple template library which makes C++ less awful for functional programmers. It offers:

1. A typeclass-like mechanism for ad-hoc polymorphism. This sort of thing is also called "Concepts" in C++ and monkey-patching in dynamic languages. (This bit is still under construction).
2. Some common typeclasses, such as Functor, Showable, and Comparable.
3. Some common higher-order functions, such as fmap (more coming soon).

## Installation

Currently installation is only from source. Make sure you have a recent Boost installed as well as a compiler that supports C++11.

To build and install with g++, try the following:
```
> cd <salveRoot>
> mkdir build
> cd build
> cmake -DCMAKE_CXX_COMPILER="g++" -DCMAKE_CXX_FLAGS="-std=c++11" ..
> make -j12
> sudo make install
```

## Understanding the code

Look at the tests to see how the library is used. I hope to provide better documentation with time.

## Related work

Efforts to extend functional programming to C++ go at least as far back as [FCPP](http://sourceforge.net/projects/fcpp/), a project that appears to be dead. 
More recently, Boost added support for ad-hoc polymorphism (called "generic programming" in this context) with the [Boost Concept Check Library](http://www.boost.org/doc/libs/1_53_0/libs/concept_check/concept_check.htm) (BCCL). 
Here, Boost "concepts" are essentially typeclasses, and this library provides a way to ensure templated types implement specified concepts.
Finally, [Boost Phoenix](http://www.boost.org/doc/libs/1_53_0/libs/phoenix/doc/html/index.html) provides a functional DSL within C++, supporting laziness, immutability, and some higher-order functions.

## Why Salve?

I started Salve because neither BCCL and Boost Phoenix appear to meet my (relatively simple) needs.
Boost Phoenix has great promise, but I found it too hard to use (truly epic compiler errors when things aren't perfect).
Salve aims to be simpler and easier to use while retaining the essential power of BCCL and Phoenix.

## TODO

1. Write macro to generate "verify" methods.
2. Write macro to check "verify" method for given implementation.
3. Highly document some representative subset of the code to make it easier to pick up.
4. Add some more methods to Seq: filter, count, others at: http://www.scala-lang.org/api/current/index.html#scala.collection.Seq
5. Add support for zipping and unzipping.
6. Run code formatter to make source pretty.