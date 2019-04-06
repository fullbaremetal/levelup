set(This airbnb)

set(Headers
    DisplayPage.hpp
    FileSystem.hpp
    AlienDictionary.hpp
)

set(Sources
    DisplayPage.cpp
    FileSystem.cpp
    AlienDictionary.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})