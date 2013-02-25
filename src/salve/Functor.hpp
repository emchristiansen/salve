#ifndef FUNCTOR_HPP_
#define FUNCTOR_HPP_

#include <functional>

#include <typeinfo>

#include "Contains.hpp"
#include "CanBuildFrom.hpp"

namespace salve {

using namespace std;

//////////////////////////////////////////

/**
 * Fancy name for anything which can be mapped over. We use "fmap" to
 * distinguish from C++ dictionaries.
 */
template<typename CollectionT, typename OtherElementT,
    typename ContainsT = Contains<CollectionT>,
    typename CanBuildFromT = CanBuildFrom<CollectionT, OtherElementT>>
struct Functor;

template<typename CollectionT, typename OtherElementT,
    typename ContainsT = Contains<CollectionT>,
    typename CanBuildFromT = CanBuildFrom<CollectionT, OtherElementT>>
struct FunctorDefinition {
  typedef typename ContainsT::ElementType ElementT;
  typedef typename CanBuildFromT::ToT ToT;

  static ToT fmap(const function<OtherElementT(ElementT)>& f,
                  const CollectionT& collection);

  static void verify() {
    typedef decltype(Functor<CollectionT, OtherElementT>::fmap) FMapT;
    const bool verifyFMap = is_same<decltype(fmap), FMapT>::value;
    static_assert(verifyFMap, "Functor not properly implemented");
  }
};

///////////////////////////////////////////

/**
 * Convenience function for Functor.
 */
template<typename CollectionT, typename OtherElementT,
    typename ContainsT = Contains<CollectionT>,
    typename CanBuildFromT = CanBuildFrom<CollectionT, OtherElementT>,
    typename FunctorT = Functor<CollectionT, OtherElementT, ContainsT,
        CanBuildFromT>>
typename CanBuildFromT::ToT fmap(
    const function<OtherElementT(typename ContainsT::ElementType)>& f,
    const CollectionT& collection) {
  return FunctorT::fmap(f, collection);
}

//////////////////////////////////

template<typename ElementT, typename OtherElementT>
struct Functor<vector<ElementT>, OtherElementT> {
  static vector<OtherElementT> fmap(const function<OtherElementT(ElementT)>& f,
                                    const vector<ElementT>& v) {
    vector<OtherElementT> output;
    output.reserve(v.size());
    for (const ElementT& e : v) {
      output.push_back(f(e));
    }
    return output;
  }
};

} // namespace salve

#endif /* FUNCTOR_HPP_ */
