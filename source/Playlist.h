#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include "PlaylistEntry.h"

using namespace std;

typedef enum _playlistShuffleMode
{
    PLAYLIST_SHUFFLE_ALL,                         //Shuffles entire playlist and resets playback iterator to beginning
    PLAYLIST_SHUFFLE_FROM_CURRENT_ENTRY,          //Shuffles all entries following playback iterator
    PLAYLIST_SHUFFLE_RESET_ON_CURRENT_ENTRY       //Moves entry of playback iterator to beginning of playlist, then shuffles the rest
} playlistShuffleMode;

class Playlist
{
private:
    
public:
    vector<PlaylistEntry> entries;
    vector<PlaylistEntry>::iterator playbackIterator;

    Playlist();
    void shuffle(const playlistShuffleMode& mode = PLAYLIST_SHUFFLE_RESET_ON_CURRENT_ENTRY);
};

#endif /* PLAYLIST_H */

