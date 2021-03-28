
#include <algorithm>
#include <random>
#include "Playlist.h"

Playlist::Playlist()
{
    
}

void Playlist::shuffle(const playlistShuffleMode& mode)
{
    random_device engine;
    switch (mode)
    {
        case PLAYLIST_SHUFFLE_ALL:
            std::shuffle(this->entries.begin(), this->entries.end(), engine);
            break;
        case PLAYLIST_SHUFFLE_FROM_CURRENT_ENTRY:
            std::shuffle(this->playbackIterator++, this->entries.end(), engine);
            break;
        case PLAYLIST_SHUFFLE_RESET_ON_CURRENT_ENTRY:
            break;
    }
}