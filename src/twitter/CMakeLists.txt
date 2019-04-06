set(This twitter)

set(Headers
    LogStorage.hpp
    MedianFromStream.hpp
    InsertInterval.hpp
)

set(Sources
    LogStorage.cpp
    MedianFromStream.cpp
    InsertInterval.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})