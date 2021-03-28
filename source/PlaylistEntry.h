#ifndef PLAYLISTENTRY_H
#define PLAYLISTENTRY_H

class PlaylistEntry
{
private:
public:
    PlaylistEntry(const unsigned int& audioTrackKey, const bool& advancesAutomatically = true);

    unsigned int audioTrackKey;
    bool advancesAutomatically;
};

#endif /* PLAYLISTENTRY_H */

