#ifndef NOTE_HPP
#define NOTE_HPP

#include <string>
#include "recipes.hpp"
#include <SFML/Audio.hpp>

class Note {
public:
    Note(int octave, int note, Instrument instrument);
    ~Note();
    void play() const;
    int getOctave() const;
    int getNoteCode() const;
    std::string getNote() const;
    std::string getFileName() const;
protected:
    int octave;
    int note;
    std::string fileName;
    sf::SoundBuffer* buffer;
    sf::Sound* sound;
};

#endif