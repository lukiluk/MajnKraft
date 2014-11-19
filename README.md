MajnKraft
=========

Prvy projekt na vyucbu 3D grafiky a tvorby hier. Cielom tohto projetku je vytvorenie funkcnej kopie hry Minecraft s vyuitim jazyka C++ a kniznice SDL2.

First project to learn 3D graphics and computer game creation. Goal of this project is to crate functional copy of Minecraft with use of C++ language and SLD2 library.

Potrebne kniznice - Required Libraries
======================================

-SDL2
-SDL2_Image
-GLEW
-GLM

Linker Options
==============

V projekte do linker options doplnte:

- v Linuxe: -lSDL2 -lGL -lGLEW -lSDL2_image
- vo Windows: -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lglew32 -lopengl32
