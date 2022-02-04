## radian
> 360° == 2π, 이므로
1° == π / 180

```c

# define PI				3.14

# define FOV_ANGLE  	60 * (PI / 180)
# define NUM_RAY 		320 (width of screen)

ray_angle += FOV_ANGLE / NUM_RAY;

// dimension of the projection plan == 320 x 200
// distance between ray : 60° / 320

```
## projection plan and distance
-------------320--------------- // projection plane
              ------160-------
			|	
			|
			|
			|	// distance player to projection plane   tan 30 == 160 / distance	// adjacent == 160 / tan 30 = 277.29
			|
			|
			|
			.
			  (fov 60)

## player movement
>  


