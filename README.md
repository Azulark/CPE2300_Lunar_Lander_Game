# CPE2300_Lunar_Lander_Game
A 2D game where you land a rocket to a launch pad (have to consider thrust power, angle position, and gravity to safely land or else it will crash and burn)
- to increase/decrease thrust, use W/S or up arrow/down arrow keys
- to rotate left, use left arrow key or A
- to rotate right, use right arrow key or D

DEVELOPER'S NOTE:
*requires msys2 ucrt54, and raylib to run code on VS Studio (aka make a development environment to test and run the code)
-MYS2 UCRT64 gives GCC to compile C code
-RayLib is the graphics library 
** VS Studio terminal needs the two following lines to run game on VS Studio:
  1. gcc LL.c -o lunarlander.exe -lraylib -lopengl32 -lgdi32 -lwinmm
  2. .\lunarlander.exe
