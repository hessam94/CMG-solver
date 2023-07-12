# CMG-solver
This package is the implementation of the Combinatorial Multigrid Preconditioner *[1]* in pure C++. The [original work](https://github.com/ikoutis/cmg-solver) is implemented by [Prof. Koutis](https://web.njit.edu/~ikoutis/) in MATALB. Combinatorial Multigrid is a preconditioner for diagonally dominant linear systems. CMG combines the strengths of multigrid with those of combinatorial preconditioning. 
CMG has proved very effective for difficult linear systems arising in optimization problems and remains one of the fastest available solvers for graph Laplacians. It has received the [best paper award](https://ieee-ceda.org/awards/william-j-mccalla-iccad-best-paper-award) at ACME/IEEE ICCAD 2022.

# Installation
This project is under development. 

## Adding necessary libraries
- you should add the `dll` path to your Environment Path.
- Also, to add the .lib and .h files, you should configure Visual Studio.
- Configuration **Properties -> VC++ Directories -> Include Directories -> Edit** to add the directory that you placed `.lib` and `.h` files
- Configuration **Properties -> Linker -> Additional Dependencies -> Edit** to add the name of the .lib files. 

In Visual Studio (project properties):
- Add the headers folder to **VC++ Directories > Library Directories**
- Add the headers folder and `headers\lib` folder to **C/C++ > General > Additional Include Directories**
- Add the `headers\lib` folder to **Linker > General > Additional Library Directories**
- Add the three libraries (`libmat.lib;libmex.lib;libmx.lib`) to **Linker > Input > Additional Dependencies**


# Citation:

[1] Ioannis Koutis, Gary L. Miller, David Tolliver, Combinatorial preconditioners and multilevel solvers for problems in computer vision and image processing, Computer Vision and Image Understanding, Volume 115, Issue 12, 2011, Pages 1638-1646, ISSN 1077-3142, https://doi.org/10.1016/j.cviu.2011.05.013.
