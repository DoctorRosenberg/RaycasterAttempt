# 📦 Raycaster-attempt

This is my attempt at making a raycaster. Maybe its code will be used by me in the future.

## 🌟 Highlights

- Made in C++ and SDL3!
- Should work!
- You can make your own level without recompiling! (no level editor but you can make a map file. Look in maps/MapMakingDoc)
- Settings feature! (Look in settings.txt. If you're confused, read settings_editing.md.)

Collisions are off for now. You can go through wall, but don't go out of your map.

## ℹ️ Overview

In this program, you can see everything inside a room, walk in it, and maybe use it for your own game.
I started on June 2nd. I thought about making a raycaster, just like ID software once did in Wolfenstein 3D. Dropped it very quickly though. DOOM used BSP.
Working on this project brought me a good ammount of problems, which I had to solve. But I am still satisfied, due to result being right here.

Definitely, it was worth that.

### ✍️ Authors

Doctor Rosenberg (Me)


## 🚀 Usage
Install a working build or build the source code first.

On linux, you should be able to launch the executable like:

```bash
cd RaycasterAttemptLINUX
./RaycasterAttempt
```

On windows, there's NO support. Build it yourself. Sorry. It may change in the future.

## 🕹️ Controls

WASD - Move;

<- -> - Turn left, right;

Mouse - Turn left, right;

ESC - quit;


## 🔨 Building
You need:
- A compiler (g++ , clang++ , anything);
- Cmake (if you're building with CMake);
- SDL3-dev


I left the CMakeLists.txt file. You can build this with CMake.
Instructions (For linux, I have no experience on Windows. But I think the process is similar with visual studio):
0. Make a build folder to not get CMake garbage get in the project root. (optional)
1. Go to the project folder with CMakeLists.txt
2. In console, write: 
`` bash
cmake -S . -B 'put your build directory here'
``
3. Go to that directory, and in consolem write:
`` bash
make
``
4. Put the compiled executable in a folder with settings.txt, and maps folder with needed maps.



For linux users UNWILLING to deal with CMake, there's compile.sh.


