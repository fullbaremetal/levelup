set(This amazon)

set(Headers
    AutoCompleteSystem.hpp
)

set(Sources
    AutoCompleteSystem.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})