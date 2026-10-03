cmake_minimum_required(VERSION 4.3)
project(tictactoe)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)
set(CMAKE_CXX_STANDARD 17)
add_executable(tictactoe Src/main.cpp
        Inc/main.h
        Inc/Pokemon_vector.h
        Src/Pokemon_vector.cpp
        Src/pokemon.cpp
        Src/Pokedex.cpp
        Inc/pokemon.h
        Inc/Pokedex.h
        Src/Pokemon_Party.cpp
        Inc/Pokemon_Party.h
        Inc/GameState.h
        Inc/Game.h
        Inc/StartState.h
        Src/StartState.cpp
        Inc/SelectPokemonState.h
        Src/SelectPokemonState.cpp
        Inc/BattleState.h
        Src/BattleState.cpp
        Inc/GameOverState.h
        Src/GameOverState.cpp
        Src/Game.cpp
        Src/RestState.cpp
        Inc/RestState.h
        Src/PokemonSprite.cpp
        Inc/PokemonSprite.h
        Inc/UI.h
        Src/UI.cpp

)
target_link_libraries(tictactoe
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)
