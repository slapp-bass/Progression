#ifndef _INSTRUMENTS_H_
#define _INSTRUMENTS_H_

#include <string>

namespace cnv{
    class Instruments{
        private:
            int channel;
            int velocity;
            int track_num;

        public:
            Instruments();
            Instruments(std::string instrument, int vel);

            int get_channel();
            int get_velocity();
    };
}

#endif