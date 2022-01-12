#include "../include/chord.hpp"

Chord::~Chord() {}

// returns RN as a string
std::string Chord::rnToString(RN rn) const {
    
    // find RN
    switch (rn) {
        case (I) : return std::string("I");
        case (ii) : return std::string("ii");
        case (iii) : return std::string("iii");
        case (IV) : return std::string("IV");
        case (V) : return std::string("V");
        case (vi) : return std::string("vi");
        case (viidim) : return std::string("viidim");
        default : return std::string("Not able to decipher RN type");
    }

    return std::string("ERROR");
}

// returns key as a string
std::string Chord::keyToString(Key key) const {

    // find key
    switch (key) {
        case (C) : return std::string("C");
        case (Db) : return std::string("Db");
        case (D) : return std::string("D");
        case (Eb) : return std::string("Eb");
        case (E) : return std::string("E");
        case (F) : return std::string("F");
        case (Gb) : return std::string("Gb");
        case (G) : return std::string("G");
        case (Ab) : return std::string("Ab");
        case (A) : return std::string("A");
        case (Bb) : return std::string("Bb");
        case (B) : return std::string("B");
    }

    return std::string("ERROR");
}