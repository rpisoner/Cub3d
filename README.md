# 🎮 Cub3D

![Gameplay](https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExa3hreXFkZHA0YjQ2bXBrY3c3cHA1azh5ZW1iOW91ZjZoZmU0cGh2ciZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/ZzkaHLO4BjvpTVWXb8/giphy.gif)

**Cub3D** is a 3D raycasting project inspired by *Wolfenstein 3D*, developed using the **MiniLibX** library. It renders a 3D environment from a 2D map, handling player movement, interactions, and basic game mechanics.

---

## ✨ Features

✔ **Raycasting Engine** – Renders a 3D environment using raycasting.  
✔ **Smooth Player Movement** – Move in all directions with smooth transitions.  
✔ **Camera Control** – Rotate using the keyboard or mouse for a more immersive experience.  
✔ **Minimap** – A top-down view displaying the player's position.  
✔ **Wall Collisions** – Prevents the player from walking through walls.  
✔ **Animated Sprites** – Dynamic objects with simple animations.  
✔ **Interactable Doors** – Open and close doors for added realism.  

---

## 🎮 Controls

🕹 **Movement:**  
- `W` / `S` → Move forward / backward  
- `A` / `D` → Strafe left / right  

🎥 **Camera Rotation:**  
- `←` / `→` → Rotate left / right  
- **Mouse Movement** → Smooth camera rotation (only works properly in ubuntu)

🗝 **Interaction:**  
- `E` → Open / Close doors  

---

## ⚙ Installation

Clone the repository and compile the project:

```bash
git clone https://github.com/jaimeol/Cub3d.git
cd cub3d
make
./cub3D maps/map.cub

```
If you want to test the bonus part:

```bash
git clone https://github.com/jaimeol/Cub3d.git
cd cub3d
make bonus
cd bonus
./cub3d_bonus maps/map.cub
