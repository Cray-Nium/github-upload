/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "globals.h"
#include "gui.h"

using namespace sf;

//For displaying on TV
/*
Vector2f viewOrigin(40,25); //First visible pixel
Vector2f viewLimit(1881,1056); //First non-visible pixel beyond center
Vector2f viewSize = viewLimit - viewOrigin;
Vector2f markerPos(40,25);
*/

//For displaying on HyperPixel
Vector2f viewOrigin(0,0); //First visible pixel
Vector2f viewLimit(800,480); //First non-visible pixel beyond center
Vector2f viewSize = viewLimit - viewOrigin;
Vector2f markerPos(0,0);

Vector2i windowPosition(700,0);

void* guiThreadRun(void* param){
    RenderWindow window(sf::VideoMode(100, 100), "My window"); //Use this to make htop visible
    //RenderWindow window( VideoMode::getFullscreenModes()[0]	, "mPi3", Style::Fullscreen);
    
    //Use one of these to limit framerate
    window.setVerticalSyncEnabled(true); //When outputting HDMI to TV, this set framerate to 60Hz
    //window.setFramerateLimit(60);
/*
    Vector2f windowSize;
    windowSize.x = window.getSize().x;
    windowSize.y = window.getSize().y;
*/
    
    window.setPosition(windowPosition);
    
    RectangleShape marker(Vector2f(2,2));
    marker.setPosition(viewOrigin);
    marker.setFillColor(Color::White);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (audioThreadDone){
            window.close();
        }

        window.clear(Color(25,25,25,255));
        markerPos.x++;
        if (markerPos.x > 99){
            markerPos.x = viewOrigin.x;
            markerPos.y++;
            if (markerPos.y > 99){
                markerPos.y = viewOrigin.y;
            }
        }
        marker.setPosition(markerPos);
        window.draw(marker);
        window.display();
    }
}

bool guiInit(){
    
    return true;
}

void guiCleanup(){
}