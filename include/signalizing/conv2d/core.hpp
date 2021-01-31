#ifndef INCLUDE_SIGNALIZING_CONV2D_CORE
#define INCLUDE_SIGNALIZING_CONV2D_CORE

#include <array>

namespace signalizing::conv2d::core {

template<typename MatrixT>
constexpr auto access(const MatrixT &a, int row, int col)
{
  if (row < 0 || col < 0 || row >= size(a) || col >= size(a[0])) {
    return 0;
  }

  return a[row][col];
}


///
///\brief Convolute a matrix a with a kernel b
///
///\tparam MatrixT1 [][] indexable matrix
///\tparam MatrixT2 [][] indexable matrix
///\tparam MatrixT3 [][] indexable matrix
///\param a Base matrix
///\param b Kernel matrix
///\param res result matrix (same dimension as a)
///
template<typename MatrixT1, typename MatrixT2, typename MatrixT3>
constexpr void convoluteSimple(const MatrixT1 &a, const MatrixT2 &b, MatrixT3 &res)
{
  const auto center = size(b)/2;

  /* For each result cell */
  for(auto row = 0; row < size(res); row++) {
    for(auto col = 0; col < size(res[row]); col++) {
      res[row][col] = 0;

      /* For each cell of b calculate colvolution sum */
      for (auto drow = 0; drow < size(b); drow++) {
        for (auto dcol = 0; dcol < size(b[drow]); dcol++) {
          res[row][col] += b[drow][dcol] * access(a, row-drow+center, col-dcol+center);
        }
      }

    }
  }
}

}

#endif /* INCLUDE_SIGNALIZING_CONV2D_CORE */
