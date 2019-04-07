set(This airbnb)

set(Headers
    DisplayPage.hpp
    FileSystem.hpp
    AlienDictionary.hpp
    CheapestFlightWithInKStops.hpp
)

set(Sources
    DisplayPage.cpp
    FileSystem.cpp
    AlienDictionary.cpp
    CheapestFlightWithInKStops.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})