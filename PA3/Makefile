# in EC327, we use the g++ compiler
# therefore, we define the GCC variable
GCC = g++
# a target to compile the Checkpoint which depends on all object-files
# and which links all object-files into an executable
Checkpoint3: TestCheckpoint3.o Building.o PokemonCenter.o PokemonGym.o GameObject.o Point2D.o Vector2D.o Pokemon.o
	$(GCC) TestCheckpoint3.o Building.o PokemonCenter.o PokemonGym.o GameObject.o Point2D.o Vector2D.o Pokemon.o -o Checkpoint3
# a target to compile the TestCheckpoint3.cpp into an object-file
TestCheckpoint3.o: TestCheckpoint3.cpp
	$(GCC) -c TestCheckpoint3.cpp
# a target to compile the GameObject.cpp into an object-file
GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp
# a target to compile the Point2D.cpp into an object-file
Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp
# a target to compile the Vector2D.cpp into an object-file
Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp
# a target to compile the Building.cpp into an object-file
Building.o: Building.cpp
	$(GCC) -c Building.cpp
# a target to compile the PokemonCenter.cpp into an object-file
PokemonCenter.o: PokemonCenter.cpp
	$(GCC) -c PokemonCenter.cpp
# a target to compile the PokemonGym.cpp into an object-file
PokemonGym.o: PokemonGym.cpp
	$(GCC) -c PokemonGym.cpp
# a target to compile the Pokemon.cpp into an object-file
Pokemon.o: Pokemon.cpp
	$(GCC) -c Pokemon.cpp