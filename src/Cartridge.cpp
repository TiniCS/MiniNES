#include <Cartridge.h>
#include <iostream>
#include <fstream>
#include <array>

namespace mn
{
    Cartridge::Cartridge() : 
        m_mapperNumber(0),
        m_mirroring(0),
        m_extendedRAM(false) {

    }

    bool Cartridge::loadFromFile(std::string path) {
        std::ifstream romFile (path, std::ios_base::binary | std::ios_base::in);
        if (!romFile)
        {
            // LOG(Error) << "Could not open ROM file from path: " << path << std::endl;
            return false;
        }
        
        std::array<byte, 16> header;
        if (!romFile.read(reinterpret_cast<char*>(header._Elems), 0x10))
        {
            // LOG(Error) << "Reading iNES header failed." << std::endl;
            return false;
        }

        byte banks = header[4];
        // LOG(Info) << "16KB PRG-ROM Banks: " << +banks << std::endl;
        if (!banks)
        {
            // LOG(Error) << "ROM has no PRG-ROM banks. Loading ROM failed." << std::endl;
            return false;
        }

        byte vbanks = header[5];
        // LOG(Info) << "8KB CHR-ROM Banks: " << +vbanks << std::endl;

        m_mirroring = header[6] & 0xB;
        // LOG(Info) << "Name Table Mirroring: " << +m_nameTableMirroring << std::endl;

        m_mapperNumber = ((header[6] >> 4) & 0xf) | (header[7] & 0xf0);
        // LOG(Info) << "Mapper #: " << +m_mapperNumber << std::endl;

        m_extendedRAM = header[6] & 0x2;
        // LOG(Info) << "Extended (CPU) RAM: " << std::boolalpha << m_extendedRAM << std::endl;

        
    }
} // namespace sn