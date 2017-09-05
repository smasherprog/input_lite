cmake_minimum_required(VERSION 3.8)
project(input_lite)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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
	src/InputManager.cpp 
	src/Input_Lite.cpp
	${INPUT_LITE_PLATFORM_SRC}
)

if(BUILD_SHARED_LIBS)
	install (TARGETS ${PROJECT_NAME}  
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	)
else()
	install (TARGETS ${PROJECT_NAME}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	)
endif()

install (FILES 
	include/Input_Lite.h 
	DESTINATION include
)

add_subdirectory(Test)
