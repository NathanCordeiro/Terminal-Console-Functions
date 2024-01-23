# Overview

These are a few functions I implemented in C++ to make my work easier while working on terminal based projects.

## Functions
- #### clearScreen()
  The clearScreen function uses the Windows Console API. It is designed to minimize flickering by efficiently updating the console buffer. system("cls"),
  on the other hand,may introduce more noticeable flickering, especially in scenarios where the console is refreshed frequently.

  However only on a windows system will the function work and if cross-platform compatability is crutial system("cls") is a better alternative.
