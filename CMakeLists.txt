cmake_minimum_required(VERSION 3.11)

project(LinkedListApp CXX)

set(CMAKE_CXX_STANDARD 23)

# —пецифичные настройки дл€ компил€тора Visual Studio
if(MSVC)
    # √енерируем статическую заглушку дл€ динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # ¬ключаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# ќбъ€вл€ем библиотеки
add_library(set_lib SHARED "include/set.cpp")
target_include_directories(set_lib PUBLIC "include")

# ќбъ€вл€ем консольное приложение
add_executable(app "app/main.cpp")
target_link_libraries(app set_lib)