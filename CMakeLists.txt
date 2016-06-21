# ------------------------------------------------------------------------------

message("Processing 3p/glm...")

# ------------------------------------------------------------------------------

set(MODULE_NAME glm)

# ------------------------------------------------------------------------------

file(GLOB GLM_INLINE glm/*.inl)
file(GLOB GLM_HEADER glm/*.hpp)

file(GLOB_RECURSE CORE_INLINE glm/detail/*.inl)
file(GLOB_RECURSE CORE_HEADER glm/detail/*.hpp)

file(GLOB_RECURSE GTC_INLINE glm/gtc/*.inl)
file(GLOB_RECURSE GTC_HEADER glm/gtc/*.hpp)

file(GLOB_RECURSE GTX_INLINE glm/gtx/*.inl)
file(GLOB_RECURSE GTX_HEADER glm/gtx/*.hpp)

# ------------------------------------------------------------------------------

source_group("GLM Files" FILES ${GLM_INLINE})
source_group("GLM Files" FILES ${GLM_HEADER})
source_group("Core Files" FILES ${CORE_HEADER})
source_group("GTC Files" FILES ${GTC_INLINE})
source_group("GTC Files" FILES ${GTC_HEADER})
source_group("GTX Files" FILES ${GTX_INLINE})
source_group("GTX Files" FILES ${GTX_HEADER})

# ------------------------------------------------------------------------------

set(HEADERS)
list(APPEND HEADERS ${GLM_INLINE})
list(APPEND HEADERS ${GLM_HEADER})
list(APPEND HEADERS ${CORE_INLINE})
list(APPEND HEADERS ${CORE_HEADER})
list(APPEND HEADERS ${GTC_INLINE})
list(APPEND HEADERS ${GTC_HEADER})
list(APPEND HEADERS ${GTX_INLINE})
list(APPEND HEADERS ${GTX_HEADER})

# ------------------------------------------------------------------------------

set(MODULE_SOURCES
	${HEADERS}
	cmake_header_only.cpp
)

# ------------------------------------------------------------------------------


add_library(${MODULE_NAME} 
	STATIC
	${MODULE_SOURCES}
)

# ------------------------------------------------------------------------------

target_include_directories(${MODULE_NAME}
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)

# ------------------------------------------------------------------------------

if(COMMAND apply_target_settings)
	apply_target_settings(${MODULE_NAME})
endif()

# ------------------------------------------------------------------------------

# Tidy up solution 
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET ${MODULE_NAME} PROPERTY FOLDER "3p" )

# ------------------------------------------------------------------------------

