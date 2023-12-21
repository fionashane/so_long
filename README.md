
# so_long - 42 Project

![so_long](https://img.shields.io/badge/ft_printf-42-success)
![Project Grade](https://img.shields.io/badge/Project_Grade-100%2F100-informational)

The **So_long** project is part of the curriculum at [42 Adelaide](https://www.42adel.org.au), designed to challenge students in building a simple 2D game using the MinilibX graphics library. This project focuses on graphics rendering, game loop implementation, and basic game design.

## Project Objectives

The main objectives of the So_long project are:

- Implement a 2D game using C and the MinilibX graphics library.
- Create a game map and render it on the screen.
- Handle user input for game controls.
- Implement game logic, such as player movement and collectibles.
- Display game information and manage the game loop.

## How to Use

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/fionashane/so_long.git
    ```

2. Compile the project using the provided Makefile:

    ```bash
    make
    ```

3. Run the game executable:

    ```bash
    ./so_long maps/map_file.ber
    ```

   Replace `map_file.ber` with the path to your custom map file.

4. Play the game! Move the player character, collect items, and reach the exit.

## Controls

- **W**: Move Up
- **A**: Move Left
- **S**: Move Down
- **D**: Move Right
- **ESC**: Exit the game

## Features

- **Graphics Rendering**: Use the MinilibX library to render graphics and create a visual representation of the game.
- **Map Loading**: Load game maps from external files in the specified format (`.ber`).
- **Player Interaction**: Implement player movement and interaction with game elements.
- **Collectibles**: Include collectible items that the player can gather.
- **Exit**: Define an exit point that the player must reach to win the game.
- **Game Loop**: Implement a game loop to continuously update and render the game.
