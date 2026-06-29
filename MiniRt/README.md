# MiniRT

MiniRT is a small ray tracing engine written in C as part of the 42 Common Core.

The goal of the project is to render simple 3D scenes from a scene description file by implementing the core principles of ray tracing: camera rays, object intersections, lighting, shadows and image rendering.

This project connects low-level C programming with graphics, geometry and mathematical reasoning.

---

## Overview

MiniRT reads a scene file, parses the objects and camera configuration, then renders the scene by casting rays from the camera into the 3D world.

For each pixel, the program computes which object is hit by the ray, calculates lighting and shadows, then displays the final image using MiniLibX.

```text
scene file
  ↓
parser
  ↓
camera + objects + lights
  ↓
ray generation
  ↓
intersection tests
  ↓
lighting and shadows
  ↓
rendered image
```

---

## Main Topics

* ray tracing
* 3D geometry
* vector math
* camera system
* object intersections
* lighting
* shadows
* scene parsing
* color handling
* MiniLibX graphics
* memory management in C

---

## Supported Scene Elements

Depending on the scene file, the renderer can handle elements such as:

* ambient light
* camera
* light sources
* spheres
* planes
* cylinders

Each object requires specific intersection logic and surface normal calculation.

---

## Skills Practiced

* C programming
* 3D mathematical reasoning
* vector operations
* ray-object intersection algorithms
* parsing structured files
* graphics programming
* debugging visual output
* memory management
* project organization

---

## Why This Project Matters

MiniRT is important because it shows how mathematical concepts become visible software.

Unlike many terminal-based projects, MiniRT produces a visual result. Small bugs in vector calculations, camera orientation, lighting or parsing can completely change the final image.

It helped me understand:

* how a 3D scene can be represented in code
* how rays are generated from a camera
* how intersections are calculated
* how lighting affects the final color
* how shadows are produced
* how difficult visual debugging can be

---

## Rendering Pipeline

The simplified rendering flow is:

```text
for each pixel:
    generate camera ray
    find closest object intersection
    compute surface normal
    check light visibility
    calculate final color
    draw pixel
```

This structure made the project a good introduction to graphics engines, rendering pipelines and game/visual programming concepts.

---

## How to Build

```bash
make
```

---

## How to Run

```bash
./miniRT path/to/scene.rt
```

Example:

```bash
./miniRT scenes/example.rt
```

The exact scene path depends on the files available in this repository.

---

## Example Scene Format

A simplified scene may contain elements like:

```text
A 0.2 255,255,255
C 0,0,0 0,0,1 70
L 10,10,10 0.8 255,255,255
sp 0,0,20 5 255,0,0
pl 0,-5,0 0,1,0 255,255,255
cy 5,0,20 0,1,0 3 10 0,255,0
```

This defines ambient light, a camera, a light source and several objects.

---

## What I Learned

The most important lessons from MiniRT were:

* how to translate geometry into code
* how vectors are used in graphics programming
* how object-specific intersection formulas work
* how camera direction and field of view affect rendering
* how surface normals are used for lighting
* how shadows are computed by casting secondary rays
* how parsing errors can affect the whole rendering pipeline
* how visual projects require a different debugging approach

---

## Notes

MiniRT was one of the most visual and mathematically interesting projects of the Common Core.

It helped me connect low-level C programming with 3D rendering concepts, which are useful foundations for graphics programming, game development, simulation and visual computing.
