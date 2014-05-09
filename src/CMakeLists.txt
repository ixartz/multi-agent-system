set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Werror -pedantic -std=c++11")

file(GLOB source
     "*.h"
     "*.cpp"
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)

add_executable(multi ${source})
qt5_use_modules(multi Widgets)