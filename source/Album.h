#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "AudioTrack.h"

using namespace std;

struct albumDisc {
    string discName;
    vector<unsigned int> trackKeys;
};

class Album
{
private:
    string directoryPath;
    string title;
    string artist;
    string coverArtFilePath;

    bool populateTitleAndArtist();
    bool populateCoverArtFilePath();
    bool populateDiscs();
    bool populateTracks();
    
public:
    vector<albumDisc> discs;
    
    Album() {}
    Album(string directoryPath);
    
    string getDirectoryPath() {return directoryPath;}
    string getTitle() {return title;}
    string getCoverArtFilePath() {return coverArtFilePath;}
    void setDirectoryPath(string dirPath) {this->directoryPath = dirPath;}
    bool populate();
};

#endif /* ALBUM_H */

