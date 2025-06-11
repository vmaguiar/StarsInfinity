<h3 style="display: block" align = "center">By vmaguiar</h3>

# StarsInfinity

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue.svg" alt="C++">
  <img src="https://img.shields.io/badge/Library-SFML-green.svg" alt="SFML">
  <img src="https://img.shields.io/badge/Build%20System-CMake-orange.svg" alt="CMake">
  <img src="https://img.shields.io/github/license/vmaguiar/StarsInfinity?color=yellow" alt="License">
</p>

---

## 🌌 Project Overview

**StarsInfinity** is a captivating star travel simulation developed in C++ using the SFML library. The goal is to create an
immersive visual experience where the user "travels" through a dynamic and infinite starfield. Stars are generated and rendered
with properties that vary according to their depth, such as color, scale, and transparency, providing a realistic sense of
perspective and movement.

This project explores concepts of 2D graphics, texture manipulation, and real-time motion simulations.

---

## ✨ Features

* **Infinite Starfield**: Dynamic generation and removal of stars to simulate an endless universe.
* **Depth-Based Visuals**: Each star's color, scale, and transparency are adjusted in real-time based on its "depth" in the
  simulation, creating a parallax effect.
* **Continuous Movement**: Simulates constant forward motion through the starfield.
* **Custom Textures**: Utilizes PNG image files to render stars, allowing for greater visual fidelity compared to simple geometric
  shapes.
* **SFML-Powered Rendering**: Leverages the power of the SFML library for efficient and fluid 2D graphics drawing.

---

## 🛠️ Technologies Used

* **C++**: Primary programming language (C++17).
* **SFML (Simple and Fast Multimedia Library)**: Graphics, window, and system library.
* **CMake**: Cross-platform build system for managing project compilation.

---

## 🚀 How to Run the Project

Follow these steps to set up and run StarsInfinity on your machine.

### Prerequisites

Make sure you have the following installed:

* **Git**: To clone the repository.
* **CMake**: Version 3.28 or higher.
* **A C++ Compiler**: Such as GCC, Clang, or MSVC (from Visual Studio).

### Setup and Execution Steps

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/vmaguiar/StarsInfinity.git](https://github.com/vmaguiar/StarsInfinity.git)
   cd StarsInfinity
   ```

2. **Create a build directory and navigate into it:**
   ```bash
   mkdir build
   cd build
   ```

3. **Configure CMake:**
   ```bash
   cmake ..
   ```
   This will generate the necessary build files for your system.

4. **Compile the project:**
   ```bash
   cmake --build .
   ```
   Alternatively, if you're in a Linux/macOS environment, you can use `make`:
   ```bash
   make
   ```
   In Windows environments with Visual Studio, you might use `msbuild`:
   ```bash
   msbuild StarsInfinity.sln /p:Configuration=Release
   ```

5. **Run the simulator:**
   The executable will be created inside the `build/bin/` folder (or `build/Debug/` / `build/Release/` depending on your
   configuration and OS).
   ```bash
   # Example on Windows (from the 'build' folder)
   .\bin\StarsInfinity.exe

   # Example on Linux/macOS (from the 'build' folder)
   ./bin/StarsInfinity
   ```
   The simulation window should appear, showing your journey through the stars.

---

## 📸 Screenshots / GIFs

![Star Infinity GIF](https://github.com/vmaguiar/StarsInfinity/blob/develop/res/readmeGIF.gif?raw=true)

---

## 💡 Future Enhancements and Improvements

* Performance optimizations to support an even larger number of stars.
* Basic User Interface (GUI) for simulation settings.
* Add user input controls (e.g., speed adjustment, pause).
* Add camera control for a more immersive exp.
* Implement different types of stars or particle effects.

---

## ✉️ Contact

If you have any questions or suggestions, feel free to reach out:

* **Vinicius Aguiar**: [GitHub Profile](https://github.com/vmaguiar)

---