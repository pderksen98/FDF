# FDF

## Description

This project modelizes a 3D "fil de fer" or "wireframe" from a map of raw data which can be found in the 
test_maps folder inside of the repository. It parses through a map of coordinates and places a model derived 
from that data on the screen.

## Installation

First download the repository with the following command and change directory to the FDF repository with the following commands:

```bash
git clone git@github.com:pderksen98/FDF.git
cd FDF
```
In order to compile the program, run the following command in the home directory of the FDF repository:

```bash
make
```

In order to run the FDF program, pass a map in the test_maps folder as argument in the command line in the following manner:

```bash
./fdf test_maps/(example_map).fdf
```

In order to increase or decrease the screen pixel size, change the values of S_WIDTH and S_HEIGHT in the fdf.h header file.
In order to increase or decrease the size of the wireframe (raster), change the values of R_WIDTH and R_HEIGHT in the fdf.h header file.

## Usage

While the program is loaded and a 3D map is displayed on the screen in isometric view, the user can press the following keys in order to alter the maps coordinates and heights.

**Modify values of the z-coordinates**

* Press and hold **Z** to increase the z-value
* Press and hold **X** to decrease the z-value

**Rotate coordinates w.r.t. the x-axis**

* Press and hold **Q** to rotate coordinates in a clockwise manner around the x-axis
* Press and hold **W** to rotate coordinates in a anti-clockwise manner around the x-axis

**Rotate coordinates w.r.t. the y-axis**

* Press and hold **E** to rotate coordinates in a clockwise manner around the y-axis
* Press and hold **R** to rotate coordinates in a anti-clockwise manner around the y-axis

**Rotate coordinates w.r.t. the z-axis**

* Press and hold **T** to rotate coordinates in a clockwise manner around the z-axis
* Press and hold **Y** to rotate coordinates in a anti-clockwise manner around the z-axis

**Shift the screen in 4 directions**

* Press and hold **&#8594;** to shift the screen to the right
* Press and hold **&#8592;** to shift the screen to the left
* Press and hold **&#8593;** to shift the screen up
* Press and hold **&#8595;** to shift the screen down

**Zooming in and out**

* **Scroll up** in order to zoom in
* **Scroll down** in order to zoom out

**Quiting the program**

* Quit the program by pressing the **ESC** button or click the red cross

## Cleaning up instructions

In order to remove the objectfiles from the mlx and libft libraries, run the followin comand in the home directory:

```bash
make clean
```

For removing the executables and object files, run the following command:

```bash
make fclean
```

For re-compiling the entire program, run the following command:

```bash
make re
```

## Examples

**Below are some examples of how the program looks like for varying maps**

*test_maps/pylone.fdf*

<img width="800" alt="Screen Shot 2022-02-25 at 11 11 36 AM" src="https://user-images.githubusercontent.com/89991397/155983059-a4903342-419b-4b9c-9039-9a8db352aae3.png">

*test_maps/mars.fdf*

<img width="800" alt="Screen Shot 2022-02-25 at 11 13 25 AM" src="https://user-images.githubusercontent.com/89991397/155983144-30215d4e-0f08-4574-a92e-5ea3144da49d.png">

*test_maps/t1.fdf*

<img width="800" alt="Screen Shot 2022-02-25 at 11 06 47 AM" src="https://user-images.githubusercontent.com/89991397/155983150-e792eeae-000a-43ca-a69a-43a177dfc5cd.png">

*test_maps/julia.fdf*

<img width="800" alt="Screen Shot 2022-02-25 at 11 10 01 AM" src="https://user-images.githubusercontent.com/89991397/155983160-ac292944-77ae-4ebd-8bca-97d797a8e2f7.png">


