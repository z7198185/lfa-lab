/*
  LFA Lab - Library to simplify local Fourier analysis.
  Copyright (C) 2018  Hannah Rittich

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. 
*/

#ifndef LFA_ND_ARRAY_H
#define LFA_ND_ARRAY_H

#include <Common.h>
#include <NdRange.h>

namespace lfa {

template<typename T>
class NdArray
{
    public:
        NdArray(ArrayFi shape = ArrayFi::Zero(0))
          : m_grid(shape)
        {
            m_elements.resize(m_grid.size());
        }

        ArrayFi shape() const { return m_grid.shape(); }

        T& operator() (const ArrayFi& pos) {
            return m_elements[m_grid.indexOf(pos)];
        }
        const T& operator() (const ArrayFi& pos) const {
            return m_elements[m_grid.indexOf(pos)];
        }

        bool index_in_range(const ArrayFi& pos) const {
            return m_grid.inRange(pos);
        }

        NdRange indices() const {
            return m_grid;
        }

        int dimension() const {
            return m_grid.dimension();
        }

    private:
        NdRange m_grid;
        vector<T> m_elements;
};


};

#endif