set(This amazon)

set(Headers
    AutoCompleteSystem.hpp
    CutoffTreesForGolfEvent.hpp
    MaxFreqStack.hpp
)

set(Sources
    AutoCompleteSystem.cpp
    CutoffTreesForGolfEvent.cpp
    MaxFreqStack.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})