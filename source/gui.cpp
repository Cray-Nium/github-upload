/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "AudioLibrary.h"
#include "AudioTrack.h"
#include "audioPlayback.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "globals.h"
#include "gui.h"

using namespace sf;

//For displaying on TV
/*
Vector2f viewOrigin(40,25); //First visible pixel
Vector2f viewLimit(1881,1056); //First non-visible pixel beyond center
Vector2f viewSize = viewLimit - viewOrigin;
*/

Vector2u windowSize;
Vector2u windowOrigin = Vector2u(0,0);

//Getting album art working
#include "Album.h"
extern vector<Album> albumLibrary;
string albumArtFilePath;
string trackFilePath;
Texture albumArtTexture;
Vector2u albumArtNativeSize;
Sprite albumArtSprite;
float albumArtFrameSideMarginPercent = .10;
float albumArtFrameTopMarginPercent = .30;
float albumArtFrameSideLength;
float albumArtTextureScaleFactor;
Vector2f albumArtFrameOrigin;
RectangleShape albumArtFrame;
unsigned int localSongNumber;
#include <ctime>
clock_t t0, t1, t2, t3, t4, t5, t6;


void* guiThreadRun(void* param){
    RenderWindow window( VideoMode::getFullscreenModes()[0], "mPi3", Style::Fullscreen);
    windowSize = window.getSize();
    window.setFramerateLimit(60);

    albumArtFrameSideLength = windowSize.x * (1 - 2 * albumArtFrameSideMarginPercent);
    albumArtFrameOrigin.x = windowSize.x * albumArtFrameSideMarginPercent;
    albumArtFrameOrigin.y = windowSize.y * albumArtFrameTopMarginPercent;
    albumArtFrame.setOrigin(albumArtFrameOrigin);
    albumArtFrame.setSize(Vector2f(albumArtFrameSideLength, albumArtFrameSideLength));
    albumArtSprite.setPosition(albumArtFrame.getOrigin());

    albumArtFilePath = coreLibrary.tracks.at(primaryPlaylist.entries.at(songNumber).audioTrackKey).artFilePath;
    albumArtTexture.loadFromFile(albumArtFilePath);
    albumArtNativeSize = albumArtTexture.getSize();    
    albumArtTextureScaleFactor = ( albumArtNativeSize.x >= albumArtNativeSize.y 
                                  ? albumArtFrameSideLength / albumArtNativeSize.x
                                  : albumArtFrameSideLength / albumArtNativeSize.y);
    albumArtTexture.setSmooth(false);
    
    albumArtSprite.setTexture(albumArtTexture);
    albumArtSprite.setScale(albumArtTextureScaleFactor, albumArtTextureScaleFactor);

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::TouchBegan:
                    break;
                case sf::Event::TouchMoved:
                    break;
                case sf::Event::TouchEnded:
                    if (event.touch.x < (windowSize.x / 2) )
                    {
                        if (getTrackTime() > 2.0){
                            audioPlaybackMessages.push(COMMAND_RESTART_TRACK);
                        }
                        else{
                            audioPlaybackMessages.push(COMMAND_PREVIOUS_TRACK);
                        }
                    }
                    else
                    {
                        audioPlaybackMessages.push(COMMAND_NEXT_TRACK);
                    }
                    break;
            }
        }
        
        if (audioThreadDone){
            window.close();
        }

        if(localSongNumber != songNumber)
        {
            localSongNumber = songNumber;
            cout << "GUI Refreshing album art texture for songNumber " << localSongNumber << endl;
            albumArtFilePath = coreLibrary.tracks.at(primaryPlaylist.entries.at(localSongNumber).audioTrackKey).artFilePath;
            trackFilePath = coreLibrary.tracks.at(primaryPlaylist.entries.at(localSongNumber).audioTrackKey).filepath;
            cout << "GUI got art filepath: " << albumArtFilePath << " for track: " << trackFilePath << endl;
            t1 = clock();
            if (!albumArtTexture.loadFromFile(albumArtFilePath))
            {
                cout << "GUI Failed to load file" << endl;
            }
            else
            {
                t2 = clock();
                albumArtNativeSize = albumArtTexture.getSize();
                albumArtTextureScaleFactor = ( albumArtNativeSize.x >= albumArtNativeSize.y 
                                              ? albumArtFrameSideLength / albumArtNativeSize.x
                                              : albumArtFrameSideLength / albumArtNativeSize.y);
                albumArtSprite.setTexture(albumArtTexture, true);
                albumArtSprite.setScale(albumArtTextureScaleFactor, albumArtTextureScaleFactor);
                cout << "Time to load texture: " << (t2 - t1) / (CLOCKS_PER_SEC / 1000) << " ms" << endl;
            }
        }
        
        window.clear(Color::Black);
        window.draw(albumArtSprite);
        window.display();
    }
}

bool guiInit(){
    return true;
}

void guiCleanup(){
}