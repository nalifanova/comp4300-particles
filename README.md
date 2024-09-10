# Particles

--------------------------------------
<div align="center">

[![RPG](https://img.shields.io/badge/Lecture-22-yellow.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZlcnNpb249IjEiIHdpZHRoPSI2MDAiIGhlaWdodD0iNjAwIj48cGF0aCBkPSJNMTI5IDExMWMtNTUgNC05MyA2Ni05MyA3OEwwIDM5OGMtMiA3MCAzNiA5MiA2OSA5MWgxYzc5IDAgODctNTcgMTMwLTEyOGgyMDFjNDMgNzEgNTAgMTI4IDEyOSAxMjhoMWMzMyAxIDcxLTIxIDY5LTkxbC0zNi0yMDljMC0xMi00MC03OC05OC03OGgtMTBjLTYzIDAtOTIgMzUtOTIgNDJIMjM2YzAtNy0yOS00Mi05Mi00MmgtMTV6IiBmaWxsPSIjZmZmIi8+PC9zdmc+)]()
[![C++ - Version](https://img.shields.io/badge/C++-20-blue.svg?style=flat&logo=c%2B%2B)](https://en.cppreference.com/w/cpp/compiler_support/20)
![GitHub last commit](https://img.shields.io/github/last-commit/nalifanova/particles?display_timestamp=author&style=flat&logo=github)

</div>

## About the course

[Video Lectures on YouTube](https://www.youtube.com/playlist?list=PL_xRyXins848nDj2v-TJYahzvs-XW9sVV)
COMP 4300 - C++ Game Programming (2022-09) by Dave Churchill

Topic in SMFL is [Vertex Array](https://www.sfml-dev.org/tutorials/2.6/graphics-vertex-array.php).


## About the project

Currently, it is just an example of generating particles using `sf::Quad` as a particle unit.
You can play with mouse click left and right button.

I might add changeable units and something more if I will 🤓. Will I? 🤔 Shall I?

### Guide style
* Each row of text in a code should be at most 120 characters long;
* Use a .cpp suffix for code files and .hpp for interface files;
* [Names and order of includes](https://google.github.io/styleguide/cppguide.html#Names_and_Order_of_Includes)
  Related header, C system headers, C++ standard library headers, other headers;
* In a class I prefer to see public methods, private methods, public vars, private vars. Exactly
  in this order.

### Build & run

run the script
```bash
chmod +x run.sh && ./run.sh
```

Or after making a build you can run the script this way
```bash
./Particles/build/bin/Particles
```
