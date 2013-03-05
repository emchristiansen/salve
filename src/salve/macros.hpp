#pragma once

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

////////////////////////////////////

namespace salve {

using namespace std;

/**
 * Returns a value of the specified type.
 * Used only for compile-time hackery; evaluating this at runtime will
 * cause a segmentation fault.
 */
#define fakeInstance(T) *reinterpret_cast<T*>(0)

/////////////////////////////////////////

#define ADD_COMMA_AND_TYPENAME(r, data, i, type) \
  BOOST_PP_COMMA_IF(i) typename type

#define ADD_COMMAS_AND_TYPENAMES(types) \
  BOOST_PP_SEQ_FOR_EACH_I(ADD_COMMA_AND_TYPENAME,, types)

#define ADD_COMMA(r, data, i, type) \
  BOOST_PP_COMMA_IF(i) type

#define ADD_COMMAS(types) \
  BOOST_PP_SEQ_FOR_EACH_I(ADD_COMMA,, types)

////////////////////////////////////

#define TYPECLASS_DECLARE_IMPLEMENTATION(typeclass, types) \
  template<ADD_COMMAS_AND_TYPENAMES(types)> \
  struct typeclass ## Implementation;

#define TYPECLASS_DECLARE_INTERFACE(typeclass, types) \
  template<ADD_COMMAS_AND_TYPENAMES(types)> \
  struct typeclass ## Interface;

#define TYPECLASS_BRIDGE(typeclass, types) \
  template<ADD_COMMAS_AND_TYPENAMES(types), \
           typename ImplementationT = typename enable_if< \
      is_base_of<typeclass ## Interface<ADD_COMMAS(types)>, \
        typeclass ## Implementation<ADD_COMMAS(types)>>::value, \
      typeclass ## Implementation<ADD_COMMAS(types)>>::type> \
  struct typeclass : public ImplementationT { \
  };

#define TYPECLASS_DEFINE_INTERFACE(typeclass, types) \
  template<ADD_COMMAS_AND_TYPENAMES(types)> \
  struct typeclass ## Interface

#define TYPECLASS(typeclass, types) \
  TYPECLASS_DECLARE_INTERFACE(typeclass, types) \
  TYPECLASS_DECLARE_IMPLEMENTATION(typeclass, types) \
  TYPECLASS_BRIDGE(typeclass, types) \
  TYPECLASS_DEFINE_INTERFACE(typeclass, types)

////////////////////////////////////

#define GENERATE_ARGUMENT_NAME(r, data, i, trash) \
  BOOST_PP_COMMA_IF(i) _autogen ## i

#define GENERATE_ARGUMENT_NAMES(argumentTypes) \
  BOOST_PP_SEQ_FOR_EACH_I(GENERATE_ARGUMENT_NAME,, argumentTypes)

#define GENERATE_ARGUMENT_PAIR(r, data, i, argumentType) \
  BOOST_PP_COMMA_IF(i) const argumentType& _autogen ## i

#define GENERATE_ARGUMENT_LIST(argumentTypes) \
  BOOST_PP_SEQ_FOR_EACH_I(GENERATE_ARGUMENT_PAIR,, argumentTypes)

/**
 * Puts a typeclass member function in the top-level namespace.
 * |member| is the name of the member function.
 * |argumentTypes| is the list of types the function takes.
 */
#define EXPOSE(typeclass, types, member, argumentTypes) \
  template<ADD_COMMAS_AND_TYPENAMES(types), \
    typename typeclass ## T = typeclass<ADD_COMMAS(types)>> \
  auto member (GENERATE_ARGUMENT_LIST(argumentTypes)) -> \
  decltype(typeclass ## T(). member (GENERATE_ARGUMENT_NAMES(argumentTypes))) { \
  return typeclass ## T(). member (GENERATE_ARGUMENT_NAMES(argumentTypes)); \
  }


////////////////////////////////////

/**
 * Says the specified type is an instance of the specified typeclass.
 * Multiple-type typeclasses are supported by passing more than one type.
 * Assumes |typeclass ## Implementation| and |typeclass ## Interface|
 * have been defined appropriately.
 */
#define INSTANCE(typeclass, types) \
  struct typeclass ## Implementation <ADD_COMMAS(types)> : \
  typeclass ## Interface <ADD_COMMAS(types)>

///////////////////////////////////////

// TODO: Force show to be imported for this to be defined.
#define PRINTLN(x) cout << show(x) << endl

/////////////////////////////////////

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

