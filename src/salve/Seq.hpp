#ifndef SEQ_HPP_
#define SEQ_HPP_

#include "Contains.hpp"
#include "collections.hpp"

namespace salve {

////////////////////

using namespace std;

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
  static ElementT head(const CollectionT& seq);

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
  static ElementT last(const CollectionT& seq);

  // TODO: Macro to remove boilerplate.
  // TODO: Macro to put call to this in anon namespace in header files.
  static void verify() {
    typedef decltype(Seq<CollectionT, ContainsT>::head) HeadT;
    const bool headEquals = is_same<decltype(head), HeadT>::value;
    static_assert(headEquals, "Seq not implemented properly");

    typedef decltype(Seq<CollectionT, ContainsT>::tail) TailT;
    const bool tailEquals = is_same<decltype(tail), TailT>::value;
    static_assert(tailEquals, "Seq not implemented properly");

    typedef decltype(Seq<CollectionT, ContainsT>::init) InitT;
    const bool initEquals = is_same<decltype(init), InitT>::value;
    static_assert(initEquals, "Seq not implemented properly");

    typedef decltype(Seq<CollectionT, ContainsT>::last) LastT;
    const bool lastEquals = is_same<decltype(last), LastT>::value;
    static_assert(lastEquals, "Seq not implemented properly");
  }
};

//////////////////////

/**
 * Convenience function for Seq.
 */
template<typename CollectionT, typename ContainsT = Contains<CollectionT>,
    typename SeqT = Seq<CollectionT, ContainsT>>
typename ContainsT::ElementType head(const CollectionT& seq) {
  return SeqT::head(seq);
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
static ElementT head(const vector<ElementT>& v) {
  // TODO
  assert(v.size() > 0);
  return v.at(0);
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

}  // namespace salve

#endif /* SEQ_HPP_ */
