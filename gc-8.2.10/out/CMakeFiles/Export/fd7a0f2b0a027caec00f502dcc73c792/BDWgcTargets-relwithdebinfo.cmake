#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "BDWgc::cord" for configuration "RelWithDebInfo"
set_property(TARGET BDWgc::cord APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(BDWgc::cord PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcord.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "BDWgc::gc"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libcord.dll"
  )

list(APPEND _cmake_import_check_targets BDWgc::cord )
list(APPEND _cmake_import_check_files_for_BDWgc::cord "${_IMPORT_PREFIX}/lib/libcord.dll.a" "${_IMPORT_PREFIX}/bin/libcord.dll" )

# Import target "BDWgc::gc" for configuration "RelWithDebInfo"
set_property(TARGET BDWgc::gc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(BDWgc::gc PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libgc.dll.a"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/libgc.dll"
  )

list(APPEND _cmake_import_check_targets BDWgc::gc )
list(APPEND _cmake_import_check_files_for_BDWgc::gc "${_IMPORT_PREFIX}/lib/libgc.dll.a" "${_IMPORT_PREFIX}/bin/libgc.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
