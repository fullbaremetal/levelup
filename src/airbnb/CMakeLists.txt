set(This airbnb)

set(Headers
    DisplayPage.hpp
    FileSystem.hpp
)

set(Sources
    DisplayPage.cpp
    FileSystem.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})