# Simple 2D Game with SGG Library

## Overview

This project is a simple 2D game developed in C++ using the [SGG (Simple Game Graphics)](https://cgaueb.github.io/sgg/index.html) library. The game involves controlling a player to collect gifts and avoid enemies (bombs), with a point-based scoring system.

## Features

- **Player Movement**: Control the player using the keyboard to move horizontally across the screen.
- **Enemies (Bombs)**: Avoid incoming bombs to stay alive and keep playing.
- **Gifts and Super Gifts**: Collect gifts to increase your score and super gifts to gain additional size and bonus points.
- **Collision Detection**: The game uses circular collision detection for interactions between the player, enemies, and gifts.
- **Audio Effects**: Enjoy sound effects when collecting gifts or getting hit by bombs.

## Project Structure

### Core Files

- **config.h**: Contains configuration settings such as asset paths and window dimensions.
- **enemy.cpp & enemy.h**: Implements the `Enemy` class, which manages bomb behavior, movement, and collision detection.
- **game1.cpp & game1.h**: Contains the main game logic, including the game loop, spawning entities, updating the game state, and handling collisions.
- **gameobject.cpp & gameObject.h**: Defines a base class for all game objects and the `Collidable` interface for collision detection.
- **gift.cpp & gift.h**: Implements the `Gift` class, representing collectible items that increase the player’s score.
- **main.cpp**: The entry point of the game, responsible for initializing the game and starting the main loop.
- **player.cpp & player.h**: Implements the `Player` class, which manages player attributes, movement, and interactions.
- **superGift.cpp & superGift.h**: Extends the `Gift` class to create a special gift with enhanced effects.
- **util.cpp & util.h**: Provides utility functions and structures used throughout the game, including random number generation and collision detection.

### Installing SGG

1. **Download SGG**: Visit the [SGG website](https://cgaueb.github.io/sgg/index.html) and download the appropriate version for your operating system.
2. **Setup**: Follow the instructions on the SGG website to configure the library in your development environment.

## How to Play

- Use the **A** and **D** keys to move the player left and right.
- Avoid bombs and collect gifts to increase your score.
- Collect super gifts to grow in size and earn more points.
- The game ends when the player’s life reaches zero.
