#include "../include/note.hpp"
#include <string>
#include <thread>

Note::Note(int octave, int note, Instrument instrument) {
    this->octave = octave;
    this->note = note;

    std::string instrumentString;
    std::string octaveString;
    std::string noteString;

    // instrument
    if ((int)instrument == 0)
        instrumentString = "00";
    else if ((int)instrument < 10)
        instrumentString = std::string("0") + std::to_string(instrument);
    else instrumentString = std::to_string(instrument);

    // octave
    if (octave == 0)
        octaveString = "00";
    else if (octave < 10)
        octaveString = std::string("0") + std::to_string(octave);
    else octaveString = std::to_string(octave);

    // note
    if (note == 0)
        noteString = "00";
    else if (note< 10)
        noteString = std::string("0") + std::to_string(note);
    else noteString = std::to_string(note);

    fileName = instrumentString + octaveString + noteString + std::string(".mp3");

    // create buffer
    buffer = new sf::SoundBuffer;
    if (!buffer->loadFromFile(std::string("data/notes/") + fileName)) {
        throw std::string("Unable to load sound from file");
        return;
    }

    // create note
    sound = new sf::Sound(*buffer);
}

Note::~Note() {
    // dealloc
    delete sound;
    delete buffer;
}

// plays the note from audio file
// will throw a string if file cannot be loaded
void Note::play() const {
    sound->play();
}

// gets note by code
int Note::getNoteCode() const {
    return note;
}

// gets note string
std::string Note::getNote() const {
    switch (note) {
        case (0) : return std::string("C");
        case (1) : return std::string("Db");
        case (2) : return std::string("D");
        case (3) : return std::string("Eb");
        case (4) : return std::string("E");
        case (5) : return std::string("F");
        case (6) : return std::string("Gb");
        case (7) : return std::string("G");
        case (8) : return std::string("Ab");
        case (9) : return std::string("A");
        case (10) : return std::string("Bb");
        case (11) : return std::string("B");
        default : return std::string("Could not print note");
    }
}

// gets octave
int Note::getOctave() const {
    return octave;
}

// gets fileName
std::string Note::getFileName() const {
    return fileName;
}