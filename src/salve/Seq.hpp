#ifndef SEQ_HPP_
#define SEQ_HPP_

#include <functional>

#include <boost/optional.hpp>

#include "Contains.hpp"
#include "collections.hpp"
#include "macros.hpp"

namespace salve {

////////////////////

using namespace std;
using boost::optional;

/**
 * A container that supports the operations you see below.
 * Modeled on Scala's Seq:
 * http://www.scala-lang.org/api/current/index.html#scala.collection.immutable.Seq
 */
template<typename CollectionT, typename ContainsT = Contains<CollectionT>>
struct Seq;

template<typename CollectionT, typename ContainsT = Contains<CollectionT>>
struct SeqDefinition {
  typedef typename ContainsT::ElementType ElementT;

  /**
   * The first element of a Seq. Asserts not empty.
   */
  static optional<ElementT> headOption(const CollectionT& seq);

  /**
   * All the elements but the first.
   */
  static CollectionT tail(const CollectionT& seq);

  /**
   * All the elements but the last.
   */
  static CollectionT init(const CollectionT& seq);

  /**
   * The last element. Asserts not empty.
   */
  // TOOO: Rename to "collection".
  // TODO: Make optional.
  static ElementT last(const CollectionT& seq);

  /**
   * Returns a new collection consisting of the first |num| elements.
   */
  static CollectionT take(const CollectionT& collection, const int num);

  /**
   * Returns a new collection consisting of the last
   * |collection.size() - num| elements.
   */
  static CollectionT drop(const CollectionT& collection, const int num);

  /**
   * Returns a new collection consisting of the elements that satisfy the
   * predicate.
   */
  static CollectionT filter(const CollectionT& collection,
                            const function<bool(ElementT)> predicate);

  /**
   * Returns the index of the first element satisfying the predicate.
   */
  static optional<int> indexOfOption(const CollectionT& collection,
                                     const function<bool(ElementT)> predicate);

  // TODO: Macro to remove boilerplate.
  static bool verify() {
    verifyMethod(Seq, headOption, CollectionT, ContainsT)
    verifyMethod(Seq, tail, CollectionT, ContainsT)
    verifyMethod(Seq, init, CollectionT, ContainsT)
    verifyMethod(Seq, last, CollectionT, ContainsT)

//    verifyMethod(Seq, take, CollectionT, ContainsT)
//    verifyMethod(Seq, drop, CollectionT, ContainsT)
//    verifyMethod(Seq, filter, CollectionT, ContainsT)
    //    verifyMethod(Seq, indexOfOption, CollectionT, ContainsT)
    return true;
  }
};

//////////////////////

/**
 * Convenience function for Seq.
 */
template<typename CollectionT, typename ContainsT = Contains<CollectionT>,
    typename SeqT = Seq<CollectionT, ContainsT>>
optional<typename ContainsT::ElementType> headOption(const CollectionT& seq) {
  return SeqT::headOption(seq);
}

/**
 * Convenience function for Seq.
 */
template<typename CollectionT, typename ContainsT = Contains<CollectionT>,
    typename SeqT = Seq<CollectionT, ContainsT>>
CollectionT tail(const CollectionT& seq) {
  return SeqT::tail(seq);
}

/**
 * Convenience function for Seq.
 */
template<typename CollectionT, typename ContainsT = Contains<CollectionT>,
    typename SeqT = Seq<CollectionT, ContainsT>>
CollectionT init(const CollectionT& seq) {
  return SeqT::init(seq);
}

/**
 * Convenience function for Seq.
 */
template<typename CollectionT, typename ContainsT = Contains<CollectionT>,
    typename SeqT = Seq<CollectionT, ContainsT>>
typename ContainsT::ElementType last(const CollectionT& seq) {
  return SeqT::last(seq);
}

//////////////////////

/**
 * Says a vector<ElementT> is a Seq.
 */
template<typename ElementT>
struct Seq<vector<ElementT>, Contains<vector<ElementT>>> {
static optional<ElementT> headOption(const vector<ElementT>& v) {
  if (v.size() == 0) return optional<ElementT>();
  else return optional<ElementT>(v.at(0));
}

static vector<ElementT> tail(const vector<ElementT>& v) {
  vector<ElementT> output;
  output.reserve(v.size() - 1);
  for (int index : range<int>(1, v.size())) {
    output.push_back(v.at(index));
  }
  return output;
}

static vector<ElementT> init(const vector<ElementT>& v) {
  vector<ElementT> output;
  output.reserve(v.size() - 1);
  for (int index : range<int>(0, v.size() - 1)) {
    output.push_back(v.at(index));
  }
  return output;
}

static ElementT last(const vector<ElementT>& v) {
  // TODO
  assert(v.size() > 0);
  return v.at(v.size() - 1);
}
};

verifyImplementation(Seq, vector<int>)

}  // namespace salve

#endif /* SEQ_HPP_ */
