# CMG-solver
This project is under development. you should add the dll path to your Environment Path. Also, to add the .lib and .h files, you should configure the Visual studio.  
Configuration Properties -> VC++ Directories -> Include Directories -> Edit to add the directory that you placed .lib and .h files  
and  
Configuration Properties -> Linker -> Additional Dependencies -> Edit to add the name of the .lib files. 

In Visual Studio (project properties):
- Add the headers folder to VC++ Directories > Library Directories
- Add the headers folder and headers\lib folder to C/C++ > General > Additional Include Directories
- Add the headers\lib folder to Linker > General > Additional Library Directories
- Add the three libraries (libmat.lib;libmex.lib;libmx.lib) to Linker > Input > Additional Dependencies
