# prog-gen
prog-gen is an advanced music chord progression generator

### External libs
prog-gen requires the external lib sfml: https://github.com/SFML/SFML

Be sure to include the sfml library for each object file compilation, and link sfml libs <system> and <audio> in the creation of the final executable, as explained in https://www.sfml-dev.org/tutorials/2.5/start-linux.php

Depending on where sfml is installed to, using `export LD_LIBRARY_PATH=<sfml-install-path>/lib && ./sfml-app` might be necessary as well

### Chords
Recipe for FakeChord is as such:

`FakeChord(int bassOct, int octRange, int numNotes, Key key, RN rn, Mode mode, Instrument instrument);`

### Progressions
Recipe for Progression is as such:

`Progression(int bassOct, int octRange, int notesPerChord, Key key, std::vector<RN> rns, Instrument instrument);`

### Extra notes

Although there are many types of roman numerals and modes in `recipes.h`, not all of them have been implemented as of yet. So far only the standard 7 roman numerals have been implemented, along with the standard 7 church modes. More instruments are expected to be implemented in the future as well, although currently there only exists `GrandPiano`