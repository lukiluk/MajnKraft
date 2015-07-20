
#include "Core/Engine.h"
#include "Game/Game.h"

//// v Linuxe: -lSDL2 -lGL -lGLEW -lSDL2_image
//// vo Windows: -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lglew32 -lopengl32
//
//#include <stdio.h>
//
//#define GLEW_STATIC
//#include <GL/glew.h>
///*
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>*/
//
//#include "SDL2/SDL.h"
//#include "Graphic/Window.h"
//#include "Graphic/Camera.h"
//#include "Graphic/GObject.h"
//#include "Core/Input.h"
//#include "Game/Svet/Svet.h"
//#include "Graphic/PhongShader.h"
//#include <vector>
//
//int main(int argc, char* argv[]) {
//    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
//
//    Window window(1336, 750, true);
//    Input input;
//
//    GObject* kocka1 = new GObject(CUBE,PHONG);
//    //GObject* kocka2 = new GObject(CUBE,PHONG);
//    GObject* plane = new GObject(PLANE, PHONG);
//
//    plane->setTextures("bricks.png");
//    //kocka2->setTextures("./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grass.png"
//    //,"./Graphic/Textures/grass.png","./Graphic/Textures/grass.png","./Graphic/Textures/grassB.png");
//    kocka1->setTextures("rock.png");
//    //Svet* svet = new Svet();
//
//    Camera camera(70.0f, (float)window.GetWidth()/window.GetHeight(), 0.01f, 1000.0f, kocka1->getActiveShader()); //vytvara cameru
//    camera.setCameraPosition(1.0f, 1.0f, 4.0f);
//    camera.setLookAtPosition(0.0f, 0.0f, -2.0f);
//    
//    SDL_Event windowEvent; //Zachytava ukoncenie okna a klavesnicu
//
//
//    PhongShader::getInstance().setAmbientLight(glm::vec3(0.1f, 0.1f, 0.1f));
//    //PhongShader::getInstance().setDirectionalLight(DirectionalLight(BaseLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.8f), glm::vec3(0.0f, -1.0f, 1.0f)));
//    PhongShader::getInstance().setSpecularIntensity(2);
//    PhongShader::getInstance().setSpecularPower(32);
//    PointLight p1 = PointLight(BaseLight(glm::vec3(0.0f, 0.5f, 0.5f), 0.8f), Attenuation(0, 0, 1), glm::vec3(0, -0.1f, 2.0f),8);
//    PointLight p2 = PointLight(BaseLight(glm::vec3(0.5f, 0.0f, 0.5f), 0.8f), Attenuation(0, 0, 1), glm::vec3(0, -0.1f, 0),8);
//    SpotLight s1 = SpotLight(PointLight(BaseLight(glm::vec3(0.5f, 0.0f, 0.5f), 0.8f), Attenuation(0, 0, 1), glm::vec3(0, 2.0f, 0),8),
//                            glm::vec3(0,-1,0.5f),0.7f);
//    std::vector<PointLight> pls;
//    std::vector<SpotLight> sls;
//    pls.push_back(p1);
//    sls.push_back(s1);
//    //pls.push_back(p2);
//    PhongShader::getInstance().setSpotLights(sls);
//    bool run = true;
////    PhongShader::getInstance().updateUniforms();
//    while (run) {
//        if (SDL_PollEvent(&windowEvent)) //zachyti udalosti ktore sa stali v okne
//            if (windowEvent.type == SDL_QUIT) break;
//        // Clear the screen to black
//        glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Nastavy cistiacu farbu ktora sa pouzije pri cisteni obrazovky
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Vycisti sa obrazovka
//        //draw cube
//        /*for (int i = 1; i <= 10; i++) {
//            for (int j = 1; j <= 10; j++) {
//                for (int k = 1; k <= 10; k++) {
//                    if(j==10){
//                        kocka2->move(k,j,i);
//                        kocka2->drawTo();
//                    }
//                    if(i==1||j==1||k==1||i==10||k==10){
//                        kocka1->move(k,j,i);
//                        kocka1->drawTo();
//                    }
//                }
//            }
//        }*/
//        kocka1->move(0,1,0);
//        kocka1->rotate(glm::sin((float)SDL_GetTicks()/1000),glm::sin((float)SDL_GetTicks()/1000)*2,0.5);
//        kocka1->draw();
//        plane->move(0, -1, 0);
//        plane->scale(4, 1, 4);
//        pls[0].SetPosition(glm::vec3(glm::sin((float)SDL_GetTicks()/1000), -0.1f, 0.0f));
//        //pls[1].SetPosition(glm::vec3(0, 0.0f, glm::sin((float)SDL_GetTicks()/1000)));
//        PhongShader::getInstance().setPointLights(pls);
//        
//        plane->draw();
//        run = input.input();
//        if (input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
//            break;
//        }
//        if (input.isKeyHolded(SDL_SCANCODE_S)) {
//            camera.moveCameraBack();
//        }
//        if (input.isKeyHolded(SDL_SCANCODE_W)) {
//            camera.moveCameraFoward();
//        }
//        if (input.isKeyHolded(SDL_SCANCODE_A)) {
//            camera.moveCameraLeft();
//        }
//        if (input.isKeyHolded(SDL_SCANCODE_D)) {
//            camera.moveCameraRight();
//        }
//        // If the mouse is moving to the left 
//
//        if (input.isMBHolded(SDL_BUTTON_LEFT)) {
//            SDL_SetRelativeMouseMode(SDL_TRUE);
//            if (input.getMouseDeltaX() < 0)
//                camera.lookLeft();
//            // If the mouse is moving to the right 
//            if (input.getMouseDeltaX() > 0)
//                camera.lookRight();
//            // If the mouse is moving up 
//            if (input.getMouseDeltaY() < 0)
//                camera.lookUp();
//            // If the mouse is moving down 
//            if (input.getMouseDeltaY() > 0)
//                camera.lookDown();
//        }
//        if (input.wasMBRelased(SDL_BUTTON_LEFT)) {
//            SDL_SetRelativeMouseMode(SDL_FALSE);
//        }
//        PhongShader::getInstance().updateUniforms(camera.getProjectionMatrix(), camera.getViewMatrix(), camera.getCameraPosition());
//        window.update();
//    }
//
//    SDL_Quit();
//
//    return 0;
//}

int main(int argc, char* argv[]) {
    Engine engine = Engine(800,600,60,"Demo: The game");
    engine.run(new Game(),60,60,60);
}