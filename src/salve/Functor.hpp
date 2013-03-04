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
 * Fancy name for anything which can be mapped over. We use "fmap" to
 * distinguish from C++ dictionaries.
 */
TYPECLASS(Functor, (FromCollectionT)(FunctionT)) {
  typedef typename Contains<FromCollectionT>::ElementT FromElementT;

    // Uses trailing return types to work with lambdas. See:
    // http://stackoverflow.com/questions/7950680/how-can-i-pass-a-lambda-c11-into-a-templated-function
  virtual auto fmap(
    const FunctionT& f,
    const FromCollectionT& collection) ->
      typename CanBuildFrom<
        FromCollectionT,
        decltype(f(fakeInstance(FromElementT)))>::ToT = 0;
};

//////////////////////////////////

/**
 * Convenience method for Functor.
 */
template<typename FromCollectionT, typename FunctionT,
    typename FunctorT = Functor<FromCollectionT, FunctionT>>
auto fmap(
    FunctionT f,
    const FromCollectionT& orig) ->
    typename CanBuildFrom<FromCollectionT, decltype(f(fakeInstance(typename FunctorT::FromElementT)))>::ToT {
  return FunctorT().fmap(f, orig);
}

/////////////////////////////////

/**
 * Functor implementation for vector.
 */
template<typename FunctionT, typename FromElementT>
INSTANCE(Functor, (vector<FromElementT>)(FunctionT)) {
  // TODO: override
  auto fmap(const FunctionT& f, const vector<FromElementT>& v) ->
  vector<decltype(f(fakeInstance(FromElementT)))> {
    vector<decltype(f(fakeInstance(FromElementT)))> output;
    output.reserve(v.size());
    for (const FromElementT& e : v) {
      output.push_back(f(e));
    }
    return output;
  }
};

}  // namespace salve

#endif /* FUNCTOR_HPP_ */
