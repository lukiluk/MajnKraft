/* 
 * File:   Game.cpp
 * Author: Lukas
 * 
 * Created on Sobota, 2015, máj 30, 16:28
 */

#include "Game.h"

Game::Game() {

}

Game::Game(const Game& orig) {

}

void Game::initialize() {

    kocka2->setTextures("./Graphic/Textures/grass.png", "./Graphic/Textures/grass.png", "./Graphic/Textures/grass.png"
            , "./Graphic/Textures/grass.png", "./Graphic/Textures/grass.png", "./Graphic/Textures/grassB.png");
    kocka1->setTextures("./Graphic/Textures/rock.png");

    camera.update(glm::vec3(1.0f, 1.0f, 4.0f), glm::vec3(0.0f, 0.0f, -1.0f), //aktualizuje kameru(pojde do hlavneho cyklu))
            glm::vec3(0.0f, 1.0f, 0.0f));
    camera.setCameraPosition(1.0f, 1.0f, 4.0f);
    camera.setLookAtPosition(0.0f, 0.0f, -2.0f);
}

void Game::input() {
    running = inputer.input();
    if (inputer.wasKeyDown(SDLK_ESCAPE)) {
        running=false;
    }
    if (inputer.isKeyPressed(SDLK_s)) {
        camera.moveCameraBack();
    }
    if (inputer.isKeyPressed(SDLK_w)) {
        camera.moveCameraFoward();
    }
    if (inputer.isKeyPressed(SDLK_a)) {
        camera.moveCameraLeft();
    }
    if (inputer.isKeyPressed(SDLK_d)) {
        camera.moveCameraRight();
    }
    // If the mouse is moving to the left 
    if (inputer.getMouseDeltaX() < 0)
        camera.lookLeft();
    // If the mouse is moving to the right 
    if (inputer.getMouseDeltaX() > 0)
        camera.lookRight();
    // If the mouse is moving up 
    if (inputer.getMouseDeltaY() < 0)
        camera.lookUp();
    // If the mouse is moving down 
    if (inputer.getMouseDeltaY() > 0)
        camera.lookDown();
    if (inputer.isMBPressed(SDL_BUTTON_LEFT)) {
        SDL_SetRelativeMouseMode(SDL_TRUE);
    }
    if (inputer.wasMBUp(SDL_BUTTON_LEFT)) {
        SDL_SetRelativeMouseMode(SDL_FALSE);
    }
}

void Game::render() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                if (j == 10) {
                    kocka2->drawTo(k, j, i);
                }
                if (i == 1 || j == 1 || k == 1 || i == 10 || k == 10) {
                    kocka1->drawTo(k, j, i);
                }
            }
        }
    }
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Nastavy cistiacu farbu ktora sa pouzije pri cisteni obrazovky
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Vycisti sa obrazovka
}

void Game::update() {
     if (SDL_PollEvent(&windowEvent))                          //zachyti udalosti ktore sa stali v okne
            if (windowEvent.type == SDL_QUIT) running=false; 
    camera.update(glm::vec3(1.0f, 1.0f, 4.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

bool Game::isRunning() const {
    return running;
}

void Game::setRunning(bool running) {
    this->running = running;
}

Game::~Game() {
    SDL_Quit();
}

