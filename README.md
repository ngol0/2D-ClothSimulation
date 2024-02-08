# 2D Cloth Simulation using Verlet Integration

A cloth made with points and stick contraints that connect the points together. Verlet Integration is used to update the points to create movement and physics simulation.

This project uses C++ and SDL.  

## Run
Download the project and open the **.sln** file in **Visual Studio 2022**. Then hit **F5** to run. If there's error, make sure [SDL is set up with Windows and VS](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php).

## Intruction
- Left mouse: drag the cloth
- Right mouse: tear the cloth
- Mouse wheel: zoom in and out the cursor size

<img src="https://github.com/ngol0/2D-ClothSimulation/blob/main/gif.gif" width="900" title="cloth simulation">

## Attribute
This follows the instruction and explanation on [Pikuma's Blog](https://pikuma.com/blog/verlet-integration-2d-cloth-physics-simulation) with some modification and `tear by distance` function.
