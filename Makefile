# in EC327, we use the g++ compiler
# therefore, we define the GCC variable
GCC = g++ -std=c++0x
# a target to compile the Checkpoint which depends on all object-files
# and which links all object-files into an executable
Game: Main.o Building.o PokemonCenter.o PokemonGym.o GameObject.o Point2D.o Vector2D.o Pokemon.o Model.o GameCommand.o View.o Rival.o BattleArena.o
	$(GCC) Main.o Building.o PokemonCenter.o PokemonGym.o GameObject.o Point2D.o Vector2D.o Pokemon.o Model.o GameCommand.o View.o Rival.o BattleArena.o -o Game
# a target to compile the TestCheckpoint3.cpp into an object-file
Main.o: Main.cpp
	$(GCC) -c Main.cpp
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
# a target to compile the Model.cpp into an object-file
Model.o: Model.cpp
	$(GCC) -c Model.cpp
# a target to compile the GameCommand.cpp into an object-file
GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp
# a target to compile the View.cpp into an object-file
View.o: View.cpp
	$(GCC) -c View.cpp
# a target to compile the Rival.cpp into an object-file
Rival.o: Rival.cpp
	$(GCC) -c Rival.cpp
# a target to compile the BattleArena.cpp into an object-file
BattleArena.o: BattleArena.cpp
	$(GCC) -c BattleArena.cpp
# a target to compile the Pokemon.cpp into an object-file
Pokemon.o: Pokemon.cpp
	$(GCC) -c Pokemon.cpp
# clean target
clean:
	rm -f *.o