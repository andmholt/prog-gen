#include "../include/progression.hpp"
#include "../include/fakeChord.hpp"
#include <thread>

Progression::Progression(int bassOct, int octRange, int notesPerChord, Key key, std::vector<RN> rns, Instrument instrument) {
    this->numChords = rns.size();
    this->instrument = instrument;
    this->key = key;

    // create chords
    for (int i=0; i<numChords; ++i) {
        Mode newMode = rnToMode(rns[i]);
        FakeChord* newChord = new FakeChord(bassOct, octRange, notesPerChord, key, rns[i], newMode, instrument);
        chords.push_back(newChord);
    }
}

Progression::~Progression() {
    for (int i=0; i<numChords; ++i)
        delete chords[i];
}

void Progression::play() const {
    for (int i=0; i<numChords; ++i) {
        chords[i]->play();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Progression::print() const {
    /*std::cout << keyToString() << ": ";
    for (int i=0; i<numChords; ++i) {
        std::cout << rnToString(chords[i])
    }*/
    for (int i=0; i<numChords; ++i) {
        chords[i]->print();
    }
}

// returns key as a string
std::string Progression::keyToString() const {

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

std::string Progression::rnToString(RN rn) const {

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

Mode Progression::rnToMode(RN rn) const {
    Mode mode;
    switch (rn) {
        case (I) : mode = Ionian;
            break;
        case (ii) : mode = Dorian;
            break;
        case (iii) : mode = Phrygian;
            break;
        case (IV) : mode = Lydian;
            break;
        case (V) : mode = Mixolydian;
            break;
        case (vi) : mode = Aeolian;
            break;
        case (viidim) : mode = Locrian;
            break;
        default : throw std::string("Mode not found");
    }
    return mode;
}