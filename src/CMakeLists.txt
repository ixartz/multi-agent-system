set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Werror -pedantic -std=c++11")

file(GLOB source
     "*.h"
     "*.cpp"
)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})
include_directories(${Qt4_INCLUDES})
add_definitions(${Qt4_DEFINITIONS})

add_executable(multi ${source})
target_link_libraries(multi ${Qt4_LIBRARIES})
qt4_use_modules(multi Core)
qt4_use_modules(multi Gui)