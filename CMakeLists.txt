cmake_minimum_required(VERSION 3.10)

#Устанавливает имя проекта в переменную PROJECT_NAME
#Объявляет проект с именем "vector_matrix"
set(PROJECT_NAME vector_matrix)
project(${PROJECT_NAME})

set_property(GLOBAL PROPERTY LIBS_P "")
set_property(GLOBAL PROPERTY LIBS_I_P "")


#Включает пользовательские функции из файла cmake/function.cmake
include(cmake/function.cmake)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) #Устанавливает директорию для статических библиотек (.a/.lib) в build/lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) #Устанавливает директорию для динамических библиотек (.so/.dll) в build/lib
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin) #Исполняемые файлы Release-сборки будут в build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}) #Debug-сборки также будут в той же папке (обычно их разделяют)

set(MP2_LIBRARY "${PROJECT_NAME}") #Имя библиотеки проекта
set(MP2_TESTS   "test_${PROJECT_NAME}") #Имя тестового модуля 
set(MP2_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include") #Путь к заголовочным файлам проекта

include_directories("${MP2_INCLUDE}" gtest) #Добавляет директории для поиска заголовочных файлов: include/ - заголовки проекта, gtest/ - заголовки Google Test

# BUILD
# Подключает поддиректории для сборки
add_subdirectory(include)
add_subdirectory(samples)
add_subdirectory(gtest)
add_subdirectory(test)