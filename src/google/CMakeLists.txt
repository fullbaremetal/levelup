set(This google)

File(GLOB Headers *.hpp)

File(GLOB Sources *.cpp)

ADD_LIBRARY(${This} STATIC ${Sources} ${Headers})
