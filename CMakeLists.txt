cmake_minimum_required(VERSION 3.12)

project(Magika-N LANGUAGES C CXX)

add_executable(Magika-N
	"main.c"
)

set_target_properties(Magika-N PROPERTIES
	C_STANDARD 99
	C_STANDARD_REQUIRED ON
	C_EXTENSIONS OFF
	CXX_STANDARD 98
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

include(CheckLibraryExists)

check_library_exists(m pow "" LIBM)
if(LIBM)
	target_link_libraries(Magika-N PRIVATE m tinfo PRIVATE m)
endif()

check_library_exists(pthread pthread_create "" LIBPTHREAD)
if(LIBPTHREAD)
	target_link_libraries(Magika-N PRIVATE pthread)
endif()

target_link_libraries(Magika-N PRIVATE ${CMAKE_DL_LIBS})

if(MSVC)
	target_compile_definitions(Magika-N PRIVATE _CRT_SECURE_NO_WARNINGS)	# Shut up those stupid warnings
endif()


include(GNUInstallDirs)

# Install directories
install(TARGETS Magika-N
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

