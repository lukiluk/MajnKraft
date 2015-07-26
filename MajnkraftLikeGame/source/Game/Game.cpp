/* 
 * File:   Game.cpp
 * Author: Lukas
 * 
 * Created on Sobota, 2015, máj 30, 16:28
 */

#include "Game.h"

Game::Game() {
}

void Game::initialize() {
    camera = Camera(70.0f, 8/6, 0.01f, 1000.0f, PhongShader::getInstance().getShaderProgram());
    camera.setCameraPosition(1.0f, 1.0f, 4.0f);
    camera.setLookAtPosition(0.0f, 0.0f, -2.0f);
    
    kocka1 = new GObject(CUBE,PHONG);
    plane = new GObject(PLANE,PHONG);

    plane->setTextures("bricks.png");
    kocka1->setTextures("rock.png");
    
    SDL_Event windowEvent; //Zachytava ukoncenie okna a klavesnicu


    PhongShader::getInstance().setAmbientLight(glm::vec3(0.1f, 0.1f, 0.1f));
    //PhongShader::getInstance().setDirectionalLight(DirectionalLight(BaseLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.8f), glm::vec3(0.0f, -1.0f, 1.0f)));
    PhongShader::getInstance().setSpecularIntensity(2);
    PhongShader::getInstance().setSpecularPower(32);
    PointLight p1 = PointLight(BaseLight(glm::vec3(0.0f, 0.5f, 0.5f), 0.8f), Attenuation(0, 0, 1), glm::vec3(0, -0.1f, 2.0f),8);
    PointLight p2 = PointLight(BaseLight(glm::vec3(0.5f, 0.0f, 0.5f), 0.8f), Attenuation(0, 0, 1), glm::vec3(0, -0.1f, 0),8);
    SpotLight s1 = SpotLight(PointLight(BaseLight(glm::vec3(0.5f, 0.0f, 0.5f), 0.8f), Attenuation(0, 0, 1), glm::vec3(0, 2.0f, 0),8),
                            glm::vec3(0,-1,0.5f),0.7f);

    pls.push_back(p1);
    sls.push_back(s1);
    PhongShader::getInstance().setSpotLights(sls);
}

void Game::input() {
    running = playerInput.input();
        if (playerInput.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
            running = false;
        }
        if (playerInput.isKeyHolded(SDL_SCANCODE_S)) {
            camera.moveCameraBack();
        }
        if (playerInput.isKeyHolded(SDL_SCANCODE_W)) {
            camera.moveCameraFoward();
        }
        if (playerInput.isKeyHolded(SDL_SCANCODE_A)) {
            camera.moveCameraLeft();
        }
        if (playerInput.isKeyHolded(SDL_SCANCODE_D)) {
            camera.moveCameraRight();
        }
        // If the mouse is moving to the left 

        if (playerInput.isMBHolded(SDL_BUTTON_LEFT)) {
            SDL_SetRelativeMouseMode(SDL_TRUE);
            if (playerInput.getMouseDeltaX() < 0)
                camera.lookLeft();
            // If the mouse is moving to the right 
            if (playerInput.getMouseDeltaX() > 0)
                camera.lookRight();
            // If the mouse is moving up 
            if (playerInput.getMouseDeltaY() < 0)
                camera.lookUp();
            // If the mouse is moving down 
            if (playerInput.getMouseDeltaY() > 0)
                camera.lookDown();
        }
        if (playerInput.wasMBRelased(SDL_BUTTON_LEFT)) {
            SDL_SetRelativeMouseMode(SDL_FALSE);
        }
}

void Game::render() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Nastavy cistiacu farbu ktora sa pouzije pri cisteni obrazovky
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Vycisti sa obrazovka
    
    kocka1->draw();
    plane->draw();
    
    PhongShader::getInstance().updateUniforms(camera.getProjectionMatrix(), camera.getViewMatrix(), camera.getCameraPosition());
}

void Game::update() {
        kocka1->move(0,1,0);
        kocka1->rotate(glm::sin((float)SDL_GetTicks()/1000),glm::sin((float)SDL_GetTicks()/1000)*2,0.5);
        plane->move(0, -1, 0);
        plane->scale(4, 1, 4);
        pls[0].SetPosition(glm::vec3(glm::sin((float)SDL_GetTicks()/1000), -0.1f, 0.0f));
        PhongShader::getInstance().setPointLights(pls);
}

bool Game::isRunning(){
    return running;
}

void Game::setRunning(bool running) {
    this->running = running;
}

Game::~Game() {
    SDL_Quit();
}

