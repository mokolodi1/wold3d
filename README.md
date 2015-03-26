# wolf3d: a 42 project

This is a project that I did at École 42. The subject for the project is here: https://cdn.intrav2.42.fr/pdf/pdf/24/wolf3d.pdf


The goal of this project was to create a 'game' modeled after Wolfenstein 3D (a first person shooter released in 1992). 

Specifications:
- the arrow keys should allow you to move around the labyrinth (or WASD; Q and E to rotate the camera)
- the escape key should quit
- the colors of the walls must vary with their orientation

I also added collision handling and a custom map generator using Google Sheets (https://docs.google.com/spreadsheets/d/1aRdje8c_uhFyBkuTSum6NVpipAV-pKIJK65KAC3L9hg/edit?usp=sharing)

Authorized functions:
- open
- read
- write
- close
- malloc
- free
- perror
- strerror
- exit
- math library functions (-lm)
- minilibx functions (-lmlx) (GUI library provided by 42, included in repo under minilibx_macos/)
