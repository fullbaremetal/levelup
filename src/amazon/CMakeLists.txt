set(This amazon)

set(Headers
    AutoCompleteSystem.hpp
    CutoffTreesForGolfEvent.hpp
)

set(Sources
    AutoCompleteSystem.cpp
    CutoffTreesForGolfEvent.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})