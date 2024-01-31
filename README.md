# Terminal-Console-Functions

## Overview

These are a few functions I implemented in C++ to make my work easier while working on terminal based projects.

## Functions
- #### clearScreen()
  The clearScreen function uses the Windows Console API. It is designed to minimize flickering by efficiently updating the console buffer. system("cls"),
  on the other hand,may introduce more noticeable flickering, especially in scenarios where the console is refreshed frequently.

  However only on a windows system will the function work and if cross-platform compatability is crutial system("cls") is a better alternative.

- #### hideCursor()
  This function creates an object 'cursor' which is used to configure the appearence and visibility of the cursor. Hiding the cursor provides a more cleaner and immersive experience in terminal projects,
  being a windows console API function it is platform specific.

- #### CenteredOutput
  The CenteredOutput class offers an encapsulated and reusable solution for centering and printing text on the terminal. It encapsulates the logic for cursor positioning and printing, promoting a modular and 
  maintainable design. The templated print function allows versatile output of different value types, enhancing readability and expressiveness. The class can be easily modified without affecting the rest of 
  the code, providing adaptability for future enhancements. By separating concerns and providing a fluent interface, the class promotes a structured and extensible approach for console output management.

  This approach provides a more precise control over positioning the text in complex layouts and dynamic scenarios.

- #### centerMovingText()
  The centerMovingText function facilitates the display of scrolling text in the center of the console window. It intelligently calculates the optimal starting position for centering based on the console screen width and the length of the input text. By introducing a specified time delay between character displays, the function creates a smooth scrolling effect. The use of leading spaces ensures the centered alignment of the scrolling text. This function enhances the visual appeal of console applications, providing a dynamic and engaging user experience.
