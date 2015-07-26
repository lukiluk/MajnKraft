
#include "Core/Engine.h"
#include "Game/Game.h"


int main(int argc, char* argv[]) {
    Engine engine = Engine(800,600,60,"Demo: The game");
    engine.run(new Game(),60,60,60);
}

/*Test*/