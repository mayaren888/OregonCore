/*
 * This file is part of the OregonCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef OREGONCORE_WORLDPACKET_H
#define OREGONCORE_WORLDPACKET_H

#include "Common.h"
#include "ByteBuffer.h"

class WorldPacket : public ByteBuffer
{
    public:
        // just container for later use
        WorldPacket()                                       : ByteBuffer(0), m_opcode(0)
        {
        }
        explicit WorldPacket(uint16 opcode, size_t res = 200) : ByteBuffer(res), m_opcode(opcode) { }
        // copy constructor
        WorldPacket(const WorldPacket& packet)              : ByteBuffer(packet), m_opcode(packet.m_opcode)
        {
        }

        void Initialize(uint16 opcode, size_t newres = 200)
        {
            clear();
            _storage.reserve(newres);
            m_opcode = opcode;
        }

        uint16 GetOpcode() const
        {
            return m_opcode;
        }
        void SetOpcode(uint16 opcode)
        {
            m_opcode = opcode;
        }

    protected:
        uint16 m_opcode;
};
#endif

