#ifndef _PIANO_H_
#define _PIANO_H_

#include "Instruments.h"
#include <unordered_map>
#include <string>

namespace cnv{
    class Piano: public Instruments{
        private:
            static const std::unordered_map<std::string, int> piano_map;
    };
}

#endif