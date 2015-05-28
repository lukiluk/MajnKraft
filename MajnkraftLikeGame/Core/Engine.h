/* 
 * File:   Engine.h
 * Author: Lukas
 *
 * Created on Štvrtok, 2015, máj 28, 1:05
 */

#ifndef ENGINE_H
#define	ENGINE_H
#include <string>

class Engine {
    
public:
    Engine(int width, int height, int fps, std::string title);
    Engine(const Engine& orig);
    virtual ~Engine();
    std::string title;
    int width;
    int height;
    double frameTime;
private:
    

};

#endif	/* ENGINE_H */

