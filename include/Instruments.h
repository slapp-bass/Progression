#ifndef _INSTRUMENTS_H_
#define _INSTRUMENTS_H_

#include <string>
#include <unordered_map>

namespace cnv{
    class Instruments{
        private:
            static const std::unordered_map<std::string, int> inst_channels;

            int channel;
            int velocity;
            int track_num;

        public:
            Instruments();
            Instruments(std::string instrument, int vel, int track_num);

            int get_channel();
            int get_velocity();
    };
}

#endif