set(This amazon)

set(Headers
    AutoCompleteSystem.hpp
    CutoffTreesForGolfEvent.hpp
    MaxFreqStack.hpp
    SerializeAndDeserialzieBinaryTree.hpp
)

set(Sources
    AutoCompleteSystem.cpp
    CutoffTreesForGolfEvent.cpp
    MaxFreqStack.cpp
    SerializeAndDeserialzieBinaryTree.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})