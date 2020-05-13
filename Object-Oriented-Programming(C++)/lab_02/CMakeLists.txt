cmake_minimum_required(VERSION 3.13)
project(lab_02)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_02
        main.cpp

        mathvector/vector/Container.h
        mathvector/vector/Container.hpp

        mathvector/vector/MathVector.h
        mathvector/vector/MathVector.hpp

        mathvector/iterator/BaseIterator.hpp
        mathvector/iterator/BaseIterator.h

        mathvector/iterator/Iterator.hpp
        mathvector/iterator/Iterator.h

        mathvector/exception/Error.h
        mathvector/exception/Error.hpp)