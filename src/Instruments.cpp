#include "Instruments.h"

#include <string>
#include <unordered_map>


namespace cnv {
    const std::unordered_map<std::string, int> Instruments::inst_channels = {
        {"temp", 0}
    };

    Instruments::Instruments(){
        channel = 0;
        velocity = 90;
        track_num = 1;
    }

    Instruments::Instruments(std::string instrument, int vel, int track_num){
        velocity = vel;
        this->track_num = track_num;

        if (Instruments::inst_channels.contains(instrument)){
            channel = Instruments::inst_channels.at(instrument);
        } else {
            channel = 0;
        }
    }

    int Instruments::get_channel(){
        return this->channel;
    }

    int Instruments::get_velocity(){
        return this->velocity;
    }
}