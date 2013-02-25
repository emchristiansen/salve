#ifndef COLLECTIONS_HPP_
#define COLLECTIONS_HPP_

#include <boost/range/irange.hpp>

/////////////////

namespace salve {

/**
 * The same as boost::irange, but returns an empty range instead of asserting
 * false when end < begin.
 */
template<typename IntT>
boost::integer_range<IntT> range(const IntT begin, const IntT end) {
  if (end < begin) return boost::irange<IntT>(begin, begin);
  else return boost::irange(begin, end);
}

//template<typename IntT>
//boost::strided_integer_range<IntT> range(const IntT begin, const IntT end,
//                                        const IntT stride) {
//  return boost::irange(begin, end, stride);
//}

} // namespace salve

#endif /* COLLECTIONS_HPP_ */
