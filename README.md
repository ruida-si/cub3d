# 🕹️ Cub3D

Cub3D is a 3D graphical project developed as part of the 42 School curriculum. It is a simple 3D game engine that uses **raycasting** to render a 3D world from a 2D map, inspired by early 90s games like *Wolfenstein 3D*.

## 📽️ Project Overview

Cub3D is built using C and the **MiniLibX** graphics library. The core idea is to simulate a 3D environment using **raycasting**, where each vertical line on the screen represents a ray cast into the 2D map to detect walls and render them with depth.

## 🔧 Features

- Raycasting engine for 3D perspective
- Keyboard controls for movement and rotation
- Basic texture mapping for walls
- Collision detection
- Configurable map parsing from `.cub` files

## 🎮 Controls

| Key       | Action          |
|-----------|-----------------|
| W / ↑     | Move forward    |
| S / ↓     | Move backward   |
| A         | Move left     |
| D         | Move right    |
| ← / →     | Rotate view     |
| ESC       | Quit game       |

## 🗺️ Map Format (`.cub`)

Your `.cub` map file must include:
- Texture paths (NO, SO, WE, EA)
- Floor and ceiling colors (F, C)
- A 2D map layout using characters:
  - `1`: wall
  - `0`: empty space
  - `N`, `S`, `E`, `W`: player start position and orientation

Example:
```plaintext
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
