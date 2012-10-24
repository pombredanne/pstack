#include "dwarf.h"
#include <iostream>
#include <tuple>
#include <functional>

template <typename T> std::ostream &operator << (std::ostream &os, const std::list<T> &entries) {
    os << "[ ";
    std::string sep = "";
    for (auto &entry : entries) {
        os << sep << entry;
        sep = ", ";
    }
    return os << " ]";
}

template <typename T> std::ostream &operator << (std::ostream &os, const std::list<T *> &entries) {
    os << "[ ";
    std::string sep = "";
    for (auto entry : entries) {
        os << sep << *entry;
        sep = ", ";
    }
    return os << " ]";
}

template <> inline
std::ostream &operator << (std::ostream &os, const std::list<std::string> &entries) {
    os << "[ ";
    std::string sep = "";
    for (auto &entry : entries) {
        os << sep << "\"" << entry << "\"";
        sep = ", ";
    }
    return os << " ]";
}

template <typename T> std::ostream &operator << (std::ostream &os, const std::vector<T> &entries) {
    os << "[ ";
    std::string sep = "";
    for (auto &entry : entries) {
        os << sep << entry;
        sep = ", ";
    }
    return os << " ]";
}

template <> inline
std::ostream &operator << (std::ostream &os, const std::vector<std::string> &entries) {
    os << "[ ";
    std::string sep = "";
    for (auto &entry : entries) {
        os << sep << "\"" << entry << "\"";
        sep = ", ";
    }
    return os << " ]";
}

template <typename T> std::ostream &operator << (std::ostream &os, const std::vector<T *> &entries) {
    os << "[ ";
    const char *sep = "";
    for (auto entry : entries) {
        os << sep << *entry;
        sep = ", ";
    }
    return os << " ]";
}

template <typename K, typename V> std::ostream &operator << (std::ostream &os, const std::map<K, V> &entries) {
    os << "{ ";
    std::string sep = "";
    for (auto &entry : entries) {
        os << sep << " \"" << entry.first << "\": " << entry.second;
        sep = ", ";
    }
    return os << " }";
}

template <typename K, typename V> std::ostream &operator << (std::ostream &os, const std::map<K, V *> &entries) {
    os << "{ ";
    std::string sep = "";
    for (auto &entry : entries) {
        const V &v = *entry.second;
        os << sep << " \"" << entry.first << "\": " << v;
        sep = ", ";
    }
    return os << " }";
}

std::ostream &operator << (std::ostream &, const DwarfAbbreviation &);
std::ostream &operator << (std::ostream &, const DwarfARange &);
std::ostream &operator << (std::ostream &, const DwarfARangeSet &);
std::ostream &operator << (std::ostream &, const DwarfAttribute &);
std::ostream &operator << (std::ostream &, const DwarfAttributeSpec &);
std::ostream &operator << (std::ostream &, const DwarfBlock &);
std::ostream &operator << (std::ostream &, const DwarfEntry &);
std::ostream &operator << (std::ostream &, const DwarfExpressionOp);
std::ostream &operator << (std::ostream &, const DwarfFileEntry &);
std::ostream &operator << (std::ostream &, const DwarfFrameInfo &);
std::ostream &operator << (std::ostream &, const DwarfInfo &);
std::ostream &operator << (std::ostream &, const DwarfLineInfo &);
std::ostream &operator << (std::ostream &, const DwarfLineState &);
std::ostream &operator << (std::ostream &, const DwarfPubname &);
std::ostream &operator << (std::ostream &, const DwarfPubnameUnit &);
std::ostream &operator << (std::ostream &, const DwarfUnit &);
std::ostream &operator << (std::ostream &, const Elf_auxv_t &);
std::ostream &operator << (std::ostream &, const Elf_Phdr &);
std::ostream &operator << (std::ostream &, const prstatus_t &);
std::ostream &operator << (std::ostream &, const std::pair<const DwarfInfo &, const DwarfCIE &> &);
std::ostream &operator << (std::ostream &, const std::pair<const DwarfInfo &, const DwarfFDE &> &);
std::ostream &operator << (std::ostream &, const std::pair<const ElfObject *, const Elf_Shdr *> &);
std::ostream &operator << (std::ostream &, DwarfAttrName);
std::ostream &operator << (std::ostream &, DwarfForm);
std::ostream &operator << (std::ostream &, DwarfLineEOpcode);
std::ostream &operator << (std::ostream &, DwarfTag);
std::ostream &operator << (std::ostream &, std::tuple<const ElfObject *, const Elf_Shdr *, const Elf_Sym *> &);
std::ostream &operator << (std::ostream &, td_err_e);
