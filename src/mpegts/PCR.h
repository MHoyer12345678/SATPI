/* PCR.h

   Copyright (C) 2014 - 2021 Marc Postema (mpostema09 -at- gmail.com)

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
   Or, point your browser to http://www.gnu.org/copyleft/gpl.html
*/
#ifndef MPEGTS_PCR_DATA_H_INCLUDE
#define MPEGTS_PCR_DATA_H_INCLUDE MPEGTS_PCR_DATA_H_INCLUDE

#include <FwDecl.h>

#include <cstdint>

FW_DECL_SP_NS1(mpegts, PCR);

namespace mpegts {

class PCR {
		// =====================================================================
		// -- Constructors and destructor --------------------------------------
		// =====================================================================
	public:

		PCR();

		virtual ~PCR();

		// =====================================================================
		//  -- Other member functions ------------------------------------------
		// =====================================================================
	public:

		/// Collect Table data for tableID
		void collectData(int streamID, const unsigned char *data);

		std::int64_t getPCRDelta() const;

		void clearPCRDelta() {
			_pcrDelta = 0;
		}

		// =====================================================================
		//  -- Data members ----------------------------------------------------
		// =====================================================================
	private:

		std::uint64_t _pcrPrev;
		std::int64_t _pcrDelta;
};

} // namespace mpegts

#endif // MPEGTS_PCR_DATA_H_INCLUDE
