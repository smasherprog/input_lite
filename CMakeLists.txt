cmake_minimum_required(VERSION 3.8)
project(input_lite)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(BUILD_EXAMPLE "Build example" ON)
option(BUILD_SHARED_LIBS "Build shared library" OFF) 

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
endif()

if(WIN32)
    set(INPUT_LITE_PLATFORM_SRC     
		src/windows/Input.cpp
    )
    set(INPUT_LITE_PLATFORM_INC     
		include/windows
    )

elseif(APPLE)
	
    set(INPUT_LITE_PLATFORM_SRC
		src/ios/Input.cpp
    )
    set(INPUT_LITE_PLATFORM_INC
		include/ios 
    )
else()
	set(INPUT_LITE_PLATFORM_SRC
		src/linux/Input.cpp
    )
	find_package(X11 REQUIRED)
	set(INPUT_LITE_PLATFORM_INC
		include/linux 
		${X11_INCLUDE_DIR}
    )	
endif()

include_directories(	
	include  
	${INPUT_LITE_PLATFORM_INC}
)
add_library(${PROJECT_NAME} 
	include/Input_Lite.h 
	src/InputManager.cpp 
	src/Input_Lite.cpp
	${INPUT_LITE_PLATFORM_SRC}
)

 if(${BUILD_SHARED_LIBS})	
	set_target_properties(${PROJECT_NAME} PROPERTIES DEFINE_SYMBOL INPUT_LITE_DLL)
	if(APPLE)
		find_package(Threads REQUIRED)
		find_library(corefoundation_lib CoreFoundation)
		find_library(cocoa_lib Cocoa)
		target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} ${corefoundation_lib} ${cocoa_lib})
	else()
		find_package(X11 REQUIRED)
		if(!X11_XTest_FOUND)
 			message(FATAL_ERROR "X11 extensions are required, but not found!")
		endif()
		if(!X11_Xfixes_LIB)
 			message(FATAL_ERROR "X11 fixes extension is required, but not found!")
		endif()
		find_package(Threads REQUIRED)
		target_link_libraries(${PROJECT_NAME} 			
			${X11_LIBRARIES}
			${X11_Xfixes_LIB}
			${X11_XTest_LIB}
			${CMAKE_THREAD_LIBS_INIT}
		)
	endif()
endif()

install (TARGETS ${PROJECT_NAME}  
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
)


install (FILES 
	include/Input_Lite.h 
	DESTINATION include
)

if(BUILD_EXAMPLE)
  add_subdirectory(Test)
endif()

