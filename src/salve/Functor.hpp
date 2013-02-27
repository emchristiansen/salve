#ifndef FUNCTOR_HPP_
#define FUNCTOR_HPP_

#include <functional>

#include <typeinfo>

#include "Contains.hpp"
#include "CanBuildFrom.hpp"
#include "macros.hpp"

namespace salve {

using namespace std;

//////////////////////////////////////////

/**
 * Returns a value of the specified type.
 * Used only for compile-time hackery; evaluating this at runtime will
 * cause a segmentation fault.
 */
// TODO: Move this somewhere better.
#define fakeInstance(T) *reinterpret_cast<T*>(0)

/**
 * Fancy name for anything which can be mapped over. We use "fmap" to
 * distinguish from C++ dictionaries.
 */
template<typename FromCollectionT, typename FunctionT,
    typename FromElementT = typename Contains<FromCollectionT>::ElementType>
struct Functor;

template<typename FromCollectionT, typename FunctionT,
    typename FromElementT = typename Contains<FromCollectionT>::ElementType,
    typename FunctorT = Functor<FromCollectionT, FunctionT, FromElementT>>
struct FunctorDefinition {
  // Uses trailing return types to work with lambdas. See:
  // http://stackoverflow.com/questions/7950680/how-can-i-pass-a-lambda-c11-into-a-templated-function
  static auto fmap(
      const FunctionT& f,
      const FromCollectionT& collection) ->
      typename CanBuildFrom<FromCollectionT, decltype(f(fakeInstance(FromElementT)))>::ToT;

  static bool verify() {
    verifyMethod(Functor, fmap, FromCollectionT, FunctionT)
    return true;
  }
};

//////////////////////////////////

/**
 * Convenience method for Functor.
 */
template<typename FromCollectionT, typename FunctionT,
    typename FromElementT = typename Contains<FromCollectionT>::ElementType,
    typename FunctorT = Functor<FromCollectionT, FunctionT, FromElementT>>
auto fmap(
    FunctionT f,
    const FromCollectionT& orig) ->
    typename CanBuildFrom<FromCollectionT, decltype(f(fakeInstance(FromElementT)))>::ToT {
  return FunctorT::fmap(f, orig);
}

/////////////////////////////////

/**
 * Functor implementation for vector.
 */
template<typename FunctionT, typename FromElementT>
struct Functor<vector<FromElementT>, FunctionT> {
  static auto fmap(const FunctionT& f, const vector<FromElementT>& v) ->
  vector<decltype(f(fakeInstance(FromElementT)))> {
    vector<decltype(f(fakeInstance(FromElementT)))> output;
    output.reserve(v.size());
    for (const FromElementT& e : v) {
      output.push_back(f(e));
    }
    return output;
  }
};

//verifyImplementation(Functor, vector<int>, function<int(double)>)

}  // namespace salve

#endif /* FUNCTOR_HPP_ */
