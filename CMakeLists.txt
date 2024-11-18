#----------------------------------------------#
#-----Konfiguration des Buildsystems CMake-----#
#----------------------------------------------#

# Minimale Version des Buildsystems
cmake_minimum_required(VERSION 3.16)
# Name des Projekts
project(ProjectAlpha)

#----------------------------------------------#
#-------------------Optionen-------------------#
#----------------------------------------------#

# Setzte verwendeten C++-Standard auf C++17
set(CMAKE_CXX_STANDARD 17)
# Optional: Baue mit Debugsymbolen / Optimierung
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)
# Optional: Prüfe alle Targets auf Speicherlecks
# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)

# Füge Includeverzeichnisse hinzu
include_directories(include)
include_directories(external)
# Legt die Variable SRC_FILES an, die alle
# .cpp-Dateien des Projekts benennt,
# die in Verzeichnis src/ liegen.
file(GLOB SRC_FILES
  ${PROJECT_SOURCE_DIR}/src/*.cpp)

#----------------------------------------------#
#---------------Erzeuge Projekt----------------#
#----------------------------------------------#

# Baue das Programm 'demo1' aus den Quellen
# examples/demo1.cpp und allen Quelldateien in
# SRC_FILES (also alle im Verzeichnis src/)
add_executable(demo_1
  examples/demo_1.cpp
  ${SRC_FILES}
)

add_executable(demo_Locke
  examples/demo_Locke.cpp
  ${SRC_FILES} ${SRC_FILES_CONTAINER}
)

add_executable(demo_Wirtz
  examples/demo_Wirtz.cpp
  ${SRC_FILES} ${SRC_FILES_CONTAINER}
)

add_executable(demo_Musa
  examples/demo_Musa.cpp
  ${SRC_FILES} ${SRC_FILES_CONTAINER}
)

#----------------------------------------------#
#----------Download and use GoogleTest---------#
#----------------------------------------------#

# Use CMakes FetchContent
include(FetchContent)
# Workaround for CMake >= 3.24
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

# Download GoogleTest (we use version 1.12.1)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Workaround for Windows:
# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Include CMake configuration of GoogleTest
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Enable GoogleTest
enable_testing()

#----------------------------------------------#
#-------------Erzeuge Testprogramme------------#
#----------------------------------------------#

# Declare test program demo_1_test
add_executable(demo_1_test tests/demo_1_test.cpp ${SRC_FILES})
target_link_libraries(demo_1_test GTest::gtest_main)
gtest_discover_tests(demo_1_test)

# Declare test program demo_2_test
add_executable(demo_2_test tests/demo_2_test.cpp ${SRC_FILES})
target_link_libraries(demo_2_test GTest::gtest_main)
gtest_discover_tests(demo_2_test)

# Declare test program demo_3_test
add_executable(demo_3_test tests/demo_3_test.cpp ${SRC_FILES})
target_link_libraries(demo_3_test GTest::gtest_main)
gtest_discover_tests(demo_3_test)

# Declare test program LinkedList_test
add_executable(LinkedList_test tests/LinkedList_test.cpp ${SRC_FILES})
target_link_libraries(LinkedList_test GTest::gtest_main)
gtest_discover_tests(LinkedList_test)

# Declare test program DoublyLinkedList_test
add_executable(DoublyLinkedList_test tests/DoublyLinkedList_test.cpp ${SRC_FILES})
target_link_libraries(DoublyLinkedList_test GTest::gtest_main)
gtest_discover_tests(DoublyLinkedList_test)

# Declare test program Stack_test
add_executable(Stack_test tests/Stack_test.cpp ${SRC_FILES})
target_link_libraries(Stack_test GTest::gtest_main)
gtest_discover_tests(Stack_test)

# Declare test program HashMap_test
add_executable(HashMap_test tests/HashMap_test.cpp ${SRC_FILES})
target_link_libraries(HashMap_test GTest::gtest_main)
gtest_discover_tests(HashMap_test)

