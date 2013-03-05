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
TYPECLASS(Seq, (CollectionT)) {
  typedef typename Contains<CollectionT>::ElementT ElementT;

  /**
   * The first element of a Seq. Asserts not empty.
   */
  virtual optional<ElementT> headOption(const CollectionT& collection) = 0;

  /**
   * All the elements but the first.
   */
  virtual CollectionT tail(const CollectionT& collection) = 0;

  /**
   * All the elements but the last.
   */
  virtual CollectionT init(const CollectionT& collection) = 0;

  /**
   * The last element. Asserts not empty.
   */
  // TOOO: Rename to "collection".
  virtual ElementT last(const CollectionT& collection) = 0;

//  /**
//   * Returns a new collection consisting of the first |num| elements.
//   */
//  virtual CollectionT take(const CollectionT& collection, const int num) = 0;
//
//  /**
//   * Returns a new collection consisting of the last
//   * |collection.size() - num| elements.
//   */
//  virtual CollectionT drop(const CollectionT& collection, const int num) = 0;
//
//  /**
//   * Returns a new collection consisting of the elements that satisfy the
//   * predicate.
//   */
//  virtual CollectionT filter(const CollectionT& collection,
//                            const function<bool(ElementT)> predicate) = 0;
//
//  /**
//   * Returns the index of the first element satisfying the predicate.
//   */
//  virtual optional<int> indexOfOption(const CollectionT& collection,
//                                     const function<bool(ElementT)> predicate) = 0;
};

//////////////////////

/**
 * Convenience functions for Seq.
 */
EXPOSE(Seq, (CollectionT), headOption, (CollectionT))
EXPOSE(Seq, (CollectionT), tail, (CollectionT))
EXPOSE(Seq, (CollectionT), init, (CollectionT))
EXPOSE(Seq, (CollectionT), last, (CollectionT))

//////////////////////

/**
 * Says a vector<ElementT> is a Seq.
 */
template<typename ElementT>
INSTANCE(Seq, (vector<ElementT>)) {
optional<ElementT> headOption(const vector<ElementT>& v) override {
  if (v.size() == 0) return optional<ElementT>();
  else return optional<ElementT>(v.at(0));
}

vector<ElementT> tail(const vector<ElementT>& v) override {
  vector<ElementT> output;
  output.reserve(v.size() - 1);
  for (int index : range<int>(1, v.size())) {
    output.push_back(v.at(index));
  }
  return output;
}

vector<ElementT> init(const vector<ElementT>& v) override {
  vector<ElementT> output;
  output.reserve(v.size() - 1);
  for (int index : range<int>(0, v.size() - 1)) {
    output.push_back(v.at(index));
  }
  return output;
}

ElementT last(const vector<ElementT>& v) override {
  // TODO
  assert(v.size() > 0);
  return v.at(v.size() - 1);
}
};

}  // namespace salve

#endif /* SEQ_HPP_ */
