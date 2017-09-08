project(input_lite_test)

if(APPLE)
	find_library(corefoundation_lib CoreFoundation)
	find_library(cocoa_lib Cocoa)
	set(INPUT_LITE_PLATFORM_LIBS ${corefoundation_lib} ${cocoa_lib})
else()
	find_package(X11 REQUIRED)
	if(!X11_XTest_FOUND)
 		message(FATAL_ERROR "X11 extensions are required, but not found!")
	endif()
	if(!X11_Xfixes_LIB)
 		message(FATAL_ERROR "X11 fixes extension is required, but not found!")
	endif()
	find_package(Threads REQUIRED)
	set(INPUT_LITE_PLATFORM_LIBS
		${X11_LIBRARIES}
		${X11_Xfixes_LIB}
		${X11_XTest_LIB}
		${CMAKE_THREAD_LIBS_INIT}
	)
	
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} input_lite ${INPUT_LITE_PLATFORM_LIBS})

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
