#ifndef MACROS_HPP_
#define MACROS_HPP_

namespace salve {

using namespace std;

/**
 * Generates the boilerplate needed to ensure a given method is implemented
 * properly for a given interface.
 */
//#define verifyMethod(specializedInterface, method) \
//  typedef decltype(specializedInterface::method) method ## OtherMethodT; \
//  typedef decltype(method) method ## GoldenMethodT; \
//  const bool method ## typeEquality = is_same<method ## OtherMethodT, method ## GoldenMethodT>::value; \
//  static_assert(method ## typeEquality, #specializedInterface "::" #method " is not implemented properly.");
#define verifyMethod(interface, method, templateArguments...) \
  typedef decltype(interface<templateArguments>::method) method ## OtherMethodT; \
  typedef decltype(method) method ## GoldenMethodT; \
  const bool method ## typeEquality = is_same<method ## OtherMethodT, method ## GoldenMethodT>::value; \
  static_assert(method ## typeEquality, #interface "::" #method " is not implemented properly.");

/**
 * A macro for ensuring that an implementation of a typeclass is correct.
 * It assumes that for a typeclass Foo, there exists a struct FooDefinition
 * with a function |verify|. The |verify| function does the actual work
 * of ensuring the interface is implemented; this macro simply calls it.
 */
#define verifyImplementation(interface, templateArguments...) \
  namespace { \
  /* It is necessary to put each call to |verify| in its own namespace */ \
  template <typename ... Ts> \
  struct StructForCreatingUniqueNames; \
  template <> \
  struct StructForCreatingUniqueNames<interface<templateArguments>> { \
    bool trash = interface ## Definition<templateArguments>::verify(); \
  }; \
  }

}  // namespace salve

#endif /* MACROS_HPP_ */
