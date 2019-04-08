set(This airbnb)

set(Headers
    DisplayPage.hpp
    FileSystem.hpp
    AlienDictionary.hpp
    CheapestFlightWithInKStops.hpp
    IPToCIDR.hpp
)

set(Sources
    DisplayPage.cpp
    FileSystem.cpp
    AlienDictionary.cpp
    CheapestFlightWithInKStops.cpp
    IPToCIDR.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})