#ifndef MACROS_HPP_
#define MACROS_HPP_

namespace salve {

/**
 * A macro for ensuring that an implementation of a typeclass is correct.
 * It assumes that for a typeclass Foo, there exists a struct FooDefinition
 * with a function |verify|. The |verify| function does the actual work
 * of ensuring the interface is implemented; this macro simply calls it.
 */
#define verifyImplementation(interface, templateArguments...) \
  namespace { \
  /* This struct makes it possible to put each call to |verify| in its own namespace */ \
  template <typename ... Ts> \
  struct StructForCreatingUniqueNames; \
  template <> \
  struct StructForCreatingUniqueNames<interface<templateArguments>> { \
    bool trash = interface ## Definition<templateArguments>::verify(); \
  }; \
  }

}  // namespace salve

#endif /* MACROS_HPP_ */
