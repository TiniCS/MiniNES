#ifndef __Cartridge_H__
#define __Cartridge_H__

#include <vector>
#include <string>

namespace mn {
    class Cartridge {
    public:
        using byte = unsigned char;
        using PRGROMBank = byte[0x4000];
        using CHRROMBank = byte[0x2000];
        using uint = unsigned int;

        Cartridge();
        bool loadFromFile(std::string& path);
        uint mapperNumber() const { return m_mapperNumber};
        uint mirroring() const { return m_mirroring; };
        bool extendedRAM() const { return m_extendedRAM; };
        const std::vector<PRGROMBank>& PRGROM() const { return m_PRGROMBanks; };
        const std::vector<CHRROMBank>& CHRROM() const { return m_CHRROMBanks; };
    private:
        std::vector<PRGROMBank> m_PRGROMBanks;
        std::vector<CHRROMBank> m_CHRROMBanks;
        bool m_mirroring;
        bool m_extendedRAM;
        uint m_mapperNumber;
    };
}

#endif // !__Cartridge_H__