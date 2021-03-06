/*
 LAWA - Library for Adaptive Wavelet Applications.
 Copyright (C) 2008-2012  Schalk, Alexander Stippler.

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef LAWA_MATH_INV_TCC
#define LAWA_MATH_INV_TCC 1

#include <cmath>
#include <lawa/flensforlawa.h>
#include <lawa/math/inv.h>

namespace lawa {

template <typename T>
int
inv(GeMatrix<T> &A)
{
    DenseVector<int>  piv;

//
//  change index base to one
//
    int i0 = A.firstRow();
    int j0 = A.firstCol();
    A.changeIndexBase(1,1);

//
//  Compute inverse
//
    int info = flens::lapack::trf(A, piv);
    if (info==0) {
        flens::lapack::tri(A, piv);
    }

//
//  restore index base
//
    A.changeIndexBase(i0,j0);
    return info;
}

} // namespace lawa

#endif // LAWA_MATH_INV_TCC

