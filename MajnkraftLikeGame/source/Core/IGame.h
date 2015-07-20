/* 
 * File:   IGame.h
 * Author: Lukas
 *
 * Created on Sobota, 2015, máj 30, 17:04
 */

#ifndef IGAME_H
#define	IGAME_H

class IGame {
public:

    virtual ~IGame() {
    }
    virtual void initialize() = 0;
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool isRunning() = 0;
};

#endif	/* IGAME_H */

