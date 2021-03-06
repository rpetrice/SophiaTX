add_executable( sophiatxd_light main.cpp )
if( UNIX AND NOT APPLE )
    set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling sophiatxd_light with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( SOPHIATX_STATIC_BUILD )
    target_link_libraries( sophiatxd_light PRIVATE
            "-static-libstdc++ -static-libgcc"
            appbase
            sophiatx_utilities
            sophiatx_plugins
            ${CMAKE_DL_LIBS}
            ${PLATFORM_SPECIFIC_LIBS}
            )
else( SOPHIATX_STATIC_BUILD )
    target_link_libraries( sophiatxd_light PRIVATE
            appbase
            sophiatx_utilities
            sophiatx_plugins
            ${CMAKE_DL_LIBS}
            ${PLATFORM_SPECIFIC_LIBS}
            )
endif( SOPHIATX_STATIC_BUILD )

if( CLANG_TIDY_EXE )
    set_target_properties(
            sophiatxd_light PROPERTIES
            CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
    )
endif( CLANG_TIDY_EXE )

install( TARGETS
        sophiatxd_light

        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )
