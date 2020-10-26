# RTv1
Simple Ray tracing technique renderer

## Descriptioin:
One rendered frame of scene, that is set in the file. Colored basic shapes: sphere, plane, cone, cylinder. Colored light points, some spots and shadows.

Ray casting algorithm explanation:
<>

## Build:
```
make
```

## Usage:
- **Run**
```
./RTv1 scenes/[scene name]
```
- **Create scene**
  - add scene to "./scenes/[scene name]". File example:
  ```
  name  point   direction   radius  color     smoothness

  cam   7,0,0   -3,0,0
  cne   0,0,0   0,0,3       1       0xF8FF33  100
  lgt   10,5,0  -           -       0xffffff  -
  ```
  cam - camera; lgt - light;
  
  sph - sphere; pln - plane; cne - cone; cld - cylinder

## Screenshots:
<>
<>
<>
