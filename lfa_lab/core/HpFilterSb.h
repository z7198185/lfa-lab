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

#ifndef LFA_HP_FILTER_SB_H
#define LFA_HP_FILTER_SB_H

#include "Common.h"
#include "SymbolBuilder.h"

namespace lfa {

  /** High-pass filter symbol builder. */
  class HpFilterSb : public SymbolBuilder {
    public:
      HpFilterSb(Grid fine_grid, Grid coarse_grid);

      virtual FoProperties properties();
      virtual Symbol generate(const SamplingProperties& conf);
    private:
      Grid m_grid;
      ArrayFi m_coarsing_factor;
  };

}

#endif